#include "World.h"
#include "Engine.h"

#define MYENGINE UEngine::GetInstance()

using namespace std;

int main()
{
	while (MYENGINE->GetIsRunning())
	{
		MYENGINE->Render();
	}
	return 0;

}