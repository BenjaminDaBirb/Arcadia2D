#pragma once
#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class ac_engine
{
public:
	static ac_engine* GetInstance(){
		return m_instance = (m_instance != nullptr) ? m_instance : new ac_engine();
	}

	bool Init();
    bool Clean();
	void Quit();

	void Update();
	void Render();
	void Events();

	inline bool i_isRunning() { return m_isRunning; }
	inline SDL_Renderer* GetRenderer() { return m_Renderer; }
	inline SDL_Window* GetWindow() { return m_Window; }

private:
	ac_engine() {}
	bool m_isRunning;
	SDL_Renderer* m_Renderer;
	SDL_Window* m_Window;
	static ac_engine* m_instance;
};

