// void glutSolidTorus(GLdouble innerRadius,
//     GLdouble outerRadius,
//     GLint nsides, GLint rings);

#include <Windows.h>
#include "glut.h"
#include <cmath>

float angleX = 0.0f, angleY = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);

    // glutSolidTorus(0.4, 0.6, 40,40);
        //     GLdouble outerRadius,
        //     GLint nsides, GLint rings);

        glutWireDodecahedron();
    


    glutSwapBuffers();
}

void keyboard(int key, int, int) {
    if (key == GLUT_KEY_UP) angleX -= 5.0;
    if (key == GLUT_KEY_DOWN) angleX += 5.0;
    if (key == GLUT_KEY_LEFT) angleY -= 5.0;
    if (key == GLUT_KEY_RIGHT) angleY += 5.0;
    glutPostRedisplay();
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
    glutCreateWindow("3D Cube - OpenGL");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboard); 

    glutMainLoop();
    return 0;
}