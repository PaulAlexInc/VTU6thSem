#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

float theta = 30;
float thetar = ((22.0/7)/180)*theta; //in radiants
float m,n;
int h=100, k=100;//fixed points

float tri[3][3]={{100,200,300}, //row 0
                {100,300,100}, //row 1
                {1,1,1}};//row 2

float rot_mat[3][3]={{0},{0},{0}};
float res[3][3]={{0},{0},{0}};

void multiply(){

    int i,j,l, s=0;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            s=0;
            for(l=0;l<3;l++){
                s=s+rot_mat[i][l]*tri[l][j];
            }
            res[i][j]=s;
        }
    }
}
void rot_mat_setup(){
    rot_mat[0][0]= cos(thetar);
    rot_mat[0][1]=-sin(thetar);
    rot_mat[0][2]= m;
    rot_mat[1][0]=sin(thetar);
    rot_mat[1][1]=cos(thetar);
    rot_mat[1][2]= n;
    rot_mat[2][0]= 0;
    rot_mat[2][1]= 0;
    rot_mat[2][2]= 1;

}
void display_tri(float tri[3][3]){
glBegin(GL_LINE_LOOP);
glVertex2f(tri[0][0], tri[1][0]); // point (100,100)
glVertex2f(tri[0][1], tri[1][1]); // point (200,300)
glVertex2f(tri[0][2], tri[1][2]); // point (300,100)
cout<<tri[2][0]<<tri[1][2]<<endl;
glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    // original Triangle
    glColor3f(1,0,0);
    display_tri(tri);

    //rotate about origin
    m=0; n=0;
    rot_mat_setup();
    glColor3f(1,1,0);//yellow
    multiply();
    display_tri(res);

    //rotate about a fixed point
    m=-h*(cos(thetar)-1)+k*(sin(thetar));
    n=-k*(cos(thetar)-1)-h*(sin(thetar));

    rot_mat_setup();
    multiply();
    glColor3f(0,1,0);
    display_tri(res);
    glFlush();
}


void myinit(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,499,0,499);
glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char ** argv)
{
glutInit (&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition (50, 50);
glutInitWindowSize (500,500);
glutCreateWindow ("Rotation about origin and fixed point - (PAUL ALEX)");
myinit();
glutDisplayFunc (display);
glutMainLoop ( );
return 0;
}

