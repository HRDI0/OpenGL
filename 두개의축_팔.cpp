#include <iostream>
#include <GL\freeglut.h>
#include <Windows.h>

GLdouble next_x = 0, next_y = 0, x = 0, y = 0, angle = 0, angle2 = 0;;

void MyKeyBoard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		angle2 = angle2 + 0.3;
		glutPostRedisplay();
		break;

	case 'd':
		angle2 = angle2 - 0.3;
		glutPostRedisplay();
		break;

	case 'w':
		angle= angle + 0.3;
		glutPostRedisplay();
		break;

	case 's':
		angle = angle - 0.3;
		glutPostRedisplay();
		break;
	}
}

void draw() {
	x = 0.5 * cos(angle);
	y = 0.5 * sin(angle);

	next_x = 0.5 * cos(angle) + (0.5 * cos(angle + angle2));
	next_y = 0.5 * sin(angle) + (0.5 * sin(angle + angle2));

	glColor3f(1.0, 0.0, 0.0);
	
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(x, y);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(next_x, next_y);
	glEnd();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	

	draw();
	glFlush();
	glutSwapBuffers();
}
void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("arm/±Ý");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyBoard);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
}