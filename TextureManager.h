#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <fstream>

class TextureManager
{
public:
	static TextureManager* GetInstance() { return m_instance = (m_instance != nullptr) ? m_instance : new TextureManager(); }

	void Load(std::string id, std::string filename);
	void Drop(std::string id);
	void Clean();

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);





private:
	TextureManager() {};
	std::map<std::string, SDL_Texture*> m_TextureMap;
	static TextureManager* m_instance;
};

