#include "Mesh.h"


using namespace glm;


Mesh::Mesh(Vertex* vertices, unsigned int nV){
	initMesh(vertices, nV);
}



Mesh::Mesh(){
}



void Mesh::initMesh(Vertex* vertices, unsigned int nV){
	drawCount = nV;

	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, vertexArrayBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffer[ POSITION_VB ]);
	glBufferData(GL_ARRAY_BUFFER, nV * sizeof(vertices[ 0 ]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}



Mesh::~Mesh(){
	glDeleteVertexArrays(1, &vertexArrayObject);
}



void Mesh::Draw(unsigned int form){
	glBindVertexArray(vertexArrayObject);

	glDrawArrays(form, 0, drawCount);
	
	glBindVertexArray(0);
}




//Tipul vectorilor care trebuie desenati

Vertex::Vertex(){
		pos.x = 0;
		pos.y = 0;
		pos.z = 0;
}


Vertex::Vertex(const vec3& pos){
		this ->pos = pos;
}


void Vertex::Add(vec3& newpos){
		pos = newpos;
}


vec3 Vertex::GetPos(){
		return pos;
}