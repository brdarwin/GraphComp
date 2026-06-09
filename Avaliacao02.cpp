#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLfloat fAspect;
GLdouble rotX = 0, rotY = 0, rotHead = 0, rotBlade = 0;
GLint  direcao= 0; 

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2);

	//glRotatef(rotX, 1, 0, 0);
	//glRotatef(rotY, 0, 1, 0);
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);

	// Base
	/*glPushMatrix();
	{	//glTranslated(300,200,0);
		glScalef(10, 10, 2);
		glutWireCube(1);
	}
	glPopMatrix();*/

	// Haste
	glPushMatrix();
	{
		glTranslated(0,-150,0);
		glScalef(2, 10, 2);
		glutWireCube(1);
	}
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 1.0f);

	glPushMatrix();
	glRotatef(rotHead,0,1,0);
	// Motor
	glPushMatrix();
	{
		//glRotatef(rotY,0,1,0);
		glScalef(4, 4, 6);
		glutWireCube(1);
	}
	glPopMatrix();

	// Ponta
	glPushMatrix();
	{
		glutSolidSphere(0.5, 10, 8);
	}
	glPopMatrix();

	glColor3f(0.0f, 1.0f, 0.0f);

	//rotacionar helice:
	
	glRotatef(rotBlade,0, 0, 1);
	glPushMatrix();
	// Hélice
	glPushMatrix();
	{
		glScalef(16, 2, 1);
		glutWireCube(1);
	}
	glPopMatrix();

	// Hélice
	glPushMatrix();
	{
		glScalef(2, 16, 1);
		glutWireCube(1);
	}
	glPopMatrix();

	glPopMatrix();// rotacionar helice
	
	glPopMatrix(); //rotacionar cabeca

	glPopMatrix();

	glutSwapBuffers();
}

void configProjection(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, fAspect, 0.5, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);
	//gluLookAt(50, 50, 50, 0, 0, 0, 0, 1, 0);
}

void resize(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;

	fAspect = (GLfloat)w / (GLfloat)h;

	configProjection();
}

void keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 'x':
		rotBlade +=30;
		break;
	case 'z':
		if(direcao == 0){
			rotHead  += 30;
			direcao = 1;
		}else if(direcao == 1){
			rotHead  = 0;
			direcao = 2;
		}else if(direcao == 2){
			rotHead   = -30;
			direcao = 3;
		}else{
			rotHead   = 0;
			direcao = 0;
		}
		break;
	case 27:
		exit(0);
		break;

	case 32:
		rotBlade +=30;
		if(direcao == 0){
			rotHead  += 30;
			direcao = 1;
		}else if(direcao == 1){
			rotHead  = 0;
			direcao = 2;
		}else if(direcao == 2){
			rotHead   = -30;
			direcao = 3;
		}else{
			rotHead   = 0;
			direcao = 0;
		}

		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void specialkeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		rotX += 10;
		break;
	case GLUT_KEY_DOWN:
		rotX += 10;
		break;
	case GLUT_KEY_LEFT:
		rotY += 10;
		break;
	case GLUT_KEY_RIGHT:
		rotY -= 10;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Avaliação 02");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeys);
	glutMainLoop();
	return 0;
}
