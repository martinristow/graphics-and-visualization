//MARTIN RISTOV - 102620

#include <gl/freeglut.h>
#include <math.h>
#define PI 3.1415926535898



GLint circle_points = 100;
void MyCircle3f(GLfloat centerx, GLfloat centery, GLfloat radius) {
	GLint i;
	GLdouble theta;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < circle_points; i++) {
		theta = 2 * PI * i / circle_points;
		glVertex2f(centerx + radius * cos(theta), centery + radius * sin(theta));
	}
	glEnd();
}

void MyCircle3f1(GLfloat centerx, GLfloat centery, GLfloat radius) {
	GLint i;
	GLdouble theta;
	glBegin(GL_POLYGON);
	for (i = 0; i < circle_points; i++) {
		theta = 2 * PI * i / circle_points;
		glVertex2f(centerx + radius * cos(theta), centery + radius * sin(theta));
	}
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
	glViewport(0, 0, 1000, 1000);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400.0, 400.0, -400.0, 400.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);



	glBegin(GL_POLYGON);//poligon za kukja
	glColor3f(0.9, 0.7, 0.4);
	glVertex2f(-140., -60.);
	glVertex2f(60., -60.);
	glVertex2f(60., 60.);
	glVertex2f(-140., 60.);
	glEnd();


	glBegin(GL_POLYGON);//poligon za krov na kukja
	glColor3f(0.4, 0.2, 0.1);
	glVertex2f(-150., 60.);
	glVertex2f(65., 60.);
	glVertex2f(-20., 145.);
	glVertex2f(-65., 145.);
	glEnd();


	glBegin(GL_POLYGON);//poligon za odzakot na kukjata
	glColor3f(0.4, 0.2, 0.1);
	glVertex2f(-120., 180.);
	glVertex2f(-100., 180.);
	glVertex2f(-100., 80.);
	glVertex2f(-120., 80.);
	glEnd();


	
	glBegin(GL_POLYGON);//poligon za vrata na kukjata
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-60., -60.);
	glVertex2f(-15., -60.);
	glVertex2f(-15., 1.);
	glVertex2f(-60., 1.);
	glEnd();

	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);//poligon za lev dzam na kukjata
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-121., 40.);
	glVertex2f(-80., 40.);
	glVertex2f(-80., 1.);
	glVertex2f(-121., 1.);
	glEnd();

	glBegin(GL_LINES);//LINII za lev dzam na kukjata
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-121., 20.);
	glVertex2f(-80., 20.);
	glVertex2f(-101., 1.);
	glVertex2f(-101., 40.);
	glEnd();


	glBegin(GL_LINE_LOOP);//poligon za DESEN dzam na kukjata
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(41., 40.);
	glVertex2f(0., 40.);
	glVertex2f(0., 1.);
	glVertex2f(41., 1.);
	glEnd();

	glBegin(GL_LINES);//LINII za DESEN dzam na kukjata
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(41., 20.);
	glVertex2f(0., 20.);
	glVertex2f(20., 40.);
	glVertex2f(20., 1.);
	glEnd();
	glLineWidth(1.0);
	
	
	glLineWidth(2.0);
	glBegin(GL_LINES);//LINIJA
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-320., -60.);
	glVertex2f(350., -60.);
	glEnd();
	glLineWidth(1.0);


	//drvoto
	glBegin(GL_POLYGON);//poligon steblo
	glColor3f(0.4, 0.2, 0.1);
	glVertex2f(200., -60.);
	glVertex2f(220., -60.);
	glVertex2f(220., 20.);
	glVertex2f(200., 20.);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	MyCircle3f1(210., 90., 70.);//krosnata 


	glColor3f(1.0, 0.0, 0.0);
	MyCircle3f1(190., 91., 10.);//jabuki
	MyCircle3f1(230., 60., 10.);
	MyCircle3f1(180., 50., 10.);
	MyCircle3f1(215., 105., 10.);
	MyCircle3f1(253., 90., 10.);
	MyCircle3f1(219., 129., 10.);
	MyCircle3f1(180., 117., 10.);

	glFlush();
}

int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	// Set the window size
	glutInitWindowSize(1000, 1000);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Hello, UGD STIP");
	// Bind the two functions (above) to respond when necessary
	init();
	//glutReshapeFunc(changeViewPort);
	glutDisplayFunc(Display);

	glutMainLoop();
	return 0;
}