#include "World.h"
#include <fstream>
#include <iostream>
#include "SDL.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"

UWorld::UWorld()
{
	
	WriteMap.open("Map.txt");

	for (int Line = 0; Line < 10; ++Line)
	{
		for (int Count = 0; Count < 10; ++Count)
		{
			if(Line == 1 && Count == 1)
			{
				WriteMap << 'P';
			}
			else if (Line == 8 && Count == 8)
			{
				WriteMap << 'G';
			}
			else if (Line == 5 && Count == 5)
			{
				WriteMap << 'M';
			}
			else if (Line == 0 || Line == 9)
			{
				WriteMap << '*';
			}
			else if (Count == 0 || Count == 9)
			{
				WriteMap << '*';
			}
			else
			{
				WriteMap << ' ';
			}
		}
	}

	WriteMap.close();
}

UWorld::~UWorld()
{
	for(auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void UWorld::SettingMap()
{
	ReadMap.open("Map.txt");

	char SpawnPosition = '0';

	for (int Line = 0; Line < 10; ++Line)
	{
		for (int Count = 0; Count < 10; ++Count)
		{
			ReadMap.get(SpawnPosition);

			if(SpawnPosition == 'P')
			{
				SpawnActor(new APlayer);
			}
			else if(SpawnPosition == 'M')
			{ 
				SpawnActor(new AMonster);
			}
			else if (SpawnPosition == 'M')
			{
				SpawnActor(new AGoal);
			}
			else if (SpawnPosition == '*')
			{
				SpawnActor(new AWall);
			}
			else if (SpawnPosition == ' ')
			{
				SpawnActor(new AFloor);
			}
		}
	}

	ReadMap.close();

}

void UWorld::RederWorld()
{
	for(auto Actor : Actors)
	{
		std::cout << Actor->GetShape();
	}
}
