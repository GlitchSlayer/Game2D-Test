#include "stdafx.h"

Player::Player(const sf::Vector2f& position, const float& width, const float& height)
	: m_position(position), m_velocity( {0, 0} ) {

	m_isAlive = true;
	
	m_font.loadFromFile("Resources/impact.ttf");
	m_txt.setFont(m_font);
	m_txt.setPosition(0, 0);
	m_txt.setFillColor({ 255, 255, 255 });
	
	m_shape.setPosition(m_position);
	m_shape.setSize( {width, height} );
	m_shape.setFillColor( {255, 0, 0} );
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_shape);
}

void Player::update(const float& deltaTime) {

	sf::Vector2f lastVelocity = m_velocity;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_velocityGoal.x = 100;
		m_slowDown = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_velocityGoal.x = -100;
		m_slowDown = false;
    }

    if(m_onGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		m_velocity.y = -250.f;
    if(m_slowDown)
		m_velocityGoal.x = 0;

	m_velocity.x = phys::Approach(m_velocityGoal.x, m_velocity.x, deltaTime*70);

	m_position += m_velocity * deltaTime;

    if(m_position.y >= 550)
    {
		m_onGround = true;
		m_position.y = 550;
	}
	else {
		m_velocity += phys::GRAVITY * deltaTime;
		m_onGround = false;
	}
	
	m_acceleration = (m_velocity - lastVelocity)/(deltaTime);
	//std::cout << "Acceleration: {" << m_acceleration.x << ", " << m_acceleration.y << "}\n";

	m_shape.setPosition(m_position);
}
