#include "Menu.h"
#include "Text.h"
void initColor(vec4& color);

Button::Button(){
}

void Button::Draw(Shader& shader, string inputText, float newScale){
	static Transform stat;
	static Text order;

	shader.Update(stat,color);
	mesh.Draw(GL_QUADS);

	order.RenderText(inputText,ButtonWord.x, ButtonWord.y , newScale, WHITE);
	
	
}


void Button::changeColor(vec4 newColor){
	color = newColor;
}













Menu::Menu(){
	initPlayButton();
	
	initExitButton();
	
	initInstructionsButton();
}

void Menu::initPlayButton(){
	PlayButton.corners[ RTOP_CORNER ].Add(vec3(-0.2, 0.2, 0));
	PlayButton.corners[ LTOP_CORNER ].Add(vec3(0.2, 0.2, 0));
	PlayButton.corners[ LBOTTOM_CORNER ].Add(vec3(-0.2, 0, 0));
	PlayButton.corners[ RBOTTOM_CORNER ].Add(vec3(0.2, 0, 0));


	PlayButton.color = ButtonColor;
	PlayButton.mesh.initMesh(PlayButton.corners,COMP);

	PlayButton.ButtonWord.x = PLAYBUTTONWORD_x;
	PlayButton.ButtonWord.y = PLAYBUTTONWORD_y;
}


void Menu::initExitButton(){
	ExitButton.corners[ RTOP_CORNER ].Add(vec3(-0.2, -0.3, 0));
	ExitButton.corners[ LTOP_CORNER ].Add(vec3(0.2, -0.3, 0));
	ExitButton.corners[ LBOTTOM_CORNER ].Add(vec3(-0.2, -0.4, 0));
	ExitButton.corners[ RBOTTOM_CORNER ].Add(vec3(0.2, -0.4, 0));

	ExitButton.color = ButtonColor;
	ExitButton.mesh.initMesh(ExitButton.corners,COMP);

	ExitButton.ButtonWord.x = EXITBUTTONWORD_x;
	ExitButton.ButtonWord.y = EXITBUTTONWORD_y;

}


void Menu::initInstructionsButton(){
	InstructionsButton.corners[ RTOP_CORNER ].Add(vec3(-0.2, -0.1, 0));
	InstructionsButton.corners[ LTOP_CORNER ].Add(vec3(0.2, -0.1, 0));
	InstructionsButton.corners[ LBOTTOM_CORNER ].Add(vec3(-0.2, -0.2, 0));
	InstructionsButton.corners[ RBOTTOM_CORNER ].Add(vec3(0.2, -0.2, 0));

	InstructionsButton.color = ButtonColor;
	InstructionsButton.mesh.initMesh(InstructionsButton.corners,COMP);
	
	InstructionsButton.ButtonWord.x = INSTRUCTIONSBUTTONWORD_x;
	InstructionsButton.ButtonWord.y = INSTRUCTIONSBUTTONWORD_y;
}