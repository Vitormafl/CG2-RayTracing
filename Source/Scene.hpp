#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SDL2/SDL.h>
#include "Image.hpp"
#include "camera.hpp"
#include "Sphere.hpp"

namespace RT
{
    class Scene
    {
        public:
            //construtor padrão.
            Scene();

            //Função que realiza o render.
            bool Render (Image &outputImage);

        private:
        
        private:
            //Camera a ser utilizada
            RT::Camera m_camera;

            //Esfera na origem, apenas para teste.
            RT::Sphere m_testSphere;
    };
}
#endif