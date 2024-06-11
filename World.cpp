#include "World.h"
#include "SDL.h"

UWorld::~UWorld()
{

	for (int i = 0; i < 10; ++i)
	{
		SDL_Log("%s", Map);
	}
}
