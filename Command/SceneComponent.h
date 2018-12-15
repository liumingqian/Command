#pragma once
#include "ActorComponent.h"
class SceneComponent :
	public ActorComponent
{
private:
	vec3 position;
public:
	SceneComponent();
	~SceneComponent();
	void SetPositionDelta(double val, glm::vec3 axis)
	{
		axis = glm::normalize(axis);
		position.x += val * axis.x;
		position.y += val * axis.y;
		position.z += val * axis.z;
	}
	vec3 GetPosition() { return position; }
};

