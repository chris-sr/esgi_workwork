#include <windows.h>
#include "application.h"
#include "../factory/types.h"
#include "../factory/factory.h"
#include "boost/timer.hpp"

#ifdef WW_DEBUG
    #define WW_RENDER_GLDLL "RenderSystem_GL_d.dll"
#else
    #define WW_RENDER_GLDLL "RenderSystem_GL.dll"
#endif

#define WW_FRAME_RATE 20

Application::Application(){
    _root = NULL;
    _renderSystem = NULL;
    _renderWindow = NULL;
}

Application::~Application(){

}

void
Application::run(){
    try{
        wwlog("Initializing renderer\n");
        Ogre::LogManager* logmanager = new Ogre::LogManager();
        logmanager->createLog("workwork.log",true,false,false);
        _root = new Ogre::Root("","","");
        _root->loadPlugin(WW_RENDER_GLDLL);
        _renderSystem = _root->getRenderSystemByName("OpenGL Rendering Subsystem");
        if(_renderSystem == NULL){
            wwlog_emergency("Error: Couldn't load the OpenGL dll\n");
            exit(1);
        }
        _root->setRenderSystem(_renderSystem);
        _renderSystem->setConfigOption("Full Screen", "No");
        _renderSystem->setConfigOption("Video Mode", "500 x 500 @ 32-bit colour");
        _renderWindow = _root->initialise(true,"Ogre Testing");

        wwlog("Creating factory\n");
        ww::Factory factory;

        wwlog("Starting to render at "<< WW_FRAME_RATE <<"fps\n");
        boost::timer timer;

        while(!_renderWindow->isClosed()){
            //Measure the time (ms) elapsed since last frame
            double elapsed = timer.elapsed()*1000;
            timer.restart();
            wwlog("Elapsed: " << elapsed << "\n");

            //If necessary, wait if we are rendering too fast
            double excedent = WW_FRAME_RATE - elapsed;
            if(excedent > 0){
                wwlog("Will sleep for " << excedent << "\n");
                Sleep(excedent);
            }

            //Capture the inputs and send them to the input manager

            //Update the factory according to that time
            factory.update(elapsed);

            //Render a frame
            _root->renderOneFrame();
            Ogre::WindowEventUtilities::messagePump();
        }

    } catch (Ogre::Exception& e){
        wwlog_emergency("Ogre Renderer threw an exception:\n"<<e.getFullDescription());
    }
}


