#shader vertex
#version 330 core
   layout (location = 0) in vec3 aPos;
   layout (location = 1) in vec3 aColor;

   uniform vec3 triangleOffset;

   out vec3 ourColor;

   void main()
   {
      ourColor = aPos; 
      gl_Position = vec4((aPos.x * -1) + triangleOffset.x, aPos.y * -1, aPos.z * -1, 1.0);
   };

#shader fragment
#version 330 core
   out vec4 FragColor;
   in vec3 ourColor;

   void main()
   {
      FragColor = vec4(ourColor, 1.0f);
   };
