#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GL\glew.h"
#include "GL\freeglut.h"

#include "shaderLoader.h" //narzàdzie do ladowania i kompilowania shaderow z pliku


// Program bazuje na tutorialu ze strony: http://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/



//Wymiary okna
int screen_width = 640;
int screen_height = 480;

float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f,  0.5f, 0.0f
};


bool VBO = false;

/*###############################################################*/

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(screen_width, screen_height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Pierwszy prog");

	glewInit(); //init rozszerzeszeñ OpenGL z biblioteki GLEW
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glutDisplayFunc(rysuj);			// def. funkcji rysuj¦cej
	//glutIdleFunc(idle);			// def. funkcji rysuj¦cej w czasie wolnym procesoora (w efekcie: ci¦gle wykonywanej)
	//glutReshapeFunc(rozmiar);		// def. obs-ugi zdarzenia resize (GLUT)

	//glutKeyboardFunc(klawisz);		// def. obs³ugi klawiatury
	//glutMouseFunc(mysz); 		// def. obs³ugi zdarzenia przycisku myszy (GLUT)
	//glutMotionFunc(mysz_ruch); // def. obs³ugi zdarzenia ruchu myszy (GLUT)

	
	unsigned int programID;
	programID = loadShaders("vertex_shader.glsl", "fragment_shader.glsl");

	glUseProgram(programID);
	


	//tworzenie bufora wierzcholków
	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);




	glDrawArrays(GL_TRIANGLES, 0, 3);
	

	glutSwapBuffers();

	glutMainLoop();					// start



	return(0);
}

