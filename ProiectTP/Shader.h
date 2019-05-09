#pragma once     //Nu lasa un header sa se initializeze de 2 ori si sa intre intr-o bucla

#include <string>
#include <iostream>
#include <fstream>
#include <GL\glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Transform.h"

using namespace glm;
#define BASIC 0
#define TEXT  1


#ifndef SHADER_H
#define SHADER_H
using namespace std;


enum {
	TRANSFORM_U,
	CHANGE_COLOR_U,
	NUM_UNIFORMS,
};



class Shader{
	public:
		Shader();
		Shader(const std::string& fileName, int newType);
		void initShader(const std::string& fileName, int newType);
		~Shader();
		void Update(vec4, Transform);
	private:
		GLuint			program;
		GLuint			vShader;			//Vertex Shader-ul
		GLuint			fShader;			//Fragment Shader-ul
		GLuint uniforms[ NUM_UNIFORMS ];	//Update-ul culorilor
		int				   type;
};




#endif            //Aici se incheie utilizarea pragma once-ului