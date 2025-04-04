#include <Windows.h>
#include "glut.h"
#include<cmath>

void circle(double x,double y,double r){
    double theta=0;
    double x0 = x + r*cos(theta*3.14/180);
    double y0 = y + r*sin(theta*3.14/180);
    
        while(theta != 360){
            theta += 0.1;
            x0 = x + r*cos(theta*3.14/180);
            y0 = y + r*sin(theta*3.14/180);

            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
        }
} 

void Display(void)
{
    //clear all pixels with the specified clear color
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    circle(50,50,10);

    //dont wait, start flushing opengl calls to display buffer
    glFlush();
}

void reshape(int w, int h)
{
    // on reshape and on startup, keep the viewport to be the entire size of the window
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // keep our logical coordinate system constant
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init(void)
{
    //set the clear color to be red
    glClearColor(0,0,0,0);
    // set the point size to be 3.0 pixels
    glPointSize(5.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv) ;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(320, 240);
    glutInitWindowPosition(0,0);
    glutCreateWindow("My First OpenGL Window");
    
    init();
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}