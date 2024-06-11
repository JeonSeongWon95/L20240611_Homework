#include "World.h"
#include "Engine.h"

using namespace std;

int main()
{
	MYENGINE->LoadLevel("Map.txt");
	MYENGINE->Run();

	return 0;

}