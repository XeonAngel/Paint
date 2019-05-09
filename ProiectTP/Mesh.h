#pragma once

#include <glm\glm.hpp>
#include <GL\glew.h>
#include "Window.h"

// Cauta daca header-il a fost deja utilizat daca da trece mai departe daca nu il initializeaza
#ifndef MESH_H
#define MESH_H


using namespace glm;

enum{
	POSITION_VB,	
	NUM_BUFFERS
};


// Clasa care creeaza plansa

class Vertex{
	public:
		Vertex();
		Vertex(const vec3&);
		void Add(vec3&);
		vec3 GetPos();
	private:
		vec3 pos;

};





class Mesh{
	public:
		Mesh();
		Mesh(Vertex* vertices, unsigned int nV);
		void initMesh(Vertex* vertices, unsigned int nv);
		~Mesh();

		void Draw(unsigned int);
	private:
		GLuint vertexArrayObject;
		GLuint vertexArrayBuffer[ NUM_BUFFERS ];
		unsigned int drawCount;
};




#endif