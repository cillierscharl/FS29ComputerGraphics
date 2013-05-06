// Open GL Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

enum scene {
	drawDannyIntials = 0,
	drawCharlInitials = 1,
	drawLeboInitials = 2,
	drawAnimal = 4,
};

#pragma region Local Variables

float pitch = 0.0f;
float yaw = 0.0f;
float zoomFactor = 10.0;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool rotating=false;
bool moving=false;

int frameCount;
int currentTime;
int previousTime;
float fps;

scene displayScene;

#pragma endregion

#pragma region Function Declarations

void displayCallBack(void);
void displayFrameCount(void);
void drawFloor(void);
void drawScene(void);
void idleCallBack(void);
void incrementYaw(void);
void displayCallBack(void);
void rotateView(bool r);
void reshapeCallBack(int w, int h);
void executeViewControl(float y, float p);
void keyboardCallBack(unsigned char key, int x, int y);
void reshapeCallBack(int w, int h);
// Animation State Containers
float rotation = 0;
float lowerLegRotation = 0;
int direction = 1;

#pragma endregion


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	
	displayScene = drawAnimal;

	// Create and name window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Need both double buffering and z buffer
    glutInitWindowSize(700, 700);
    glutCreateWindow("Computer Graphics");

	// Add Display & Mouse CallBacks
	glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	//glutIdleFunc(idleCallBack); // Starts the Idle Function as having no routine attached to it. This is modified in rotateView()
	//glutMouseFunc(mouseClickCallBack);
	//glutMotionFunc(mouseMotionCallBack);
	glutKeyboardFunc(keyboardCallBack);


	glClearColor(1, 1.0, 1.0, 1.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST);

	// Print Application Usage
	printf("Program Controls:\n");
	printf("Left Mouse Button & Drag - Changes the View.\n");
	printf("Key \"b\" - Back Fill.\n");
	printf("Key \"f\" - Front Fill.\n");
	printf("Key \"l\" - Wire Frame/Line Fill.\n");
	printf("Key \"i\" - Increment Sections of Curve.\n");
	printf("Key \"d\" - Decrement Sections of Curve.\n");
	printf("Key \"r\" - Automated Rotation.\n");
	printf("Key \"R\" - Reset the View.\n");

	glutMainLoop();

	return 0;
}

/**
	Outputs the frame count to the console
*/
void displayFrameCount()
{
    //  Increase frame count
    frameCount++;
 
    //  Get the number of milliseconds since glutInit called
    //  (or first call to glutGet(GLUT ELAPSED TIME)).
    currentTime = glutGet(GLUT_ELAPSED_TIME);
 
    //  Calculate time passed
    int timeInterval = currentTime - previousTime;
 
    if(timeInterval > 1000)
    {
        //  calculate the number of frames per second
        fps = frameCount / (timeInterval / 1000.0f);

		// Print frame stats to the console
		printf("FPS %f \n", fps);

        //  Set time
        previousTime = currentTime;
 
        //  Reset frame count
        frameCount = 0;
    }
}

/**
	Draws the floor of the scene
*/
void drawFloor() {
	glBegin(GL_QUADS);
		glColor3f(0,0,0);
		glVertex3f(-20000,-2,20000);
		glVertex3f(20000,-2,20000);
		glVertex3f(20000,-2,-20000);
		glVertex3f(-20000,-2,-20000);
	glEnd();
}

/**
	Draws the scene
*/
void drawScene(){

	switch (displayScene)
	{
	case drawDannyIntials:
		drawDannyScene();
		break;

	case drawCharlInitials:
		drawCharlScene();
		break;

	case drawLeboInitials:
		drawLeboScene();
		break;

	case drawAnimal:
	default:
		drawAnimalScene(rotation,lowerLegRotation);
		break;
	}
	displayFrameCount();
}

void incrementYaw(){
	//pitch=pitch+.25;
	yaw=yaw+.8;
}



void idleCallBack () {
	if(rotating) incrementYaw();

	//
	if(direction == 1){
		if(rotation < 30){
			rotation += 1;
		}else {
			direction = 0;
		}
		if(lowerLegRotation < 2){
			lowerLegRotation++;
		}
		
		
	}else {
		if(rotation > -30){
			rotation -= 1;
		}else {
			direction = 1;
		}

		if(lowerLegRotation > -20){
			lowerLegRotation--;
		}
		
	}
	//

    glutPostRedisplay();
}

void rotateView(bool r) {
	rotating = r;
	if (moving | rotating) glutIdleFunc(idleCallBack); else glutIdleFunc(NULL);
}

void keyboardCallBack(unsigned char key, int x, int y) {
	printf("Keyboard call back: key=%c, x=%d, y=%d\n", key, x, y);
	switch(key)
	{
	case 'a':
	case 'A':
		displayScene = drawAnimal;
		break;
	case 's':
	case 'S':
		displayScene = drawDannyIntials;
		break;
	case 'd':
	case 'D':
		displayScene = drawCharlInitials;
		break;
	case 'f':
	case 'F':
		displayScene = drawLeboInitials;
		break;
	case 'r': 
		rotating= !rotating;
		rotateView(rotating);
	break;
	case 'R':
        //resetView();
	break;
	case 'm': 
		//moving= !moving;
		//moveView(moving);
	break;
	case 'z': 
		if (zoomFactor > 1) zoomFactor = zoomFactor - 1;
	break;
	case 'Z':
        zoomFactor = zoomFactor + 1;
	break;
	default:
		printf("Press a - Draw Armadillo s - Draw Daniel's Initials f - Draw Lebo's Initials d - Draw Charl's Initials r - rotate; R - reset view\n");
	}

	glutPostRedisplay();
}

void executeViewControl (float y, float p) {
	glRotatef(y, 0.0f, 1.0f, 0.0f); //yaw about y-axis
    glRotatef(p, 1.0f, 0.0f, 0.0f); //pitch about x-axis 
}

void displayCallBack() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	executeViewControl (yaw, pitch);
	drawScene();
	glutSwapBuffers();
}

void reshapeCallBack(int w, int h) 
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	if (w == 0 || h == 0) return;
    if (w <= h) glOrtho(-zoomFactor, zoomFactor, -zoomFactor * (GLfloat) h / (GLfloat) w, zoomFactor * (GLfloat) h / (GLfloat) w, -20.0, 20.0);
    else        glOrtho(-zoomFactor* (GLfloat) w / (GLfloat) h, zoomFactor * (GLfloat) w / (GLfloat) h, -zoomFactor, zoomFactor, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}



