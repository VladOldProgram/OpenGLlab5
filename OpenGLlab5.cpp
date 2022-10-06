#include <iostream>
#include <glut.h>

#define _USE_MATH_DEFINES
#include <math.h>

class SpaceObject {
public:
    float distance, orbit, orbitStepSize;
    SpaceObject(float newDistance, float newOrbit, float newOrbitStepSize) {
        distance = newDistance;
        orbit = newOrbit;
        orbitStepSize = newOrbitStepSize;
    }
};

SpaceObject sun(0.0f, 0.0f, 0.0f);
SpaceObject mercury(-12.0f, 0.0f, 4.8f);
SpaceObject venus(-13.2f, 0.0f, 3.5f);
SpaceObject earth(-15.2f, 0.0f, 3.0f);
SpaceObject moon(-1.0f, 0.0f, 5.4f);
SpaceObject mars(-17.5f, 0.0f, 2.4f);
SpaceObject jupiter(-22.0f, 0.0f, 1.3f);
SpaceObject saturn(-26.5f, 0.0f, 1.0f);
SpaceObject saturnRings(0.0f, 0.0f, 1.0f);
SpaceObject uranus(-30.0f, 0.0f, 0.7f);
SpaceObject neptune(-34.0f, 0.0f, 0.5f);

bool animationIsEnabled = false;

void Animate(int id)
{
    if (animationIsEnabled) {
        mercury.orbit += mercury.orbitStepSize;
        venus.orbit += venus.orbitStepSize;
        earth.orbit += earth.orbitStepSize;
        moon.orbit += moon.orbitStepSize;
        mars.orbit += mars.orbitStepSize;
        jupiter.orbit += jupiter.orbitStepSize;
        saturn.orbit += saturn.orbitStepSize;
        uranus.orbit += uranus.orbitStepSize;
        neptune.orbit += neptune.orbitStepSize;

        if (mercury.orbit > 360.0) mercury.orbit -= 360.0;
        if (venus.orbit > 360.0) venus.orbit -= 360.0;
        if (earth.orbit > 360.0) earth.orbit -= 360.0;
        if (moon.orbit > 360.0) moon.orbit -= 360.0;
        if (mars.orbit > 360.0) mars.orbit -= 360.0;
        if (jupiter.orbit > 360.0) jupiter.orbit -= 360.0;
        if (saturn.orbit > 360.0) saturn.orbit -= 360.0;
        if (uranus.orbit > 360.0) uranus.orbit -= 360.0;
        if (neptune.orbit > 360.0) neptune.orbit -= 360.0;

        glutPostRedisplay();
        glutTimerFunc(30, Animate, 0);
    }
}

void EnableAnimation(unsigned char key, int x, int y)
{
    if (key == ' ') {
        if (animationIsEnabled) {
            animationIsEnabled = false;
        } 
        else {
            animationIsEnabled = true;
            Animate(0);
        }
    }
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    GLfloat light0_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    GLfloat light0_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    GLfloat light0_position[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glEnable(GL_LIGHT0);

    glColor3f(1.0f, 1.0f, 0.3f);
    glutSolidSphere(8, 80, 80);

    glPushMatrix();
    glRotatef(mercury.orbit, 0.0f, 1.0f, 0.7f);
    glTranslatef(mercury.distance, 0.0f, 0.0f);
    glColor3f(0.26f, 0.29f, 0.29f);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glRotatef(venus.orbit, 0.0f, 1.0f, 0.7f);
    glTranslatef(venus.distance, 0.0f, 0.0f);
    glColor3f(0.35f, 0.17f, 0.075f);
    glutSolidSphere(0.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(earth.orbit, 0.0f, 1.0f, 0.7f);
    glTranslatef(earth.distance, 0.0f, 0.0f);
    glColor3f(0.14f, 0.25f, 0.35f);
    glutSolidSphere(0.7, 40, 40);
    glPushMatrix();
    glRotatef(moon.orbit, 0.0f, 1.0f, 0.7f);
    glTranslatef(moon.distance, 0.0f, 0.0f);
    glColor3f(0.84f, 0.92f, 0.97f);
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glRotatef(mars.orbit, 0.0f, 1.0f, 0.7f);
    glTranslatef(mars.distance, 0.0f, 0.0f);
    glColor3f(0.39f, 0.12f, 0.09f);
    glutSolidSphere(0.6, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glRotatef(jupiter.orbit, 0.0f, 1.0f, 0.7f);
    glTranslatef(jupiter.distance, 0.0f, 0.0f);
    glColor3f(0.9f, 0.6f, 0.4f);
    glutSolidSphere(2.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(saturn.orbit, 0.0f, 1.0f, 0.7f);
    glTranslatef(saturn.distance, 0.0f, 0.0f);
    glColor3f(0.9f, 0.4f, 0.2f);
    glutSolidSphere(1.3, 40, 40);
    glPushMatrix();
    glTranslatef(saturnRings.distance, 0.0f, 0.0f);
    glColor3f(0.4f, 0.4f, 0.4f);
    GLUquadricObj* quadric = gluNewQuadric();
    gluDisk(quadric, 1.45, 1.75, 20, 1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glRotatef(uranus.orbit, 0.0f, 1.0f, 0.7f);
    glTranslatef(uranus.distance, 0.0f, 0.0f);
    glColor3f(0.18f, 0.52f, 0.76f);
    glutSolidSphere(1.0, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glRotatef(neptune.orbit, 0.0f, 1.0f, 0.7f);
    glTranslatef(neptune.distance, 0.0f, 0.0f);
    glColor3f(0.08f, 0.26f, 0.38f);
    glutSolidSphere(1.0, 40, 40);
    glPopMatrix();

    glutSwapBuffers();
}

void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-35.0, 35.0, -35.0, 35.0, -35.0, 35.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("OpenGL lab 5");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glutReshapeFunc(Reshape);
    glutDisplayFunc(Display);
    glutKeyboardFunc(EnableAnimation);

    glutMainLoop();

    return 0;
}