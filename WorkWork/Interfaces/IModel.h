#ifndef IMODEL_H
#define IMODEL_H

#include <SFML/Graphics.hpp>

namespace ww
{
	class IModel
	{
	public:
		/* Pour forcer l'appel du destructeur de la classe enfant */
		virtual ~IModel() {};
	};
}

#endif