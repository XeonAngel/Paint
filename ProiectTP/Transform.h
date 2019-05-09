#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#ifndef TRANSFORM_H
#define TRANSFORM_H


using namespace glm;


class Transform{
	public:
		Transform();

		mat4 Translation_Matrix();

		void setPos	  (vec3& newPos  ) { Pos   = newPos  ; }
		
	private:
		vec3 Pos;
	
};

#endif