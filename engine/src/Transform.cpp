#include "Transform.h"
#include <imgui.h>

void Transform::Update() { }

void Transform::InspectorInfo() {
	ImGui::BeginChildFrame(69420, {-1, -1});
	ImGui::InputFloat2("Position", (float*)&this->position.x);
	ImGui::InputFloat2("Scale", (float*)&this->scale.x);
	ImGui::EndChild();
}