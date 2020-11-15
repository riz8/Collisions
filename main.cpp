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

bool PointCollideRectangle(const sf::Vector2f& p, const sf::RectangleShape& r)
{
	const auto& rpos = r.getPosition();
	if (
		p.x >= rpos.x && // right of left side
		p.x <= rpos.x + r.getSize().x && // left of right side
		p.y >= rpos.y && // below top side
		p.y <= rpos.y + r.getSize().y // above bottom side
		)
	{
		return true;
	}

	return false;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Test Window");

	sf::Color background_color = sf::Color::Black;

	sf::Vertex mousePoint(sf::Vector2f(10.f, 10.f));

	sf::RectangleShape targetRectangle(sf::Vector2f(50.f, 50.f));
	targetRectangle.setPosition(250.f, 250.f);
	targetRectangle.setFillColor(sf::Color::Green);

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

		if (PointCollideRectangle(mousePoint.position, targetRectangle))
		{
			background_color = sf::Color::Red;
		}
		else
		{
			background_color = sf::Color::Black;
		}

		window.clear(background_color);
		window.draw(&mousePoint, 1, sf::Points);
		window.draw(targetRectangle);
		window.display();
	}

	return 0;
}