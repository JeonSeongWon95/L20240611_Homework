#pragma once
#include "Actor.h"
class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY,Teamname NewTeam = Teamname::REDTEAM, int NewHP = 100);
	virtual ~APlayer();
	virtual void Tick() override;
};

