#include "stdafx.h"
#include"Command.h"
#include"Pawn.h"

Command::Command()
{
}

void SetTransformCommand::Execute(Pawn* target,vec3 value,float moveRate,bool bIsUndo)
{
	assert(target);
	if (bIsUndo)
		moveRate = 0 - moveRate;
	target->GetSceneComponent()->SetPositionDelta(moveRate, value);
}