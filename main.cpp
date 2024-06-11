#include "World.h"
#include "Engine.h"

using namespace std;

int main()
{
	while (MYENGINE->GetIsRunning())
	{
		MYENGINE->Render();
	}
	return 0;

}