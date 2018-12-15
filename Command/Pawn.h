#pragma once
#include"SceneComponent.h"

class Controller;

class Pawn
{
protected:
	SceneComponent* sceneComponent;
	Controller* playerController;
public:
	Pawn()
	{
		sceneComponent = new SceneComponent;
		playerController = nullptr;
	}
	~Pawn() {};

	SceneComponent*GetSceneComponent()
	{
		return sceneComponent;
	}
	vec3 GetPosition()
	{
		return sceneComponent->GetPosition();
	}
	void SetController(Controller* pc)
	{
		playerController = pc;
	}
	Controller* GetController()
	{
		return playerController;
	}
};

