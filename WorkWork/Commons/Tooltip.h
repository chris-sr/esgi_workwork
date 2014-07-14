//
//  Tooltip.h
//  WorkWork
//
//  Created by Christophe Sin Ronia on 29/04/2014.
//  Copyright (c) 2014 Christophe Sin Ronia. All rights reserved.
//

#ifndef __WorkWork__Tooltip__
#define __WorkWork__Tooltip__

#include <SFML/Graphics.hpp>

#include "Entity.h"

namespace ww
{
    class Tooltip : public Entity
    {
    private:
        bool _visible;
        sf::RectangleShape _rect;
        sf::Text _text;
        
    protected:
        
    public:
        Tooltip();
        ~Tooltip();
        
        void draw(sf::RenderWindow & window);
        
        void centerText();
        
        bool isVisible();
        void setVisible(bool visible);
        
        sf::RectangleShape & getRect();
        sf::Text & getText();
    };
}

#endif /* defined(__WorkWork__Tooltip__) */
