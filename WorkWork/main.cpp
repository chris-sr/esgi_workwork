#include <iostream>

#include <SFML/Graphics.hpp>

#include "Simulation.h"

int main(int argc, char* argv[])
{
	ww::Simulation simulation;
	simulation.setShowTextFPS(true);
	simulation.setShowGrid(true);
	simulation.setShowTextEntityDraw(true);
	simulation.setShowTextVideoMode(true);
	simulation.run();
    
	return EXIT_SUCCESS;
}