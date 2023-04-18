// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
using namespace sf;
using namespace std;
int main()
{
	sf::View view(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Fullscreen);
	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			/*if (event.type == Event::KeyReleased && !paused)
			{
			}*/
		}
		/*****************************************
			Update the scene
		*****************************************/
		//do stuff
		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.setView(view);
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		//window.draw(
		// Show everything we just drew
		window.display();
	}

	return 0;
}
