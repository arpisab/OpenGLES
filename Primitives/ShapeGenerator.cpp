#include <GL\glew.h>
#include "Primitives\ShapeGenerator.h"
#include <glm\glm.hpp>
//#include <Primitives\vertex.h>

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)    //****

ShapeData ShapeGenerator::makeTriangle()
{
	ShapeData ret;

	Vertex myTri[] =
	{
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),

		glm::vec3(-1.0f, -1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f, -1.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),
	};
	//ret.numVertices = sizeof(myTri) / sizeof(*myTri);
	ret.numVertices = NUM_ARRAY_ELEMENTS(myTri);        //****
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, myTri, sizeof(myTri));

	GLushort indices[] = { 0, 1, 2 }; // we define how our positions are connected using their array
	ret.numIndices = NUM_ARRAY_ELEMENTS(indices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, indices, sizeof(indices));
	
	return ret;
}

