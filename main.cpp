#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Test Window");

	sf::Vertex line1[] =
	{
		sf::Vertex(sf::Vector2f(50.f, 50.f)),
		sf::Vertex(sf::Vector2f(100.f, 100.f))
	};

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(line1, 2, sf::Lines);
		window.display();
	}

	return 0;
}