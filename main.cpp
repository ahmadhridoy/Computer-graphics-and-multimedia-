#include <GL/glut.h>
#include <cmath>

int windowWidth = 800;
int windowHeight = 600;

void drawLineDirect(float x1, float y1, float x2, float y2) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; ++i) {
        glVertex2f(x, y);
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();

    glFlush();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawLineDirect(100, 100, 500, 400);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Direct Equation Line Algorithm");
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
