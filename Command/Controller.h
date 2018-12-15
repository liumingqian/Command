#pragma once
#include"Pawn.h"
#include"SceneComponent.h"
#include"Command.h"

class Controller
{
protected:
	Pawn * controlledPawn;
public:
	Controller();
	~Controller();
	void Possess(Pawn* pawn)
	{
		controlledPawn = pawn;
		pawn->SetController(this);
	}
	void UnPossess()
	{
		controlledPawn->SetController(nullptr);
		controlledPawn = nullptr;
	}
	void ExecuteCommand(CommandInfo* command)
	{
		command->Execute();
	}

	Pawn* GetControlledPawn()
	{
		return controlledPawn;
	}
};

