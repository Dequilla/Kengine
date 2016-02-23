#include "Button.h"

Kengine::Button::Button(sf::Font &font, sf::Vector2f size) : m_overActive(true)
{
	this->setSize(size);
	this->setFont(font);
}

void Kengine::Button::setSize(const sf::Vector2f size)
{
	m_size = size;
	m_body.setSize(m_size);
	this->update();
}

void Kengine::Button::setString(const std::string string)
{
	this->m_text.setString(string);
	this->update();
}

void Kengine::Button::setFont(sf::Font & font)
{
	m_font = & font;
	m_text.setFont(*m_font);
	this->update();
}

void Kengine::Button::events(sf::Event & event)
{
	if (m_clicked == true) m_clicked = false;
	

	if (event.type == sf::Event::MouseButtonPressed && m_mouseCursorOver)
	{
		m_buttonPressed = true;
	}
	else if (m_buttonPressed && event.type == sf::Event::MouseButtonReleased)
	{
		m_buttonPressed = false;
		if (m_mouseCursorOver)
		{
			m_clicked = true;
		}
	}
}

void Kengine::Button::handler(sf::RenderWindow & window)
{
	
	sf::FloatRect body(this->getPosition().x, this->getPosition().y, this->m_size.x, this->m_size.y);
	if (body.contains(sf::Vector2f(sf::Mouse::getPosition(window))))
	{
		this->m_mouseCursorOver = true;
		this->setOverAction(true);
		if (m_overActive)
		{
			m_text.setColor(m_overTextColor);
			m_body.setFillColor(m_overBackgroundColor);
			m_body.setOutlineColor(m_overOutlineColor);
		}
		
	}
	else if (m_text.getColor() != m_textColor || m_body.getFillColor() != m_backgroundColor || m_body.getOutlineColor() != m_outlineColor)
	{
		this->m_mouseCursorOver = false;
		m_body.setFillColor(m_backgroundColor);
		m_body.setOutlineColor(m_outlineColor);
	}
}

void Kengine::Button::update()
{
	if (m_size.x > 0 && m_size.y > 0 && m_text.getString() != "")
	{
		if (m_text.getGlobalBounds().width < m_size.x / 4 * 3 && m_text.getGlobalBounds().height < m_size.y - 10.0f)
		{
			while (m_text.getGlobalBounds().width < m_size.x / 4 * 3 && m_text.getGlobalBounds().height < m_size.y - 10.f)
			{
				m_text.setCharacterSize(m_text.getCharacterSize() + 1);
			}
			if (m_text.getGlobalBounds().width < m_size.x / 4 * 3 || m_text.getGlobalBounds().height < m_size.y - 10.f)
			{
				m_text.setCharacterSize(m_text.getCharacterSize() - 1);
			}
		}
		else
		{
			while (m_text.getGlobalBounds().width > m_size.x / 4 * 3 && m_text.getGlobalBounds().height > m_size.y - 10.f)
			{
				m_text.setCharacterSize(m_text.getCharacterSize() - 1);
			}
			if (m_text.getGlobalBounds().width > m_size.x / 4 * 3 || m_text.getGlobalBounds().height > m_size.y - 10.f)
			{
				m_text.setCharacterSize(m_text.getCharacterSize() + 1);
			}
		}
		
		m_text.setOrigin(m_text.getLocalBounds().left + m_text.getLocalBounds().width / 2, m_text.getLocalBounds().top + m_text.getLocalBounds().height / 2);
		m_text.setPosition(m_size.x / 2, m_size.y / 2);

	}
}

void Kengine::Button::setOverAction(bool active)
{
	this->m_overActive = active;
}

void Kengine::Button::setOverBackgroundColor(const sf::Color & color)
{
	this->m_overBackgroundColor = color;
}

void Kengine::Button::setOverTextColor(const sf::Color & color)
{
	this->m_overTextColor = color;
}

void Kengine::Button::setOverOutlineColor(const sf::Color & color)
{
	this->m_overOutlineColor = color;
}

void Kengine::Button::setBackgroundColor(const sf::Color & color)
{
	this->m_backgroundColor = color;
	this->m_body.setFillColor(color);
}

void Kengine::Button::setTextColor(const sf::Color & color)
{
	this->m_textColor = color;
	this->m_text.setColor(color);
}

void Kengine::Button::setOutlineThickness(float thickness)
{
	this->m_body.setOutlineThickness(thickness);
}

void Kengine::Button::setOutlineColor(const sf::Color & color)
{
	this->m_outlineColor = color;
	this->m_body.setOutlineColor(color);
}

void Kengine::Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_body, states);
	target.draw(m_text, states);
}
