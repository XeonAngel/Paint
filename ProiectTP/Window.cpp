#include "Square.h"

SDL_Event event;

vec4 random_color();
vec4 Color(0, 0, 0, 1);

Display::Display(int width, int height, const std::string& title){

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE    ,  8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE  ,  8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE   ,  8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE  ,  8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE , 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,  1);
	
	window = SDL_CreateWindow(title.c_str(), 
		                      SDL_WINDOWPOS_CENTERED, 
							  SDL_WINDOWPOS_CENTERED, 
							  width, 
							  height, 
							  SDL_WINDOW_OPENGL); 
	context = SDL_GL_CreateContext(window);
	
	
	

	GLenum status = glewInit();
	if(status != GLEW_OK)	 std::cerr<<"ERROR";

	isClosed = false;

}

void Display::Background(glm::vec4 Color){
	glClearColor(Color.x, Color.y, Color.z, Color.w);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::WindowisNotClosed(){
	return isClosed;
}

Display::~Display(){
	SDL_GL_DeleteContext (context);
	SDL_DestroyWindow    (window);
}






bool checkExit() {
	if (SDL_PollEvent(&event))
		if (event.type == SDL_QUIT)
			return true;

	return false;
}



void Display::Update(){
	SDL_GL_SwapWindow(window);
	
	if (checkExit())	isClosed = true;

}

void Display::Close(){
	isClosed = true;
}




void Brush::setColor() {
	newColor = random_color();
}

void Brush::takeCoord() {

	int x = event.button.x;
	int y = event.button.y;

	float nx, ny;

	nx = x - 512;
	nx = nx / 512;

	ny = y - 512;
	ny = ny / 512 * (-1);

	coord.x = nx;
	coord.y = ny;
}



bool ThisIsTheSquare(coord mouse, coord top_corner, float dim) {
	coord bot_corner = { top_corner.x + dim, top_corner.y - dim };
	if  (mouse.x >= top_corner.x && mouse.y <= top_corner.y && mouse.x < bot_corner.x && mouse.y > bot_corner.y) return true;
	return false;
}


int pow(int x, int y){
	int pow = 1;
	for (int i = 1; i <= y; i++)
		pow = pow*x;
	return pow;
}
void Brush::Paint(Squares& squares) {
	takeCoord();

	if (event.type == SDL_MOUSEBUTTONDOWN)
		for (int i = 0; i < squares.squaresCount; i++)
			if (ThisIsTheSquare(coord, squares.position[i], squares.dimension)) {
				squares.color[i + pow(8,squares.level + 1)] = Color;
				return;
			}
}