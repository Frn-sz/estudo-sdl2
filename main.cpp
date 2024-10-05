#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

void initialize_SDL();

int main(int argc, char const *argv[])
{
    initialize_SDL();

    return 0;
}

void initialize_SDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        cout << "SDL couldn't be initialized" << SDL_GetError();
    else
        cout << "SDL Initialized" << endl;
}
