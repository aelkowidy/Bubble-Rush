#include <GL/glut.h>
#include <math.h>
float xinc=0;
float yinc=0;



//void RenderScene(void){

//glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0,0,125,125);
	//glColor3f(0.8,0.9,1.0);
	//glRectf(-0.50, 0.50, 0.50, -0.50);
	 //glFlush();}

//void display(){
//glClear(GL_COLOR_BUFFER_BIT);
//glMatrixMode(GL_MODELVIEW);
//glRotated(-90,0,0,1);
//glScaled(2,2,1);
//glTranslated(100,100,0);

//glBegin(GL_TRIANGLES);

//glColor3f(0.8,0.9,1.0);
//glVertex2f(0.0,0.0);

//glColor3f(0.0,1.0,0.0);
//glVertex2f(200.0,200.0);

//glColor3f(1.0,0.0,0.0);
//glVertex2f(0.0,200.0);

//glEnd();

//glFlush();

//}





void circle(double cx, double cy, double radius) {
	double PI = 3.14;
	double step = 100;

	double delet =2 * PI / step;



	glBegin(GL_TRIANGLE_FAN);

	double angle = 0;
	glVertex2d(cx, cy);
	for (int i = 0; i <= step; i++) {

		double x = cx + radius * cos(angle);
		double y = cy + radius * sin(angle);
		glVertex2d(x, y);
		angle += delet;

	}

	glEnd();
}



void bubblerush (void)
{
glClear(GL_COLOR_BUFFER_BIT );

glColor3f(0.8,0.9,1.0);
glViewport(5+xinc,5+yinc,200,200);
circle(0.5,0.5,0.5);
glColor3f(0.5,0.2,1.0);




    glFlush();


}
    void keyUp ( unsigned char key, int x, int y) {

 if (key=='a'){
xinc-=50;

}


      else if(key=='w'){
    yinc+=50;
}

    else if(key=='d'){

        xinc+=50;
    }

    else if(key=='s'){

        yinc-=50;
    }
//else if (key=='h'){
   // glScaled(2,2,1);

  //  }


    bubblerush();




}

void special(int key,int x,int y){

if (key==GLUT_KEY_UP){

    yinc+=50;
}

else if(key==GLUT_KEY_DOWN){
    yinc-=50;

}

else if(key==GLUT_KEY_LEFT){
    xinc-=50;
}

else if(key==GLUT_KEY_RIGHT){
    xinc+=50;
}




bubblerush();
}



int main(int argc, char *argv[])
{
   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

   glutCreateWindow("BUBBLE RUSH");

   glutDisplayFunc(bubblerush);

   //glutDisplayFunc(display);
   //glutDisplayFunc(RenderScene);

   glClearColor(0.0f,0.7f,0.7f,1.0f);

   glutKeyboardFunc(keyUp);

   glutSpecialFunc(special);

   glutMainLoop();

    return 0;
}
