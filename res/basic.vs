#version 450 core

layout (location = 0) in vec3 a_Pos;
layout (location = 1) in vec3 a_Col;

out vec3 v_Col;
out vec2 v_FragCoord;
out float v_Time;

uniform float u_Time;

void main()
{
   gl_Position = vec4(a_Pos, 1.0);
   v_Col = a_Col;
   v_FragCoord = a_Pos.xy / 2.0 + vec2(0.5);
   v_Time = u_Time;
}