#pragma once

#include <vector>
#include "Window.h"
#include "Transform.h"


#define L1 0.00396025
#define L2 0.03125
#define L3 0.25

enum{ LVL3, LVL2, LVL1};


struct coord {
	float x, y;
};

class Squares;





class Brush {

public:
	void setColor();
	void Paint(Squares&);
	void takeCoord();
private:
	coord coord;
	vec4 newColor;
};



class Squares {
	friend class Brush;
	public:
		Squares(unsigned int level);
		void initForm(float);
		void initCoordonates(int count, float dim);
		void Draw(Shader& shader);
		
		
		
	private:
		std::vector <coord> position;
		std::vector <vec4> color;
		Vertex form[ 4 ];
		int level;
		int squaresCount;
		double dimension;

		Transform translation;
		
};