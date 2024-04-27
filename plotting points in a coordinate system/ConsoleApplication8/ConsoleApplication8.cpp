#include <gl/freeglut.h>
#include <math.h>

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


}

float i = 0;
void Display(void)
{
	glViewport(0, 0, 400, 400);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200.0, 200.0, -200.0, 200.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	CrtajKoordinatenSistem();

	glPointSize(8.0);
	glBegin(GL_POINTS);
	glColor3f(1., 0., 0.);
	glVertex2d(-30,30);
	glVertex2d(0, 30);
	glVertex2d(0, 0);
	glVertex2d(0, -30);
	glVertex2d(30, -30);
	glEnd();


	

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
	glutCreateWindow("Hello, UGD STIP");
	// Bind the two functions (above) to respond when necessary
	init();
	//glutReshapeFunc(changeViewPort);
	glutDisplayFunc(Display);

	glutMainLoop();
	return 0;
}