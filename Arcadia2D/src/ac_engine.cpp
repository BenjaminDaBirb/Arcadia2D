#include "ac_engine.h"
#include <iostream>
#include "TextureManager.h"
#include "InputManager.h"
#include "Actor.h"


ac_engine* ac_engine::m_instance = nullptr;

bool ac_engine::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	m_Window = SDL_CreateWindow("Arcadia 2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!m_Window) {
		SDL_Log("Could Not Initialize the SDL Window, Error: ", SDL_GetError() );
	}
	else {
		SDL_Log("SDL Window Successfully Initialized, With Zero Errors!");
	}

	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG) != 0){
		SDL_Log("SDL Video and Image API Could not be loaded, Error: ", SDL_GetError());
	}
	else {
		SDL_Log("SDL Video and Image API has been Successfully Initialized, With Zero Errors!");
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_Renderer) {
		SDL_Log("Failed to create a Renderer Instance, Error: ", SDL_GetError());
	}
	else {
		SDL_Log("Renderer fully initialized, with Zero Errors!");
	}


	TextureManager::GetInstance()->Load("wood", "assets/img.jpg");
	return m_isRunning = true;

}

bool ac_engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(ac_engine::GetInstance()->GetRenderer());
	SDL_Log("Renderer Destroyed...");
	SDL_DestroyWindow(ac_engine::GetInstance()->GetWindow());
	SDL_Log("Window Destroyed...");
	IMG_Quit();
	SDL_Quit();

	SDL_Log("SDL and SDL Image Library has Quit.");
	SDL_Log("Finished..");



	return true;
}

void ac_engine::Quit()
{
	m_isRunning = false;
}

void ac_engine::Update()
{
	SDL_Log("Updating...");
}

void ac_engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	TextureManager::GetInstance()->Draw("wood", 100, 100, 347, 465);
	SDL_RenderPresent(m_Renderer);
}

void ac_engine::Events()
{
	InputManager::GetInstance()->Listen();
}
