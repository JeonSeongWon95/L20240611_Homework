#include "World.h"
#include "SDL.h"
#include "Engine.h"

int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{
		std::cout << "Init Fail" << endl;
	}
	else
	{
		std::cout << "Init Success" << endl;
	}

	SDL_Window* MyWindow;
	MyWindow = SDL_CreateWindow("My Game", 10, 10, 640, 480, SDL_WINDOW_OPENGL);


	SDL_Renderer* MYRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	MYENGINE->LoadLevel("Map.txt");
	MYENGINE->Run();

	return 0;

}

