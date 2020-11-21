//
//  enemy.cpp
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#include "enemy.h"

Enemy::Enemy()
{
    m_ySpeed = 400;
    m_xSpeed = 50;
    m_Position.x = 2500;
    m_Position.y = 300;
    
    m_TextureAlive.loadFromFile("/Users/nickmartin/projects/cpp/game/images/nick.png");
    m_TextureDead.loadFromFile("/Users/nickmartin/projects/cpp/game/images/explosion2.png");
    m_Sprite.setTexture(m_TextureAlive);
}

Sprite Enemy::getSprite()
{
    return m_Sprite;
}

FloatRect Enemy::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

int Enemy::getySpeed()
{
    return m_ySpeed;
}

void Enemy::reverse()
{
    m_ySpeed = -m_ySpeed;
}

void Enemy::die()
{
    m_Sprite.setTexture(m_TextureDead, true);
    m_ySpeed = 0;
    m_xSpeed = 0;
}

void Enemy::update(bool hitStatus, float elapsedTime, Vector2u winSize)
{
    if (getPosition().top < 0 || ((getPosition().top + getPosition().height) > winSize.y))
        reverse();
    
    m_Position.x -= m_xSpeed * elapsedTime;
    m_Position.y += m_ySpeed * elapsedTime;
    m_Sprite.setPosition(m_Position);
    if (hitStatus)
        die();
}

void Enemy::reset()
{
    m_ySpeed = 400;
    m_xSpeed = 50;
    m_Position.x = 2500;
    m_Position.y = 300;
    m_Sprite.setTexture(m_TextureAlive);
}

void Enemy::reset_stop()
{
    m_ySpeed = 0;
    m_xSpeed = 0;
    m_Position.x = 2500;
    m_Position.y = 300;
    m_Sprite.setTexture(m_TextureAlive);
}
