#pragma once

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace Kengine
{
	///////////////////////////////////////////////////////////////////////////
	// 
	//	Kopter is a class that is made to read .kopt option files used
	//	with your Kengine game.
	//
	//	Example use:	Kengine::Kopter	kopter;	
	//					kopter.readFile("FILEPATH");
	//					string option = kopter.getStringOption("OPTION-NAME");
	// 
	///////////////////////////////////////////////////////////////////////////
	class Kopter
	{
	public:
		Kopter();
		~Kopter() {};

		bool readFile(std::string filePath);

		std::string getStringOptionAt(std::string optionName);
		bool		getBoolOptionAt(std::string optionName);
		int			getIntOptionAt(std::string optionName);
		float		getFloatOptionAt(std::string optionName);

	private:

		std::vector<std::string>	seperateOptions(std::string optionsLine);

		std::map<std::string, std::string>			m_optionsContainer;
		std::fstream								m_file;


	};
}