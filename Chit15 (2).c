#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xa, ya, xb, yb, xc, yc, r;

int ROUND(float a){
  return (int) (a + 0.5);
}

void BresCircle(int xc, int yc, int r){
  int x, y, d;
  x = 0; y = r; d = 3-2*r;

  do{
  glVertex2d(xc+x,yc+y);
  glVertex2d(xc+y,yc+x);
  glVertex2d(xc-x,yc-y);
  glVertex2d(xc-y,yc-x);
  glVertex2d(xc+x,yc-y);
  glVertex2d(xc-x,yc+y);
  glVertex2d(xc-y,yc+x);
  glVertex2d(xc+y,yc-x);

    if(d<0){
      x = x+1;
      d = d+4*x+6;
    }

    else{
      x = x+1;
      y = y-1;
      d = d+4*x-4*y+10;
    }
  }
  while(y>=x);
}

void shape(){
    BresCircle(xc,yc,r);
    BresCircle(xc+2*r,yc,r);
    BresCircle(xc-2*r,yc,r);
    BresCircle(xc+2*r*(0.5),yc+2*r*(0.866),r);
    BresCircle(xc+2*r*(-0.5),yc+2*r*(0.866),r);
    BresCircle(xc+2*r*(-0.5),yc+2*r*(-0.866),r);
    BresCircle(xc+2*r*(0.5),yc+2*r*(-0.866),r);
    BresCircle(xc,yc,2*r);
}

void Mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
            xc = x;
            yc = 720-y;
            glutPostRedisplay();
       }
}

void Draw(){
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
shape();
glEnd();
glFlush();
}

int main(int argc ,char **argv){

printf("\nEnter radius length: ");
scanf("%d", &r);

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(1080,720);
glutCreateWindow("WINDOW");
glClearColor(1,1,1,0);
glColor3f(0,0,0);
gluOrtho2D(0,1080,0,720);
glutMouseFunc(Mouse);
glutDisplayFunc(Draw);
glutMainLoop();
return 0;
}
