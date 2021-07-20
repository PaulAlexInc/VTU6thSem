#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef GLfloat point[2];
void computeBezPt(float u, point bezCurvePt, int numControlPoints, point *controlPoints, int *C){
    int k;
    float bezBlendFn;
    bezCurvePt[0]=0;
    bezCurvePt[1]=0;
    int n=numControlPoints-1;
    for(k=0;k<numControlPoints;k++){
        bezBlendFn = C[k]*pow(u,k)*pow(1-u,n-k);
        bezCurvePt[0]+=controlPoints[k][0]*bezBlendFn;
        bezCurvePt[1]+=controlPoints[k][1]*bezBlendFn;
        printf("cbez: %d %f %f\n",C[k],bezCurvePt[0],bezCurvePt[1]);
    }
}

void binCoeff(int n, int *C){
    int k,j;
    /*Compute n!/(k!(n-k)!)*/
    for(k=0;k<=n;k++){
        C[k]=1;
        for(j=n;j>=(n-k)+1;j--)
            C[k]*=j;
        for(j=k;j>=2;j--)
            C[k]/=j;
        printf("%d: %d\n",k,C[k]);
    }
}
void bezier(point *controlPoints, int numControlPoints, int nBezierPoints)
{
    point bezCurvePt;
    float u;
    int *C,k;
    C = new int[numControlPoints];
    binCoeff(numControlPoints-1,C);

    glBegin(GL_LINE_STRIP);
    for(k=0;k<nBezierPoints;k++){
        u=(float)k/(float)nBezierPoints;//weighs
        computeBezPt(u, bezCurvePt, numControlPoints,controlPoints,C);
        glVertex2fv(bezCurvePt);
}
glEnd();
delete [] C;
}

void display()
{
    static float theta =0;
    double Pl_rad = ((22.0/7.0)/180.0);
    int numControlPoints = 4;// the number of control points
    int nBezierPoints=20;// the number of points approximated for the bezier curve
    point controlPoints[]= {{20,100},{30,110},{50,90},{60,100}};
    glClear(GL_COLOR_BUFFER_BIT);
    controlPoints[1][0]+=10*sin(theta*Pl_rad);
    controlPoints[1][1]+=5*sin(theta*Pl_rad);
    controlPoints[2][0]+=10*sin((theta+30)*Pl_rad);
    controlPoints[2][1]+=10*sin((theta+30)*Pl_rad);
    controlPoints[3][0]+=4*sin((theta)*Pl_rad);
    controlPoints[3][1]+=sin((theta-30)*Pl_rad);

    theta+=5;//Waving speed

    if(theta>360) theta-=360;
    glPushMatrix();
    glLineWidth(5);
    glColor3f(255.0/255.0,153.0/255.0,51.0/255.0);
    for(int i=0;i<8;i++){
        glTranslatef(0,-0.8,0);
        bezier(controlPoints,numControlPoints,nBezierPoints);
    }

    glColor3f(255.0/255.0,255.0/255.0,255.0/255.0);
    for(int i=0;i<8;i++){
        glTranslatef(0,-0.8,0);
        bezier(controlPoints,numControlPoints,nBezierPoints);
    }

    glColor3f(19.0/255.0,136.0/255.0,8.0/255.0);
    for(int i=0;i<8;i++){
        glTranslatef(0,-0.8,0);
        bezier(controlPoints,numControlPoints,nBezierPoints);
    }

    glPopMatrix();


    //pole
    glColor3f(0.7,0.5,0.3);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(20,100);
    glVertex2f(20,40);
    glEnd();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}


void myinit(){
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,130,0,130);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("Bezier Curve-PaulAlex");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}
