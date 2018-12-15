#pragma once
#include"SceneComponent.h"
#include<glm/glm.hpp>
 

class Pawn;

class Command
{
public:

protected:

protected:
	Command();
	virtual ~Command() {}
public:
	virtual void Execute(Pawn* target, glm::vec3 value = vec3(0), float rate = 1, bool bIsUndo = false) {}
};

class CommandInfo 
{
private:
	Command* command;
	Pawn* target;
	vec3 value;
	float rate;
public:
	CommandInfo(){
		command = nullptr;
		target = nullptr;
	}

	CommandInfo(Command*c,Pawn* t,vec3 v=vec3(),float r=1)
	{
		command = c;
		target = t;
		value = v;
		rate = r;
	}
	void Execute()
	{
		command->Execute(target, value, rate);
	}
	void Undo()
	{
		command->Execute(target, value, rate,true);
	}
};
class SetTransformCommand :public Command
{
public:
	SetTransformCommand() {
	};
	~SetTransformCommand() {};
private:
	void Execute(Pawn* target,vec3 value,float MoveRate,bool bIsUndo);
};

class UndoCommand :public Command
{
public:
	void Execute(CommandInfo* commandInfo)
	{
		commandInfo->Undo();
	}
};

class RevertCommand :public Command
{
public:
	void Execute(CommandInfo* commandInfo)
	{
		commandInfo->Execute();
	}
};