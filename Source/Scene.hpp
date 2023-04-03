#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SDL2/SDL.h>
#include "Image.hpp"

namespace RT
{
    class Scene
    {
        public:
            Scene();

            bool Render (Image &outputImage);

        private:
        
    };
}
#endif