
#include <GL/glut.h> // Vklucuvanje na GLUT
#include <math.h>
#define PI 3.1415926535898
GLint circle_points = 100;
void MyCircle3f(GLfloat centerx, GLfloat centery, GLfloat radius) {
	GLint i;
	GLdouble theta;
	glBegin(GL_POLYGON);

	for (i = 0; i < circle_points; i++)
	{
		theta = 2 * PI * i / circle_points;
		glVertex2f(centerx + radius * cos(theta), centery + radius * sin(theta));
	}
	glEnd();
}

void renderPrimitive(void) {
	glColor3f(0.8, 0.5, 0.0);
	glBegin(GL_POLYGON); // iscrtuvanje na teloto na kukata   
	glVertex3f(2, 1, 0.0); // dolno levo teme   
	glVertex3f(2, 4, 0.0); // gorno levo teme  
	glVertex3f(7, 4, 0.0); // gorno desno teme
	glVertex3f(7, 1, 0.0); // dolno desno teme  	
	glEnd();
	glBegin(GL_POLYGON); // iscrtuvanje na vrata na kukata 
	glColor3f(0.6, 0.0, 0.0);
	glVertex3f(4, 1, 0.0); // dolno levo teme   
	glVertex3f(4, 2, 0.0); // gorno levo teme  
	glVertex3f(5, 2, 0.0); // gorno desno teme
	glVertex3f(5, 1, 0.0); // dolno desno teme  	
	glEnd();

	glBegin(GL_LINE_LOOP); // iscrtuvanje na prozorcite  na kukata 
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(2.5, 2, 0.0); // dolno levo teme   
	glVertex3f(2.5, 3, 0.0); // gorno levo teme  
	glVertex3f(3.5, 3, 0.0); // gorno desno teme
	glVertex3f(3.5, 2, 0.0); // dolno desno teme  

	glEnd();
	glBegin(GL_LINE_STRIP);

	glVertex3f(3, 2, 0.0);
	glVertex3f(3, 3, 0.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(2.5, 2.5, 0.0);
	glVertex3f(3.5, 2.5, 0.0);

	glEnd();

	glBegin(GL_LINE_LOOP); // iscrtuvanje na prozorcite  na kukata 
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(5.5, 2, 0.0); // dolno levo teme   
	glVertex3f(5.5, 3, 0.0); // gorno levo teme  
	glVertex3f(6.5, 3, 0.0); // gorno desno teme
	glVertex3f(6.5, 2, 0.0); // dolno desno teme  

	glEnd();
	glBegin(GL_LINE_STRIP);

	glVertex3f(6, 2, 0.0);
	glVertex3f(6, 3, 0.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(5.5, 2.5, 0.0);
	glVertex3f(6.5, 2.5, 0.0);

	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.35, 0.05); //iscrtuvanje na krovot na kukata
	glVertex3f(1, 4, 0.0); // dolno levo teme   
	glVertex3f(2.5, 7, 0.0); // gorno levo teme  
	glVertex3f(6.5, 7, 0.0); // gorno desno teme
	glVertex3f(8, 4, 0.0); // dolno desno teme  
	glEnd(); // kraj na naredbata za iscrtuvanje	
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.35, 0.05); //iscrtuvanje na odjakot  na kukata
	glVertex3f(1.5, 5, 0.0); // dolno levo teme   
	glVertex3f(1.5, 8, 0.0); // gorno levo teme  
	glVertex3f(2, 8, 0.0); // gorno desno teme
	glVertex3f(2, 6, 0.0); // dolno desno teme  
	glEnd(); // kraj na naredbata za iscrtuvanje	


	glBegin(GL_POLYGON);// iscrtuvanje na stebloto na drvoto .
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(10, 1, 0.0);
	glVertex3f(10.5, 1, 0.0);

	glVertex3f(10.5, 4, 0.0);
	glVertex3f(10, 4, 0.0);
	glEnd();


}   // ovde zavrsuva renderiranjeto na primitivot.

void display(void) {

	glClearColor(0.0, 0.0, 0.0, 0.0); // postavuvanje boja za pozadina   
	glClear(GL_COLOR_BUFFER_BIT); // cistenje na memorijata za boja so bojata za pozadina   
	glLoadIdentity(); // povikuvanje na Identity Matrix za da se ponisti prethodno zacuvanata pozicija na objektite i kamerata   

	glTranslatef(0.0, 0.0, -10.0); // pomestuvanje na scenata 2 edinici nanazad

	renderPrimitive(); // povikuvanje na metod  
	glColor3f(0.0, 0.8, 0.1);// definiranje boja na kruznicata
	MyCircle3f(10.3, 5, 1.5); // povikuvanje na metod
	glColor3f(1.0, 0.0, 0.0);
	MyCircle3f(9.5, 5.4, 0.2);
	glColor3f(1.0, 0.0, 0.0);
	MyCircle3f(10, 5.8, 0.2);
	glColor3f(1.0, 0.0, 0.0);
	MyCircle3f(10.7, 6, 0.2);
	glColor3f(1.0, 0.0, 0.0);
	MyCircle3f(10.18, 5.1, 0.2);
	glColor3f(1.0, 0.0, 0.0);
	MyCircle3f(9.4, 4.3, 0.2);
	glColor3f(1.0, 0.0, 0.0);
	MyCircle3f(10.9, 4.6, 0.2);

	glFlush(); // gi egzekutira OpenGL naredbite vo konecno vreme
}

void reshape(int width, int height)
{
	glViewport(-200, 0, width, height); // odreduvanje na pregledot   
	glMatrixMode(GL_PROJECTION); //povikuvanje na matrica na proekcija   
	glLoadIdentity(); //se povikuva edinecnata matrica za da se ponistat site prethodno zapameteni koordinati na proekcija
	gluPerspective(100, width / height, 1.0, 100.0); // odreduva perspektiva
	glMatrixMode(GL_MODELVIEW); // povikuvanje na MODELVIEW-matricata
}



int main(int argc, char** argv) {
	glutInit(&argc, argv); // inicijalizacija na GLUT   
	glutInitDisplayMode(GLUT_SINGLE); // postavuvanje tip na vizuelizacija   
	glutInitWindowSize(500, 500); // odreduvanje dimenzii na prozorecot vo pikseli   
	glutInitWindowPosition(100, 100); // odreduvanje pocetna lokacija na prozorecot   
	glutCreateWindow("Domasna zadaca"); // kreiranje na prozorecot so konkretno ime

	glutDisplayFunc(display); // povikuvanje na "display" metodot

	glutReshapeFunc(reshape); // povikuvanje na "reshape" metodot      

	glutMainLoop(); // vleguvanje vo glavniot GLUT ciklus
}

