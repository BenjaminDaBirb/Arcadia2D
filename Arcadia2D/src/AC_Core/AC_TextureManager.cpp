#include "AC_TextureManager.h"
#include <SDL_image.h>
#include <SDL.h>
#include "AC_engine.h"
#include <map>

TextureManager* TextureManager::m_instance = nullptr;

void TextureManager::Load(std::string id, std::string filename)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (surface == nullptr) {
		SDL_Log("Failed to Load Image ", filename.c_str(), "Error: ", SDL_GetError());
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(ac_engine::GetInstance()->GetRenderer(), surface);
	if (!texture) {
		SDL_Log("Failed to Create Texture From ", filename.c_str(), "Error: ", SDL_GetError());
	}

	m_TextureMap[id] = texture;

}

void TextureManager::Drop(std::string id)
{
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}

void TextureManager::Clean()
{
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = m_TextureMap.begin(); it != m_TextureMap.end(); it++) {
		SDL_DestroyTexture(it->second);
	}

	m_TextureMap.clear();

	SDL_Log("Texture Map Cleaned...");
	
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { 0, 0, width, height };
	SDL_Rect datRect = { x, y, width, height };

	SDL_RenderCopyEx(ac_engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &datRect, 0, nullptr,
		flip);

}
