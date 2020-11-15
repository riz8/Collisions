#include <SFML/Graphics.hpp>
#include <cmath>

bool PointCollidePoint(const sf::Vector2f& a, const sf::Vector2f& b)
{
	if (a.x == b.x && a.y == b.y)
		return true;

	return false;
}

bool PointCollideCircle(const sf::Vector2f& p, const sf::CircleShape& c)
{
	// SFML objects origo is top left
	float delta_x = p.x - c.getPosition().x - c.getRadius();
	float delta_y = p.y - c.getPosition().y - c.getRadius();

	// Pythagoras to find distance between point and circle center
	float distance = std::sqrt((delta_x*delta_x) + (delta_y*delta_y));

	if (distance <= c.getRadius())
		return true;

	return false;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Test Window");

	sf::Color background_color = sf::Color::Black;

	sf::Vertex mousePoint(sf::Vector2f(10.f, 10.f));
	
	const float radius = 15.f;
	sf::CircleShape circle(radius*2);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(250.f - radius, 250.f - radius);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::MouseMoved)
			{
				auto new_position = sf::Vector2f{ static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y) };
				mousePoint.position = new_position;
			}
		}

		if (PointCollideCircle(mousePoint.position, circle))
		{
			background_color = sf::Color::Red;
		}
		else
		{
			background_color = sf::Color::Black;
		}

		window.clear(background_color);
		window.draw(&mousePoint, 1, sf::Points);
		window.draw(circle);
		window.display();
	}

	return 0;
}