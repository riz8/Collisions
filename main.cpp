#include <SFML/Graphics.hpp>

bool PointCollidePoint(const sf::Vector2f& a, const sf::Vector2f& b)
{
	if (a.x == b.x && a.y == b.y)
		return true;

	return false;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Test Window");

	sf::Color background_color = sf::Color::Black;

	sf::Vertex mousePoint(sf::Vector2f(10.f, 10.f));
	sf::Vertex targetPoint(sf::Vector2f(250.f, 250.f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::MouseMoved)
			{
				auto new_position = sf::Vector2f{ static_cast<float>(event.mouseMove.x - 20), static_cast<float>(event.mouseMove.y - 20) };
				mousePoint.position = new_position;
			}
		}

		if (PointCollidePoint(mousePoint.position, targetPoint.position))
		{
			background_color = sf::Color::Red;
		}
		else
		{
			background_color = sf::Color::Black;
		}

		window.clear(background_color);
		window.draw(&targetPoint, 1, sf::Points);
		window.draw(&mousePoint, 1, sf::Points);
		window.display();
	}

	return 0;
}