#include<stdio.h>
#include<GL/glut.h>

int xa, ya, xb, yb;
int clickcount = 0;

int ROUND(float a){
  return (int) (a + 0.5);
}

int bresline(int xa, int ya, int xb, int yb){
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


bresline(xa,ya,xb,ya);
bresline(xb,ya,xb,yb);
bresline(xb,yb,xa,yb);
bresline(xa,yb,xa,ya);

bresline((xb+xa)/2,ya,xb,(yb+ya)/2);
bresline(xb,(yb+ya)/2,(xb+xa)/2,yb);
bresline((xb+xa)/2,yb,xa,(yb+ya)/2);
bresline(xa,(yb+ya)/2,(xb+xa)/2,ya);

bresline((((xb+xa)/2)+xb)/2, (((yb+ya)/2)+ya)/2, (((xb+xa)/2)+xb)/2, (((yb+ya)/2)+yb)/2);
bresline((((xb+xa)/2)+xb)/2, (((yb+ya)/2)+yb)/2,(((xb+xa)/2)+xa)/2, (((yb+ya)/2)+yb)/2);
bresline((((xb+xa)/2)+xa)/2, (((yb+ya)/2)+yb)/2,(((xb+xa)/2)+xa)/2, (((yb+ya)/2)+ya)/2);
bresline((((xb+xa)/2)+xa)/2, (((yb+ya)/2)+ya)/2,(((xb+xa)/2)+xb)/2, (((yb+ya)/2)+ya)/2);



}

void Mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        if(clickcount == 0){
            xa = x;
            ya = 720-y;
            clickcount = 1;
        }
        else {
            xb = x;
            yb = 720-y;
            clickcount = 0;

            glutPostRedisplay();
        }
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
/*
printf("\nEnter 1st points coordinates: ");
scanf("%d%d", &xa , &ya);

printf("\nEnter 2st points coordinates: ");
scanf("%d%d", &xb , &yb);
*/
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(1080,720);
glutCreateWindow("WINDOW");

glClearColor(1,1,1,0);
glColor3f(0,0,0);

gluOrtho2D(0,1080,0,720);

glutDisplayFunc(Draw);
glutMouseFunc(Mouse);
glutMainLoop();
return 0;
}
