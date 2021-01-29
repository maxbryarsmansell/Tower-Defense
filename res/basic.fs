#version 450 core

out vec4 o_Col;

in vec3 v_Col;
in vec2 v_FragCoord;

void main()
{
	o_Col = vec4(v_Col, 1.0);
}