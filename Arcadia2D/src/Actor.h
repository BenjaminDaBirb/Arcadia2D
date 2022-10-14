#pragma once
#include "IActor.h"
#include "Transform.h"
#include <SDL.h>

struct Properties {

public:
	Properties(std::string textureID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		X = x;
	    Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
	}




public:
	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;
};


class Actor : public IActor
{
public:
	Actor(Properties* props) m_TextureID(props->TextureID),
	m_Width(props->Width), m_Height(props->Height), m_Flip(props->Flip) {
	    
		m_transform = new Transform(props->X, props->Y);
	}

	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void Update(float dt) = 0;

protected:
	Transform* m_transform;
	int m_Width, m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;


};
