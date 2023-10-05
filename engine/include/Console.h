#pragma once
#include "Window.h"
#include <sstream>
#include <ostream>
#include <iostream>
#include <vector>

class Console : public Window
{
private:
	std::vector<const char*> message_list;

	std::streambuf* m_OldOutput = std::cout.rdbuf();
	std::ostringstream m_Output;
private:
	Console();
	~Console();
public:
	Console(Console&&) = delete;
	Console(const Console&) = delete;
	Console& operator=(Console&&) = delete;
	Console& operator=(const Console&) = delete;

	static Console& GetInstance();

	void Display();
};