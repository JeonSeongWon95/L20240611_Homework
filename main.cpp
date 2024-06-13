#include "World.h"
#include "SDL.h"
#include "Engine.h"

int SDL_main(int argc, char* argv[])
{
	MYENGINE->LoadLevel("Map.txt");
	MYENGINE->Run();

	return 0;

}

