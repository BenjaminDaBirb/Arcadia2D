#include "ac_engine.h"
#include <chrono>
#include <thread>

int main(int argc, char** argv)
{
	auto engine = ac_engine::GetInstance();
	engine->Init();

	while (engine->i_isRunning()) {
		engine->Events();
		engine->Update();
		engine->Render();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	
	engine->Clean();
	return 0;
}