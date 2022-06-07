#version 330 core

layout(location = 0) out vec4 color;
in vec3 v_Position;
in vec4 v_Color;

void main()
{
	float distance = 1.0 - length(v_Position.xy);
	// float value = distance;
	//if (distance > 0.005)
		//value = 1.0;
	// color = vec4(vec3(value), 1.0);
	color = v_Color;
	if (distance <= 0)
		color = vec4(1.0, 1.0, 0.0, 0.0);
// if (color <= vec4(0.0, 0.0, 0.0, 1.0))
//		color = vec4(1.0, 1.0, 0.0, 0.0);
};