#include <iostream>
#include <GL\freeglut.h>
#define INIT_WIN_X 800
#define INIT_WIN_Y 800

float viewX = 0, viewY = -1500;
float lr = 0;
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

void MyKeyBoard(unsigned char key,int x, int y) {
	float a = 10.0, b = 5;
	float l = -5, r = 5;
	switch (key) {
	case '27':
		exit(0);
		break;
	case 'w':
		if (viewX == -180|| viewX == 180) viewY -= b;
		else viewY += b;
		glutPostRedisplay();
		break;
	case 's':
		if (viewX == -180 || viewX == 180) viewY += b;
		else viewY -= b;
		glutPostRedisplay();
		break;
	case 'a':
		if (viewX == -180) a = 0;
		else a = 10;
		viewX -= a;
		glutPostRedisplay();
		break;
	case 'd':
		if (viewX == 180) a = 0;
		else a = 10;
		viewX += a;
		glutPostRedisplay();
		break;
	case 'q':
		lr += l;
		glutPostRedisplay();
		break;
	case 'e':
		lr += r;
		glutPostRedisplay();
		break;
	}
}



void DrawTorus() {
	float x = viewX;

		glPushMatrix();
		gluLookAt(0.0, 0.5, 0.0, 0.0, 1.8, -1.0, 0.0, 1.0, 0.0);
	glRotated(-x,0.0, 0.0,1.0);
	glutSolidTorus(0.2,0.6,4,9);
	glutSolidTorus(0.2, 0.2, 4, 3);
		glPopMatrix();
}

void DrawSmallQuads() {
	float y = viewY;
	float x = viewX;
	int a = 0;
	glMatrixMode(GL_PROJECTION);

	glPushMatrix();

	glLoadIdentity();
	gluPerspective(120, 1.0, 3.0, 100.0);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glTranslatef(lr, 0.0, 0.0);
	glRotatef(x, 0.0, 1.0, 0.0);
	gluLookAt(0.0, y, -9.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	for (a = 0; a <= 2000; a = a + 10) {
		glTranslatef(0.0, -a, 0.0);
		glBegin(GL_QUADS);
		glVertex3f(-5, -15, 0.0);
		glVertex3f(5, -15, 0.0);
		glVertex3f(5, 15, 0.0);
		glVertex3f(-5, 15, 0.0);
		glEnd();
	}

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void DrawQuads() {
	glMatrixMode(GL_PROJECTION);
	float y = viewY;
	float x = viewX;
	
		glPushMatrix();

		glLoadIdentity();
		gluPerspective(120, 1.0, 3.0, 100.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		glTranslatef(lr, 0.0, 0.0);
		glRotatef(x, 0.0, 1.0, 0.0);
		gluLookAt(0.0, y, -10.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
		
		glBegin(GL_POLYGON);
		glVertex3f(-2000.0, -2000.0, 0.0);
		glVertex3f(2000.0, -2000.0, 0.0);
		glVertex3f(2000.0, 2000.0, 0.0);
		glVertex3f(-2000.0, 2000.0, 0.0);
		glEnd();

		glPopMatrix();

		glMatrixMode(GL_PROJECTION);

		glPopMatrix();
}

void r_DrawSmallQuads() {
	float y = viewY;
	float x = viewX;
	int a = 0;
	glMatrixMode(GL_PROJECTION);

	glPushMatrix();

	glLoadIdentity();
	gluPerspective(120, 1.0, 3.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(lr, 0.0, 0.0);
	glRotatef(x, 0.0, 1.0, 0.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	gluLookAt(0.0, y, -9, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	for (a = 0; a <= 2000; a = a + 10) {
		glTranslatef(0.0, -a, 0.0);
		glBegin(GL_QUADS);
		glVertex3f(-5, -15, 0.0);
		glVertex3f(5, -15, 0.0);
		glVertex3f(5, 15, 0.0);
		glVertex3f(-5, 15, 0.0);
		glEnd();
	}

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void r_DrawQuads() {
	float y = viewY;
	float x = viewX;

	glMatrixMode(GL_PROJECTION);

	glPushMatrix();

	glLoadIdentity();
	gluPerspective(120, 1.0, 3.0, 100.0);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glTranslatef(lr, 0.0, 0.0);
	glRotatef(x, 0.0, 1.0, 0.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	gluLookAt(0.0, y, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	glBegin(GL_QUADS);
	glVertex3f(-2000.0, -2000.0, 0.0);
	glVertex3f(2000.0, -2000.0, 0.0);
	glVertex3f(2000.0, 2000.0, 0.0);
	glVertex3f(-2000.0, 2000.0, 0.0);
	glEnd();

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);

	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	glViewport(0, 0, INIT_WIN_X, INIT_WIN_Y / 2);
		glPushMatrix();
	DrawTorus();
		glPopMatrix();


	glViewport(0, INIT_WIN_Y / 2, INIT_WIN_X, INIT_WIN_Y / 2);
		glPushMatrix();
		DrawSmallQuads();
	DrawQuads();
		glPopMatrix();

	glViewport(INIT_WIN_X / 3, 700 , INIT_WIN_X/3, INIT_WIN_Y / 3);
		glPushMatrix();
		r_DrawSmallQuads();
	r_DrawQuads();
		glPopMatrix();

	glViewport(0, INIT_WIN_Y / 4, INIT_WIN_X/5, INIT_WIN_Y / 3);
		glPushMatrix();
		r_DrawSmallQuads();
	r_DrawQuads();
		glPopMatrix();

	glViewport(INIT_WIN_X-150, INIT_WIN_Y / 4, INIT_WIN_X / 5, INIT_WIN_Y / 3);
		glPushMatrix();
		r_DrawSmallQuads();
	r_DrawQuads();
		glPopMatrix();

	glutSwapBuffers();
	glFlush();
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
	glutCreateWindow("play_car");

	glutKeyboardFunc(MyKeyBoard);
	glutDisplayFunc(MyDisplay);
	glClearColor(0.0, 55.0, 180.0, 1.0);
	glutReshapeFunc(MyReshape);
	InitLight();
	glutMainLoop();

	return 0;
}