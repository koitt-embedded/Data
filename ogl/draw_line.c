#include <GL/glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);     // mode 선택
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);	
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(200, 200);
	glutCreateWindow("Draw Line");
	
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}
