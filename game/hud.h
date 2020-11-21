//
//  hud.h
//  game
//
//  Created by Nick Martin on 11/21/20.
//

#ifndef hud_h
#define hud_h

#include <SFML/Graphics.hpp>
using namespace sf;

class HUD
{
private:
    Font font;
    Text bulletText, restartText, livesText, reasonText;
    
public:
    HUD();
    
    Text getBulletText();
    Text getRestartText();
    Text getLivesText();
    Text getReasonText();
    void update(int, int, int);
};

#endif /* hud_h */
