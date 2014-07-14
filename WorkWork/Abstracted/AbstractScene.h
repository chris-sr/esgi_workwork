#ifndef ABSTRACTSCENE_H
#define ABSTRACTSCENE_H

/* c++ header */
#include <vector>

/* SFML header */
#include <SFML/Graphics.hpp>

#include "IScene.h"

namespace ww
{
	class Simulation;
	class IModel;
	class ResourceHandler;

	class AbstractScene : public IScene
	{
	private:

	protected:
		Simulation* _simulation;
		ResourceHandler* _resourceHandler;
		
        AbstractScene* _nextScene;
        
        sf::Vector2f _size;

	public:
		AbstractScene(Simulation* simulation, const sf::Vector2f & size);
		/* Pour forcer l'appel du destructeur de la classe enfant */
		virtual ~AbstractScene();

		virtual void load();
		virtual void eventInput(sf::RenderWindow & window, sf::Event & event);
		virtual void update(const sf::Time & deltaTime);
		virtual void render(sf::RenderWindow & window);
		virtual void unload();
		virtual void switchScene();

		bool haveLoadErrors();

		void loadFont(const std::string & fontPath);
		sf::Font & getFont(const std::string & fontPath);

		void loadTexture(const std::string & texturePath);
		void loadTextureSmooth(const std::string & texturePath);
		sf::Texture & getTexture(const std::string & fontPath);
        
        sf::Vector2f & getSize();
        void setSize(float width, float height);
        void setSize(const sf::Vector2f & size);
	};
}

#endif