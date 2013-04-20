////////////////////////////////////////////////////////////////
//
// lettersHBI - Code to produce the letters HBI
// 
// Author: Lebohang Danster
// Date:   18-04-2013
//
////////////////////////////////////////////////////////////////

#include <glut.h>
#include "3DCurve.h"
#include "3DPipe.h"

void drawCurve(void);

void drawHShape() {
	glPushMatrix();
		glTranslatef(-1.5, 0, 0);
		draw3DPipe(4, 1, 2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.5, 0, 0);
		draw3DPipe(4, 1, 2);
	glPopMatrix();

	glPushMatrix();
		glRotatef(90, 0, 0, 1);
		draw3DPipe(4, 1, 2);
	glPopMatrix();
}

void drawBShape() {
	glPushMatrix();
		glTranslatef(-1.5, 0, 0);
		draw3DPipe(4, 1, 2);
	glPopMatrix();

	
	glPushMatrix();
		glRotatef(180, 0, 0, 1);
		glTranslatef(0.5, -1, 0);
		glScalef(0.5, 0.5, 1);
		drawCurve();
	glPopMatrix();
	

	glPushMatrix();
		glRotatef(180, 0, 0, 1);
		glTranslatef(0.5, 1, 0);
		glScalef(0.5, 0.5, 1);
		drawCurve();
	glPopMatrix();
}

void drawIShape() {
	glPushMatrix();
		glTranslatef(-1.5, 0, 0);
		draw3DPipe(4, 1, 2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5, 3, 0);
		glScalef(0.5, 0.5, 1);
		glRotatef(90,0,0,1);
		draw3Dcurve(
			2,          //depth  
			0,			//inner radius
			1,			//outer radius
			0,			//start angle
			360,		//stop angle
			1.0			//anular increments
		);				
	glPopMatrix();
}

#pragma region HelperFunction

void drawCurve() {
	glPushMatrix();
		glRotatef(90,0,0,1);
		draw3Dcurve(
			2,          //depth  
			0.8,			//inner radius
			2,			//outer radius
			0,			//start angle
			180,		//stop angle
			1.0			//anular increments
		);				
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5, 1.38, 0);
		draw3DPipe(1.2,1,2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5,-1.38,0);
		draw3DPipe(1.2,1,2);
	glPopMatrix();
}

#pragma endregion

