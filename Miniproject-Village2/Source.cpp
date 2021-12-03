#include<iostream>
#include<stdlib.h>
//#include <stdio.h>
#include<math.h>
//#include<GL/gl.h>
#include<GL/glut.h>
using namespace std;

void myInit() {
	glEnable(GL_DEPTH_TEST);
	gluOrtho2D(0, 1600, 0, 800);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float sun_move = 0.0f;
float cloud_move = 0.0f;
float cloud_move1 = 0.0f;
float cloud_move2 = 0.0f;
float boat_angle = 0.0f;
float speed = 3.0f;

bool start1 = false;
bool start2 = false;
bool start3 = false;
bool start4 = false;
bool start5 = false;

void update1(int value) {
	if (speed > 1 || speed < 0)
	{
		speed = 0.0f;
	}

	boat_angle += speed;
	if (boat_angle > 90) {
		boat_angle -= 200;
	}
	//Tell GLUT to call update again in 20 milliseconds
	glutTimerFunc(20, update1, 0);
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'b': 
		speed += 0.0005f;
		update1(0);
		break;
	case 's': 
		speed -= 0.5f;
		update1(0);
		break;
	}
}

void circle(float x, float y, double r) {
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++) {
		float pi = 3.1416;
		float A = (i * 2 * pi) / 25;
		float x1 = x + ((r - .07) * cos(A));
		float y1 = y + ((r)*sin(A));
		glVertex2f(x1, y1);
	}
	glEnd();
}
/*void drawcircle(float x, float y, double r) {
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++) {
		float pi = 3.1416;
		float A = (i * 2 * pi) / 25;
		float x1 = x + ((r - .09) * cos(A));
		float y1 = y + ((r)*sin(A));
		glVertex2f(x1, y1);
	}
	glEnd();
}
void drawCircle(float x, float y, double r) {
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++) {
		float pi = 3.1416;
		float A = (i * 2 * pi) / 25;
		float x1 = x + ((r - .03) * cos(A));
		float y1 = y + ((r)*sin(A));
		glVertex2f(x1, y1);
	}
	glEnd();
}*/
void sky() {
	glColor3f(0.118, 0.565, 1.000);
	glBegin(GL_QUADS);
	glVertex2f(-1.0, 0.2);
	glVertex2f(-1.0, 1.0);
	glVertex2f(1.0, 1.0);
	glVertex2f(1.0, 0.2);
	glEnd();
}
void river() {
	glColor3f(0.255, 0.412, 0.882);
	glBegin(GL_QUADS);
	glVertex2f(-1.0, -1.0);
	glVertex2f(-1.0, -0.5);
	glVertex2f(1.0, -0.1);
	glVertex2f(1.0, -1.0);
	glEnd();
}
void field() {
	glColor3f(0.420, 0.557, 0.137);
	glBegin(GL_QUADS);
	glVertex2f(-1.0, 0.2);
	glVertex2f(-1.0, -0.5);
	glVertex2f(1.0, -0.1);
	glVertex2f(1.0, 0.2);
	glEnd();
}
void hill() {
	glColor3f(0.627, 0.322, 0.176);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2, 0.2);
	glVertex2f(0.03, 0.5);
	glVertex2f(0.2, 0.2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.05, 0.2);
	glVertex2f(-0.38, 0.45);
	glVertex2f(-0.6, 0.2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.9, 0.2);
	glVertex2f(-0.65, 0.38);
	glVertex2f(-0.5, 0.2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-1.3, 0.2);
	glVertex2f(-0.98, 0.35);
	glVertex2f(-0.90, 0.40);
	glVertex2f(-0.75, 0.20);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0.56, 0.2);
	glVertex2f(0.38, 0.45);
	glVertex2f(0.10, 0.2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0.82, 0.2);
	glVertex2f(0.67, 0.4);
	glVertex2f(0.43, 0.2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1.3, 0.2);
	glVertex2f(0.89, 0.4);
	glVertex2f(0.71, 0.2);
	glEnd();
}
void Tree1() {
	glColor3f(0.38f,0.19f,0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.25, -0.3);
	glVertex2f(-0.25, -0.12);
	glVertex2f(-0.27, -0.12);
	glVertex2f(-0.27, -0.3);
	glEnd();
	glColor3f(0.0, 0.43, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.36, -0.12);
	glVertex2f(-0.26, 0.12);
	glVertex2f(-0.16, -0.12);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.36, -0.04);
	glVertex2f(-0.26, 0.2);
	glVertex2f(-0.16, -0.04);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.36, -0.04);
	glVertex2f(-0.26, 0.28);
	glVertex2f(-0.16, -0.04);
	glEnd();

}
void Tree2() {
	glColor3f(0.38f, 0.19f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05, -0.2);
	glVertex2f(-0.05, 0.00);
	glVertex2f(-0.07, 0.00);
	glVertex2f(-0.07, -0.2);
	glEnd();
	glColor3f(0.0, 0.43, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.18, 0.0);
	glVertex2f(-0.06, 0.24);
	glVertex2f(0.06, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.18, 0.08);
	glVertex2f(-0.06, 0.32);
	glVertex2f(0.06, 0.08);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.18, 0.16);
	glVertex2f(-0.06, 0.4);
	glVertex2f(0.06, 0.16);
	glEnd();

}
void Tree3() {
	glColor3f(0.38f, 0.19f, 0.0f);
	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(0.92,0.0);
	glVertex2f(0.92,0.11);
	glEnd();

	glColor3f(0.0, 0.43, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.98, 0.10);
	glVertex2f(0.92, 0.5);
	glVertex2f(0.86, 0.1);
	glEnd();

}
void Tree4() {
	glColor3f(0.38f, 0.19f, 0.0f);
	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(0.74, 0.0);
	glVertex2f(0.74, 0.11);
	glEnd();

	glColor3f(0.0, 0.43, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.8, 0.10);
	glVertex2f(0.74, 0.5);
	glVertex2f(0.68, 0.1);
	glEnd();

}
void Tree5() {
	glColor3f(0.38f, 0.19f, 0.0f);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(0.56, 0.0);
	glVertex2f(0.56, 0.11);
	glEnd();

	glColor3f(0.0, 0.43, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.62, 0.10);
	glVertex2f(0.56, 0.5);
	glVertex2f(0.5, 0.1);
	glEnd();

}
void Tree6() {
	glColor3f(0.38f, 0.19f, 0.0f);
	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(-0.46, -0.3);
	glVertex2f(-0.46, -0.2);
	glEnd();

	glColor3f(0.0, 0.43, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.52, -0.22);
	glVertex2f(-0.46, -0.0);
	glVertex2f(-0.4, -0.22);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.52, -0.17);
	glVertex2f(-0.46, -0.0);
	glVertex2f(-0.4, -0.17);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.52, -0.12);
	glVertex2f(-0.46, -0.0);
	glVertex2f(-0.4, -0.12);
	glEnd();

}
void house1() {
	glColor3f(0.38f, 0.19f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.95, -0.04);
	glVertex2f(-0.91, 0.10);
	glVertex2f(-0.63, 0.10);
	glVertex2f(-0.59, -0.04);
	glEnd();

	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.89, -0.08);
	glVertex2f(-0.89, -0.20);
	glVertex2f(-0.82, -0.20);
	glVertex2f(-0.82, -0.08);
	glEnd();

	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.81, -0.09);
	glVertex2f(-0.81, -0.320);
	glVertex2f(-0.73, -0.320);
	glVertex2f(-0.73, -0.09);
	glEnd();

	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.72, -0.08);
	glVertex2f(-0.72, -0.20);
	glVertex2f(-0.65, -0.20);
	glVertex2f(-0.65, -0.08);
	glEnd();

	glColor3f(1.0, 0.14, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-0.91, -0.32);
	glVertex2f(-0.91, -0.040);
	glVertex2f(-0.63, -0.040);
	glVertex2f(-0.63, -0.32);
	glEnd();
}
void house2() {
	glColor3f(0.38f, 0.19f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.15, 0.12);
	glVertex2f(0.19, 0.26);
	glVertex2f(0.47, 0.26);
	glVertex2f(0.51, 0.12);
	glEnd();

	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(0.2, -0.01);
	glVertex2f(0.2, 0.10);
	glVertex2f(0.27, 0.10);
	glVertex2f(0.27, -0.01);
	glEnd();

	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(0.39, -0.01);
	glVertex2f(0.39, 0.10);
	glVertex2f(0.46, 0.10);
	glVertex2f(0.46, -0.01);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.29, -0.2);
	glVertex2f(0.29, 0.10);
	glVertex2f(0.37, 0.10);
	glVertex2f(0.37, -0.2);
	glEnd();

	glColor3f(0.0, 0.65, 0.42);
	glBegin(GL_QUADS);
	glVertex2f(0.19, -0.2);
	glVertex2f(0.19, 0.120);
	glVertex2f(0.47, 0.120);
	glVertex2f(0.47,-0.2);
	glEnd();
}
void house3() {
	glColor3f(0.38f, 0.19f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.70, 0.1);
	glVertex2f(-0.66, 0.240);
	glVertex2f(-0.38, 0.240);
	glVertex2f(-0.34, 0.1);
	glEnd();

	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.64, 0.08);
	glVertex2f(-0.64, -0.04);
	glVertex2f(-0.58, -0.04);
	glVertex2f(-0.58, 0.08);
	glEnd();

	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.57, 0.07);
	glVertex2f(-0.57, -0.180);
	glVertex2f(-0.48, -0.180);
	glVertex2f(-0.48, 0.07);
	glEnd();

	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47, 0.08);
	glVertex2f(-0.47, -0.04);
	glVertex2f(-0.4, -0.04);
	glVertex2f(-0.4, 0.08);
	glEnd();

	glColor3f(0.7, 0.14, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-0.38, -0.18);
	glVertex2f(-0.38, 0.10);
	glVertex2f(-0.66, 0.10);
	glVertex2f(-0.66, -0.18);
	glEnd();
}
void Sun() {
	glColor3f(1.000, 0.843, 0.000);
	circle(-0.25, 0.75, 0.18);
}
void Moon() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	circle(0.75, 0.75, 0.18);
	glPopMatrix();
}
void Cloud1() {
	glColor3f(0.80, 0.80, 0.80);
	circle(-0.85, 0.77, 0.15);
	circle(-0.79, 0.70, 0.15);
	circle(-0.70, 0.70, 0.15);
	circle(-0.75, 0.77, 0.15);
}
void Cloud2() {
	glColor3f(0.80, 0.80, 0.80);
	circle(-0.35, 0.77, 0.15);
	circle(-00.45, 0.70, 0.15);
	circle(-0.55, 0.75, 0.15);
	circle(-0.45, 0.80, 0.15);
}
void Cloud3() {
	glColor3f(0.80, 0.80, 0.80);
	circle(-0.07, 0.85, 0.15);
	circle(-0.01, 0.80, 0.15);
	circle(0.08, 0.83, 0.15);
	circle(0.02, 0.85, 0.15);
}
void Boat() {
	glPushMatrix();
	glTranslatef(boat_angle, 0.0, 0.0);
	glColor3f(0.000, 0.000, 0.502);
	glBegin(GL_QUADS);
	glVertex2f(-0.78, -0.89);
	glVertex2f(-0.84, -0.76);
	glVertex2f(-0.40, -0.76);
	glVertex2f(-0.46, -0.89);
	glEnd();
	glColor3f(0.698, 0.133, 0.133);
	glBegin(GL_POLYGON);
	glVertex2f(-0.62, -0.75);
	glVertex2f(-0.88, -0.75);
	glVertex2f(-0.62, -0.56);
	glEnd();
	glColor3f(0.104, 0.310, 0.310);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(-0.58, -0.76);
	glVertex2f(-.58, -.56);
	glEnd();
	glPopMatrix();
}

void menu(int id)
{
	switch (id)
	{
	case 1:
		start2 = true;  break;
	case 2: 
		start1 = true;   break;
	}
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1, 0, 0);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	Tree1();
	Tree2();
	Tree3();
	Tree4();
	Tree5();
	Tree6();
	house1();
	house2();
	house3();
	hill();
	field();
	Boat();
	/////////moving boat//////
	/*glPushMatrix();
	glTranslatef(boat_move, 0.0, 0.0);
	Boat();
	glPopMatrix();
	if (start4 == true) {
		boat_move += .005;
		//if (boat_move > 1.9)
			if (boat_move > 1.0) {
				boat_move = -1.0;
			}
			if (boat_move > .67) {
				start4 = false;
				Boat();
			}
	
				/*if (boat_move > 0.005) {
					boat_move = -1.0;
					if (start5 == true) {
						start4 == false;
					}
					if (start4 == false) {
						
					}
				}
	
	}
	if (start5 == true) {
		start4 = false;
		//Boat();
		
	}*/
	///////// moving cloud/////////
	glPushMatrix();
	glTranslatef(cloud_move, 0.0, 0.0);
	Cloud1();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(cloud_move1, 0.0, 0.0);
	Cloud2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(cloud_move2, 0.0, 0.0);
	Cloud3();
	glPopMatrix();
	cloud_move += .003;
	{
		{
			if (cloud_move > 1.9) {
				cloud_move = -1.0;
			}
		}
	}
	cloud_move1 += .003; {
		if (cloud_move1 > 1.0) {
			cloud_move1 = -1.7;
		}
	}
	cloud_move2 += .003; {
		if (cloud_move2 > 1.5) {
			cloud_move2 = -1.2;
		}
	}

	//////////moving sun/////////
	glPushMatrix();
	glTranslatef(0.0, sun_move, 0.0);
	Sun();
	glPopMatrix();
	if (start3 == true) {
		Moon();
	}
	if (start1 == true) {
		sun_move -= .005;
		if (sun_move < - .67) {
			glDisable(GL_LIGHT0);
			start1 = false;
			start3 = true;
		}
	}
	if (start2 == true) {
		{
			start3 = false;
			glEnable(GL_LIGHT0);
			sun_move += 0.005;
			/*if (sun_move > .30) {
				glEnable(GL_LIGHT0);
			}*/
			if (sun_move > 0) {
				start2 = false;
			}
		}
	}
	
	sky();
	river();
	glutSwapBuffers();

}
void update(int value) {
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 700);
	glutCreateWindow("scenary");
    myInit();
	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(25, update, 0);
	glutCreateMenu(menu);
	glutAddMenuEntry("Day", 1);
	glutAddMenuEntry("Night", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}