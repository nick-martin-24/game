//
//  engine.h
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#ifndef engine_h
#define engine_h

#include <SFML/Graphics.hpp>
#include "player.h"
#include "enemy.h"
#include "hud.h"

using namespace sf;
class Engine
{
private:
    //A regular RenderWindow
    RenderWindow m_Window;
    int reason;
    
    // Declare a sprite and a texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture1, m_BackgroundTexture2;
    
    // An instance of Bob
    Enemy m_Enemy;
    Player m_Player;
    HUD m_HUD;
    
    enum class State {PLAYING, GAME_OVER};
    State m_state;
    
    void input();
    void update(float dtAsSeconds);
    void draw();
    void playerHit();
    void reset();
    
public:
    Engine();
    void start();
    Time gameTimeTotal, lastPressed;
};
#endif /* engine_h */
