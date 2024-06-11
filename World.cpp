#include "World.h"
#include <fstream>
#include <iostream>
#include "SDL.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"

UWorld::~UWorld()
{
	Map.open("Map.txt", std::ios::in);

	for(int Line = 0; Line < 10; ++Line )
	{
		for(int Count = 0; Count < 10; ++Count)
		{
			if (Line == 0 || Line == 9)
			{
				SpwanActor(new AWall);
			}
			else if(Count == 0 || Count == 9)
			{
				SpwanActor(new AWall);
			}
			else if (Count ==  || Count == 9)
			{

			}
			else if (Count == 0 || Count == 9)
			{
			}
			else if (Count == 0 || Count == 9)
			{
			}
		}
	}
}

void UWorld::SpwanActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}
