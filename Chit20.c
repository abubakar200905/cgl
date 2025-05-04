#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xc, yc, r;

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
    int r1, r2;
    r1 = r*2.2;
    r2 = r*1.2;

    glColor3f(0,0,0);
    BresCircle(xc,yc,r);
    glColor3f(1,0,0);
    BresCircle(xc+r1,yc,r);
    glColor3f(0,0,1);
    BresCircle(xc-r1,yc,r);
    glColor3f(1,1,0);
    BresCircle(xc+r1*(-0.5),yc+r2*(-0.866),r);
    glColor3f(0,1,0);
    BresCircle(xc+r1*(0.5),yc+r2*(-0.866),r);
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
glPointSize(7);
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
gluOrtho2D(0,1080,0,720);
glutDisplayFunc(Draw);
glutMouseFunc(Mouse);
glutMainLoop();
return 0;
}
