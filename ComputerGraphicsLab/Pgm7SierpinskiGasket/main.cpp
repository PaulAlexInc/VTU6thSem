
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

typedef float point[3];
int m=0;
point v[] = {{0,0,1},{-1,-1,-1}, {1,-1,-1},{0,1,-1}};

void display_triangle(point a, point b, point c){
    glBegin(GL_POLYGON);
        glVertex3fv(a);
        glVertex3fv(b);
        glVertex3fv(c);
    glEnd();
}
void divide_triangle(point a, point b, point c, int k){
    if (k>0){
        point v1,v2,v3;
        //midpoint of a and b
        v1[0] = (a[0]+b[0])/2;//x
        v1[1] = (a[1]+b[1])/2;//y
        v1[2] = (a[2]+b[2])/2;//z
        //midpoint of a and c
        v2[0] = (a[0]+c[0])/2;//x
        v2[1] = (a[1]+c[1])/2;//y
        v2[2] = (a[2]+c[2])/2;//z
        //midpoint of b and c
        v3[0] = (b[0]+c[0])/2;//x
        v3[1] = (b[1]+c[1])/2;//ys
        v3[2] = (b[2]+c[2])/2;//z

        divide_triangle(a, v1,v2, k-1);
        divide_triangle(b, v1,v3, k-1);
        divide_triangle(c, v2,v3, k-1);
    }else
        display_triangle(a,b,c);
}
void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glColor3f(0,1,0);
divide_triangle(v[1],v[2],v[3],m); //bottom face

glColor3f(1,0,0);
divide_triangle(v[0],v[1],v[2],m);

glColor3f(0,0,1);
divide_triangle(v[0],v[1],v[3],m);

glColor3f(1,1,0);
divide_triangle(v[0],v[2],v[3],m);

glFlush();
}


void myinit(){
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2,2,-2,2,-2,2);
glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char ** argv)
{
    printf("Enter the number of subdivisions m\n");
    scanf("%d", &m);
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB| GLUT_DEPTH); //3D
    glEnable(GL_DEPTH_TEST);// Very important in case of Linux systems
    glutInitWindowSize(500,500);
    glutCreateWindow ("Sierpinski - PAUL ALEX");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}

