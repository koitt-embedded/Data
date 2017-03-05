#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINE_LOOP);
	glVertex3f(100.0, 0.0, 0.0);
	glVertex3f(-100.0, 0.0, 0.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 100.0, 0.0);
	glVertex3f(0.0, -100.0, 0.0);
	glEnd();

	glutSwapBuffers();
}

void setup_rc(void)
{
	glClearColor(0.0f, 0.4f, 0.5f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
}

void reshape(int w, int h)
{
	GLfloat n_range = 100.0f;

	if(h == 0)
		h = 1;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w <= h)
		glOrtho(-n_range, n_range, -n_range * h / w, n_range * h / w, -n_range, n_range);
	else
		glOrtho(-n_range * w / h, n_range * w / h, -n_range, n_range, -n_range, n_range);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(800, 600);
	glutCreateWindow("OGL Drawing Example");
	glutReshapeFunc(reshape);
	//glutSpecialFunc(keyboard);
	glutDisplayFunc(display);
	setup_rc();
	glutMainLoop();

	return 0;
}
