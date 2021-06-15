/*Draw a color cube and allow the user to move the camera suitably to experiment with
perspective viewing.*/

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;;
#include<iostream>
int axis=2;// y axis
float theta[] = {0,0,0};//theta x,y,z
float vertices[][3]={
    {-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1},//z=-1
    {-1,-1,1},{1,-1,1},{1,1,1},{-1,1,1}//z=0
};
float colors[][3]={
    {0,0,0},{1,0,0},{1,1,0},{0,1,0},
    {0,0,1},{1,0,1},{1,1,1},{0,1,1}
};
double viewer[] = {0,0,5};//x,y,z
void quad(int a, int b, int c, int d){
    glBegin(GL_POLYGON);
        //glColor3fv(colors[a]);
        glVertex3fv(vertices[a]);
        //glColor3fv(colors[b]);
        glVertex3fv(vertices[b]);
        //glColor3fv(colors[c]);
        glVertex3fv(vertices[c]);
        //glColor3fv(colors[d]);
        glVertex3fv(vertices[d]);
    glEnd();
}
void cube() {
    glColor3f(1,0,0);//red
    quad(0,3,2,1);//Face A

    glColor3f(0,1,0);//green
    quad(1,2,6,5);//Face B

    glColor3f(0,0,1);//blue
    quad(4,5,6,7);//Face C

    glColor3f(1,1,0);//yellow
    quad(0,4,7,3);

    glColor3f(1,0,1);//Magenta
    quad(2,3,7,6);

    glColor3f(0,1,1);//Cyan
    quad(0,1,5,4);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(viewer[0],viewer[1], viewer[2],//eye position
              0,0,0, // at center position
              0,1,0);// up position
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
//glFrustum(-1,1,-1,1,2,20);

gluPerspective(45,1,2,20);
//left, right, bottom, top
// distance to near clipping plane
// distance to far clipping plane
glMatrixMode(GL_MODELVIEW);
}
void keys(unsigned char key, int x, int y){// to change the camera position with the keyboard
    if (key == 'x') viewer[0]-=0.1;//move left
    if (key == 'X') viewer[0]+=0.1;//move right
    if (key == 'y') viewer[1]-=0.1;//move down
    if (key == 'Y') viewer[1]+=0.1;//move up
    if (key == 'z') viewer[2]-=0.1;//move away
    if (key == 'Z') viewer[2]+=0.1;//move closer
    cout<<"viewer(x,y,z)"<<viewer[0]<<","<<viewer[1]<<","<<viewer[2]<<endl;

    glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y){
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis=0;// x axis
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis=1;
    if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis=2;

    theta[axis]+=0.5;
    if(theta[axis]>=360) theta[axis] -= 360;

    cout<<"theta(x,y,z)"<<theta[0]<<","<<theta[1]<<","<<theta[2]<<endl;
    glutPostRedisplay();
}
int main (int argc, char ** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE| GLUT_DEPTH); //3D
    glutInitWindowSize(500,500);
    glutCreateWindow ("perspective viewing - PAUL ALEX");
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutMouseFunc(mouse);
    myinit();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
