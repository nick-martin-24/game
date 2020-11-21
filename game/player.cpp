//
//  player.cpp
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#include "player.h"
#include "bullet.h"

Player::Player()
{
    m_Speed = 800;
    m_Position.x = 500;
    m_Position.y = 1300;
    
    m_Texture.loadFromFile("/Users/nickmartin/projects/cpp/game/images/kara.png");
    m_Sprite.setTexture(m_Texture);
    
    m_clipSize = 10;
    m_currentBullet = 0;
    m_bulletsRemaining = m_clipSize - m_currentBullet;
    m_lives = 3;
    hitEnemy = false;
    beenHit = false;
}

Sprite Player::getSprite()
{
    return m_Sprite;
}

Vector2f Player::getPosition()
{
    return m_Position;
}

Bullet Player::getBullet(int position)
{
    return m_Bullets[position];
}

int Player::getCurrentBullet()
{
    return m_currentBullet;
}

int Player::getClipSize()
{
    return m_clipSize;
}

int Player::getLives()
{
    return m_lives;
}

int Player::getBulletsRemaining()
{
    return m_bulletsRemaining;
}

int Player::getSpeed()
{
    return m_Speed;
}

void Player::fireBullet()
{
    m_currentBullet++;
    m_bulletsRemaining--;
}

void Player::decrementLives()
{
    m_lives--;
}

void Player::moveLeft()
{
    m_LeftPressed = true;
}

void Player::moveRight()
{
    m_RightPressed = true;
}

void Player::moveUp()
{
    m_UpPressed = true;
}

void Player::moveDown()
{
    m_DownPressed = true;
}

void Player::shoot()
{
    m_SpacePressed = true;
}

void Player::stopLeft()
{
    m_LeftPressed = false;
}

void Player::stopRight()
{
    m_RightPressed = false;
}

void Player::stopUp()
{
    m_UpPressed = false;
}

void Player::stopDown()
{
    m_DownPressed = false;
}

void Player::stopShoot()
{
    m_SpacePressed = false;
}

bool Player::hasHitEnemy()
{
    return hitEnemy;
}

bool Player::hasBeenHit()
{
    return beenHit;
}

bool Player::anyBulletInFlight()
{
    for (int i=0; i<getClipSize(); i++)
    {
        if (m_Bullets[i].isInFlight())
            return true;
    }
    return false;
}

void Player::hit()
{
    decrementLives();
    this->reset_position();
    m_currentBullet = 0;
}

void Player::update(float elapsedTime, Vector2u winSize, FloatRect enemyPosition, Time gameTimeTotal)
{
    // move right
    if (m_RightPressed && m_Position.x < winSize.x - m_Texture.getSize().x)
        m_Position.x += m_Speed * elapsedTime;
    
    // move left
    if (m_LeftPressed && m_Position.x > 0)
        m_Position.x -= m_Speed * elapsedTime;
    
    // move up
    if (m_UpPressed && m_Position.y > 0)
        m_Position.y -= m_Speed * elapsedTime;
    
    // move down
    if (m_DownPressed && m_Position.y < winSize.y - m_Texture.getSize().y)
        m_Position.y += m_Speed * elapsedTime;
    
    // shoot
    if (m_SpacePressed)
    {
        m_Bullets[getCurrentBullet()].shoot(this->getSprite().getGlobalBounds());
        fireBullet();
        m_SpacePressed = false;
    }
    
    // update bullets
    for (int i=0; i<getClipSize(); i++)
    {
        m_Bullets[i].update(elapsedTime, winSize);
        if ((gameTimeTotal.asMilliseconds() > 100) && (m_Bullets[i].getPosition().intersects(enemyPosition)))
        {
            m_Bullets[i].stop();
            hitEnemy = true;
        }
    }
    
    // Now move the sprite to its new position
    m_Sprite.setPosition(m_Position);
}

void Player::reset()
{
    this->reset_position();
    m_currentBullet = 0;
    m_bulletsRemaining = m_clipSize - m_currentBullet;
    m_lives = 3;
    hitEnemy = false;
    beenHit = false;
    for (int i=0; i<getClipSize(); i++)
    {
        m_Bullets[i].resetPosition();
    }
}

void Player::reset_position()
{
    m_Position.x = 500;
    m_Position.y = 1300;
}
