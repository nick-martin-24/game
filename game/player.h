//
//  player.h
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#ifndef player_h
#define player_h

#include <SFML/Graphics.hpp>
#include "bullet.h"
using namespace sf;

class Player
{
private:
    float m_Speed;
    Vector2f m_Position;
    
    Texture m_Texture;
    Sprite m_Sprite;
    
    int m_clipSize, m_currentBullet, m_bulletsRemaining, m_lives;
    Bullet m_Bullets[10];
    
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_SpacePressed;
    bool hitEnemy;
    bool beenHit;
    
public:
    Player();
    
    Sprite getSprite();
    Vector2f getPosition();
    Bullet getBullet(int);
    int getCurrentBullet();
    int getClipSize();
    int getLives();
    int getBulletsRemaining();
    int getSpeed();
    
    void fireBullet();
    void decrementLives();
    
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void shoot();
    
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    void stopShoot();
    
    bool hasHitEnemy();
    bool hasBeenHit();
    bool anyBulletInFlight();
    
    void hit();
    void update(float, Vector2u, FloatRect, Time);
    void reset();
    void reset_position();
};

#endif /* player_h */
