#pragma once

namespace phys
{
	const sf::Vector2f GRAVITY = { 0, 100 };

    float DotProduct(const sf::Vector2f& a, const sf::Vector2f& b);
    float Approach(const float& flGoal, const float& flCurrent, const float& dt);
};

