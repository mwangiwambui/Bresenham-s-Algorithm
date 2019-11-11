//Group Members are: Gabriel Wangai - (101536)
					//Naomi Mwangi (101426)
					//Ian Kiragu (99928)
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;
int x00; 
int y00;
int xEnd;
int yEnd;

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode( GL_PROJECTION );
    gluOrtho2D(0,100,0,100);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
	int dx = fabs(xEnd - x00), dy = fabs(yEnd - y00);
	int p = 2 * dy - dx;    
	int x, y;    //the constants have been declared at this section.

	if (x00 > xEnd) { //to determine the direction of the line and swap the values
		x = xEnd;
		y = yEnd;
		xEnd = x00;
	}
	else {
		x = x00;
		y = y00;
	}
	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	glVertex2i(x, y);
	glEnd();

	while (x < xEnd) { //to check if the values of x have reached the end.
		x++;
		if (p < 0) {    //to compute for when p is less than zero
			p = p + 2 * dy;
		}
		else {			//computes for when p is greater then zero
			y++;	
			p = p + 2 * dy - 2 * dx;
		}
		glBegin(GL_POINTS);
		glColor3f(0, 0, 0);
		glVertex2i(x, y);
		glEnd();

	}

	glFlush();

}

int main(int argc, char* argv[])
{
    cout<<"Enter xBegin: ";
	cin >> x00;
	cout << "Enter yBegin: ";
	cin >> y00;
	cout << "Enter xEnd: ";
	cin >> xEnd;
	cout << "Enter yEnd: ";
	cin >> yEnd;

    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("Bresenham's Algo");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}