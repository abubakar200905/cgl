#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>

int v; 
int input[2][10];
float bcol[3];
float fcol[3];
int x, y;

int xa, ya, xb, yb;
int ROUND(float a){
    return (int)(a+0.5);
}

void dda(int xa, int ya, int xb, int yb){
    int dx, dy, steps;
    dx = xb - xa;
    dy = yb - ya;

    if(abs(dx)>abs(dy)){
        steps = abs(dx);
    }
    else{
        steps = abs(dy);
    }

     float xinc, yinc;

    xinc = (float)dx/steps;
    yinc = (float)dy/steps;
    
    float x = xa;
    float y = ya;

    for(int i = 0; i<steps; i++){
        glBegin(GL_POINTS);
        x = x + xinc;
        y = y + yinc;
        glVertex2d(ROUND(x), ROUND(y));
    }
    glEnd();
}

void bfill(int x, int y, float bcol[3], float fcol[3]){
    float current[3];
    glReadPixels(x, y,1.0, 1.0, GL_RGB, GL_FLOAT, current);
    
    

    if((bcol[0] != current[0] || bcol[1] != current[1] || bcol[2] != current[2]) && 
    (fcol[0] != current[0] || fcol[1] != current[1] || fcol[2] != current[2]))
    {
        glColor3f(fcol[0], fcol[1], fcol[2]);
        glBegin(GL_POINTS);
        glVertex2d(x,y);
        glEnd();
        glFlush();

        bfill(x+1, y, bcol, fcol);
        bfill(x-1, y, bcol, fcol);
        bfill(x, y+1, bcol, fcol);
        bfill(x, y-1, bcol, fcol);

    }
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    
    int i;
    for(i = 0; i < v-1; i++){
        dda(input[0][i],input[1][i],input[0][i+1], input[1][i+1]);
    }
    dda(input[0][i], input[1][i], input[0][0], input[1][0]);
    
    glEnd();
    glFlush();

    bfill(x, y, bcol, fcol);
}

int main(int argc, char** argv) {
    printf("Enter no of vertices: ");
    scanf("%d", &v);

    for(int i = 0; i < v; i++){
        printf("Enter x,y: ");
        scanf("%d %d", &input[0][i], &input[1][i]);
    }

    printf("\nBoundary color: ");
    for(int i =0 ; i<3; i++){
        scanf("%f", &bcol[i]);
    }

    printf("\nFill color: ");
    for(int i =0 ; i<3; i++){
        scanf("%f", &fcol[i]);
    }

    printf("Seed Points (x,y): ");
    scanf("%d %d", &x, &y);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("DDA");
    glClearColor(0,0,0,0);
    
    gluOrtho2D(0,640,0,480);
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
