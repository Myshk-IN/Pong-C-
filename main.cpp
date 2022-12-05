#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>  
#include <ctime>
#include <cstdlib>

using namespace std;

int leftX1 = -370;
int leftX2 = -358;
int leftY1 = 35;
int leftY2 = -35;

int rightX1 = 370;
int rightX2 = 358;
int rightY1 = 35;
int rightY2 = -35;


float a=3.9;//x
float b=3.9;//y

int scoreL=0;
int scoreR=0;



struct Points
{
    float speedX;
    float speedY;
    float posX=0;
    float posY=0;


} p[1];




void Rectangles ()
{
    //rectangle on the left side
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2i(leftX1,leftY1);
    glVertex2i(leftX2,leftY1);
    glVertex2i(leftX2,leftY2);
    glVertex2i(leftX1,leftY2);
    glEnd();

    //rectangle onМиндовг the right side
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2i(rightX1,rightY1);
    glVertex2i(rightX2,rightY1);
    glVertex2i(rightX2,rightY2);
    glVertex2i(rightX1,rightY2);
    glEnd();
}

void Point()
{
    //Point
    glPointSize(20);
    glBegin(GL_POINTS);
    glColor3f (1,1,1);
    glVertex2i(p[0].posX,p[0].posY);
    glEnd();

}

void PointMove()
{
    p[0].speedX=a;
    p[0].speedY=b;

    p[0].posX+=p[0].speedX;
    p[0].posY+=p[0].speedY;

    //if the sqaure reaches the sticks
  /*  for(float i=leftY2; i<=leftY1; i+=0.2)
    {
        if(p[0].posY>=i && p.[0].posY<=left && p[0].posX<=leftX2+10)
        {
            a*=-1;
            //b*=-1;
            scoreL++;
            break;
        }
    } */

    //right
    if(p[0].posY>=leftY2 && p[0].posY<=leftY1 && p[0].posX<=leftX2+20/2)
    {
            a*=-1;
            //b*=-1;


    }

    /*for(int i=rightY2; i<=rightY1; i++)
    {
        if(p[0].posY==i && p[0].posX==rightX2-20/2)
        {
            a*=-1;
            //b*=-1;

            break;
        }
    }*/

    if(p[0].posY>=rightY2 && p[0].posY<=rightY1 && p[0].posX>=rightX2-20/2)
    {
            a*=-1;
            //b*=-1;

    }


    //if the sqaure reaches the frame
    if(p[0].posX>=380-20/2)
    {
       p[0].posX=0;
       p[0].posY=0;
       scoreL++;
       a*=-1;
    }
    else if(p[0].posX<=-380+20/2)
    {
        p[0].posX=0;
        p[0].posY=0;
        scoreR++;
        a*=-1;
    }

    if(p[0].posY>=280-20/2)
    {
        b*=-1;
    }
    else if(p[0].posY<=-280+20/2)
    {
        b*=-1;
    }

}

void Score()
{
    //for the LEFT side
    switch (scoreL)
    {

    case 0:
        glLineWidth(5);
        glBegin(GL_LINE_LOOP);
        glColor3f(1,1,1);
        glVertex2f(-40,250);
        glVertex2f(-20,250);
        glVertex2f(-20,200);
        glVertex2f(-40,200);
        glEnd();
        break;

    case 1:
        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,250);
        glVertex2f(-40,200);
        glEnd();
        break;

    case 2:
        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,250);
        glVertex2f(-20,250);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,250);
        glVertex2f(-20,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,225);
        glVertex2f(-40,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,225);
        glVertex2f(-40,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,200);
        glVertex2f(-20,200);
        glEnd();
        break;

    case 3:

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,250);
        glVertex2f(-20,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,250);
        glVertex2f(-40,250);
        glEnd();


        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,225);
        glVertex2f(-40,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,200);
        glVertex2f(-40,200);
        glEnd();
        break;

    case 4:

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,250);
        glVertex2f(-40,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,225);
        glVertex2f(-20,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,250);
        glVertex2f(-20,200);
        glEnd();
        break;

    case 5:
        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,250);
        glVertex2f(-20,250);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,250);
        glVertex2f(-40,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,225);
        glVertex2f(-40,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,225);
        glVertex2f(-20,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,200);
        glVertex2f(-20,200);
        glEnd();
        break;

    case 6:


        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,250);
        glVertex2f(-40,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,250);
        glVertex2f(-20,250);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINE_LOOP);
        glColor3f(1,1,1);
        glVertex2f(-40,225);
        glVertex2f(-20,225);
        glVertex2f(-20,200);
        glVertex2f(-40,200);
        glEnd();
        break;

    case 7:

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-20,250);
        glVertex2f(-20,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(-40,250);
        glVertex2f(-20,250);
        glEnd();
        break;
    }


    //for the RIGHT side
    switch(scoreR)
    {
    case 0:
        glLineWidth(5);
        glBegin(GL_LINE_LOOP);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(20,250);
        glVertex2f(20,200);
        glVertex2f(40,200);
        glEnd();
        break;

    case 1:
        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(40,200);
        glEnd();
        break;

    case 2:
        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(20,250);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(40,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(20,225);
        glVertex2f(40,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(20,225);
        glVertex2f(20,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,200);
        glVertex2f(20,200);
        glEnd();
        break;
    case 3:

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(40,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(20,250);
        glVertex2f(40,250);
        glEnd();


        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(20,225);
        glVertex2f(40,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(20,200);
        glVertex2f(40,200);
        glEnd();
        break;

    case 4:

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(20,250);
        glVertex2f(20,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,225);
        glVertex2f(20,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(40,200);
        glEnd();
        break;

    case 5:
        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(20,250);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(20,250);
        glVertex2f(20,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(20,225);
        glVertex2f(40,225);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,225);
        glVertex2f(40,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,200);
        glVertex2f(20,200);
        glEnd();
        break;

    case 6:


        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(20,250);
        glVertex2f(20,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(20,250);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINE_LOOP);
        glColor3f(1,1,1);
        glVertex2f(40,225);
        glVertex2f(20,225);
        glVertex2f(20,200);
        glVertex2f(40,200);
        glEnd();
        break;

    case 7:

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(40,200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(40,250);
        glVertex2f(20,250);
        glEnd();
        break;
    }


}

void ManoVaizdas()//Pagrindine paisymo funkcija
{
    glClear(GL_COLOR_BUFFER_BIT);

    //frame
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex2f(-380,280);
    glVertex2f(380,280);
    glVertex2f(380,-280);
    glVertex2f(-380,-280);
    glEnd();

    //middle line
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0,280);
    glVertex2f(0,-280);
    glEnd();

    //rectangles
    Rectangles();

    //point
    Point();
    PointMove();

    //Score
    Score();

    if(scoreL==8)
    {

            a=0;
            b=0;
            p[0].posX=0;
            p[0].posY=0;

            //win
            glLineWidth(3);
            glBegin(GL_LINES);
            glColor3f(1,1,1);
            glVertex2f(-280,250);
            glVertex2f(-265,200);
            glVertex2f(-265,200);
            glVertex2f(-250,250);
            glVertex2f(-250,250);
            glVertex2f(-235,200);
            glVertex2f(-235,200);
            glVertex2f(-220,250);

            glVertex2f(-210,250);
            glVertex2f(-210,200);

            glVertex2f(-200,250);
            glVertex2f(-200,200);
            glVertex2f(-200,250);
            glVertex2f(-170,200);
            glVertex2f(-170,250);
            glVertex2f(-170,200);
            glEnd();

    }
    else if(scoreR==8)
    {

            a=0;
            b=0;
            p[0].posX=0;
            p[0].posY=0;

            //win
            glLineWidth(3);
            glBegin(GL_LINES);
            glColor3f(1,1,1);
            glVertex2f(170,250);
            glVertex2f(185,200);
            glVertex2f(185,200);
            glVertex2f(200,250);
            glVertex2f(200,250);
            glVertex2f(215,200);
            glVertex2f(215,200);
            glVertex2f(230,250);

            glVertex2f(240,250);
            glVertex2f(240,200);

            glVertex2f(250,250);
            glVertex2f(250,200);
            glVertex2f(250,250);
            glVertex2f(280,200);
            glVertex2f(280,250);
            glVertex2f(280,200);
            glEnd();
    }
    //glFlush();//refresh
    glutSwapBuffers();//refresh
    glutPostRedisplay();

}

void init()
{
    glClearColor(0,0,0,0);//background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400,400,-300,300);
}


void SpecKlavishai(int key,int x,int y)
{


    if(key==GLUT_KEY_UP && rightY1<275)
    {
        rightY1+=20;
        rightY2+=20;

    }
    else if(key==GLUT_KEY_DOWN && rightY2>-275)
    {
        rightY1-=20;
        rightY2-=20;

    }

}

void Klavishai(unsigned char key,int x,int y)
{


    if(key=='w' && leftY1<275)
    {
        leftY1+=20;
        leftY2+=20;

    }
    else if(key=='s' && leftY2>-275)
    {
        leftY1-=20;
        leftY2-=20;

    }

}

int main(int arqc, char* arqv[])
{
    srand(time(NULL));

    glutInit(&arqc,arqv);//grafikos inicializacija
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Mano pirma programa");
    glutDisplayFunc(ManoVaizdas);
    glutSpecialFunc(SpecKlavishai);
    glutKeyboardFunc(Klavishai);
    init();
    glutMainLoop();//kaip ciklas

    return 0;
}
