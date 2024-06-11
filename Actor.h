#pragma once
#include "Engine.h"

enum class Teamname 
{
	NONE = -1,
	REDTEAM = 0,
	GREENTEAM,
	BLUETEAM,
	MAX
};

class AActor : public UEngine
{
public:
	
	AActor();
	virtual ~AActor();
	
	inline int GetX() { return X; }
	inline int GetY() { return Y; }
	inline char GetShape() { return Shape; }
	inline int GetHP() { return HP; }
	inline Teamname GetTeam() { return Team; }
	void SetHP(int NewHP);
	void SetTeam(Teamname NewTeam);
	void SetX(int NewX);
	void SetY(int NewY);
	void SetShape(char NewShape);




protected:
	int X;
	int Y;
	int HP;
	Teamname Team;
	char Shape;
	
};

