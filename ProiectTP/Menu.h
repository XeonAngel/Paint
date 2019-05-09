#include "Treap.h"

#ifndef MENU_H
#define MENU_H
#define ButtonColor						vec4(0.7f, 0.2f, 0.6f, 1.0f)
#define Pressed_ButtonColor				vec4(0.5f, 0.2f, 0.6f, 1.0f)


enum{
	LTOP_CORNER,
	RTOP_CORNER,
	LBOTTOM_CORNER,
	RBOTTOM_CORNER,
	COMP
};

class Button{
	friend class Menu;
	public:
		Button();
		void Draw(Shader&, string ButtonText, float fontScale);
		void changeColor(vec4);
	private: 
		Vertex corners[ COMP ];
		vec4   color;
		Mesh   mesh;
		coord  ButtonWord;
};

class Menu{
	friend void DrawButtons(Menu&, Shader&); 
	friend class Display;
	public:
		Menu();
		void initPlayButton();
		void initExitButton();
		void initInstructionsButton();
		void Check_button_interaction(unsigned int&, bool&, Shader&, unsigned int, Player&, Objective&);
	private:
		Button PlayButton;
		Button ExitButton;
		Button InstructionsButton;

};


#endif