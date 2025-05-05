// Slip1
#include <GL/glut.h>
#include <stdio.h>

void BresLine(int xa, int ya, int xb, int yb, int type){
    int dx, dy, d;
    int c, r, f;
    dx = xb - xa;
    dy = yb - ya;
    int i = 0;
    printf("Type: %d", type);


    if(abs(dx) > abs(dy)){
        d = 2 * abs(dy) - abs(dx);
        if(dx > 0){
            c = xa;
            r = ya;
            f = xb;
        }else{
            c = xb;
            r = yb;
            f = xa;
        }
        while(f > c){
            if(d < 0){
                c++;
                d = d + 2 * abs(dy);
            }else{
                if(dx > 0 && dy > 0 || dx < 0 && dy < 0){
                    r++;
                }else{
                    r--;
                }
                c++;
                d = d + 2 * abs(dy) - 2 * abs(dx);
            }
            // glVertex2d(c, r);
               // General
        if(type == 0){
            glVertex2d(c, r);
        }    
    
        // Type: Dotted
        if(type == 1){
            if(i % 4 == 0){
                glVertex2d(c, r);
            }
        }

        // Type: Dashed
        if(type == 2){
            if(i % 10  < 5){
                glVertex2d(c, r);
            }
        }

        // Type: Dotted Dash
        if(type == 3){
            if(i % 15 < 5 || (i % 15 > 8 && i % 15 < 10)){
                glVertex2d(c, r);
            }
        }
        i++;
        }
    }else{
        d = 2 * abs(dx) - abs(dy);
        if(dy > 0){
            c = xa;
            r = ya;
            f = yb;
        }else{
            c = xb;
            r = yb;
            f = ya;
        }
        while(f > r){
            if(d < 0){
                r++;
                d = d + 2 * abs(dx);
            }else{
                if(dx > 0 && dy > 0 || dx < 0 && dy < 0){
                    c++;
                }else{
                    c--;
                }
                r++;
                d = d + 2 * abs(dx) - 2 * abs(dy);
            }
            // General
        if(type == 0){
            glVertex2d(c, r);
        }    
    
        // Type: Dotted
        if(type == 1){
            if(i % 4 == 0){
                glVertex2d(c, r);
            }
        }

        // Type: Dashed
        if(type == 2){
            if(i % 10  < 5){
                glVertex2d(c, r);
            }
        }

        // Type: Dotted Dash
        if(type == 3){
            if(i % 15 < 5 || (i % 15 > 8 && i % 15 < 10)){
                glVertex2d(c, r);
            }
        }
        i++;
        }
    }
}


void Draw(){
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2d(-320, 100);

    // Window
    BresLine(-320, 0, 320, 0, 0);
    BresLine(0, -240, 0, 240, 0);

    BresLine(0, 0, -200, 100, 0);
    BresLine(0, 0, -200, 120, 1);
    BresLine(0, 0, -200, 140, 2);
    BresLine(0, 0, -200, 160, 3);



    
    glEnd();
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("1");
    glutInitWindowPosition(0, 0);
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0, 0, 0);
    gluOrtho2D(-320, 320, -240, 240);
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}