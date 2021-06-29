/*Clip a lines using Cohen-Sutherland algorithm*/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdlib.h>
using namespace std;
#include <iostream>
#define outcode int

int xmin = 50, ymin = 50, xmax = 150, ymax = 150;
double xa,ya,xb,yb;
int RIGHT=8, TOP=4, LEFT=2, BOTTOM=1;

outcode compute_outcode(double x, double y){
    outcode code=0;
    if(x>xmax) code |= RIGHT;
    if(y>ymax) code |= TOP;
    if(x<xmin) code |= LEFT;
    if(y<ymin) code |= BOTTOM;

    return code;
}

void cohen(double x1, double y1,double x2, double y2){
    outcode oc1, oc2, ocOut;
    oc1 = compute_outcode(x1,y1);
    oc2 = compute_outcode(x2,y2);
    cout<<"Outcodes: oc1: "<<oc1<<" oc2: "<<oc2<<endl;

    bool accept=false, done=false;
    do
    {

        if(oc1==0 && oc2==0){
            done = true;accept=true;
        }else if((oc1 & oc2)!=0){
            done=true;
        }else{
            double x,y;//point of intersection
            double dx=x2-x1, dy=y2-y1;
            ocOut = oc1?oc1:oc2;

            if(ocOut & TOP){
                x=x1+dx*(ymax-y1)/dy;
                y=ymax;
            }else if(ocOut & BOTTOM){
                x=x1+dx*(ymin-y1)/dy;
                y=ymin;
            }
            else if(ocOut & RIGHT){
                x=xmax;
                y=y1+dy*(xmax-x1)/dx;
            }
            else if(ocOut & RIGHT){//left
                x=xmin;
                y=y1+dy*(xmin-x1)/dx;
            }
            if(ocOut == oc1){
                x1=x; y1=y;
                oc1 = compute_outcode(x1,y1);
            }
            else{
                x2=x; y2=y;
                oc2 = compute_outcode(x2,y2);
            }
            cout<<"\n(x1,y1): "<<x1<<","<<y1<<"\n(x2,y2): "<<x2<<","<<y2<<endl;
            cout<<"Outcodes: oc1: "<<oc1<<" oc2: "<<oc2<<endl;
        }
    }while(!done);
    glLoadIdentity();//Window
    glTranslatef(150,150,0);
    glScalef(1.5,1.5,1);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(xmin, ymin);
        glVertex2i(xmin, ymax);
        glVertex2i(xmax, ymax);
        glVertex2i(xmax, ymin);
     glEnd();
    if(accept){
        glColor3f(0,1,0);
        glBegin(GL_LINES);
            glVertex2d(x1,y1);
            glVertex2d(x2,y2);
        glEnd();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
        xa=60;ya=100;xb = 80;yb = 120;//completely inside
        //xa=170; ya = 70; xb=190; yb= 130; // completely outside(same region)
        //xa = 60; ya = 120; xb=100, yb=180; // one in one out
       //xa = 30; ya = 100; xb= 80; yb = 30; //both out different region,intersecting window
        //xa= 30; ya = 60; xb = 70; yb=30; // completely outside, different region

    //before Clipping - Window
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(xmin, ymin);
        glVertex2i(xmin, ymax);
        glVertex2i(xmax, ymax);
        glVertex2i(xmax, ymin);
    glEnd();

    //Line before clipping
    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex2d(xa,ya);
        glVertex2d(xb,yb);
    glEnd();
    cohen(xa,ya,xb,yb);
    glFlush();
}

void myinit(){
        glClearColor(1,1,1,1);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0,499,0,499);
        glMatrixMode(GL_MODELVIEW);
}
int main (int argc, char ** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_SINGLE| GLUT_RGB); //3D
    glutInitWindowSize(500,500);
    glutCreateWindow ("Cohen Sutherland - PAUL ALEX");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
