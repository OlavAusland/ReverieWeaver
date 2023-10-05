#pragma once
#include "Window.h"
#include "Entity.h"

#define ID(x) #x

class Inspector : public Window
{
private:
	int name;
	double age;
	Entity* selected{ nullptr };
private:
	Inspector() {};
public:
	Inspector(Inspector&&) = delete;
	Inspector(const Inspector&) = delete;
	Inspector& operator=(Inspector&&) = delete;
	Inspector& operator=(const Inspector&) = delete;

	static Inspector& GetInstance();
public:
	void SetEntity(Entity*);
	void Display() override;
};