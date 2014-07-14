#ifndef IVIEW_H
#define IVIEW_H

#include <SFML/Graphics.hpp>

namespace ww
{
	class IEntity;

	class IView
	{
	public:
		/* Pour forcer l'appel du destructeur de la classe enfant */
		virtual ~IView() {};

		virtual void init() = 0;
		virtual void render(sf::RenderWindow & window) = 0;
	};
}

#endif