//
//  enemy.h
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#ifndef enemy_h
#define enemy_h

#include <SFML/Graphics.hpp>
using namespace sf;

class Enemy
{
private:
    float m_xSpeed, m_ySpeed;
    Vector2f m_Position;
    
    Texture m_TextureAlive, m_TextureDead;
    Sprite m_Sprite;
    
public:
    Enemy();
    
    Sprite getSprite();
    FloatRect getPosition();
    int getySpeed();
    
    void reverse();
    void die();
    void update(bool, float, Vector2u);
    void reset();
    void reset_stop();
};

#endif /* enemy_h */
