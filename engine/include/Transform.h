#pragma once
#include "MonoBehaviour.h"
#include "Vec2D.h"

class Transform : public MonoBehaviour
{
public:
	Vec2D position;
	Vec2D scale;
public:
	void Update();
	void InspectorInfo();
};