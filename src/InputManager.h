#include <SDL.h>

struct Key {
	SDL_KeyboardEvent event;
};

#pragma once
class InputManager
{
public:
	static InputManager* GetInstance() { return m_instance = (m_instance != nullptr) ? m_instance : new InputManager(); }
	void Listen();
	bool GetKeyDown(SDL_Scancode key);



private:
	InputManager();
	void KeyUp();
	void KeyDown();
	const Uint8* m_KeyStates;
	static InputManager* m_instance;
};

