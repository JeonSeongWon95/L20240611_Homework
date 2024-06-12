#include "World.h"
#include "Engine.h"

int main()
{

	MYENGINE->LoadLevel("Map.txt");
	MYENGINE->Run();

	return 0;

}

