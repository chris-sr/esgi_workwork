#ifndef WORKSPACEVIEW_H
#define WORKSPACEVIEW_H

/* c++ header */
#include <sstream>

/* SFML header */
#include <SFML/Graphics.hpp>

#include "AbstractView.h"

namespace ww
{
	class WorkspaceModel;
	class DrawHandler;

	class WorkspaceView : public AbstractView
	{
	private:
		WorkspaceModel* _model;

	protected:

	public:
		WorkspaceView(WorkspaceModel* model, DrawHandler* drawHandler);
		~WorkspaceView();

		void init();
		void render(sf::RenderWindow & window);
	};
}

#endif