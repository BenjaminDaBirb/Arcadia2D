#include "ac_engine.h"
#include <iostream>
#include "TextureManager.h"
#include "TextManager.h"
#include "InputManager.h"
#include "Actor.h"


ac_engine* ac_engine::m_instance = nullptr;

bool ac_engine::Init()
{
	//Initialize all the SDL components and systems in one peace.
	SDL_Init(SDL_INIT_EVERYTHING);
	//Initialize the SDL TTF library for text and font rendering work.
	TTF_Init();

    //Checks if the SDL TTF library returns -1 as an output, which is a sign the library failed to initialize.
	if(TTF_Init()==-1) {
      SDL_Log("Initialization for the SDL TTF Library has failed: %s\n", TTF_GetError());
      exit(2);
   }
   else{
	  SDL_Log("SDL TTF Library was successfully initialized! With Zero Errors!");
   }
   
   if(!TTF_WasInit() && TTF_Init()==-1) { 
	  SDL_Log("TTF_Init: %s\n", TTF_GetError()); 
	  exit(1);
   }

    //Create and initialize the main SDL window to display, render and begin performing other engine-related functions.
	m_Window = SDL_CreateWindow("Arcadia 2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!m_Window) {
		SDL_Log("Could Not Initialize the SDL Window, Error: %s", SDL_GetError() );
		exit(2);
	}
	else {
		SDL_Log("SDL Window Successfully Initialized, With Zero Errors!");
	}

    //Checks if SDL_INIT_VIDEO, IMG_INIT_JPG and IMG_INIT_PNG are not intiialized.
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0){
		SDL_Log("SDL Video and Image API Could not be loaded, Error: %s", SDL_GetError());
		exit(2);
	}
	else {
		SDL_Log("SDL Video and Image API has been Successfully Initialized, With Zero Errors!");
	}

    //Creates and intializes the main SDL Renderer for rendering graphical objects, including text rendering and everything else.
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_Renderer) {
		SDL_Log("Failed to create a Renderer Instance, Error: %s", SDL_GetError());
		exit(2);
	}
	else {
		SDL_Log("Renderer fully initialized, with Zero Errors!");
	}


	TextureManager::GetInstance()->Load("wood", "assets/img.jpg");
	TextureManager::GetInstance()->Load("house_backdrop","assets/house.jpg");
	TextManager::GetInstance()->CleanAllFonts();
	ac_engine::Renderer_Draw("house_backdrop", 200, 200, 300, 300);
	ac_engine::Renderer_Draw("wood", 100, 100, 347, 465);
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
	TTF_Quit();

	SDL_Log("SDL, SDL Font Library and SDL Image Library has Quit.");
	SDL_Log("Finished..");



	return true;
}

void ac_engine::Quit()
{
	m_isRunning = false;
}

void ac_engine::Update()
{
	
}

void ac_engine::Render()
{
	//Set up the renderer, and start rendering!
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderPresent(m_Renderer);
}

void ac_engine::Renderer_Draw(std::string id, int x, int y, int width, int height)
{
	//Draw and render any given jpg/png into the renderer.
	TextureManager::GetInstance()->Draw(id, x, y, width, height);
}

void ac_engine::Events()
{
	//Listen to input.
	InputManager::GetInstance()->Listen();
}
