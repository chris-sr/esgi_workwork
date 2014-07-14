#ifndef DRAWHANDLER_H
#define DRAWHANDLER_H

#include <SFML/Graphics.hpp>

#include <vector>

namespace ww
{
	class Entity;

	class DrawHandler
	{
	private:
		std::vector<Entity*> _drawQueue;

	protected:

	public:
		DrawHandler();
		~DrawHandler();

		void addInDrawQueue(Entity* entity);
		void sortDrawQueue();
		void drawExecute(sf::RenderWindow & window);
		void clearDrawQueue();

		int getQueueSize();
	};
}

#endif
