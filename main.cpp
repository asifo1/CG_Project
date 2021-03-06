#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


double px = 1090, py = 100,si=90,c_x4=0,c_x3=0,c_x2=0,c_x1=0,fp=0;
int value = 0;
int arx [300],ary[300];
double tp = 0,trinc=0.002; //tree position
int trb = 0;

void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.1); // Set display window colour to white
glMatrixMode(GL_PROJECTION); // Set projection parameters
gluOrtho2D(0.0, 1000.0, 0.0, 600.0);
}



int generate_random(int l, int r) { //this will generate random number in range l and r
    int i;
    int rand_num = (rand() % (r - l + 1)) + l;
    return rand_num;

}


void star(GLfloat x,GLfloat y,double s){
    s = 1/s;
glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d (x+3.5*s, y+6.8*s);
    glVertex2d (x+4.5*s, y+9*s);
    glVertex2d (x+5.5*s, y+6.8*s);
     glVertex2d (x+5.5*s, y+6.8*s);
    glVertex2d (x+8*s, y+6.8*s);
   glVertex2d (x+6.8*s, y+4.5*s);
     glVertex2d (x+8*s, y+2.4*s);
    glVertex2d (x+5.5*s, y+2.4*s);
     glVertex2d (x+4.5*s, y+0*s);
     glVertex2d (x+3.4*s, y+2.4*s);
     glVertex2d (x+1*s, y+2.4*s);
     glVertex2d (x+2.2*s, y+4.5*s);
     glVertex2d (x+1*s, y+6.8*s);
     glVertex2d (x+3.5*s, y+6.8*s);
 glEnd();
}

void putStars(){
    if (value==0){
        value=1;
        int j;
        for(j=0;j<300;j++){
            arx[j] = generate_random(10,999);
            ary[j] = generate_random(200,580);
        }

    }

    int i;
    for (i=0;i<300;i++){
        star(arx[i],ary[i],generate_random(2,4));
    }

}
void house(GLfloat ax,GLfloat by,GLfloat dx,GLfloat roofh){


  //left house
    glColor3ub (0,1, 4);
    glBegin(GL_POLYGON);
    glVertex2d (ax, 0);
    glVertex2d (ax, by);
    glVertex2d (dx, by);
    glVertex2d (dx, 0);
    glEnd();


    //Roof
    glBegin(GL_POLYGON);
    glVertex2d (ax-20, by);
    glVertex2d ((ax+dx)/2, by+roofh);
    glVertex2d (dx+20, by);

    glEnd();
    //Roof
    //left house
}

void circle(GLfloat x,GLfloat y,GLfloat r){
    glBegin(GL_POLYGON);
    int i;
    for(i=0;i<360;i++){
        float theta=i*3.142/180;
        glVertex2f(x+r*cos(theta),y+r*sin(theta));
    }
    glEnd();


}


void fench(GLfloat ax,GLfloat by,GLfloat dx,GLfloat caph){
   house(ax,by,dx,0);
    glBegin(GL_POLYGON);
    glVertex2d (ax, by);
    glVertex2d ((ax+dx)/2, caph);
    glVertex2d (dx, by);
    glEnd();

}

void window(GLfloat ax,GLfloat  ay,GLfloat  by,GLfloat dx){
    glBegin(GL_POLYGON);
    glColor3ub (240,147, 0);
    glVertex2d (ax, ay);
    glVertex2d (dx, ay);
    glVertex2d (dx,by);
    glVertex2d (ax, by);
    glEnd();
}

void window_line(GLfloat xv,GLfloat y1v,GLfloat y2v,GLfloat x1h,GLfloat x2h,GLfloat y1h,GLfloat y2h){
    glColor3ub (1,1, 1);
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex3f(xv, y1v, 0.0);
    glVertex3f(xv, y2v, 0);
    glEnd();


    glColor3ub (1.0,1.0, 0.0);

    glBegin(GL_LINES);
    glVertex3f(x1h, y1h, 0.0);
    glVertex3f(x2h, y1h, 0);
    glEnd();

     glBegin(GL_LINES);
    glVertex3f(x1h, y2h, 0.0);
    glVertex3f(x2h, y2h, 0);
    glEnd();
}

void tree(){
    if (tp>2.5 && trb == 0){
        trinc = -0.002;
        trb = 1;
    }
    else if (tp<-4.5 && trb == 1){
        trinc = 0.002;
        trb = 0;
    }


    tp += trinc;

glColor3f(0,0,0);
     circle(100,130,30);
     circle(50,130,30);
         glColor3ub (19,56, 75);
        circle(124.5,147,40);
        circle(25,140,43);
        glColor3f(0,0,0);

    glBegin(GL_POLYGON);

    glVertex2d (65,100); //a
    glVertex2d (65,200); //b
    glVertex2d (85,200); //c
    glVertex2d (85,100); //d
    glEnd();

    circle(112+tp,210,30);
    circle(75+tp,230,50);
    circle(125+tp,230,30);
     circle(112+tp,250,30);
      circle(85+tp,260,35);
       circle(65+tp,260,30);
       circle(45+tp,230,30);
       circle(58+tp,210,30);

}

void cloud(GLfloat x,GLfloat y,GLfloat s){
    glColor3f(0.94,0.94,0.97);
    circle(100+x*s,300+y*s,30);
    circle(70+x*s,320+y*s,30);
    circle(50+x*s,300+y*s,30);
    circle(32+x*s,285+y*s,30);
    circle(120+x*s,275+y*s,25);
    circle(90+x*s,275+y*s,30);
    circle(62+x*s,285+y*s,35);
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //background
    glColor3ub (19,56, 75);
    glBegin(GL_POLYGON);
    glVertex2d (0, 0);
    glVertex2d (1000, 0);
    glVertex2d (1000, 600);
    glVertex2d (0, 600);
    glEnd();
    //background


if(py>660){
            value = 0;
px = 1090;
 py = 100;
 si=90;
}
else{
    px -= 0.018;
    py += 0.015;
    si-=0.001;
}

glColor3f(0.996, 0.988, 0.843);
circle(px,py,si);
//Moon

    //star
putStars();
//star

double c_speed =0.039;
if(c_x4>268) c_x4 = -875;
c_x4 += c_speed;

if(c_x3>568) c_x3 = -575;
c_x3 += c_speed;


if(c_x2>768) c_x2 = -375;
c_x2 += c_speed;


if(c_x1>978) c_x1 = -200;
c_x1 += c_speed;




cloud(65+c_x1,195,1);
cloud(20+c_x1,190,1);
cloud(230+c_x2,120,1);
cloud(430+c_x3,200,1);
cloud(730+c_x4,150,1);



tree();

    //field
    glColor3ub (0,1, 4);
    glBegin(GL_POLYGON);
    glVertex2d (0, 0);
    glVertex2d (0, 90);
    glVertex2d (80, 110);
    glVertex2d (200, 120);
    glVertex2d (250, 122);
    glVertex2d (275, 120);
    glVertex2d (375, 110);
    glVertex2d (425, 115);
    glVertex2d (480, 110);
    glVertex2d (600, 120);
    glVertex2d (650, 122);
    glVertex2d (675, 120);
    glVertex2d (775, 110);
    glVertex2d (820, 115);
    glVertex2d (850, 110);
    glVertex2d (870, 120);
    glVertex2d (910, 118);
    glVertex2d (935, 110);
    glVertex2d (975, 100);
    glVertex2d (1000, 97);
    glVertex2d (1000, 0);
    glEnd();
    //field


    house(170,340,305,160);
    house(235,180,430,100);
    house(480,210,750,120);

    //Chimni

    glColor3ub (0,1, 4);
    glBegin(GL_POLYGON);
    glVertex2d (500, 185);
    glVertex2d (500, 285);
    glVertex2d (530, 285);
    glVertex2d (530, 225);
    glEnd();


    glColor3ub (0,1, 4);
    glBegin(GL_POLYGON);
    glVertex2d (497, 285);
    glVertex2d (497, 290);
    glVertex2d (533, 290);
    glVertex2d (533, 285);
    glEnd();
    //Chimni



    //fench
  fench(434,150,446,160);
  fench(450,150,462,160);
  fench(465,150,477,160);

  glLineWidth(7.5);
glBegin(GL_LINES);
glColor3ub (0,1, 0);
glVertex3f(410, 135, 0);
glVertex3f(480, 135, 0);
glEnd();


     //fench

    //side house
    glColor3ub (0,1, 4);
    glBegin(GL_POLYGON);
    glVertex2d (750, 0);
    glVertex2d (750, 160);
    glVertex2d (790, 160);
    glVertex2d (790, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d (750, 160);
    glVertex2d (750, 180);
    glVertex2d (800, 160);
    glEnd();
    //side house


    //Window 1
    window(215,230,300,260);
    //Window 1

//window 1 upper radius
circle(237.5,298,22.7);

//window 1 lines
window_line((215+260)/2,230,298+22.7,215,260,255,290);


//window 1 upper circle
glColor3ub (240,147, 0);
circle(237.5,388,22.7);
//lines for circle
glLineWidth(2.5);
glBegin(GL_LINES);
glColor3ub (0,0, 0);
glVertex3f(237.5, 450, 0.0);
glVertex3f(237.5, 365, 0);
glEnd();

glLineWidth(2.5);
glBegin(GL_LINES);
glColor3ub (0,1, 0);
glVertex3f(270, 387, 0);
glVertex3f(210, 387, 0);
glEnd();


//2nd window
    glBegin(GL_POLYGON);
    glColor3ub (240,147, 0);

    glVertex2d (315, 120);
    glVertex2d (360, 120);
    glVertex2d (360, 165);
    glVertex2d (315, 165);
    glEnd();
glLineWidth(2.5);
glBegin(GL_LINES);
glColor3ub (0,1, 0);
glVertex3f((315+360)/2, 120, 0);
glVertex3f((315+360)/2, 165, 0);
glEnd();
glBegin(GL_LINES);
glColor3ub (0,1, 0);
glVertex3f(315, (120+165)/2, 0);
glVertex3f(360, (120+165)/2, 0);
glEnd();

//3rd window
    glBegin(GL_POLYGON);
    glColor3ub (240,147, 0);

    glVertex2d (590, 240);
    glVertex2d (635, 240);
    glVertex2d (635, 285);
    glVertex2d (590, 285);
    glEnd();

glLineWidth(2.5);
glBegin(GL_LINES);
glColor3ub (0,1, 0);
glVertex3f((590+635)/2, 240, 0);
glVertex3f((590+635)/2, 285, 0);
glEnd();

glBegin(GL_LINES);
glColor3ub (0,1, 0);
glVertex3f(590, (240+285)/2, 0);
glVertex3f(635, (240+285)/2, 0);
glEnd();


//big house window 1
window(525,120,185,565);
circle(545,180,20);
window_line(545,120,185+20,525,565,142,170);
//big house window 1

//big house window 2
window(668,120,185,708);
circle(688,180,20);
window_line(688,120,185+20,668,708,142,170);
//big house window 2


//Wind mill
glColor3f(0, 0, 0);
glBegin(GL_POLYGON);
glVertex3f(830, 100, 0);
glVertex3f(830, 125, 0);
glVertex3f(900, 125, 0);
glVertex3f(900, 100, 0);
glEnd();

//stand
glBegin(GL_POLYGON);
glVertex3f(845, 120, 0);
glVertex3f(855, 400, 0);
glVertex3f(875, 400, 0);
glVertex3f(885, 120, 0);
glEnd();






fp -= 0.1;

//fan
glColor3f(0, 0, 0);
glPushMatrix();
glLineWidth(15);
glTranslatef(866.5, 400,0);
glRotatef(fp,0,0,1.0);
glBegin(GL_LINES);
glVertex3f(0, 0, 0);
glVertex3f(100, 100, 0);
glEnd();

glTranslatef(0, 0,0);
glRotatef(120,0,0,1.0);
glBegin(GL_LINES);
glVertex3f(0, 0, 0);
glVertex3f(100, 100, 0);
glEnd();

glTranslatef(0, 0,0);
glRotatef(120,0,0,1.0);
glBegin(GL_LINES);
glVertex3f(0, 0, 0);
glVertex3f(100, 100, 0);
glEnd();


glPopMatrix();
circle(865,400,20);
//Wind mill






glutPostRedisplay();
    glFlush();


}








int main(int argc, char* argv[])
{
glutInit(&argc, argv); // Initalise GLUT
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // Set display mode
glutInitWindowPosition(100, 100); // Set window
//position
glutInitWindowSize(1000, 600); // Set
//window size
glutCreateWindow("CG Project By Asif Shahriar 171-15-8617"); // Create display
//window

//pg. 18
init(); // Execute initialisation
//procedure
glutDisplayFunc(display); // Send graphics to display window
glutMainLoop(); // Display everything and wait
return 0;
}
