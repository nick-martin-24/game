//
//  bullet.cpp
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#include "bullet.h"
#include "player.h"

Bullet::Bullet()
{
    m_Speed = 1500;
    m_InFlight = false;
    
    m_Texture.loadFromFile("/Users/nickmartin/projects/cpp/game/images/burger.png");
    m_Sprite.setTexture(m_Texture);
}

Sprite Bullet::getSprite()
{
    return m_Sprite;
}

FloatRect Bullet::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

int Bullet::getSpeed()
{
    return m_Speed;
}

bool Bullet::isInFlight()
{
    return m_InFlight;
}

void Bullet::resetPosition()
{
    m_Position.x = 0;
    m_Position.y = 0;
}

void Bullet::stop()
{
    m_InFlight = false;
}

void Bullet::shoot(FloatRect pos)
{
    m_InFlight = true;
    m_Position.x = pos.left + pos.width/2;
    m_Position.y = pos.top + pos.height/2;
}

void Bullet::update(float elapsedTime, Vector2u winSize)
{
    if (m_InFlight)
        m_Position.x += m_Speed * elapsedTime;
    
    if (m_Position.x > winSize.x) stop();
    
    m_Sprite.setPosition(m_Position);
}
