////////////////////////////////////////////////////////////////
//
// 3DPipe.cpp
// 
// Author: Charl Cilliers
// Date:   23-03-2013
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>


void draw3DPipe(float height, float width,float breadth){

	float posWidth = width /2;
	float negWidth = (posWidth) * -1;

	float posHeight = height /2;
	float negHeight = (posHeight) *-1;

	float posBreadth = breadth/2;
	float negBreadth = (posBreadth) * -1;

	glPushMatrix();
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(negWidth,negHeight,posBreadth);
		glVertex3f(posWidth,negHeight,posBreadth);
		glVertex3f(posWidth,posHeight,posBreadth);
		glVertex3f(negWidth,posHeight,posBreadth);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-breadth/2);
		glBegin(GL_QUADS);
			glColor3f(0,1,0);
			glVertex3f(negWidth,negHeight,0);
			glVertex3f(posWidth,negHeight,0);
			glVertex3f(posWidth,posHeight,0);
			glVertex3f(negWidth,posHeight,0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posWidth,0,0);
	glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glColor3f(0,1,1);
			glVertex3f(negBreadth,negHeight,0);
			glVertex3f(posBreadth,negHeight,0);
			glVertex3f(posBreadth,posHeight,0);
			glVertex3f(negBreadth,posHeight,0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-posWidth,0,0);
	glRotatef(90,0,1,0);
		glBegin(GL_QUADS);
			glColor3f(0,1,1);
			glVertex3f(negBreadth,negHeight,0);
			glVertex3f(posBreadth,negHeight,0);
			glVertex3f(posBreadth,posHeight,0);
			glVertex3f(negBreadth,posHeight,0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,posHeight,0);
	glRotatef(90,1,0,0);
		glBegin(GL_QUADS);
			glColor3f(0.5,0.5,0.5);
			glVertex3f(negWidth,negBreadth,0);
			glVertex3f(posWidth,negBreadth,0);
			glVertex3f(posWidth,posBreadth,0);
			glVertex3f(negWidth,posBreadth,0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,negHeight,0);
	glRotatef(90,1,0,0);
		glBegin(GL_QUADS);
			glColor3f(0.5,0.5,0.5);
			glVertex3f(negWidth,negBreadth,0);
			glVertex3f(posWidth,negBreadth,0);
			glVertex3f(posWidth,posBreadth,0);
			glVertex3f(negWidth,posBreadth,0);
		glEnd();
	glPopMatrix();



}