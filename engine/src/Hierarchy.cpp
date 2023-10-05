#include "Hierarchy.h"
#include "Inspector.h"
#include <imgui.h>
#include <iostream>

Hierarchy& Hierarchy::GetInstance() {
	static Hierarchy instance;
	return instance;
}

void Hierarchy::Display()
{
	static bool setting = false;
	ImGui::Begin("Hierarchy");

	for (int i = 0; i < entities.size(); i++)
	{
		if (ImGui::Button(entities.at(i)->GetName().c_str(), {-1, 0}))
		{
			Inspector::GetInstance().SetEntity(entities.at(i));
			std::cout << entities.at(i)->GetName().c_str() << "\n";
		}

		entities.at(i)->Execute();
	}

	if (ImGui::IsMouseClicked(ImGuiMouseButton_Right)) {
		ImGui::SetWindowPos("Hierarchy Menu", { ImGui::GetMousePos()[0], ImGui::GetMousePos()[1] });
		setting = !setting;
	}

	if (setting)
	{
		ImGui::Begin("Hierarchy Menu");

		if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !ImGui::IsWindowHovered()) {
			setting = false;
		}
		
		if (ImGui::Button("Create GameObject", { -1, 20 }))
		{
			entities.push_back(new Entity("New GameObject"));
		}

		ImGui::End();
	}

	ImGui::End();
}

void Hierarchy::DeleteElement(Entity* entity)
{
	for (auto it = entities.begin(); it != entities.end(); it++) {
		if (*it == entity) {
			delete* it;
			entities.erase(it);
			return;
		}
	}
}