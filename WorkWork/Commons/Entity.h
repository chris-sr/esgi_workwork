#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "IEntity.h"

namespace ww
{
	class Entity : public IEntity
	{
	private:
	
	protected:
		sf::Vector2f _pos;
		sf::Vector2f _size;
		sf::Sprite _sprite;
		bool _enabled;
		bool _visible;
		int _drawOrder;
		
	public:
		Entity();
		~Entity();

		virtual void update(const sf::Time & deltaTime);
		virtual void draw(sf::RenderWindow & window);
        
        bool containsMouse(const sf::Vector2f & mousePos);
        bool isClicked(const sf::Vector2f & mousePos);

		sf::Vector2f & getPosition();
		void setPosition(const sf::Vector2f & pos);
		void setPosition(float posX, float posY);

		sf::Vector2f & getSize();
		void setSize(sf::Vector2f & size);
		void setSize(float width, float height);

		sf::Sprite & getSprite();

		int getDrawOrder();
		void setDrawOrder(int drawOrder);

		bool isEnabled();
		void setEnabled(bool enabled);

		bool isVisible();
		void setVisible(bool visible);
	};
}

#endif

