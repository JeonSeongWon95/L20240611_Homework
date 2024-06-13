#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster();
	AMonster(int NewX, int NewY, Teamname NewTeam = Teamname::ENEMY, int NewHP = 50);
	virtual ~AMonster();

	virtual void Tick() override;
};

