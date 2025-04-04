#include <Windows.h>
#include "glut.h"
#include <iostream>
// #include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <cmath>
using namespace std;

vector<float> sales(12);
#define MONTHS 12
float totalSales = 0;
int displayMode = 0; 

void readSalesData() {
    ifstream file("sales.txt");
    if (!file) {
        cout << "Error opening sales file!\n";
        return;
    }
    
    totalSales = 0;
    for (int i = 0; i < MONTHS; i++) {
        file >> sales[i];
        totalSales += sales[i];
    }
    file.close();
}

void drawPieChart() {
    float theta = 0.0;
    glTranslatef(0, 0, 0); 

    for (int i = 0; i < MONTHS; i++) {
        float percentage = (sales[i] / totalSales);
        float endAngle = theta + (percentage * 360);

        float r = 1.0*(rand() % 100)/100;
        float g = 1.0*(rand() % 100)/100;
        float b = 1.0*(rand() % 100)/100;

        glColor3f(r, g, b);

        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0); 
        for (float i = theta; i <= endAngle; i += 1.0) {
            float rad = i * 3.14159265 / 180.0;
            glVertex2f(0.4 * cos(rad), 0.4 * sin(rad)); 
        }
        glEnd();

        theta = endAngle;
    }
}

void drawBarChart() {
    float maxSale = 0;
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] > maxSale) maxSale = sales[i];
    }

    glPushMatrix(); 
    glTranslatef(-0.9, -0.5, 0); 

    float barWidth = 1.8 / MONTHS; 
    for (int i = 0; i < MONTHS; i++) {
        float barHeight = sales[i] / maxSale * 0.6; 

        glColor3f(0.2, 0.5, 1.0); 
        glBegin(GL_QUADS);
        glVertex2f(i * barWidth, 0);
        glVertex2f(i * barWidth + barWidth * 0.8, 0);
        glVertex2f(i * barWidth + barWidth * 0.8, barHeight);
        glVertex2f(i * barWidth, barHeight);
        glEnd();
    }

    glPopMatrix(); 
}

void menuHandler(int option) {
    if (option == 1) {
        displayMode = 0; 
    } else if (option == 2) {
        displayMode = 1; 
    }
    glutPostRedisplay(); 
}

void createMenu() {
    int menu = glutCreateMenu(menuHandler);
    glutAddMenuEntry("Show Pie Chart", 1);
    glutAddMenuEntry("Show Bar Chart", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    if (displayMode == 0) {
        drawPieChart(); 
    } else {
        drawBarChart(); 
    }

    glutSwapBuffers();
}

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}


int main(int argc, char** argv) {
    readSalesData(); 

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Annual Sales: Pie & Bar Chart");

    init();
    createMenu(); 

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
