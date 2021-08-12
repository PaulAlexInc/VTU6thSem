#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
int flag_fill=1;
using namespace std;

typedef struct Point point;

struct Point{
    float x,y;
};

void menu (int id){
    switch(id){
        case 0:
            exit(0);
        break;
        case 1:
            flag_fill = 1;
            break;
        case 2:
            flag_fill = 0;
            break;
        case 5:
            flag_fill = 5;
            break;
        case 6:
            flag_fill = 6;
            break;
        case 7:
            flag_fill = 7;
            break;
}
glutPostRedisplay();
}

void edgedetect(point a, point b, int *le, int *re){
    float dx, dy, m;
    if(b.y<a.y){
        point t = a;
        a=b;
        b=t;
    }
    dx = b.x-a.x;
    dy = b.y-a.y;
    if (dx!=0)
        m=dy/dx;
    else
        m=dy;
    /*float mx = 1/m;*/
    cout<<"m"<<m<<"1/m"<<endl;
    cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<endl;

    int x = a.x;
    for(int y = a.y; y<=b.y;y++){//incrementing along the scan line
        if(x<(int)le[y]) le[y]=(int)x;//change
        if(x>(int)re[y]) re[y]=(int)x;//change
        x+=1/m;
    }
}
void scanline(point p1, point p2, point p3, point p4){
    int re[500], le[500];
    for(int i = 0;i<500;i++){
        re[i]=0; le[i]=500;
    }
    edgedetect(p1,p2, le, re);
    edgedetect(p2,p3, le, re);
    edgedetect(p3,p4, le, re);
    edgedetect(p4,p1, le, re);
    glBegin(GL_POINTS);
        for(int y =0; y<500;y++){
            if(le[y]<=re[y]){
                for(int x =(int)le[y];x<=(int)re[y];x++)
                    glVertex2i(x,y);
            }
        }
        glEnd();
}

void display(){
glClear(GL_COLOR_BUFFER_BIT);

point p1, p2, p3, p4;
p1.x=100;
p1.y=200;
p2.x=200;
p2.y=300;
p3.x=300;
p3.y=200;
p4.x=200;
p4.y=100;


if (flag_fill==5){
    glColor3f(1,0,0);
    scanline(p1,p2,p3,p4);
}//red
if (flag_fill==6){
    glColor3f(0,1,0);
    scanline(p1,p2,p3,p4);
}//green
if (flag_fill==7){
    glColor3f(1,1,0);
    scanline(p1,p2,p3,p4);
}//yellow
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(p1.x, p1.y);
glVertex2f(p2.x, p2.y);
glVertex2f(p3.x, p3.y);
glVertex2f(p4.x, p4.y);
glEnd();

glFlush();
}

void myinit(){
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,499,0,499);
glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char *argv[])
{
    glutInit (&argc, argv);
    glutInitWindowSize(500,500);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow ("Scan Line Algorithm - (PAUL ALEX)");
    myinit();
    glutDisplayFunc(display);
    int fill_menu = glutCreateMenu(menu);
    glutAddMenuEntry("Red",5);
    glutAddMenuEntry("Green",6);
    glutAddMenuEntry("Yellow",7);
    glutCreateMenu(menu);
    glutAddMenuEntry("Clear",2);
    glutAddMenuEntry("Quit",0);
    glutAddSubMenu("Fill",fill_menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
