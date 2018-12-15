#pragma once
class Timer
{
private:
	static Timer * Singleton;
	Timer();

public:
	~Timer();

	static Timer* GetInstance() {
		if (!Singleton)
		{
			Singleton = new Timer();
		}

		return Singleton;
	}
};

