#pragma once

class Player
{

public:
    bool m_slowDown;

    void update(const float& deltaTime);
    void draw(sf::RenderWindow& window);

    Player(const sf::Vector2f& _position, const float& width, const float& height);
	~Player() { }

private:
	bool m_isAlive;
	bool m_onGround;

	sf::Font m_font;
	sf::Text m_txt;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_velocityGoal;
	sf::RectangleShape m_shape;
};

