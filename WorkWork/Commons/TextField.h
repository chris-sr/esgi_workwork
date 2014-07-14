#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <SFML/Graphics.hpp>

#include "Entity.h"

namespace ww
{
	class TextField : public Entity
	{
	private:
		sf::Text _text;

	protected:

	public:
		TextField();
		~TextField();

		void load(sf::Texture & texture, sf::Font & font);
		void update(const sf::Time & deltaTime);
		void draw(sf::RenderWindow & window);
	
		bool containsMouse(const sf::Vector2f & mousePos);
		bool isClicked(const sf::Vector2f & mousePos);

		void centerText();
		bool isLetter(char letter);

		sf::Sprite & getSprite();
		sf::Text & getText();
	};
}

#endif

