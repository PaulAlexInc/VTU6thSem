/*Draw a colour cube and spin it using OpenGL transformation matrices.*/
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float vertices[][3]={
    {-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1},//z=-1
    {-1,-1,1},{1,-1,1},{1,1,1},{-1,1,1}//z=0
};
float colors[][3]={
    {0,0,0},{1,0,0},{1,1,0},{0,1,0},
    {0,0,1},{1,0,1},{1,1,1},{0,1,1}
};
int axis = 2;// y axis
float theta [] = {0,0,0};//theta x,y,z
void quad(int a, int b, int c, int d){
    glBegin(GL_POLYGON);
        glColor3fv(colors[a]);
        glVertex3fv(vertices[a]);
        glColor3fv(colors[b]);
        glVertex3fv(vertices[b]);
        glColor3fv(colors[c]);
        glVertex3fv(vertices[c]);
        glColor3fv(colors[d]);
        glVertex3fv(vertices[d]);
    glEnd();
}
void cube() {
    glColor3f(1,0,0);

    quad(0,3,2,1);//Face A
    quad(1,2,6,5);//Face B
    quad(4,5,6,7);//Face C
    quad(0,4,7,3);
    quad(2,3,7,6);
    quad(0,1,5,4);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1,0,0);// rotate about x axis
    glRotatef(theta[1], 0,1,0);// rotate about y axis
    glRotatef(theta[2], 0,0,1);// rotate about z axis
    cube();


    glFlush();
    glutSwapBuffers();
}
void myinit(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-5,5,-5,5,-10,10);
glMatrixMode(GL_MODELVIEW);
}
void spinCube(){
        theta[axis]+=0.05;//speed of rotation
        if(theta[axis]>=360)theta[axis]-=360;
        glutPostRedisplay();
}
void mouse(int btn, int state, int x, int y){
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis=0;// x axis
    if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis=1;// y axis
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis=2;// z axis

    glutPostRedisplay();
}
int main (int argc, char ** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE| GLUT_DEPTH); //3D
    glutInitWindowSize(500,500);
    glutCreateWindow ("Color Cube - PAUL ALEX");
    glutDisplayFunc(display);
    glutIdleFunc(spinCube);
    glutMouseFunc(mouse);
    myinit();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
