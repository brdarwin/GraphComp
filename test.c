#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>


void display(){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPointSize(10);
    /*glBegin(GL_POINTS);
    {
        glColor3f(1, 1, 0);
        glVertex2f(0, 0);
        glVertex2f(0.5, 0.5);
    }
    glEnd();*/
    /*glBegin(GL_QUADS);
    {
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.75, -0.2);
    glVertex2f(-0.35, -0.5);
    glVertex2f(-0.35, 0.5);
    glVertex2f(-0.15, 0.45);
    }
    glEnd();*/
   glBegin(GL_TRIANGLE_STRIP);  // Indica que serão desenhados somente pontos
  {
    glColor3f(1.0f, 0.0f, 0.0f);  // Define a cor do desenho em formato RGB
    glVertex2f(-1, 0);  // Especifica pontos no espaço bidimensional (pixels)

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(1, 0);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0, -1);
  }
  glEnd(); ;
    glFlush();
    
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("example");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}