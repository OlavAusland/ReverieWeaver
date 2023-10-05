#pragma once
#include "MonoBehaviour.h"
#include <string>
#include <vector>
#include "DrawPlayer.h"
#include "Transform.h"

class Entity
{
private:
	std::string name = "undefined";
	std::vector<MonoBehaviour*> scripts = { new DrawPlayer(), new Transform()};
public:
	Entity(const char* name);
	virtual std::vector<MonoBehaviour*>& GetScripts();
	virtual std::string& GetName();
	virtual void DisplayEditor();
public:
	void Execute();
};
inline std::string& Entity::GetName() { return this->name; }
inline std::vector<MonoBehaviour*>& Entity::GetScripts() { return this->scripts; }
