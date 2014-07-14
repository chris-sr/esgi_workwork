#include <iostream>
#include <sstream>
#include <fstream>

#include "Settings.h"
#include "Constants.h"

ww::Settings::Settings()
{
	sf::VideoMode desktopVideoMode = sf::VideoMode::getDesktopMode();

	_currentVideoMode = sf::VideoMode(desktopVideoMode.width, desktopVideoMode.height);
	//_currentVideoMode = sf::VideoMode(1280, 720);
	
	_fullscreen = true;
	
	loadSettingsFile();
	detectFullscreenVideoModes();
}

ww::Settings::~Settings()
{

}

void ww::Settings::loadSettingsFile()
{
	char delim = '=';
	std::string line;
	//std::istringstream iss;
	std::ifstream file(ww::File::CONFIG);

	if (file.is_open())
	{
		std::cout << "///*** Loading config file ! ***///" << std::endl;
		
		while (std::getline(file, line, delim))
		{
			std::cout << line << std::endl;
		}
		file.close();
		
		std::cout << "///*** Config file loaded ***///" << std::endl << std::endl;
	}
	else
	{
		std::cout << "Error loading config file !" << std::endl;
	}
}

void ww::Settings::detectFullscreenVideoModes()
{
	// Display the list of all the video modes available for fullscreen
	std::vector<sf::VideoMode> tmp_modes = sf::VideoMode::getFullscreenModes();
	for (int i = 0; i < tmp_modes.size(); i++)
	{
		sf::VideoMode mode = tmp_modes[i];
		std::cout << "Mode #" << i << ": "
				  << mode.width << "x" << mode.height << " - "
				  << mode.bitsPerPixel << " bpp" << std::endl;
	}
	std::cout << std::endl;
	//TODO Trier/recuperer que certains modes video
	//_fullscreenVideoModes =
}

sf::VideoMode & ww::Settings::getCurrentVideoMode()
{
	return _currentVideoMode;
}

bool ww::Settings::isFullscreen()
{
	return _fullscreen;
}