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
	void SettingMap();
	void RederWorld();


protected:
	vector<AActor*> Actors;

	
};

