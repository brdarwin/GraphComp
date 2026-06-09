#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


void display(){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); // Informa que as operações seguintes serão executadas na matrix modelview
	glLoadIdentity();			// Carrega a matriz identidade
    
    glClear(GL_COLOR_BUFFER_BIT); // Inicializa o buffer de cores antes de ele ser alterado
	glLineWidth(3);				  // Espessura das linhas a serem desenhadas

    glBegin(GL_LINES);			 // Indica que serão traçadas linhas com os pontos a seguir
	glColor3f(0.0f, 0.0f, 0.0f); // Define a cor do desenho em formato RGB
	glVertex2f(-250, 0);		 // Especifica pontos no espaço bidimensional (pixels)
	glVertex2f(250, 0);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0, -250);
	glVertex2f(0, 250);
	glEnd();

    
    glBegin(GL_TRIANGLES);{
        glColor3f(1.0f, 1.0f, 0.0f);
	    glVertex2f(-125, 0); // 1
	    glVertex2f(0, 125); // 2
        glVertex2f(125, 0); // 3
    }
    glEnd();
    
    //glPushMatrix();{}

    glFlush();
}

int main(int argc, char *argv[])
{   
    float  winWidth = 500, winHeight = 500;
    float* pWidth = &winWidth;
    float* pHeight = &winHeight;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(*pWidth,*pHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Ortho");
    glutDisplayFunc(display);
    //glutKeyboardFunc(keyboard);
    glutMainLoop();

    
    
	return 0;
}