#include "FileExplorer.h"
#include <filesystem>

namespace fs = std::filesystem;

FileExplorer::FileExplorer() {

}

FileExplorer& FileExplorer::GetInstance() {
	static FileExplorer instance;
	return instance;
}


void FileExplorer::Display() {
	static bool setting;
	ImGui::Begin("File Explorer");

	for (const auto& entry : fs::directory_iterator(workingDirectory))
		ImGui::Text(entry.path().generic_string().c_str());

	ImGui::End();
}