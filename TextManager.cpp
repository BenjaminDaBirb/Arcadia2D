#include "TextManager.h"

TextManager* TextManager::m_instance = nullptr;

void TextManager::LoadFont(const char* font_file_path, TTF_Font* font, int size)
{
    font = TTF_OpenFont(font_file_path, size);
    if(!font){
        SDL_Log("Couldn't open the file from the given path: ", font_file_path, SDL_GetError());
        return;
    }

    m_FontMap[font_file_path] = font;
}

void TextManager::FontStyle(TTF_Font* font, int font_style)
{
    TTF_SetFontStyle(font, font_style);
}

void TextManager::CleanAllFonts()
{
    std::map<const char*, TTF_Font*>::iterator it;
    if(m_FontMap.empty())
    {
        return;
        SDL_Log("Literally no Fonts and paths in this map");
    }
    else
    {
        for (it = m_FontMap.begin(); it != m_FontMap.end(); ++it) 
        {
		   TTF_CloseFont(it->second);
	    }

        m_FontMap.clear();
    }
}

void TextManager::ClearFont(TTF_Font* font)
{
    TTF_CloseFont(font);
}