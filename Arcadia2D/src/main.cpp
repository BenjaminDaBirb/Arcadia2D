#include "ac_engine.h"

int main(int argc, char** argv)
{
	auto engine = ac_engine::GetInstance();
	engine->Init();

	while (engine->i_isRunning()) {
		engine->Events();
		engine->Update();
		engine->Render();
	}

	engine->Clean();
	return 0;
}