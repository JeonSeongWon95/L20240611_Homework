#pragma once

enum class Teamname 
{
	NONE = -1,
	REDTEAM = 0,
	GREENTEAM,
	BLUETEAM,
	ENEMY,
	MAX
};

class AActor
{
public:
	
	AActor();
	virtual ~AActor();
	
	inline int GetLayer() const { return Layer; }
	inline int GetX() const { return X; }
	inline int GetY() const { return Y; }
	inline char GetShape() const { return Shape; }
	inline int GetHP() const { return HP; }
	inline Teamname GetTeam() const { return Team; }
	virtual void Tick();
	void Render();
	void SetHP(int NewHP);
	void SetTeam(Teamname NewTeam);
	void SetX(int NewX);
	void SetY(int NewY);
	void SetShape(char NewShape);
	




protected:
	int Layer;
	int X;
	int Y;
	int HP;
	Teamname Team;
	char Shape;
	
};

