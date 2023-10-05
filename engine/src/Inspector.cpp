#include "Inspector.h"
#include "Hierarchy.h"
#include <typeinfo>
#include <string.h>

Inspector& Inspector::GetInstance() {
	static Inspector instance;
	return instance;
}

void Inspector::Display()
{
	ImGui::Begin("Inspector");
	if (!selected) { ImGui::Text("Nothing Selected!"); ImGui::End(); return; }
	ImGui::InputText("##", (char*)selected->GetName().c_str(), selected->GetName().capacity());

	for (int i = 0; i < selected->GetScripts().size(); i++)
	{
		std::string name = typeid(*selected->GetScripts()[i]).name();
		ImGui::BeginChildFrame(100 + i, { -1, 100 });
		ImGui::Text(name.substr(name.find(' ') + 1).c_str());
		
		selected->GetScripts()[i]->InspectorInfo();

		ImGui::EndChildFrame();
	}

	ImGui::Button("Add Module", {-1, 0});
	if (ImGui::Button("Delete", { -1, 0 })) {
		Hierarchy::GetInstance().DeleteElement(selected);
		selected = nullptr;
	}
		
	ImGui::End();
}

void Inspector::SetEntity(Entity* entity) {
	selected = entity;
}