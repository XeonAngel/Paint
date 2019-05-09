#include "Square.h"

int main(int argc, char* args[]){

	Display	  display( SCREEN_DIMENSION , SCREEN_DIMENSION, "Paint");

	Squares squares( LVL1);
 
	Shader shader("./res/basicShader", BASIC);

	Brush brush;

	while(!display.WindowisNotClosed()){

		brush.Paint(squares);

		display.Background(vec4(1.0, 1, 0, 1.0));
		
		squares.Draw(shader);
		
		display.Update();
	}
	return EXIT_SUCCESS;
}