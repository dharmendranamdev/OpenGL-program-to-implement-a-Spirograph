#include <GL/glut.h>
#include <math.h>
#include<iostream>
using namespace std;
double R ;//Radius of Outer Circle
double r; //Radius of Inner Circle
double p; //point A lying somewhere inside the Inner C_{i} is
// located a distance p < r from center of inner circle.
void myinit(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D (0.0,640.0,0.0,480.0);
 }

void setPixel(GLint x,GLint y)//Plot The Pixel
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
  glutSwapBuffers();
}
void circleMidPoint()
{
    double xCenter = 380; //center of Outer Circle C(xCenter, yCenter)
    double yCenter = 250;

    double k = r / R;
    double l = p / r;

    double t; //t is a angle ...Which changes according to inner circle moving inside the Bigger(Outer) Circle
    double x1 = R * ((1-k)*cos(t) +  l*k *cos(  ((1-k) / k) * t));
    double y1 =  R * ((1-k)*sin(t) -  l*k *sin( ((1-k) / k) * t));
    double x,y;
    t = 0.05;
    do
    {
        //
        x = R * ((1-k)*cos(t) + l*k *cos(  ((1-k) / k) * t));
        y =  R * ((1-k)*sin(t) -  l*k *sin( ((1-k) / k) * t));

         setPixel(xCenter + x, yCenter + y);
         setPixel(xCenter + x1, yCenter + y1);
         x1 = x;
         y1 = y;
         t  += 0.05;

    }
     while(t < 800);
    glFlush();
}
void display()
{

     glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
     glColor3f(1.0,0.0,0.0);          // red foreground
     glPointSize(2.0);               // size of points to be drawing (in pixel)

     //establish a coordinate system for the image
     circleMidPoint();
     glFlush();
}

int main(int argc,char** argv)
{
    cout<<" Radius of Outer circle : ";
    cin>>R;
    cout<<" \nRadius of inner circle : ";
    cin>>r;
    cout<<" \nDistance of point : ";
    cin>>p;
	glutInit(&argc,argv);
    glutInitWindowSize(700,400); // set the size of the window
    glutInitWindowPosition(10,10); // the position of the top-left of window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
	myinit();
    glutDisplayFunc(display); // set the gl display callback function
    glutMainLoop(); // enter the GL event loop

}
