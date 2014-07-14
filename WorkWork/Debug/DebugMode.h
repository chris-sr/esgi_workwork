#ifndef DEBUGMODE_H
#define DEBUGMODE_H

#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

namespace ww
{
	class Simulation;
	class ResourceHandler;

	class DebugMode
	{
	private:
		Simulation* _simulation;
		ResourceHandler* _resourceHandler;
	
		std::stringstream _ss;
		sf::Text _text;
        sf::Vector2f _gridSize;

		bool _showTextFPS;
		bool _showGrid;
		bool _showTextEntityDraw;
		bool _showTextVideoMode;

	protected:

	public:
		DebugMode(Simulation* simulation);
		~DebugMode();

		bool loadFont(const std::string & fontPath);

		void renderDebug(sf::RenderWindow & window);
		void drawTextFPS(sf::RenderWindow & window, const std::string & msg, float posX, float posY,
                         int charSize, const sf::Color & color);
		void drawGrid(sf::RenderWindow & window);
		void drawTextEntityDraw(sf::RenderWindow & window, const std::string & msg, float posX, float posY,
                                const int charSize, const sf::Color & color);
		void drawTextVideoMode(sf::RenderWindow & window, const std::string & msg, float posX, float posY,
                               const int charSize, const sf::Color & color);

		sf::Text & getText();

        void setGridSize(const sf::Vector2f & gridSize);
        void setGridSize(float width, float height);

		void setShowTextFPS(bool showTextFPS);
		void setShowGrid(bool showGrid);
		void setShowTextEntityDraw(bool showTextEntityDraw);
		void setShowTextVideoMode(bool showTextVideoMode);
	};
}

#endif
