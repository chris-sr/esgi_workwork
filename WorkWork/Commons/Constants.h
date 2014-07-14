#ifndef CONSTANTS_H
#define CONSTANTS_H

    #ifdef __APPLE_CC__
        #include "ResourcePath.hpp"
    #endif

namespace ww
{
    namespace File
    {
        static const std::string CONFIG = resourcePath() + "config.txt";
    
        namespace Font
        {
            static const std::string ARIAL = resourcePath() + "arial.ttf";
            static const std::string ARIALB = resourcePath() + "arialbd.ttf";
        }

        namespace Texture
        {
            static const std::string GUI = resourcePath() + "GUI_01.png";
            static const std::string ICONS = resourcePath() + "Icons32x32.png";

            namespace WALLPAPERS
            {
                static const std::string BLUE_MOSAIQUE = resourcePath() + "Blue_Mosaique_1280x720.jpg";
                static const std::string GRAY = resourcePath() + "Gray_Wallpaper_1280x720.jpg";
                static const std::string EARTH_LANDSCAPE = resourcePath() + "Earth_Landscape_1280x720.jpg";
            }
        }
    }
}

#endif