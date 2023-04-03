#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include "./Source/Image.hpp"
#include "./Source/Scene.hpp"
#include "./Source/camera.hpp"

class App
{
  public:
    App();
    
    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event *event);
    void OnLoop();
    void OnRender();
    void OnExit();

  private:
    void PrintVector(const qbVector<double> &inputVector);

  private:
    Image m_image;

    RT::Scene m_scene;

    bool isRunning;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;

};

#endif