#include <iostream>
#include <GL\freeglut.h>
#define INIT_WIN_X 800
#define INIT_WIN_Y 800
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define PI 3.1415926535

GLint viewX = 0, viewY = 0;

GLfloat degree = 0.0f;

void InitLight()
{
	GLfloat mat_diffuse[] = { 0.5,0.5,0.6,1.0 };
	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat mat_ambient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_diffuse[] = { 0.8,0.8,0.8,1.0 };
	GLfloat light_ambidnt[] = { 0.3,0.3,0.3,1.0 };
	GLfloat light_position[] = { -3,6, 3.0,0.0 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambidnt);

	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);


}
void MyMouse(GLint X, GLint Y)
{
	viewX = X;
	viewY = Y;
	glutPostRedisplay();
}
void Draw() {
	int x = viewX - 400;
	int y = viewY - 400;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
	glRotated(y , 1, 0, 0);
	glRotated(x, 0, 1, 0);
	
	glutSolidCube(0.5);
	glutSwapBuffers();
}
void MyReshape(int NewWidth, int NewHeight)
{
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)INIT_WIN_X;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)INIT_WIN_Y;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(INIT_WIN_X, INIT_WIN_Y);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL CAMERA TEST");

	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();
	glutMotionFunc(MyMouse);
	glutDisplayFunc(Draw);
	glutReshapeFunc(MyReshape);
	glutMainLoop();

	return 0;
}


