#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#include <gl/glew.h>
#include <GL/glut.h>


double rotate_y = 0;
double rotate_x = 0;

void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glRotatef(rotate_x, 1.0 , 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	//BASE
	glBegin(GL_POLYGON);

	glColor3f(1.0,0.0,0.0);  glVertex3f(-0.5, -0.5, -0.5);	//p1
	glColor3f(0.0, 1.0,0.0); glVertex3f(-0.5, -0.5, 0.5); //p2
	glColor3f(0.0, 0.0,1.0); glVertex3f(0.5, -0.5, 0.5); //p3
	glColor3f(1.0, 0.0,1.0); glVertex3f(0.5, -0.5, -0.5); //p4

	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0); //White
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glEnd;

	//Left
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);//Green
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glEnd();

	//Back
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);//yellow
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	//Frontal
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);//Blue
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();

	//Right
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);//Red
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();


}



void specialKeys(int key, int x, int y){

	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;
	else if (key == GLUT_KEY_UP)
		rotate_x += 5;
	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	glutPostRedisplay();
}



int main(int argc, char* argv[]){

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Super Cubo");
	/*Z-BUFFER - Utilizado para criar os efeitos 3d que desejamos � anunciado com o GLUT_DEPTH*/
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	glutMainLoop();

	return 0; //Close Program
}

