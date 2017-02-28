#include <GL/glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
	glFlush();
}

void reshape(GLsizei w, GLsizei h)
{
	GLfloat aspect_ratio;

	if(h == 0)
		h = 1;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspect_ratio = (GLfloat)w / (GLfloat)h;

	if(w <= h)
		glOrtho(-100.0, 100.0, 100.0/aspect_ratio, 100.0/aspect_ratio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspect_ratio, 100.0 * aspect_ratio, -100.0, 100.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("OGL Drawing Example");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
