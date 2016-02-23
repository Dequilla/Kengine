#pragma once
#include "SFML/Graphics.hpp"

class MenuButton : public sf::Text
{
public:
	
	bool clicked();
	void setClicked(bool clicked);

private:
	bool		m_clicked;

};