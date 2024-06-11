#pragma once
#include "Engine.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Actor.h"


class UWorld : public UEngine
{
public:
	UWorld();
	virtual ~UWorld();

	void SpawnActor(AActor* NewActor);
	void SettingMap();
	void RederWorld();


protected:

	std::ifstream ReadMap;
	std::ofstream WriteMap;
	std::vector<AActor*> Actors;
};

