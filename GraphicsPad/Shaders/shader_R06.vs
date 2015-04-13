#version 450

in layout(location=0) vec3 position;
in layout(location=1) vec3 vertexColor;

// uniform mat4 modelTransformMatrix;
uniform mat4 fullTransformMatrix;

out vec3 theColor;

void main()
{
	vec4 v = vec4(position, 1.0); 
	
	// vec4 newPosition = modelTransformMatrix * v;
	// vec4 projectedPosition = projectionMatrix * newPosition;
	// gl_Position = projectedPosition;

	gl_Position = fullTransformMatrix *v;
	theColor = vertexColor;
};