#pragma once
#include"PlayerController.h"
#include<list>

using namespace std;

class GameManager
{
private:

	SetTransformCommand * transformCommand;
	UndoCommand* undoCommand;
	RevertCommand* revertCommand;

	PlayerController* defaultPlayerController;
	PlayerController* currentController;
	int queueCapacity = 15;
	std::list<CommandInfo>history;
	
	std::list<CommandInfo>::reverse_iterator currentHistory;
public:
	GameManager()
	{
		defaultPlayerController = new PlayerController();//Unreal中是根据反射机制得到的默认PlayerController类
		currentController = nullptr;
		
		currentHistory = history.rbegin();

		transformCommand = new SetTransformCommand();
		undoCommand = new UndoCommand();
	}
	~GameManager() {};

	void Init()
	{
		currentController = defaultPlayerController;

		BindCommand('w', transformCommand);
		BindCommand('W', transformCommand);
		BindCommand('s', transformCommand);
		BindCommand('S', transformCommand);
		BindCommand('a', transformCommand);
		BindCommand('A', transformCommand);
		BindCommand('d', transformCommand);
		BindCommand('D', transformCommand);
		BindAxis('w', vec3(0, 1, 0));
		BindAxis('d', vec3(1, 0, 0));
		BindAxis('s', vec3(0, -1, 0));
		BindAxis('a', vec3(-1, 0, 0));
		BindAxis('W', vec3(0, 1, 0));
		BindAxis('D', vec3(1, 0, 0));
		BindAxis('S', vec3(0, -1, 0));
		BindAxis('A', vec3(-1, 0, 0));

		BindCommand('z', undoCommand);
		BindCommand('Z', undoCommand);
		BindCommand('x', revertCommand);
		BindCommand('X', revertCommand);
	}
	void BindAxis(char key,vec3 axis)
	{
		currentController->BindAxis(key, axis);
	}
	void BindCommand(char key, Command* command)
	{
		currentController->BindCommand(key, command);
	}
	void HandleInput(char c)
	{
		if ((c == 'z' || c == 'Z'))
		{
			if (currentHistory != history.rend())
			{
				currentHistory->Undo();
				currentHistory++;

			}
		}
		else if ((c == 'x' || c == 'X'))
		{
			if (currentHistory != history.rbegin())
			{		
				currentHistory--;
				currentHistory->Execute();
			}
		}
		else {
			CommandInfo* newCommandInfo = nullptr;
			newCommandInfo = currentController->GenerateCommand(c);
			if (!newCommandInfo)
				return;
			if (history.size() == queueCapacity)
				history.pop_front();
			for (auto i = currentHistory.base(); i != history.end(); )
			{
				i = history.erase(i);
			}
			history.push_back(*newCommandInfo);
			currentHistory=history.rbegin();

			newCommandInfo->Execute();

		}
		

	}
	PlayerController* GetDefaultPlayerController()
	{
		return defaultPlayerController;
	}
};

