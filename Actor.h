#pragma once
#include "SDL.h"

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
	inline int GetHP() const { return HP; }
	inline SDL_Rect GetRect() const { return MyRect; }
	inline Teamname GetTeam() const { return Team; }
	virtual void Tick();
	virtual void Render();
	void SetHP(int NewHP);
	void SetTeam(Teamname NewTeam);
	void SetX(int NewX);
	void SetY(int NewY);
	bool Predict(int NewX, int NewY);
	inline bool GetIsCollision() { return IsCollision; }
	




protected:

	int Layer;
	int X;
	int Y;
	int HP;
	int SpriteSize;
	bool IsCollision;
	Teamname Team;
	SDL_Surface* MySurface;
	SDL_Texture* MyTexture;
	SDL_Rect MyRect;

};

