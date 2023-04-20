
//Chaos Project by Julian Rambob and Prabhi Singh

// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
using namespace sf;
using namespace std;
int main()
{
	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;
	View mainView(FloatRect(0.0f, 0.0f, width, height));
	//width = 800; height = 600;
	// Create a video mode object
	VideoMode vm(width, height);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game", Style::Default);

	vector<Vector2f> vertices;
	vector<Vector2f> points;

	bool chaos = false;
	int point_counter = 0;

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
						std::cout << "the left button was pressed" << std::endl;
						std::cout << "mouse x: " << event.mouseButton.x << std::endl;
						std::cout << "mouse y: " << event.mouseButton.y << std::endl;
						vertices.push_back({ (float)event.mouseButton.x, (float)event.mouseButton.y });
				}
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					if (vertices.size() >= 3)
						{
						std::cout << "the right button was pressed" << std::endl;
						points.push_back({ (float)event.mouseButton.x, (float)event.mouseButton.y });
						chaos = true;
					}

				}
			}
		}

		/*****************************************
			Update the scene
		*****************************************/
		//generate points

		instructions.setString("Left click the vertices of your shape, then right click to start the Chaos");

		if (chaos)
		{	
			int random = rand() % vertices.size();
			Vector2f next_p(static_cast<float>((vertices.at(random).x + points.at(point_counter).x) / 2), static_cast<float>((vertices.at(random).y + points.at(point_counter).y )/ 2));
			point_counter++;
			points.push_back(next_p);

		}

		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.setView(mainView);
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		RectangleShape r{ Vector2f{ 5, 5} }; //width, height. Center uninitialized
		r.setFillColor(Color::Cyan);

		for (size_t i = 0; i < vertices.size(); i++)
		{
			r.setPosition(Vector2f{ vertices.at(i).x, vertices.at(i).y });
			window.draw(r);
		}

		RectangleShape p{ Vector2f{1, 1} };
		p.setFillColor(Color::Magenta);

		for (size_t i = 0; i < points.size(); i++)
		{
			p.setPosition(Vector2f{ points.at(i).x, points.at(i).y });
			window.draw(p);
		}

	
		window.draw(instructions);

		// Show everything we just drew
		window.display();
	}

	return 0;
}
	