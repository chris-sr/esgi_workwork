#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <map>

namespace ww
{
	class ResourceHandler
	{
	private:
		std::map<const std::string, sf::Font> _fontMap;
		std::map<const std::string, sf::Texture> _textureMap;
		std::vector<const std::string> _loadErrors;

	protected:

	public:
		ResourceHandler();
		~ResourceHandler();

		void addLoadError(const std::string & errorMsg);
		bool haveLoadErrors();
		void displayLoadErrors();
		void clearLoadError();

		bool loadFont(const std::string & fontPath);
		void clearFonts();

		bool loadTexture(const std::string & texturePath);
		void clearTextures();

		std::map<const std::string, sf::Font> & getFontMap();
		std::map<const std::string, sf::Texture> & getTextureMap();
	};
}

#endif
