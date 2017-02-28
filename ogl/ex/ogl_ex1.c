#include <GL/glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 0.0, 0.0);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("OGL Drawing Example");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
