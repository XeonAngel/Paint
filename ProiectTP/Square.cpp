#include "Square.h"

#define WHITE vec4(1.0, 1.0, 1.0, 1.0)


void Squares::initForm(float dim) {
	form[0] = vec3(0, 0, 0);
	form[1] = vec3(dim, 0, 0);
	form[2] = vec3(dim, dim, 0);
	form[3] = vec3(0, dim, 0);

}

void Squares::initCoordonates(int count, float dim) {
	float column = -1;
	float line = 1;

	for (int i = 0; i < count; i++) {
		coord new_item;
		
		new_item.x = column;
		new_item.y = line;

		position.push_back(new_item);
		color.push_back(WHITE);
		
		column >= 1 - dim ? line-=dim, column = -1 : column += dim;
	}

}



Squares::Squares(unsigned int level) {
	this->level = level;
	
	switch (level) {

	case LVL3:
		this->dimension = L3;
		this->squaresCount = 72;
			break;

	case LVL2:
		this->dimension = L2;
		this->squaresCount = 4096 + 64;
			break;
	
	case LVL1: 
		this->dimension = L1;
		this->squaresCount = 262144;
		break;

	}


	initForm(dimension);
	initCoordonates(squaresCount, dimension);
}





vec4 random_color() {
	float rx = sign(rand()) * static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float ry = sign(rand()) * static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float rz = sign(rand()) * static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	vec4 random(rx, ry, rz, 1);

	return random;
}



void Squares::Draw(Shader& shader) {
	static Mesh drawer(form, 4);

	for (int i = 0; i < squaresCount; i++) {
		//Mutarea Patratelor create in origine spre coordonatele sale
		translation.setPos( vec3(position[i].x, position[i].y, 0 ));
		shader.Update( color[ i ] , translation);
		drawer.Draw(GL_QUADS);
		

	}
}