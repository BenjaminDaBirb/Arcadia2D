#include "InputManager.h"
#include "ac_engine.h"

InputManager* InputManager::m_instance = nullptr;

InputManager::InputManager() {
	m_KeyStates = SDL_GetKeyboardState(nullptr);
	mouseState = SDL_GetMouseState(nullptr, nullptr);
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

		   case SDL_MOUSEBUTTONDOWN: MouseButtonDown(event.button); break;

		   case SDL_MOUSEBUTTONUP: MouseButtonUp(event.button); break;
		}
	}

    mouseState = SDL_GetMouseState(nullptr, nullptr);
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

void InputManager::MouseButtonDown(const SDL_MouseButtonEvent& button_press_event)
{
	m_MouseButtonStates |= SDL_BUTTON(button_press_event.button);
}

void InputManager::MouseButtonUp(const SDL_MouseButtonEvent& button_release_event)
{
	m_MouseButtonStates &= ~SDL_BUTTON(button_release_event.button);
}

bool InputManager::LMBDown()
{
    return (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
}

bool InputManager::LMBUp()
{
    return (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) == 0;
}

bool InputManager::RMBDown()
{
	
    return (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0;
}

bool InputManager::RMBUp()
{
    return (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) == 0;
}

bool InputManager::MMBDown()
{
    return (mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0;
}

bool InputManager::MMBScrollDown()
{
	SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_MOUSEWHEEL:
                if (event.wheel.y < 0 && event.button.button == SDL_BUTTON_MIDDLE) {
                    return true;
                }
                break;
        }
    }

    return false;
}

bool InputManager::MMBScrollUp()
{
	SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_MOUSEWHEEL:
                if (event.wheel.y > 0 && event.button.button == SDL_BUTTON_MIDDLE) {
                    return true;
                }
                break;
        }
    }

    return false;
}

bool InputManager::MMBUp()
{
	return (mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE)) == 0;
}