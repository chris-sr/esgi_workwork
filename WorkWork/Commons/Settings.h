#ifndef SETTINGS_H
#define SETTINGS_H

/* c++ header */
#include <iostream>
#include <vector>

/* SFML header */
#include <SFML/Graphics.hpp>

namespace ww
{
	class Settings
	{
	private:
		void detectFullscreenVideoModes();
		void loadSettingsFile();

		bool _fullscreen;
		sf::VideoMode _currentVideoMode;
		std::vector<sf::VideoMode> _fullscreenVideoModes;

	protected:

	public:
		Settings();
		~Settings();

		sf::VideoMode & getCurrentVideoMode();
		bool isFullscreen();
	};
}

#endif