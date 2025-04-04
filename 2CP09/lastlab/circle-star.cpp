#include <Windows.h>
#include "glut.h"
#include <cmath>
const float PI = 3.14159265;
float angle = 0.0;  
float radius = 0.5; 


void drawOrbit() {
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++) {
        float theta = 2 * PI * i / 100;
        glVertex2f(radius * cos(theta), radius * sin(theta));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawOrbit();

    float x = radius * cos(angle);
    float y = radius * sin(angle);

    glColor3f(1.0, 1.0, 1.0); 
    glPointSize(20.0); 
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    angle += 0.05; 
    if (angle > 2 * PI) angle -= 2 * PI;

    glutPostRedisplay();
    glutTimerFunc(30, update, 0); 
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circular Orbiting Dot");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);

    glutMainLoop();
    return 0;
}
