#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>

#include "Utilities.h"

namespace Kengine
{
template<typename Derived, typename T>
class ResourceManager
{
public:
	ResourceManager(const std::string& filePath)
	{
		loadPaths(filePath);
	}

	virtual ~ResourceManager() { purgeResources(); }


	T* getResource(const std::string& id)
	{
		// Look for our string argument in the map
		auto res = find(id);

		// Return at pointer to the pair element of the map if something is found.
		// return nullptr if nothing is found.
		return (res ? res->first : nullptr);
	}

	std::string getPath(const std::string& id)
	{
		// Get the path to a particular resource
		auto path = m_paths.find(id);
		return(path != m_paths.end() ? path->second : "");
	}

	// Make sure that the resource doesn't get de-allocated while it's being used.
	bool requireResource(const std::string& id)
	{
		auto res = find(id);

		// Increment the counter of instances a resource is being used when it's required
		if (res)
		{
			++res->second;
			return true;
		}

		auto path = m_paths.find(id);
		if (path == m_paths.end()) { return false; }

		// Acquire a pointer to newly allocated memory
		T* resource = load(path->second);
		if (!resource) { return false; }

		// If load doesn't return a nullptr value, insert resource with a counter set to 1
		m_resources.emplace(id, std::make_pair(resource, 1));

		return true;
	}

	bool releaseResource(const std::string& id)
	{
		auto res = find(id);
		if (!res) { return false; }
		
		--res->second;
		
		if (!res->second) { unload(id); }
		return true;
	}

	// PURGE ALL RESOURCES
	void purgeResources()
	{
		while (m_resources.begin() != m_resources.end())
		{
			delete m_resources.begin()->second.first;
			m_resources.erase(m_resources.begin());
		}
	}

	T* load(const std::string& path)
	{
		return static_cast<Derived*>(this)->load(path);
	}

private: 
	std::unordered_map<std::string, std::pair<T*, unsigned int>> m_resources;
	std::unordered_map<std::string, std::string> m_paths;

	std::pair<T*, unsigned int>* find(const std::string& id)
	{
		auto itr = m_resources.find(id);
		return (itr != m_resources.end() ? &itr->second : nullptr);
	}

	bool unload(const std::string& id)
	{
		auto itr = m_resources.find(id);
		if (itr == m_resources.end()) { return false; }

		delete itr->second.first;
		m_resources.erase(itr);
		
		return true;
	}

	void loadPaths(const std::string& pathFile)
	{
		std::ifstream paths;
		paths.open(Utils::getWorkingDirectory() + pathFile);

		if (paths.is_open())
		{
			std::string line;

			while (std::getline(paths, line))
			{
				std::stringstream keystream(line);
				std::string pathName;
				std::string path;
				keystream >> pathName;
				keystream >> path;
				m_paths.emplace(pathName, path);
			}
			paths.close();
			return;
		}
		std::cerr << "! Failed loading the path file: " << pathFile << std::endl;
	}
};
}