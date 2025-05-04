#define GL_SILENCE_DEPRECATION
#include<GLUT/glut.h>
#include<stdlib.h>
#include<stdio.h>

int input[2][10];
int v,x,y;
float bcol[3];
float backcol[3];
float fcol[3];

void FloodFill(int x,int y,float backcol[3],float fcol[3])
{
	float current[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,current);
	
	if((current[0]==backcol[0] && current[1]==backcol[1] && current[2]==backcol[2] ) && (current[0]!=fcol[0] || current[1]!=fcol[1] || current[2]!=fcol[2] ) )
	{
		glColor3f(fcol[0],fcol[1],fcol[2]);
		glBegin(GL_POINTS);
		glVertex2d(x,y);
		glEnd();
		glFlush();
		
		FloodFill(x+1,y,backcol,fcol);
		FloodFill(x-1,y,backcol,fcol);
		FloodFill(x,y+1,backcol,fcol);
		FloodFill(x,y-1,backcol,fcol);
	}
}

int ROUND(float a)
{
	return (int) (a+0.5);
}
void DDA(int xa, int ya,int xb, int yb)
{
	int dx,dy,steps;
	dx=xb-xa;
	dy=yb-ya;
	
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
	}
	
	float xinc,yinc;
	xinc=(float)dx/steps;
	yinc=(float)dy/steps;
	
	glVertex2d(xa,ya);
	
	float x=xa,y=ya;
	for (int i=0;i<steps;i++)
	{
		x=x+xinc;
		y=y+yinc;
		glVertex2d(ROUND(x),ROUND(y));
	}
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	int i;
	for (i=0;i<v-1;i++)
	{	
		
		
		DDA(input[0][i],input[1][i],input[0][i+1],input[1][i+1]);
	}
	
		DDA(input[0][i],input[1][i],input[0][0],input[1][0]);
		
	glEnd();
	glFlush();
	
	FloodFill( x,y,backcol,fcol);
	
}

int main(int argc,char **argv)
{
	printf("\nEnter no of Vertices: ");
	scanf("%d",&v);
	
	for(int i=0;i<v;i++)
	{
		printf("\nX[%d]: ",i+1);
		scanf("%d",&input[0][i]);
		printf("\nY[%d]: ",i+1);
		scanf("%d",&input[1][i]);
	}
	
	printf("\nEnter Inside Point: ");
	scanf("%d%d",&x,&y);
	
	for(int i=0;i<3;i++)
	{
		printf("\nBackgrount Color: ");
		scanf("%f",&backcol[i]);
	}
	
	for(int i=0;i<3;i++)
	{
		printf("\nFill Color: ");
		scanf("%f",&fcol[i]);
	}
	

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("Flood Filling");
	glClearColor(backcol[0],backcol[1],backcol[2],0);
	glColor3f(0,0,0);
	gluOrtho2D(0,640,0,480);
	glutDisplayFunc(Draw);
	glutMainLoop();
	
	return 0;
}