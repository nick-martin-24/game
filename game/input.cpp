//
//  input.cpp
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#include "engine.h"

void Engine::input()
{
    // Handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape))
        m_Window.close();
    
    if (m_state == State::GAME_OVER)
        {
        if (Keyboard::isKeyPressed(Keyboard::Y))
            reset();
        else if (Keyboard::isKeyPressed(Keyboard::N))
            m_Window.close();
    }
    
    // Handle the player moveing
    if (Keyboard::isKeyPressed(Keyboard::Left))
        m_Player.moveLeft();
    else
        m_Player.stopLeft();
    
    if (Keyboard::isKeyPressed(Keyboard::Right))
        m_Player.moveRight();
    else
        m_Player.stopRight();
    
    if (Keyboard::isKeyPressed(Keyboard::Up))
        m_Player.moveUp();
    else
        m_Player.stopUp();
    
    if (Keyboard::isKeyPressed(Keyboard::Down))
        m_Player.moveDown();
    else
        m_Player.stopDown();
    
    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        if ((gameTimeTotal.asMilliseconds() - lastPressed.asMilliseconds() > 500) && (m_Player.getCurrentBullet() < m_Player.getClipSize()))
        {
            m_Player.shoot();
            lastPressed = gameTimeTotal;
        }
    }
    else
        m_Player.stopShoot();
}
