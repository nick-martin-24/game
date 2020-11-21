//
//  update.cpp
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#include "engine.h"

void Engine::update(float dtAsSeconds)
{
    m_Player.update(dtAsSeconds, m_Window.getSize(), m_Enemy.getPosition(), gameTimeTotal);
    if (m_Player.hasHitEnemy())
    {
        reason = 1;
        m_state = State::GAME_OVER;
    }
    
    if (m_Player.getLives() == 0)
    {
        reason = 2;
        m_state = State::GAME_OVER;
        m_Enemy.reset_stop();
        m_Player.reset_position();
    }
    
    if (m_Player.getBulletsRemaining() == 0 && !m_Player.anyBulletInFlight())
    {
        reason = 3;
        m_state = State::GAME_OVER;
        m_Enemy.reset_stop();
        m_Player.reset_position();
    }
    
    m_Enemy.update(m_Player.hasHitEnemy(), dtAsSeconds, m_Window.getSize());

    if ((gameTimeTotal.asMilliseconds() > 100) && (m_Player.getSprite().getGlobalBounds().intersects(m_Enemy.getPosition())))
        playerHit();
    
    m_HUD.update(m_Player.getBulletsRemaining(), m_Player.getLives(), reason);
}
