#include <Windows.h>
#include "glut.h"
#include <iostream>
#include <fstream>
#include <cmath>

const int MONTHS = 12;
float sales[MONTHS];  // Stores sales for 12 months
float totalSales = 0;

// Function to read sales data from file
void readSalesData() {
    std::ifstream file("sales.txt");
    if (!file) {
        std::cerr << "Error opening sales file!\n";
        exit(1);
    }
    
    totalSales = 0;
    for (int i = 0; i < MONTHS; i++) {
        file >> sales[i];
        totalSales += sales[i];
    }
    file.close();
}

// Function to draw a Pie Chart
void drawPieChart() {
    float startAngle = 0.0;
    glTranslatef(-0.5, 0.5, 0); // Move left to fit bar chart
    for (int i = 0; i < MONTHS; i++) {
        float percentage = (sales[i] / totalSales);
        float endAngle = startAngle + (percentage * 360);

        // Set random color for each slice
        glColor3f((i % 3) * 0.3, (i % 4) * 0.2, (i % 5) * 0.4);
        
        // Draw Pie Slice
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0); // Center
        for (float angle = startAngle; angle <= endAngle; angle += 1.0) {
            float rad = angle * 3.14159265 / 180.0;
            glVertex2f(0.3 * cos(rad), 0.3 * sin(rad)); // Outer edge
        }
        glEnd();

        startAngle = endAngle;
    }
}

// Function to draw a Bar Chart
// void drawBarChart() {
//     float maxSale = 0;
//     for (int i = 0; i < MONTHS; i++) {
//         if (sales[i] > maxSale) maxSale = sales[i];
//     }

//     glTranslatef(0.8, -0.5, 0); // Move right and down for visibility

//     for (int i = 0; i < MONTHS; i++) {
//         float barHeight = sales[i] / maxSale * 0.5; // Normalize height

//         glColor3f(0.2, 0.5, 1.0); // Blue bars
//         glBegin(GL_QUADS);
//         glVertex2f(i * 0.1, 0);
//         glVertex2f(i * 0.1 + 0.08, 0);
//         glVertex2f(i * 0.1 + 0.08, barHeight);
//         glVertex2f(i * 0.1, barHeight);
//         glEnd();
//     }
// }

void drawBarChart() {
    float maxSale = 0;
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] > maxSale) maxSale = sales[i];
    }

    glPushMatrix(); // Save the current transformation
    glTranslatef(-0.4, -0.5, 0); // Move to the left for better visibility

    float barWidth = 1.8 / MONTHS; // Adjust bar width to fit in window
    for (int i = 0; i < MONTHS; i++) {
        float barHeight = sales[i] / maxSale * 0.5; // Normalize height

        glColor3f(0.2, 0.5, 1.0); // Blue bars
        glBegin(GL_QUADS);
        glVertex2f(i * barWidth, 0);
        glVertex2f(i * barWidth + barWidth * 0.8, 0);
        glVertex2f(i * barWidth + barWidth * 0.8, barHeight);
        glVertex2f(i * barWidth, barHeight);
        glEnd();
    }

    glPopMatrix(); // Restore original transformation
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawPieChart();
    drawBarChart();

    glutSwapBuffers();
}

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

// Main function
int main(int argc, char** argv) {
    readSalesData(); // Read sales data

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Annual Sales: Pie & Bar Chart");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
