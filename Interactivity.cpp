#include "Interactivity.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/freeglut.h>
#endif

#include <iostream>
#include <cmath>
using namespace std;

float theta = 0;								// The angle of rotation
float Interactivity::eye[] = {5, 5, 0};		// The first 3 paramters of gluLookAt
float Interactivity::center[] = {0, 0, 0};		// The first 4-6 paramters of gluLookAt

void Interactivity::keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'q':			// Quit the program
		case 'Q':
		case 27:
			exit(0);
			break;
	}
}

void Interactivity::special(int key, int x, int y) {
	float r, change;
	switch (key) {
		case GLUT_KEY_LEFT:			// Rotate around the scene
 		case GLUT_KEY_RIGHT:
			r = sqrt(pow(eye[0] - center[0], 2) + pow(eye[2] - center[2], 2));
			change = key == GLUT_KEY_LEFT ? 0.1 : -0.1;	// postive or negative
			theta = theta < 360 ? theta + change : 0;		// increment or reset to 0
			eye[0] = r * cos(theta);						// circular motion
			eye[2] = r * sin(theta);
 			break;
 		case GLUT_KEY_UP:			// Move camera strictly upwards
			++eye[1];
			++center[1];
 			break;
 		case GLUT_KEY_DOWN:			// Move camera striclty downwards
			--eye[1];
			--center[1];
 			break;
	}
}

void Interactivity::printInstructions() {
	cout << "-----------------------------------"  << endl;
	cout << "INSTRUCITONS: " << endl;
	cout << "KEY        ACTION" << endl;
	cout << "Q          Quit"   << endl;
	cout << "ESC"            << endl;
	cout << "-----------------------------------"  << endl;
}