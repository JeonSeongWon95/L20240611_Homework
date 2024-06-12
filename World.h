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



protected:
	vector<AActor*> Actors;

	
};

