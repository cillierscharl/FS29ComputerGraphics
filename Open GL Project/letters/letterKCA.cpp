////////////////////////////////////////////////////////////////
//
// lettersKCA - Code to produce the letters LGD
// 
// Author: Lebohang Danster
// Date:   27-03-2013
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "3DCurve.h"
#include "3DPipe.h"

void drawKShape() {

	glPushMatrix();
		glTranslatef(-1.5, 0, 0);
		draw3DPipe(4, 1, 2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.3, 0.6, 0);
		glRotatef(135, 0, 0, 1);
		draw3DPipe(3, 1, 2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, -1, 0);
		glRotatef(45, 0, 0, 1);
		draw3DPipe(1.8, 1, 2);
	glPopMatrix();	
}

void drawCShape() {

	glPushMatrix();
		glRotatef(90,0,0,1);
		draw3Dcurve(
			2,          //depth  
			1,			//inner radius
			2,			//outer radius
			0,			//start angle
			180,		//stop angle
			1.0			//anular increments
		);				
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5, 1.5, 0);
		draw3DPipe(1,1,2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5,-1.5,0);
		draw3DPipe(1,1,2);
	glPopMatrix();
}

void drawAShape() {

	glPushMatrix();
		glTranslatef(0, 2,0);
		draw3DPipe(1,1,2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.1, 0.5,0);
		glRotatef(30, 0, 0, 1);
		draw3DPipe(4,1,2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.1, 0.5, 0);
		glRotatef(-30, 0, 0, 1);
		draw3DPipe(4,1,2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 0.2, 0);
		glRotatef(90, 0, 0, 1);
		draw3DPipe(2 , 1, 2);
	glPopMatrix();

}