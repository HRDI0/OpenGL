#include <GL\freeglut.h>
#include <GL\GLU.h>

int Width, Height;
void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void InitLight() {
	GLfloat mat_diffuse[] = { 0.5, 0.5, 0.6, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_position[] = { -3, 6, 3.0, 0.0 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT,GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT,GL_SHININESS, mat_shininess);
}
void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glPopMatrix();
	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
		glTranslatef(0.0, 0.0, -0.5);
		glutWireTeapot(1.0);
	glPopMatrix();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		DrawScene();
	glPopMatrix();
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		DrawScene();
	glPopMatrix();
	glViewport(0, Height / 2, Width / 2, Height / 2);
	glPushMatrix();
		gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
		DrawScene();
	glPopMatrix();
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
		gluPerspective(30, 1.0, 3.0, 50.0);
		glMatrixMode(GL_MODELVIEW);			
		glPushMatrix();
			gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			glColor3f(0.7, 0.7, 0.7);
			glPushMatrix();
			glTranslatef(0.0, -1.0, 0.0);
			glBegin(GL_QUADS);
			glColor3f(0.7, 0.7, 0.7);
			glVertex3f(2.0, 0.0, 2.0);
			glVertex3f(2.0, 0.0, -2.0);
			glVertex3f(-2.0, 0.0, -2.0);
			glVertex3f(-2.0, 0.0, 2.0);
			glEnd();
			glPopMatrix();
			glPushMatrix();
			InitLight();
			glColor3f(0.7, 0.7, 0.7);
			glTranslatef(0.0, 0.0, -0.5);
			glutSolidTeapot(1.0);
			glPopMatrix();
		glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}

void Myshade(int w, int h) {
	w = Width;
	h = Height;
	glViewport(0, 0, w, h);
	GLfloat WidthFactor = (GLfloat)w / (GLfloat)500;
	GLfloat HeightFactor = (GLfloat)h / (GLfloat)500;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0 * WidthFactor, 2.0 * WidthFactor, -2.0 * HeightFactor, 2.0 * HeightFactor, 0.5, 5.0);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	Width = 500; Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("201621763_허성민");
	Init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(Myshade);
	glutMainLoop();
	return 0;
}
