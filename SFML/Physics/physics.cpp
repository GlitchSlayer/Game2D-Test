#include "stdafx.h"

float phys::DotProduct(const sf::Vector2f& a, const sf::Vector2f& b)
{
    return a.x * b.x + a.y * b.y;
}

float phys::Approach(const float& flGoal, const float& flCurrent, const float& dt)
{
    float flDiffrence = flGoal - flCurrent;

    if(flDiffrence > dt)
        return flCurrent + dt;

    if(flDiffrence < -dt)
        return flCurrent - dt;

    return flGoal;
}
