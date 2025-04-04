#include <Windows.h>
#include "glut.h"

using namespace std;

void init(){
    glClearColor(0,0,0,0);
    glPointSize(10);
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
    glutCreateWindow("my first");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}