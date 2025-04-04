#include <Windows.h>
#include "glut.h"
#include <cmath>


float cycleX = -1.0; 
float speed = 0.01;  


void drawCircle(float x, float y, float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159265f * i / 100;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawCycle(float x) {
    glColor3f(1.0, 1.0, 1.0); 

    
    drawCircle(x - 0.2, -0.3, 0.1); 
    drawCircle(x + 0.2, -0.3, 0.1); 

    
    glBegin(GL_LINES);
    glVertex2f(x - 0.2, -0.3); glVertex2f(x, -0.1);
    glVertex2f(x + 0.2, -0.3); glVertex2f(x, -0.1); 
    glVertex2f(x, -0.1); glVertex2f(x + 0.05, 0.05); 
    glVertex2f(x + 0.05, 0.05); glVertex2f(x + 0.15, 0.1); 
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    
    drawCycle(cycleX);

    glutSwapBuffers();
}

void update(int value) {
    cycleX += speed; 
    if (cycleX > 1.2) cycleX = -1.2; 

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
    glutCreateWindow("Moving Cycle");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);

    glutMainLoop();
    return 0;
}
