// Open GL Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

enum scene {
	drawDannyIntials = 0,
	drawCharlInitials = 1,
	drawLeboInitials = 2,
	drawAnimal = 4
};

#pragma region Local Variables

float pitch = 0;
float yaw = 0;
float zoomFactor = 10.0;
float deltaPitch;
float deltaYaw;
bool mouseDown;
int deltaMouseX;
int deltaMouseY;
bool rotateScene = false;
bool gridLines = false;
bool animate;

// FPS State Containers
int frameCount;
int currentTime;
int previousTime;
float fps;

// Animation State Containers
float upperLegRotation = 0;
float lowerLegRotation = 0;
int direction = 1;
// Scene State
scene displayScene;

#pragma endregion

#pragma region Function Declarations
void displayCallBack(void);
void displayFrameCount(void);
void drawFloor(void);
void drawScene(void);
void idleCallBack(void);
void animateYaw(void);
void rotateView(bool r);
void reshapeCallBack(int w, int h);
void executeViewControl(float y, float p);
void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display);
void keyboardCallBack(unsigned char key, int x, int y);
void clickCallBack(int button, int state, int x, int y);
void motionCallback(int x, int y);
void reshapeCallBack(int w, int h);
void toggleAnimation(bool t);
#pragma endregion


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	// Set the default scene
	displayScene = drawAnimal;

	// Create a new window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 700);
    glutCreateWindow("Computer Graphics");

	// Register callback functions
	glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	glutMouseFunc(clickCallBack);
	glutMotionFunc(motionCallback);
	glutKeyboardFunc(keyboardCallBack);

	glClearColor(1, 1, 1, 1);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST);

	// Print out the initial controls to the console.
	printf("Program Controls:\n");
	printf("Left Mouse Button & Drag - Changes the View.\n");
	printf("Key \"a\" - Draw Animal.\n");
	printf("Key \"s\" - Draw Danny Letters.\n");
	printf("Key \"d\" - Draw Charl Letter.\n");
	printf("Key \"f\" - Draw Lebohang Letter.\n");
	printf("Key \"g\" - Draw Gridlines.\n");
	printf("Key \"m\" - Start / Stop Animation.\n");


	glutMainLoop();
	// When the application is exiting return a success code.
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
			drawAnimalScene(upperLegRotation,lowerLegRotation);
			break;
	}
	displayFrameCount();
}

void animateYaw(){
	yaw = yaw + .8;
}

void idleCallBack () {
	// Rotation
	if(rotateScene) animateYaw();
	// Leg animations (Upper and Lower)
	if(animate){
		if(direction == 1){
			if(upperLegRotation < 30){
				upperLegRotation += 1;
			}else {
				direction = 0;
			}
			if(lowerLegRotation < 2){
				lowerLegRotation++;
			}
		
		}else {
			if(upperLegRotation > -30){
				upperLegRotation -= 1;
			}else {
				direction = 1;
			}

			if(lowerLegRotation > -20){
				lowerLegRotation--;
			}
		
		}
	}
    glutPostRedisplay();
}

void rotateView(bool r) {
	rotateScene = r;
	if(r){
		glutIdleFunc(idleCallBack); 
	}else{ 
		glutIdleFunc(NULL);
	}
}

void toggleAnimation(bool t){
	animate = t;
	if(t){
		glutIdleFunc(idleCallBack); 
	}else{
		glutIdleFunc(NULL);
		rotateScene = false;
	}
}

void keyboardCallBack(unsigned char key, int x, int y) {
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
		rotateScene= !rotateScene;
		rotateView(rotateScene);
	break;
	case 'm':
		toggleAnimation(!animate);
		break;
	case 'G':
	case 'g':
		gridLines = !gridLines;
		break;
	case 'z': 
		if (zoomFactor > 1) zoomFactor = zoomFactor - 1;
	break;
	case 'Z':
        zoomFactor = zoomFactor + 1;
	break;
	default:
		printf("Press a - Draw Armadillo s - Draw Daniel's Initials f - Draw Lebo's Initials d - Draw Charl's Initials r - rotate; g - Grid Lines\n");
	}

	glutPostRedisplay();
}

void clickCallBack(int button, int state, int x, int y) {
    switch (state)
    {
		case GLUT_DOWN:
			mouseDown = true;
			deltaPitch = pitch; 
			deltaYaw = yaw;
			deltaMouseX = x; 
			deltaMouseY = y;
			break;
		default:
		case GLUT_UP:
			mouseDown = false;
			break;
    }
} 

void motionCallback(int x, int y) 
{
    pitch = deltaPitch + (y - deltaMouseY);
    yaw = deltaYaw + (x - deltaMouseX);
	glutPostRedisplay();
} 

void applyViewChange (float y, float p) {
	glRotatef(y, 0, 1, 0);
    glRotatef(p, 1, 0, 0);
}

void displayCallBack() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	applyViewChange (yaw, pitch);
	if(gridLines) drawAxesAndGridLines(true,true,true);
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

void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display)
{
	float offset; int gd;
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(-20, 0, 0);					
		glVertex3f(+20, 0, 0);					
		glVertex3f( 0 ,-20, 0);				    	
		glVertex3f(	0, +20, 0);
		glVertex3f( 0, 0,-20);				    	
		glVertex3f(	0, 0, +20);

	glEnd();
	
	glLineStipple(1, 0xAAAA); //line style = fine dots
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINES);
		
		if (x_y_display) {glColor3f(0.0,0.7,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-y plane
			glVertex3f(-10.0, offset, 0.0);					// Top Left
			glVertex3f(+10.0, offset, 0.0);					// Top Right
			glVertex3f( offset,-10, 0.0);					// Bottom Right
			glVertex3f(	offset,+10.0, 0.0);					// Bottom Left
		}}

		if (y_z_display) {glColor3f(0.7,0.0,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in y-z plane
			glVertex3f( 0, offset, -10);					
			glVertex3f(	0, offset, 10.0);
			glVertex3f( 0, -10, offset);					
			glVertex3f(	0, 10, offset);
		}}

		if (x_z_display) {glColor3f(0.7,0.7,0.0);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-z plane
			glVertex3f( offset, 0, -10);					
			glVertex3f(	offset, 0, 10.0);
			glVertex3f( -10, 0, offset);					
			glVertex3f(	10, 0, offset);
		}}

	glEnd();
	glDisable(GL_LINE_STIPPLE);

}