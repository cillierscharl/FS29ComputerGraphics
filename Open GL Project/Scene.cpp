////////////////////////////////////////////////////////////////
//
// Scene - Code to produce the scenes
// 
// Author: Lebohang Danster
// Date:   18-04-2013
//
////////////////////////////////////////////////////////////////


#include <GL/glut.h>
#include "lettersLGD.h"
#include "lettersHBI.h"
#include "lettersKCA.h"

#pragma region Function Declarations

void drawD(float x, float y);
void drawK(float x, float y);
void drawI(float x, float y);
void drawC(float x, float y);
void drawH(float x, float y);
void drawA(float x, float y);
void drawL(float x, float y);
void drawG(float x, float y);
void drawB(float x, float y);

#pragma endregion

#pragma region Local Variables

float coordinates[][2] = {
	{ -4, 0 },
	{ 0.5, 0 },
	{ 4, 0 },
	{ -0.5, 0 },
	{ 4.5, -0.5 },
	{ 3.5, 0 }
};

#pragma endregion

void drawDannyScene() {
	drawD(coordinates[0][0], coordinates[0][1]);
	drawK(coordinates[1][0], coordinates[1][1]);
	drawI(coordinates[2][0], coordinates[2][1]);
}

void drawCharlScene() {
	drawC(coordinates[0][0], coordinates[0][1]);
	drawH(coordinates[3][0], coordinates[3][1]);
	drawA(coordinates[4][0], coordinates[4][1]);
}

void drawLeboScene() {
	drawL(coordinates[0][0], coordinates[0][1]);
	drawG(coordinates[3][0], coordinates[3][1]);
	drawB(coordinates[5][0], coordinates[5][1]);
}

void drawAnimalScene() {
	for(int i = 120; i >= -120 ; i -= 10){
		glPushMatrix();
			glRotatef(90,0,0,1);
			glRotatef(i,0,1,0);
			glTranslatef(2,0,0);
			glScalef(1,3,0.1);
			drawDShape();
		glPopMatrix();
	}

	glPushMatrix();
		glTranslatef(-3,-1,1);
		glScalef(1,1,0.3);
		drawLShape();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3,-1,-1);
		glScalef(1,1,0.3);
		drawLShape();
	glPopMatrix();

	//front arms

	glPushMatrix();
		glTranslatef(3,-0.5,-1);
		glScalef(0.1,0.8,0.3);
		drawLShape();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(3,-0.5,1);
		glScalef(0.1,0.8,0.3);
		drawLShape();
	glPopMatrix();
}

#pragma region Scene Draw Functions

void drawD(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 1);
		drawDShape();
	glPopMatrix();
}

void drawK(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 1);
		drawKShape();
	glPopMatrix();
}

void drawI(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 1);
		drawIShape();
	glPopMatrix();
}

void drawC(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 1);
		drawCShape();
	glPopMatrix();
}

void drawH(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 1);
		drawHShape();
	glPopMatrix();
}

void drawA(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 1);
		drawAShape();
	glPopMatrix();
}

void drawL(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 1);
		drawLShape();
	glPopMatrix();
}

void drawG(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 1);
		drawGShape();
	glPopMatrix();
}

void drawB(float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 1);
		drawBShape();
	glPopMatrix();
}

#pragma endregion