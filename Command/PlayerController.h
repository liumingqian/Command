#pragma once

#include"Controller.h"

#include<string>
#include<map>
#include<stack>

class PlayerController:public Controller
{
	friend class GameManager;

private:



	std::map<char, vec3>axisMapping;
	std::map<char, Command*>commandMapping;
private:
	PlayerController();

public:
	~PlayerController();
	void BindAxis(char c, vec3 axis)
	{
		if (axisMapping.find(c) != axisMapping.end())
			axisMapping.erase(c);

		axisMapping.insert(std::pair<char, vec3>(c, axis));

	}
	void BindCommand(char key, Command* command)
	{
		commandMapping.insert(std::pair<char, Command*>(key, command));
	}
	void BindKeyToAction(char c, std::string action)
	{

	}
	void BindMouseAction()
	{

	}
	void UnbindAxis(char c)
	{

	}
	CommandInfo* GenerateCommand(char c)
	{
		CommandInfo* command;
		if (controlledPawn
			&&commandMapping.find(c) != commandMapping.end()
			&&axisMapping.find(c)!=axisMapping.end())
		{
			command = new CommandInfo(commandMapping[c], GetControlledPawn(),axisMapping[c]);
		}
		else command = nullptr;
		return command;
	}

};


