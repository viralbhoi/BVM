#include <windows.h>
#include "glut.h"

int n = 0;
int vx[10], vy[10];
int ind = 0;
float angle = 0;
int h;
float scale = 1;
float add = 0.5;

int opt = 1;

void display()

{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 1, 1);
  glPushMatrix();
  if (opt == 1)
  {
    glTranslatef(vx[0], vy[0], 0);
    glRotatef(angle, 0, 0, 1);
    glScalef(scale, scale, scale);
    glTranslatef(-vx[0], -vy[0], 0);
  }
  else
  {
    float cx = 0;
    float cy = 0;
    int sz = 0;
    for (auto x : vx)
    {
      cx += x;
      if(x!=0){
      sz++;
    }
    }

    for (auto y : vy)
    {
      cy += y;
    }

    glTranslatef((cx / ind),(cy/ind),0);
    glRotatef(angle,0,0,1);
    glScalef(scale,scale,scale);
    glTranslatef(-vx[0],-vy[0],0);
  }

  glBegin(GL_POLYGON);
  for (int i = 0; i < n; i++)
    glVertex2i(vx[i], vy[i]);
  glEnd();
  glPopMatrix();

  glFlush();
}

void keyb(unsigned char key, int x, int y)
{

  if (key == 49)
  {
    angle = angle + 30;
    opt = 1;
    glutPostRedisplay();
  }
  else if (key == 50)
  {
    angle = angle - 30;
    opt = 1;
    glutPostRedisplay();
  }

  else if (key == 51)
  {
    scale = scale + add;
    opt = 1;
    glutPostRedisplay();
  }

  else if (key == 52)
  {
    scale = scale - add;
    opt = 1;
    glutPostRedisplay();
  }

  else if (key == 53)
  {
    scale = scale + add;
    opt = 2;
    glutPostRedisplay();
  }
}

void mouse(int button, int state, int x, int y)
{

  switch (button)
  {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN)
    {
      vx[ind] = x;
      vy[ind] = h - y;
      glBegin(GL_POINTS);
      glVertex2i(vx[ind], vy[ind]);
      glEnd();
      glFlush();
      ind++;
    }

    break;
  case GLUT_RIGHT_BUTTON:
    if (state == GLUT_DOWN)
      n = ind;

    glutPostRedisplay();

    break;

  default:
    break;
  }
}

void reshape(GLsizei width, GLsizei height)
{ // GLsizei for non-negative integer
  // Compute aspect ratio of the new window

  h = height;
  // Set the viewport to cover the new window
  glViewport(0, 0, width, height);

  // Set the aspect ratio of the clipping area to match the viewport
  glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
  glLoadIdentity();            // Reset the projection matrix

  gluOrtho2D(0, width, 0, height);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
void init(void)
{
  glClearColor(0, 0, 0, 0);
  glPointSize(10);

  glPolygonMode(GL_FRONT, GL_LINE);
  glPolygonMode(GL_BACK, GL_LINE);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("my first");

  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyb);
  glutMouseFunc(mouse);

  glutMainLoop();
  return 0;
}