#ifndef APPLICATION_H
#define APPLICATION_H

#include "../factory/factory.h"
#include "Ogre.h"

class Application{
public:
                    Application();
                    ~Application();
    void            run();

private:
    Ogre::Root*     _root;

    Ogre::RenderSystem*
            _renderSystem;

    Ogre::RenderWindow*
            _renderWindow;
};

#endif // APPLICATION_H
