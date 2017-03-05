#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>

GLfloat x_rot = 0.0f;
GLfloat y_rot = 0.0f;
GLfloat z_rot = 0.0f;

void display(void)
{
	GLfloat x,y,z,angle;
	GLfloat sizes[2];
	GLfloat step;
	GLfloat curSize;
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(x_rot, 1.0f, 0.0f, 0.0f);
	glRotatef(y_rot, 0.0f, 1.0f, 0.0f);
	glRotatef(z_rot, 0.0f, 0.0f, 1.0f);
	glGetFloatv(GL_POINT_SIZE_RANGE,sizes);
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);
	curSize = sizes[0];
	z = -50.0f;
	for(angle = 0.0f; angle <= (2.0f*3.1415f)*3.0f; angle += 0.1f)
	{
		x = 50.0f*sin(angle);
		y = 50.0f*cos(angle);
		glPointSize(curSize);
		glBegin(GL_POINTS);
		glVertex3f(x, y, z);
		glEnd();
		z += 0.5f;
		curSize += step;
	}
	glPopMatrix();
	glutSwapBuffers();
}

void setup_rc(void)
{
	glClearColor(0.5f, 0.4f, 0.5f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
}

void keyboard(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
		x_rot -= 5.0f;
	if(key == GLUT_KEY_DOWN)
		x_rot += 5.0f;
	if(key == GLUT_KEY_LEFT)
		y_rot -= 5.0f;
	if(key == GLUT_KEY_RIGHT)
		y_rot += 5.0f;
	if(key == GLUT_KEY_PAGE_UP)
		z_rot -= 5.0f;
	if(key == GLUT_KEY_PAGE_DOWN)
		z_rot += 5.0f;
	glutPostRedisplay();
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
	glutSpecialFunc(keyboard);
	glutDisplayFunc(display);
	setup_rc();
	glutMainLoop();

	return 0;
}
