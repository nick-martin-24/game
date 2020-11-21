//
//  bullet.h
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#ifndef bullet_h
#define bullet_h

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet
{
private:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;
    bool m_InFlight;
    float m_Speed;
    
public:
    Bullet();
    
    Sprite getSprite();
    FloatRect getPosition();
    int getSpeed();
    
    bool isInFlight();
    void resetPosition();
    void stop();
    void shoot(FloatRect);
    void update(float elapsedTime, Vector2u winSize);
};

#endif /* bullet_h */
