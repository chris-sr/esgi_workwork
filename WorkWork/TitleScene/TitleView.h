#ifndef TITLEVIEW_H
#define TITLEVIEW_H

/* c++ header */
#include <sstream>
#include <vector>

/* SFML header */
#include <SFML/Graphics.hpp>

#include "AbstractView.h"

namespace ww
{
	class TitleModel;
	class DrawHandler;
	class Entity;
	class Button;

	class TitleView : public AbstractView
	{
	private:
		TitleModel* _model;

	protected:

	public:
		TitleView(TitleModel* model, DrawHandler* _drawHandler);
		~TitleView();
		
		void init();
		void render(sf::RenderWindow & window);
	};
}

#endif