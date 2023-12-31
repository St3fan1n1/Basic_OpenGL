#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform vec3 triangleOffset;

out vec3 ourColor;

void main()
{
   ourColor = aPos; 
   gl_Position = vec4((aPos.x * -1) + triangleOffset.x, aPos.y * -1, aPos.z * -1, 1.0);
}
