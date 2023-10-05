#pragma once
#include "Entity.h"
#include <vector>

class Hierarchy
{
private:
	std::vector<Entity*> entities;
private:
	Hierarchy() { entities = { new Entity("Olav"), new Entity("Fredrik") }; }
public:
	Hierarchy(Hierarchy&&) = delete;
	Hierarchy(const Hierarchy&) = delete;
	Hierarchy& operator=(Hierarchy&&) = delete;
	Hierarchy& operator=(const Hierarchy&) = delete;

	static Hierarchy& GetInstance();
public:
	void Display();
	void DeleteElement(Entity*);
};