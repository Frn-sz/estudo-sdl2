#include <SDL3/SDL.h>
#include <iostream>

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600

using namespace std;

void initialize_SDL();

int main(int argc, char const *argv[])
{
    SDL_Window *window = nullptr;

    initialize_SDL();

    window = SDL_CreateWindow("SDL2 Test", SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (!window)
        exit(1);

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                quit = true;
                break;
            case SDL_EVENT_MOUSE_MOTION:
                cout << "Mouse has been moved" << endl;
                break;
            case SDL_EVENT_KEY_DOWN:
                cout << event.key.key << "key has been pressed" << endl;
                break;
            default:
                break;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

void initialize_SDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        cout << "SDL couldn't be initialized" << SDL_GetError();
    else
        cout << "SDL Initialized" << endl;
}
