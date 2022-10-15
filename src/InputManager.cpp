#include "InputManager.h"
#include "ac_engine.h"

InputManager* InputManager::m_instance = nullptr;

InputManager::InputManager() {
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void InputManager::Listen()
{
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		switch (event.type) {
		   case SDL_QUIT:
			   ac_engine::GetInstance()->Quit(); break;
		   
		   case SDL_KEYDOWN: KeyDown(); break;
		   
		   case SDL_KEYUP: KeyUp(); break;
		}
	}
}

bool InputManager::GetKeyDown(SDL_Scancode key)
{
	return (m_KeyStates[key] == 1);
}

void InputManager::KeyUp()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void InputManager::KeyDown()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}
