//
//  hud.cpp
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#include "hud.h"
#include <sstream>

HUD::HUD()
{
    font.loadFromFile("/Users/nickmartin/projects/cpp/game/fonts/DS-DIGIT.ttf");
    bulletText.setFont(font);
    bulletText.setCharacterSize(200);
    bulletText.setFillColor(Color::White);
    bulletText.setPosition(0, 0);
    
    restartText.setFont(font);
    restartText.setCharacterSize(200);
    restartText.setFillColor(Color::White);
    restartText.setPosition(1000, 500);
    restartText.setString("Restart? (Y/N)");
    
    livesText.setFont(font);
    livesText.setCharacterSize(200);
    livesText.setFillColor(Color::White);
    livesText.setPosition(0, 200);
    
    reasonText.setFont(font);
    reasonText.setCharacterSize(200);
    reasonText.setFillColor(Color::White);
    reasonText.setPosition(1000, 300);
    reasonText.setString("GAME OVER");
}

Text HUD::getBulletText()
{
    return bulletText;
}

Text HUD::getRestartText()
{
    return restartText;
}

Text HUD::getLivesText()
{
    return livesText;
}

Text HUD::getReasonText()
{
    return reasonText;
}

void HUD::update(int bulletsRemaining, int lives, int reason)
{
    // update bulletText
    std::stringstream streamBullets;
    streamBullets << "Bullets: " << bulletsRemaining;
    bulletText.setString(streamBullets.str());
    
    // update livesText
    std::stringstream streamLives;
    streamLives << "Lives: " << lives;
    livesText.setString(streamLives.str());

    // update reasonText
    switch (reason)
    {
        case 0:
            reasonText.setString("Test");
            break;
        case 1:
            reasonText.setString("Enemy Destroyed!!!");
            break;
        case 2:
            reasonText.setString("Out of Lives!!!");
            break;
        case 3:
            reasonText.setString("Out of Bullets!!!");
            break;
        default:
            reasonText.setString("Default");
            break;

    }
}
