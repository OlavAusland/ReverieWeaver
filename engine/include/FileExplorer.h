#include "Window.h"

class FileExplorer : public Window
{
private:
	const char* workingDirectory = "C:\\dev\\test";
private:
	FileExplorer();
public:
	FileExplorer(FileExplorer&&) = delete;
	FileExplorer(const FileExplorer&) = delete;
	FileExplorer& operator=(FileExplorer&&) = delete;
	FileExplorer& operator=(const FileExplorer&) = delete;

	static FileExplorer& GetInstance();
	void Display() override;
};