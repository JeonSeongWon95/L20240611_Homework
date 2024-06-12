#include "World.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include "SDL.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"


UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void UWorld::SettingMap(std::string Filename)
{
	std::ifstream ReadMap;
	ReadMap.open(Filename);

	char SpawnPosition[256];

	int Line = 0;

	while(ReadMap.getline(SpawnPosition, 80))
	{
		for (int Count = 0; Count < strlen(SpawnPosition); ++Count)
		{
			if (SpawnPosition[Count] == 'P')
			{
				SpawnActor(new APlayer(Count, Line));
				SpawnActor(new AFloor(Count, Line));
			}
			else if (SpawnPosition[Count] == 'M')
			{
				SpawnActor(new AMonster(Count, Line));
				SpawnActor(new AFloor(Count, Line));
			}
			else if (SpawnPosition[Count] == 'G')
			{
				SpawnActor(new AGoal(Count, Line));
				SpawnActor(new AFloor(Count, Line));
			}
			else if (SpawnPosition[Count] == '*')
			{
				SpawnActor(new AWall(Count, Line));
				SpawnActor(new AFloor(Count, Line));
			}
			else if(SpawnPosition[Count] == ' ')
			{
				SpawnActor(new AFloor(Count, Line));
			}
		}

		Line++;
	}

	sort();

	ReadMap.close();

}

void UWorld::RederWorld()
{

	for(auto Actor : Actors)
	{
		Actor->Render();
	}

}

void UWorld::TickWorld()
{
	for(auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::sort()
{
	AActor* Temp;

	for(int i  = 0; i < Actors.size(); ++i)
	{
		for(int j = i + 1; j < Actors.size(); ++j)
		{
			if(Actors[i]->GetLayer() < Actors[j]->GetLayer())
			{
				Temp = Actors[j];
				Actors[j] = Actors[i];
				Actors[i] = Temp;
			}
		}
	}
}
