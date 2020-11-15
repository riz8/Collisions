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

bool CircleCollideCircle(const sf::CircleShape& c1, const sf::CircleShape& c2)
{
	auto c1x = c1.getPosition().x + c1.getRadius();
	auto c2x = c2.getPosition().x + c2.getRadius();
	auto c1y = c1.getPosition().y + c1.getRadius();
	auto c2y = c2.getPosition().y + c2.getRadius();

	float delta_x = c1x - c2x;
	float delta_y = c1y - c2y;

	float distance = std::sqrt((delta_x*delta_x) + (delta_y*delta_y));

	if (distance <= c1.getRadius() + c2.getRadius())
		return true;

	return false;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Test Window");

	sf::Color background_color = sf::Color::Black;

	const float radius_mouseCirle = 15.f;
	sf::CircleShape mouseCircle(radius_mouseCirle * 2);
	mouseCircle.setFillColor(sf::Color::Blue);

	const float radius_targetCircle = 15.f;
	sf::CircleShape targetCircle(radius_targetCircle *2);
	targetCircle.setFillColor(sf::Color::Green);
	targetCircle.setPosition(250.f - radius_targetCircle, 250.f - radius_targetCircle);

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
				mouseCircle.setPosition(new_position);
			}
		}

		if (CircleCollideCircle(mouseCircle, targetCircle))
		{
			background_color = sf::Color::Red;
		}
		else
		{
			background_color = sf::Color::Black;
		}

		window.clear(background_color);
		window.draw(targetCircle);
		window.draw(mouseCircle);
		window.display();
	}

	return 0;
}