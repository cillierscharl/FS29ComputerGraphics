////////////////////////////////////////////////////////////////
//
// lettersLGD - Code to produce the letters LGD
// 
// Author: Charl Cilliers
// Date:   23-03-2013
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "3DCurve.h"
#include "3DPipe.h"

void drawLShape(){
	glPushMatrix();
		glTranslatef(-1.5,0,0);
		draw3DPipe(4,1,2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,-1.5,0);
		draw3DPipe(1,2,2);
	glPopMatrix();
}

void drawGShape(){
	glPushMatrix();
		glRotatef(50,0,0,1);
		draw3Dcurve(
			2,          //depth  
			1,			//inner radius
			2,			//outer radius
			0,			//start angle
			255,		//stop angle
			1.0			//anular increments
		);				
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1,-1,0);
		draw3DPipe(2,1,2);
	glPopMatrix();
}

void drawDShape(){
	glPushMatrix();
		glRotatef(-90,0,0,1);
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
		glTranslatef(-0.5,1.5,0);
		draw3DPipe(1,1,2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5,-1.5,0);
		draw3DPipe(1,1,2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5,0,0);
		draw3DPipe(4,1,2);
	glPopMatrix();
		
}