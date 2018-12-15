#include"stdafx.h"
#include<iostream>
#include"Command.h"
#include"GameManager.h"
#include"Timer.h"
#include"SpectatorPawn.h"
using namespace std;

int main()
{
	GameManager manager;
	SpectatorPawn pawn;

	manager.Init();

	manager.GetDefaultPlayerController()->Possess(&pawn);

	char order;
	while (cin >> order)
	{
		manager.HandleInput(order);//GameManager�п���ע�����ɽ�������ĵ�Ԫ����viwo����mfc�ַ�
		vec3 position = pawn.GetPosition();
		cout << position.x <<" "<<position.y <<" "<< position.z << endl;
	}
	return 0;
}