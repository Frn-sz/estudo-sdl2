#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <iostream>

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600

using namespace std;

void initialize_SDL();
void set_default_window_attributes();

int main(int argc, char const *argv[]) {
  SDL_Window *window = nullptr;

  initialize_SDL();
  set_default_window_attributes();

  window = SDL_CreateWindow("SDL3 Test", SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_OPENGL);

  SDL_GLContext context = SDL_GL_CreateContext(window);

  gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

  if (!window)
    exit(1);

  bool quit = false;

  while (!quit) {
    glViewport(0, 0, 600, 800);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
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

    const bool *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_RIGHT]) {
      cout << "Right arrow is being pressed" << endl;
    }

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
  }

  SDL_DestroyWindow(window);

  SDL_Quit();
  return 0;
}

void initialize_SDL() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    cout << "SDL couldn't be initialized" << SDL_GetError();
  else
    cout << "SDL Initialized" << endl;
}

void set_default_window_attributes() {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}
