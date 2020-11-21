//
//  draw.cpp
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#include "engine.h"

void Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(Color::White);
    
    // Draw the background, player, and enemy
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_Player.getSprite());
    m_Window.draw(m_Enemy.getSprite());
    
    // Draw bullets
    for (int i=0; i<m_Player.getClipSize(); i++)
    {
        if (m_Player.getBullet(i).isInFlight())
            m_Window.draw(m_Player.getBullet(i).getSprite());
    }
    
    // draw text
    m_Window.draw(m_HUD.getBulletText());
    m_Window.draw(m_HUD.getLivesText());
    
    if (m_state == State::GAME_OVER)
    {
        m_Window.draw(m_HUD.getReasonText());
        m_Window.draw(m_HUD.getRestartText());
    }
    
    // Show everything we have just drawn
    m_Window.display();
}
