#include <Windows.h>
#include "glut.h"
#include <iostream>
#include <fstream>
#include <cmath>

float angleX = 0.0f, angleY = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

 
    gluLookAt(0.0, 0.0, 5.0,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0); 

    glColor3f(1.0, 1.0, 1.0);  
    glutSolidSphere(1.0, 70, 50); 

    glutSwapBuffers();
}


void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Sphere - OpenGL");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); 

    glutMainLoop();
    return 0;
}