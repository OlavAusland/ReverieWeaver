#include "Entity.h"
#include "MonoBehaviour.h"
#include <imgui.h>

Entity::Entity(const char* _name) : name(_name) 
{
	name.reserve(100);
}
void Entity::DisplayEditor()
{
	ImGui::Begin("Editor");
	ImGui::InputText("Name:", &name[0], 10);
	ImGui::End();
}

void Entity::Execute() 
{
	for (auto script : scripts)
	{
		script->Update();
	}
}