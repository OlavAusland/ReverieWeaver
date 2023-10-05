#include "Console.h"
#include <iostream>

Console::Console()
{
	std::cout.rdbuf(m_Output.rdbuf());
}

Console::~Console()
{
	std::cout.rdbuf(m_OldOutput);
}

Console& Console::GetInstance()
{
	static Console console;
	return console;
}

void Console::Display()
{
	static std::string str = "";
	str += m_Output.str();

	ImGui::Begin("Console");
	ImGui::Text(str.c_str());
	ImGui::End();

	m_Output.str("");
	m_Output.clear();
}