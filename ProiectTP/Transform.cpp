#include "Transform.h"
using namespace glm;


Transform::Transform(){
	Pos.x = 0, Pos.y = 0, Pos.z = 0;
}





mat4 Transform::Translation_Matrix(){
	
	//Crearea Matricii care v-a muta patratele

	mat4 posMatrix = translate(Pos);
	

	return posMatrix;
}