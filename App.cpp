
#include "App.h"

// The constructor (default)
App::App()
{
	isRunning = true;
	pWindow = NULL;
	pRenderer = NULL;
}

bool App::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}
	
	pWindow = SDL_CreateWindow("qbRayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	
	if (pWindow != NULL)
	{
		// Initialise the renderer.
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
		
		// Initialise the qbImage instance.
		m_image.Initialize(1280, 720, pRenderer);
		
		RT::Camera testCamera;
		testCamera.SetPosition(qbVector<double>(std::vector<double>{0.0, 0.0, 0.0}));
		testCamera.SetLookAt(qbVector<double>(std::vector<double>{0.0, 2.0, 0.0}));
		testCamera.SetUp(qbVector<double>(std::vector<double>{0.0, 0.0, 1.0}));
		testCamera.SetLength(1.0);
		testCamera.SetHorzSize(1.0);
		testCamera.SetAspect(1.0);
		testCamera.UpdateCameraGeometry();
		
		// Get the screen centre and U,V vectors and display.
		auto screenCentre = testCamera.GetScreenCentre();
		auto screenU = testCamera.GetU();
		auto screenV = testCamera.GetV();
		
		// And display to the terminal.
		std::cout << "Camera screen centre:" << std::endl;
		PrintVector(screenCentre);
		std::cout << "\nCamera U vector:" << std::endl;
		PrintVector(screenU);
		std::cout << "\nCamera V vector:" << std::endl;
		PrintVector(screenV);
	}
	else
	{
		return false;
	}
	
	return true;
}

int App::OnExecute()
{
	SDL_Event event;
	
	if (OnInit() == false)
	{
		return -1;
	}
	
	while (isRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			OnEvent(&event);
		}
		
		OnLoop();
		OnRender();
	}
	
	OnExit();
	return 0;
}

void App::OnEvent(SDL_Event *event)
{
	if (event->type == SDL_QUIT)
	{
		isRunning = false;
	}
}

void App::OnLoop()
{

}

void App::OnRender()
{
	// Set the background colour to white.
	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(pRenderer);

	//Render the Scene
	m_scene.Render(m_image);
	
	// Display the image.
	m_image.Display();
	
	// Show the result.
	SDL_RenderPresent(pRenderer);
}

void App::OnExit()
{
	// Tidy up SDL2 stuff.
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = NULL;
	SDL_Quit();
}

void App::PrintVector(const qbVector<double> &inputVector)
{
	int nRows = inputVector.GetNumDims();
	for (int row = 0; row<nRows; ++row)
  {
  std::cout << std::fixed << std::setprecision(3) << inputVector.GetElement(row) << std::endl;
	} 	
}
