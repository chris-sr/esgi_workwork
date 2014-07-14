#ifndef IENTITY_H
#define IENTITY_H

#include <SFML/Graphics.hpp>

namespace ww
{
	class IEntity
	{
	public:
		/* Pour forcer l'appel du destructeur de la classe enfant */
		virtual ~IEntity() {};

		static const float UNIT_WIDTH;
		static const float UNIT_HEIGHT;

		virtual void update(const sf::Time & deltaTime) = 0;
		virtual void draw(sf::RenderWindow & window) = 0;
	};
}

#endif