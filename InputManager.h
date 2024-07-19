#include <SDL2/SDL.h>

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

	//Mouse Events
	virtual bool LMBDown();
	virtual bool LMBUp();
	virtual bool RMBDown();
	virtual bool RMBUp();
	virtual bool MMBDown();
	virtual bool MMBScrollUp();
	virtual bool MMBScrollDown();
	virtual bool MMBUp();

private:
	InputManager();
	void KeyUp();
	void KeyDown();
	const Uint8* m_KeyStates;
    Uint32 mouseState;
	static InputManager* m_instance;

	Uint32 m_MouseButtonStates;

	void MouseButtonDown(const SDL_MouseButtonEvent& button_press_event);
    void MouseButtonUp(const SDL_MouseButtonEvent& button_release_event);
};

