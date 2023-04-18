// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
using namespace sf;
using namespace std;
int main()
{
	sf::View view(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
	// Create a video mode object
	VideoMode vm(800, 600);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game", Style::Default);

	vector<Vector2f> vertices;
	vector<Vector2f> points;

	Font f;
	f.loadFromFile("ApeMount-WyPM9.ttf");

	Text instructions;
	instructions.setPosition(10, 10);
	instructions.setFont(f);
	instructions.setCharacterSize(24);
	instructions.setFillColor(Color::White);

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
			if (event.type == Event::Closed)
			{
				window.close();
			}

			//mouse click event
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					vertices.push_back({(float) event.mouseButton.x, (float) event.mouseButton.y });
				}
			}
		}

		/*****************************************
			Update the scene
		*****************************************/
		//generate points

		instructions.setString("Click Three points, then click once to start the Chaos");
		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.setView(view);
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		RectangleShape r{ Vector2f{ 10, 10} }; //width, height. Center uninitialized
		r.setFillColor(Color::Yellow);
		for (size_t i = 0; i < vertices.size(); i++)
		{

			r.setPosition(Vector2f{ vertices.at(i).x, vertices.at(i).y });
			window.draw(r);
		}

		window.draw(instructions);

		// Show everything we just drew
		window.display();
	}

	return 0;
}
