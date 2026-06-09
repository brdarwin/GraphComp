#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void  display (){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_QUADS);
    {
        glColor3f(1,0,0);
        glVertex2f(-0.25,0);//1
        glVertex2f(0,0);//2
        glVertex2f(0,0.25);//3
        glVertex2f(-0.25,0.25);//4
        

        
      



    }
    glEnd();
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,1);
        glVertex2f(0,0);//1
        glVertex2f(0.5,0);//2
        glVertex2f(0.5,0.25);//3
        glVertex2f(0,0.25);//4
        

        
      



    }
    glEnd();
    glBegin(GL_TRIANGLES);
    {
        glColor3f(0,1,0);
        glVertex2f(-0.25,0.25);//1
        glVertex2f(-0.125,0.375);//2
        glVertex2f(0,0.25);//3

    }
    glEnd();
    glBegin(GL_QUADS);
    {
        glColor3f(0,1,1);
        glVertex2f(0,0.25);//1
        glVertex2f(0.5,0.25);//2
        glVertex2f(0.333,0.375);//3
        glVertex2f(-0.125,0.375);//4
        

        
      



    }
    glEnd();
    glBegin(GL_QUADS);
    {
        glColor3f(1,0,1);
        glVertex2f(-0.161,0);//1
        glVertex2f(-0.083,0);//2
        glVertex2f(-0.083,0.161);//3
        glVertex2f(-0.161,0.161);//4
        

        
      



    }
    glEnd();
     glBegin(GL_QUADS);
    {
        glColor3f(0,1,1);
        glVertex2f(-1,-1);//1
        glVertex2f(-0.5,-1);//2
        glVertex2f(-0.161,0);
        glVertex2f(-0.083,0);
        

        
      



    }
    glEnd();
    
    glFlush();

}


int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow(" House ");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0  ;
}