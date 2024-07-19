#include <string>
#include <SDL2/SDL_ttf.h>
#include <map>



class TextManager
{
public:
    static TextManager* GetInstance() { return m_instance = (m_instance != nullptr) ? m_instance : new TextManager(); }
    

    virtual void LoadFont(const char* font_file_path, TTF_Font* font, int size);
    virtual void FontStyle(TTF_Font* font, int font_style);
    virtual void ClearFont(TTF_Font* font);
    virtual void CleanAllFonts();


private:
   TextManager(){}
   static TextManager* m_instance;
   std::map<const char*, TTF_Font*> m_FontMap;

};