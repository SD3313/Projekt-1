#version 330 core 

in vec3 ourColor;
out vec4 FragColor;

void main()
{
    FragColor = vec4(ourColor, 1.0);
	//gl_FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
} 
