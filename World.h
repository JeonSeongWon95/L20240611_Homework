#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "Actor.h"

using namespace std;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void SpawnActor(AActor* NewActor);
	void SettingMap(std::string Filename);
	void RederWorld();
	void TickWorld();
	void sort();
	inline vector<AActor*> GetActors() { return Actors; }



protected:
	vector<AActor*> Actors;

	
};

