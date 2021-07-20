#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void wall(double thickness)
{
    glPushMatrix();
    glTranslated(0.5,0.5*thickness,0.5);
    glScaled(1.0,thickness,1.0);
    glutSolidCube(1.0);
    glPopMatrix();
}
void tableleg(double thick, double len)
{
    glPushMatrix();
    glTranslated(0,len/2,0);
    glScaled(thick,len,thick);
    glutSolidCube(1.0);
    glPopMatrix();
}
void table(double topwid, double topthick, double legthick, double leglen)
{
    glPushMatrix();
    glTranslated(0,leglen,0);
    glScaled(topwid,topthick,topwid);
    glutSolidCube(1.0);
    glPopMatrix();

    double dist=0.95*topwid/2.0-legthick/2.0;

    glPushMatrix();
    glTranslated(dist,0,dist);
    tableleg(legthick,leglen);

    glTranslated(0,0,-2*dist);
    tableleg(legthick,leglen);

    glTranslated(-2*dist,0,2*dist);
    tableleg(legthick,leglen);

    glTranslated(0,0,-2*dist);
    tableleg(legthick,leglen);
    glPopMatrix();
}

void display()
{
    float light_intensity[]={0.7,0.7,0.7,0.7};
    float light_position[]={2,6,3};

    float mat_ambient_diffuse[]={0.8,0.2,0,1};
    float mat_specular[]={0.7,0.7,0.7,0.7};
    float mat_shininess=50.0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-64/48, 64/48, -1,1,1,50);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(4.3,2,5,0,0,0,0,1,0);//camera angle

    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_intensity);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,mat_ambient_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialf(GL_FRONT,GL_SHININESS,mat_shininess);

    //teapot
    glPushMatrix();
    glTranslated(0.4,0.4,0.37);
    glutSolidTeapot(0.1);
    glPopMatrix();

    //table
    glPushMatrix();
    glTranslated(0.4,0,0.4);
    float mat_ambient_diffuse_tab[]={0.8,0.5,0,1};
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,mat_ambient_diffuse_tab);
    table(0.6,0.07,0.06,0.3);
    glPopMatrix();

    //wall
    glPushMatrix();
    glRotated(90,0,0,1);
    float mat_ambient_diffuse_wall[]={0.5,0.5,0.5,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambient_diffuse_wall);
    wall(0.02);//left wall
    glPopMatrix();

    glPushMatrix();
    glRotated(-90,1,0,0);
    wall(0.02);//right wall
    glPopMatrix();

    glPushMatrix();
    glRotated(0,0,1,0);
    wall(0.02);//floor
    glPopMatrix();

    glFlush();
}


int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutCreateWindow("Teapot - Paul Alex");
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glutMainLoop();
    return 0;
}
