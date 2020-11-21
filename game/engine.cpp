//
//  engine.cpp
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#include "engine.h"
using namespace sf;

// Public Functions
//Default Constructor
Engine::Engine()
{
    // Get the screen resolution and create an SFML window and View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y), "Game", Style::Fullscreen);
    
    //Load the background into the texture
    m_BackgroundTexture1.loadFromFile("/Users/nickmartin/projects/cpp/game/images/manarola.jpg");
    
    // Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture1);
    reason = 0;
}

void Engine::start()
{
    //Timing
    Clock clock;
    
    while (m_Window.isOpen())
    {
        Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                // Someone closed the window - bye
                m_Window.close();
        }
        
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();
        
        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();
        gameTimeTotal += dt;
        
        // external cpp files
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::playerHit()
{
    m_Enemy.reset();
    m_Player.hit();
}

void Engine::reset()
{
    m_Player.reset();
    m_Enemy.reset();
    m_state = State::PLAYING;
    reason = 0;
}
