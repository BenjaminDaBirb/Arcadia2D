#ifndef AC_ENGINE_H
#define AC_ENGINE_H

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class ac_engine
{
public:
	static ac_engine* GetInstance(){
		if (m_instance == nullptr) {
        m_instance = new ac_engine();
       }
       return m_instance;
	}

	virtual bool Init();
    virtual bool Clean();
	virtual void Quit();

	virtual void Update();
    virtual void Render();
	virtual void Renderer_Draw(std::string id, int x, int y, int width, int height);
	virtual void Events();

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

#endif // AC_ENGINE_H


