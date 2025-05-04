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

void bresline(int xa, int ya, int xb, int yb){
    int c,r,f;
    int dx, dy, d;

    dx = xb - xa;
    dy = yb - ya;

    if(abs(dx)>abs(dy)){
        d = 2*abs(dy)-abs(dx);

        if(dx>0){
              c = xa;
              r = ya;
              f = xb;
                }
        else{
              c = xb;
              r = yb;
              f = xa;
            }
        while(f>c){
                    if(d<0){
                        c = c+1;
                        d = d+2*abs(dy);
                    }
                    else{
                        if(dx>0 && dy>0 || dx<0 && dy<0){
                            c = c+1;
                            r = r+1;
                        }
                        else{
                            c = c+1;
                            r = r-1;
                        }
                        d = d+2*abs(dy)- 2*abs(dx);
                    }
                glVertex2d(c,r);
                }

    }

    else{
        d = 2*abs(dx)-abs(dy);

        if(dy>0){
              c = xa;
              r = ya;
              f = yb;
                }
        else{
              c = xb;
              r = yb;
              f = ya;
            }
        while(f>r){
                    if(d<0){
                        r = r+1;
                        d = d+2*abs(dx);
                    }
                    else{
                        if(dx>0 && dy>0 || dx<0 && dy<0){
                            c = c+1;
                            r = r+1;
                        }
                        else{
                            c = c-1;
                            r = r+1;
                        }
                        d = d+2*abs(dx)- 2*abs(dy);
                    }
                glVertex2d(c,r);
                }
    }
}

void shape(){
    BresCircle(540,360,r);
    BresCircle(540,360,2*r);
    BresCircle(540,360,3*r);
    BresCircle(540,360,4*r);
    BresCircle(540,360,5*r);
    BresCircle(540,360,6*r);
    bresline(540,0,540,720);
    bresline(0,360,1080,360);
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

glutDisplayFunc(Draw);
glutMainLoop();
return 0;
}
