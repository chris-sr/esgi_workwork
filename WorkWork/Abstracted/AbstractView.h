#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

/* c++ header */
#include <sstream>
#include <vector>

/* SFML header */
#include <SFML/Graphics.hpp>

#include "IView.h"

namespace ww
{
	class DrawHandler;
	class IEntity;

	class AbstractView : public IView
	{
	private:
		
	protected:
		DrawHandler* _drawHandler;
		
		bool _enabled;
		bool _visible;

		std::stringstream _ss;

	public:
		AbstractView();
		~AbstractView();

		virtual void init();
		virtual void render(sf::RenderWindow & window);

		bool isVisible();
		void setVisible(bool visible);

		bool isEnabled();
		void setEnabled(bool enabled);
	};
}

#endif