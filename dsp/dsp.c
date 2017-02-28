#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include <GL/glut.h>

#define SLICE	36

float common_angles[5] = {15.0, 30.0, 45.0, 60.0, 75.0};
float freq_table[5] = {1000.0, 2400.0, 5000.0, 24000.0, 77000.0};

float rotate = 0.0;
float start = 0.0;

void draw_sinewave(void)
{
	float radius = 3.0;
	float x2 = 0, y2, cx, cy, fx, fy;
	float cos_y, cache_cos_y;
	int cache = 0;
	start += 1.0;

	if(start > 360)
		start = 0;

	glBegin(GL_LINES);
	float angle = 0;
	for(angle = start; ; angle += 1.0)
	{
		if(angle > 1020)
		{
			break;
			angle = 0.0;
		}

		float rad_angle = angle * (M_PI / 180.0);
		x2 += 0.1;
		y2 = radius * sin((double)rad_angle);
		cos_y = radius * sin((double)-rad_angle);

		if(cache)
		{
			glVertex2f(cx, cy);
			glVertex2f(x2, y2);

			//glVertex2f(cx, cache_cos_y);
			//glVertex2f(x2, cos_y);
		}
#if 0
		else
		{
			fx = x2;
			fy = y2;
		}
#endif

		cache = 1;
		cx = x2;
		cy = y2;
		cache_cos_y = cos_y;
	}
	glEnd();
}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(10);
	glLoadIdentity();
	glTranslatef(-40, 0, -30);
	glColor3f(1, 0, 0);

	draw_sinewave();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
	}
}

void set_rand_amplitude(float *amp)
{
	*amp = rand() % 3 + 3;
}

void set_angle_with_common_angles(float *angle)
{
	*angle = common_angles[rand() % 5];
}

void angle2radian(float *angle, float *radian)
{
	*radian = *angle * M_PI / 180.0;
}

void radian2angle(float *angle, float *radian)
{
	*angle = *radian * 180.0 / M_PI;
}

void set_rand_frequency(float *freq)
{
	*freq = freq_table[rand() % 5];
}

void calc_period(float *freq, float *period)
{
	*period = 1 / (*freq);
}

void calc_angular_velocity(float *freq, float *ang_vel)
{
	*ang_vel = 2 * M_PI * (*freq);
}

float get_step(float slice, float period)
{
	return period / slice;
}

void cos_sim(float amplitude, float ang_vel, float period)
{
	int cnt = 0;
	float step, time = 0.0;

	time = step = get_step(SLICE, period);

	while(cnt++ < 36)
	{
		printf("%.1fcos(%f * %.8f) = %f\n", amplitude, ang_vel,
			time, amplitude * cos(ang_vel * time));
		time += step;
	}
}

void sin_sim(float amplitude, float ang_vel, float period)
{
	int cnt = 0;
	float step, time = 0.0;

	time = step = get_step(SLICE, period);

	while(cnt++ < 36)
	{
		printf("%.1fsin(%f * %.8f) = %f\n", amplitude, ang_vel,
			time, amplitude * sin(ang_vel * time));
		time += step;
	}
}

int main(int argc, char **argv)
{
	float amplitude, angle, period, frequency, radian, angular_velocity;
	float step = 0.0;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Digital Signal Processing");

	srand(time(NULL));

	set_rand_amplitude(&amplitude);
	set_angle_with_common_angles(&angle);
	angle2radian(&angle, &radian);
	set_rand_frequency(&frequency);
	calc_period(&frequency, &period);
	calc_angular_velocity(&frequency, &angular_velocity);

	printf("amplitude = %f\n", amplitude);
	printf("angle = %f degree\n", angle);
	printf("radian = %f\n", radian);
	printf("frequency = %f\n", frequency);
	printf("period = %f\n", period);
	printf("angular_velocity = %f\n", angular_velocity);

	cos_sim(amplitude, angular_velocity, period);
	sin_sim(amplitude, angular_velocity, period);

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
