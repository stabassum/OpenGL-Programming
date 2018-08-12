// Project 3
// by Sumaiya Tabassum
// CS 368 - Computer Graphics

#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <string>
#include <iostream>

using namespace std;

GLfloat pos[] = { -2, 4, 5, 1 }, // Light position
amb[] = { 0.3, 0.3, 0.3, 1.0 }; // Ambient Intensity

GLfloat front_amb_diff[] = { 0.7, 1.0, 0.1, 1.0 }; // Front side property
GLfloat back_amb_diff[] = { 0.4, 0.7, 0.1, 1.0 }; // Front side property
GLfloat front_amb_diff_planet[] = { 0.0, 0.4, 1.75, 0.6 }; // Bluish
GLfloat front_amb_diff_ring[] = { 1.9, .55, 0.3, 0.0 }; // Redish brownish
GLfloat front_amb_diff_bigCircle[] = { 1.15, .5, .15, 0 }; // Redish brownish
GLfloat front_amb_diff_planetPurple1[] = { 1.0, 0.0, 1.0, 0 }; // Purplish
GLfloat front_amb_diff_planetPurple2[] = { 0.9, -0.2, 0.99, 0 }; // Purplish

GLfloat front_amb_diff_moon[] = { 0.75, 0.85, 0.75, 0.15 }; // Whitish-greyish

GLfloat front_amb_diff_star[] = { 0.65, .74, 0.71, 0.0 }; //greyish

GLfloat front_amb_diff_Planet2[] = { 1.65, .24, 0.21, 0.0 }; //redish-purplusish-pinkish

GLfloat front_amb_diff_planetGreen[] = { 0.05, 1.14, 0.01, 1.0 }; //greyish

GLfloat front_amb_diff_roadInSpace[] = { 0.7, 0.7, 0.7, 0.0 }; //greyish

GLfloat spe[] = { 0.25, 0.25, 0.25, 1.0 }; // Property for front and back

GLfloat theta = 0, theta_rotate = 0, dt = 0.5, axes[3][3] = { { 1,0,0 },{ 0,1,0 },{ 0,0,1 } };
GLfloat s;
GLdouble b = 1.1;
int axis = 0;

// Road in space

void roadInSpace(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_roadInSpace);
    
    glPushMatrix();
    glTranslated(0.0, -3.50, -7.0);
    glutSolidCone(2.9, 0.2989, 3, 4); // Define object and size
    glPopMatrix();
}

// Star

void star1(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, 1, 0, 1);
    glTranslated(2.0, 0.0, 0.1);
    
    glutSolidCube(0.02); // Define cube object and size
    
    glPopMatrix();
}

// Star

void star2(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, 0, 0, 1);
    glTranslated(2.0, 0.0, 0.1);
    
    glutSolidCube(0.02); // Define cube object and size
    
    glPopMatrix();
}

// Star

void star3(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, 1, 0, 1);
    glTranslated(-2.1, 0.0, -0.1);
    
    glutSolidCube(0.0343); // Define cube object and size
    
    glPopMatrix();
}

// Star

void star4(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, 1, 0, 1);
    glTranslated(-2.7, 0.0, -0.1);
    
    glutSolidCube(0.022); // Define cube object and size
    
    glPopMatrix();
}

// Star

void star5(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, 1, 1, 1);
    glTranslated(-1.9, 0.0, -0.15);
    
    glutSolidCube(0.03001); // Define cube object and size
    
    glPopMatrix();
}

// Star

void star6(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, 0, 1, 0);
    glTranslated(-2.9, 0.0, -0.15);
    
    glutSolidCube(0.02001); // Define cube object and size
    
    glPopMatrix();
}

// Star

void star7(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, -1, 0, -1);
    glTranslated(1.3, 0.0, -0.15);
    
    glutSolidCube(0.023001); // Define cube object and size
    
    glPopMatrix();
}

// Star

void star8(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, -1, 0, -1);
    glTranslated(1.3, 0.0, -0.55);
    
    glutSolidCube(0.0298801); // Define cube object and size
    
    glPopMatrix();
}

// Star

void star9(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, -1, 0, 1);
    glTranslated(1.3, 0.0, 0.15);
    
    glutSolidCube(0.01901); // Define cube object and size
    
    glPopMatrix();
}

// Star

void star10(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_star);
    
    glPushMatrix();
    glRotated(theta_rotate, 1, 0, -1);
    glTranslated(11.3, 0.0, -0.15);
    
    glutSolidCube(0.019801); // Define cube object and size
    
    glPopMatrix();
}

// Rolling planet

void planetRollingOnRoad(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, front_amb_diff_Planet2);
    glMaterialfv(GL_BACK, GL_AMBIENT, front_amb_diff_Planet2);
    
    for (int i = 0; i<2; i++)
    {
        glPushMatrix();
        glRotated(theta + i, 1, 0, 0);
        glTranslated(0, -3, 0);
        glutSolidSphere(0.4, 50, 25); // Define object and size
        glPopMatrix();
    }
}

// Rolling planet

void planetRollingOnRoad2(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, front_amb_diff_planetGreen);
    glMaterialfv(GL_BACK, GL_AMBIENT, front_amb_diff_planetGreen);
    
    int i = 0;
    glPushMatrix();
    glRotated(theta + i, 1, 0, 0);
    glTranslated(-0.2, -5, 0.3);
    glutSolidSphere(0.2, 25, 12.25); // Define object and size
    glPopMatrix();
    
}

// Make an method objectSpehere to use in making planet

void objectSphere(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_bigCircle);
    
    glPushMatrix();
    glRotated(theta_rotate, 1, 0, 0);
    glTranslated(1, 0, 0);
    
    glutSolidSphere(0.8, 150, 100); // Define object and size
    glPopMatrix();
}

// Make a ring to use for planet making

void objectTorus(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_ring);
    
    glPushMatrix();
    glRotated(theta_rotate, 0, 0, 0);
    glTranslated(1, 0, 0);
    
    glutSolidTorus(0.2, 0.8, 20, 40); // Define object and size
    glPopMatrix();
}

// Make sphere for planet making

void objectSpherePlanet(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_planetPurple1);
    
    glPushMatrix();
    glRotated(theta_rotate, 0, -1, 0);
    glTranslated(3.0, 0, -0.1);
    
    glutSolidSphere(0.2, 25, 50); // Define object and size
    glPopMatrix();
}

// Make ring for plant making

void objectTorusForSphere(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_planetPurple2);
    
    glPushMatrix();
    glRotated(theta_rotate, 0, -1, 0);
    glTranslated(3.0, 0, -0.1);
    
    glutSolidTorus(0.0195, 0.4, 10, 40);  // Define object and size
    glPopMatrix();
}

// Make another ring for planet making, used for planet with two rings

void objectTorusForSphere1(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_planetPurple2);
    
    glPushMatrix();
    glRotated(theta_rotate, 0, -1, 0);
    glTranslated(3.0, 0, -0.1);
    
    glutSolidTorus(0.045, 0.5, 20, 60); //  // Define object and size
    glPopMatrix();
}

// Make a blue planet

void objectSmallSphere(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_planet);
    
    glPushMatrix();
    glRotated(theta_rotate, 0, 1, 0);
    glTranslated(2.7, 0, -0.1);
    
    glutSolidSphere(0.4, 25, 50);  // Define object and size
    glPopMatrix();
}

// Make a moon

void tinySphere(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_moon); // color of moon
    
    glPushMatrix();
    glRotated(theta_rotate, 0, 1, 0);
    glTranslated(2.1, 0, -0.1);
    
    glutSolidSphere(0.2, 25, 55);  // Define object and size
    glPopMatrix();
}

// Green planet

void tinyPlanet(void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff_planetGreen);
    
    glPushMatrix();
    glRotated(theta_rotate, 0, -1, -1);
    glTranslated(2.8, .03, -0.5);
    
    glutSolidSphere(0.1, 25, 55);  // Define object and size
    glPopMatrix();
}

// Add the space objects to the display

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    roadInSpace(); // Road in space
    star1(); // Star
    star2(); // Star
    star3(); // Star
    star4(); // Star
    star5(); // Star
    star6(); // Star
    star7(); // Star
    star8(); // Star
    star9(); // Star
    star10(); // Star
    objectSphere(); // Sphere for planet
    objectTorus(); // Ring for planet
    objectSmallSphere(); // Blue planet
    tinySphere(); // Moon
    tinyPlanet(); // Green planet
    objectSpherePlanet(); // Sphere for planet
    objectTorusForSphere(); // Ring for planet
    objectTorusForSphere1(); // Ring for planet
    planetRollingOnRoad(); // Rolling planet
    planetRollingOnRoad2(); // Rolling planet
    
    glutSwapBuffers();
}

// Rotation

void idle(void)
{
    theta = (theta < 360) ? theta + dt : dt;
    theta_rotate = (theta_rotate < 360) ? theta_rotate + 0.4 : 0.4;
    glutPostRedisplay();
}

// Keyboard functions

void keyboard(unsigned char key, int x, int y) {
    
    switch (key) {
            
            // pause program
        case ' ':
            if (dt == 0)
                dt = s;
            else {
                s = dt;
                dt = 0;
            }
            break;
            
            // exit the program
        case 'x':
            exit(0);
            break;
    }
    glutPostRedisplay();
}

// Arrow key functions

void Arrow_Keys(int key, int x, int y) {
    
    switch (key) {
            
            // speed up and go forward
        case GLUT_KEY_UP:
            dt = dt + 0.1;
            if (dt >= 5) dt = 5;
            break;
            
            // slow down and eventually go backwards
        case GLUT_KEY_DOWN:
             dt = dt - 0.1;
            if (dt <= -1) dt = -1;
            break;
            
    }
    glutPostRedisplay();
    
}

// User guide messages for program and keyboard functions

void keyBoardFunctions() {
    
    cout << "Movement of center two planets.\n\n" << endl;
    
    cout << "Keyboard Functions:\n " << endl;
    
    cout << "Up Arrow - Speed up movement of center planets and move forward. (max Speed: 3)\n";
    
    cout << "Down Arrow - Slow down movement of center planets and eventually move backwards. (min Speed: -1)\n";
    
    cout << "Space - Pause the program \n";
    
    cout << "x - Exit the program.\n";
    
    cout << "\n\nNote: No objects in space will be affected except the center planets" << endl;
    
}

// Main program

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(750, 650);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Project 3 - Sumaiya Tabassum");
    glClearColor(-0.1, 0.0, -0.05, 0.0); // background color
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(43, 1.0, 1, 80);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, -5);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glutSpecialFunc(Arrow_Keys); // keyboard function
    
    glutKeyboardFunc(keyboard);
    
    glutDisplayFunc(display); // visual display function
    
    glutIdleFunc(idle);
    keyBoardFunctions();// initial message to guide user
    glutMainLoop();
}
