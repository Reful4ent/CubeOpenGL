
#include <iostream>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#define WIDTH 800
#define HEIGHT 800

float xCheck = 10, yCheck =10, zCheck = 10;
int xMove = 0, yMove = 0, zMove = 0;

GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},
{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0} };

GLfloat colors[][3] = { {0.5,0.0,0.3},{1.0,0.0,0.0},
{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},
{1.0,0.0,1.0},{0.4,0.7,0.8},{0.0,1.0,1.0} };

void RotateCube(unsigned char key, int x, int y) {
    switch (key) {
    case 'z':
        if (zCheck - 1 >= -20) {
            zCheck -= 1;
            glutPostRedisplay();
        }
        else {
            zCheck = 5;
            glutPostRedisplay();
        }
        break;
    case 'x':
        if (zCheck + 1 <= 20)
        {
            zCheck += 1;
            glutPostRedisplay();
        }
        else {
            zCheck = -5;
            glutPostRedisplay();
        }
        break;
    }
}
void RotateCube(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        if ((xCheck - 1)>-20) {
            xCheck -= 0.5;
            glutPostRedisplay();
        }
        else {
            xCheck = 20;
            glutPostRedisplay();
        }
        break;
    case GLUT_KEY_RIGHT:
        if (xCheck + 1 <= 20)
        {
            xCheck += 1;
            glutPostRedisplay();
        }
        else {
            xCheck = 0;
            glutPostRedisplay();
        }
        break;
    case GLUT_KEY_UP:
        if (yCheck - 1 >= -20) {
            yCheck -= 1;
            glutPostRedisplay();
        }
        else {
            yCheck = 5;
            glutPostRedisplay();
        }
        break;
    case GLUT_KEY_DOWN:
        if (yCheck + 1 <= 20)
        {
            yCheck += 1;
            glutPostRedisplay();
        }
        else {
            yCheck = -5;
            glutPostRedisplay();
        }
        break;
    }
}


void reshape(int w, int h) {
    
}

void DrawSurface(int ind1, int ind2, int ind3, int ind4)
{
    glBegin(GL_POLYGON);
    glColor3fv(colors[ind1]);
    glVertex3fv(vertices[ind1]);
    glColor3fv(colors[ind2]);
    glVertex3fv(vertices[ind2]);
    glColor3fv(colors[ind3]);
    glVertex3fv(vertices[ind3]);
    glColor3fv(colors[ind4]);
    glVertex3fv(vertices[ind4]);
    glEnd();
}
void DrawCube()
{
    DrawSurface(0, 3, 2, 1);
    DrawSurface(2, 3, 7, 6);
    DrawSurface(0, 4, 7, 3);
    DrawSurface(1, 2, 6, 5);
    DrawSurface(4, 5, 6, 7);
    DrawSurface(0, 1, 5, 4);
}
void resize(int width, int height)
{

}


void  display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glShadeModel(GL_FLAT);
    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5, 5, -5, 5, 10, 20);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(xCheck, yCheck, zCheck, 0, 0, 0, 0, 0, 1); 
    DrawCube();
    glPopMatrix();
    glutSwapBuffers();

    /*glShadeModel(GL_FLAT);
    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5, 5, -5, 5, 6, 10);
    gluPerspective(45, 2, 5, 7);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    DrawCube();
    glFlush();*/
}
void init(void)
{
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1, 1, 1, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
    int IWidth = GetSystemMetrics(SM_CXSCREEN), IHeight = GetSystemMetrics(SM_CYSCREEN);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowPosition(IWidth / 2 - 400, IHeight / 2 - 400);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Cube");
    glutReshapeFunc(resize);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(RotateCube);
    glutSpecialFunc(RotateCube);
    glutMainLoop();
    return 0;
}

