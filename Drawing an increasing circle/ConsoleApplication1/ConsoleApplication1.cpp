// OpenGL2016.cpp : Defines the entry point for the console application.
//


#include <gl/freeglut.h>
#include <math.h>
#define PI 3.1415926535898

void changeViewPort(int w, int h)
{
	//glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}



GLint circle_points = 100;
void MyCircle3f(GLfloat centerx, GLfloat centery, GLfloat radius) {
	GLint i;
	GLdouble theta;
	glBegin(GL_POLYGON);
	for (i = 0; i < circle_points; i++) {
		theta = 2 * PI * i / circle_points;
		glVertex2f(centerx + radius * cos(theta), centery + radius * sin(theta));
	}
	glEnd();
}

void CrtajFigura()
{
	glColor3f(0.8, 0.0, 0.9);
	glBegin(GL_LINES);
	glVertex2f(0., 100.);
	glVertex2f(100., 100.);
	glEnd();
	glColor3f(0, 1.0, 0.9);
	MyCircle3f(100., 100., 5.);
}

void CrtajFiguraAnim()
{
	glColor3f(0.8, 0.0, 0.9);
	glBegin(GL_LINES);
	glVertex2f(0., 0.);
	glVertex2f(0., 100.);
	glEnd();
	glColor3f(0, 1.0, 0.9);
	MyCircle3f(0., 100., 5.);
}

void CrtajKvadrat()
{

	glBegin(GL_POLYGON);
	glVertex2f(50., 100.);
	glVertex2f(100., 100.);
	glVertex2f(100., 200.);
	glVertex2f(50., 200.);
	glEnd();
	MyCircle3f(50., 100., 5.);
}

void CrtajKoordinatenSistem()
{
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex2d(-200, 0);
	glVertex2d(200, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(0, -200);
	glVertex2d(0, 200);
	glEnd();
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();

	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 400, 400);
	gluOrtho2D(-300.0, 300.0, -300.0, 300.0);



}

float i = 0;
void Display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	




	//Primer za Animacija

	glColor3f(0.0, 0.8, 0.1);
	MyCircle3f(i + 0., i + 0., i + 10.);
	i += 0.01;
	glutPostRedisplay();

	glFlush();
}

int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	// Set the window size
	glutInitWindowSize(400, 400);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Zdravo Martin");
	// Bind the two functions (above) to respond when necessary
	init();
	//glutReshapeFunc(changeViewPort);
	glutDisplayFunc(Display);

	glutMainLoop();
	return 0;
}