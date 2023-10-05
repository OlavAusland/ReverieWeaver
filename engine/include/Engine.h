class Engine
{
private:
	Engine();
public:
	Engine(Engine&&) = delete;
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
	Engine& operator=(const Engine&&) = delete;

	static Engine* GetInstance() {
		static Engine engine;
		return engine;
	}
};