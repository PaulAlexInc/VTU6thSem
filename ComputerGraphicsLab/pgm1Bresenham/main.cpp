using namespace std;
#include<iostream>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

float xa,ya,xb,yb;
void draw_pixel(float x,float y){
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}
void bres(float xa, float ya, float xb, float yb){
    int inc=1;
    float x=xa,y=ya;
    float dx,dy, m;
    float p = 2*dy-dx;
    dx=xb-xa;
    dy=yb-ya;
    m=dy/dx;//calculating slope
    dx=fabs(dx);
    dy=fabs(dy); //make sure dx and dy are absolute
    cout<<"m "<<m;
    if (m<0)
        inc=-1;// negative slope

    if(fabs(m)<1){
        if(xb<xa){x=xb;y=yb;}//to ensure starting point is leftmost if it is a gradual slope
        draw_pixel(x,y);
        for(int i=0;i<dx;i++){
            x++;
            if(p<0)
                p+=2*dy;
            else{
                p+=2*dy-2*dx;
                y+=inc;
            }
            draw_pixel(x,y);
        }
    }
    else{//steep slope
         if(yb<ya){x=xb;y=yb;}//to ensure starting point is leftmost if it is a gradual slope
        draw_pixel(x,y);
        for(int i=0;i<dy;i++){
            y++;
            if(p<0)
                p+=2*dx;
            else{
                p+=2*dx-2*dy;
                x+=inc;
            }
            draw_pixel(x,y);//plotting the first point
        }
    }
}
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    bres(xa,ya,xb,yb);
    glColor3f(0,0,1);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(xa,ya);
    glVertex2f(xb,yb);
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
int main(int argc, char** argv){
    cout<<"Enter two points (xa,ya), (xb, yb)";
    cin>>xa>>ya>>xb>>yb;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham_PAULALEX");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}
