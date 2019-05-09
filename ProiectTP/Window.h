
#include <string>
#include <iostream>
#include <GL\glew.h>
#include <SDL2\SDL.h>
#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include "Shader.h"
#include "Mesh.h"


#ifndef WINDOW_H
#define WINDOW_H

#define SCREEN_DIMENSION 1024

class Display{
	friend int main(int argc, char* args[]);
	public:
		Display(int, int, const std::string&);
		~Display();
		bool WindowisNotClosed();
		void Update();
		void Background(glm::vec4);
		void Close();
	

	private:
		SDL_Window*	  window;
		SDL_GLContext context;
		bool isClosed;
	
};


#endif