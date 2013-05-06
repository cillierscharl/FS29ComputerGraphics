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

#include "stdafx.h"

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

void drawLeg(int sections,int footSections,float legRotation, float lowerLegRotation, float scale){
	glPushMatrix();
		int halfSections = sections / 2;

		glRotatef(legRotation,0,0,1);
		glScalef(scale,scale,scale);

		for(int i = 0 ; i < halfSections + 1 ; i++){
			glPushMatrix();
				glTranslatef(0,i * -3,0);
				drawKShape();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.6,i * -3,0);
				glRotatef(180,0,1,0);
				drawKShape();
			glPopMatrix();
		}

		glRotatef(lowerLegRotation,0,0,1);

		glTranslatef(0,-3,0);
		for(int i = halfSections ; i < sections + 1 ; i++){

			glPushMatrix();
				glTranslatef(0,i * -3,0);
				drawKShape();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.6,i * -3,0);
				glRotatef(180,0,1,0);
				drawKShape();
			glPopMatrix();
		}

	glPopMatrix();

	glRotatef(lowerLegRotation,0,0,1);

	glPushMatrix();
		glRotatef(legRotation,0,0,1);	
		glScalef(scale,scale,scale);
		for(int i = 1 ; i < footSections + 1; i++){
			glPushMatrix();
				glTranslatef(0,(sections + i) * -3,0);
				glRotatef(50,0,0,1);
				drawKShape();
			glPopMatrix();
			glPushMatrix();
					glTranslatef(0.6,(sections + i) * -3,0);
					glRotatef(180,0,1,0);
					glRotatef(50,0,0,1);
					drawKShape();
			glPopMatrix();
		}
	glPopMatrix();
}


void drawBody(){
	for(int i = 120; i >= -120 ; i -= 10){
		glPushMatrix();
			glRotatef(90,0,0,1);
			glRotatef(i,0,1,0);
			glTranslatef(2,0,0);
			glScalef(1,3,0.1);
			drawDShape();
		glPopMatrix();
	}
}

void drawArms(int legRotation, int lowerLegRotation){
	glPushMatrix();
		glPushMatrix();
			glTranslatef(4,-1,-1);
			drawLeg(2,1,-legRotation,-lowerLegRotation,0.3);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(4,-1,1);			
			drawLeg(2,1,legRotation,lowerLegRotation,0.3);
		glPopMatrix();
	glPopMatrix();
}

void drawLegs(int legRotation, int lowerLegRotation){
	glPushMatrix();
		glTranslatef(-5,-1,-1);
		drawLeg(2,1,-legRotation,-lowerLegRotation,0.3);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5,-1,1);
		drawLeg(2,1,legRotation,lowerLegRotation,0.3);
	glPopMatrix();
}

void drawMouth(){
	glPushMatrix();
		glTranslatef(6,0,0);
		glRotatef(-90,0,0,1);
		glRotatef(-20,0,0,1);
		for(int i = 0 ; i < 360; i+= 10 ){
			glPushMatrix();
				glRotatef(i,0,1,0);
				glScalef(1,1.5,.1);
				drawAShape();
			glPopMatrix();
		}
	glPopMatrix();
}

void drawTail(){
	glPushMatrix();
		glTranslatef(-15,-4,0);
		glRotatef(-90,0,0,1);
		glRotatef(270,1,0,0);
		for(float i = 1 ; i < 10 ; i += 1){
			glPushMatrix();
				glTranslatef(0,0,i);
				glTranslatef((i/2) * -1,0,0);
				glRotatef(-15,0,1,0);
				printf("Count %f \n", i/100);
				glScalef( i / 10, i / 10,1);
				drawCShape();
			glPopMatrix();
		}
	glPopMatrix();
}

void drawEyes(){
	glPushMatrix();
		glTranslatef(7,0,1.7);
		glScalef(.2,.2,.1);
		drawGShape();

	glPopMatrix();
}


void drawAnimalScene(float legRotation, float lowerLegRotation) {

	drawBody();
	drawLegs(legRotation,lowerLegRotation);
	drawArms(legRotation,lowerLegRotation);
	drawMouth();
	drawTail();
	drawEyes();
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