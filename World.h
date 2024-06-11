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

	inline char GetKey() const { return Key; }

	void SpawnActor(AActor* NewActor);
	void SettingMap(std::string Filename);
	void RederWorld();
	void TickWorld();
	void Input();
	void sort();



protected:
	vector<AActor*> Actors;
	char Key;

	
};

