#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Tooltip.h"

namespace ww
{
	class Button : public Entity
	{
	private:
		sf::Text _text;
        std::string _tooltipLabel;

	protected:

	public:
		Button();
		Button(const sf::Vector2f & pos, const sf::Vector2f & size);
		~Button();

		void load(sf::Texture & texture, sf::Font & font);
		void update(const sf::Time & deltaTime);
		void draw(sf::RenderWindow & window);
        
        bool actionMouseEntered(const sf::Vector2f & mousePos, ww::Tooltip & tooltip);

		void setText(const std::string & label, int labelSize, const sf::Color & labelColor);
		void centerText();

		sf::Text & getText();
        
        std::string & getTooltipLabel();
        void setTooltipLabel(const std::string & tooltipLabel);
	};
}

#endif

