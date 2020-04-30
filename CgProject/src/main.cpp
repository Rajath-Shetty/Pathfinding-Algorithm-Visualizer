//#include <GL/glew.h>
#include <windows.h>  // For MS Windows
#include <GL/glut.h>
#include <iostream>
#include "GameManager.h"


void init()
{   
    glClearColor(0.2, 0.2, 0.2, 1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
     drawGui(gui); 
     drawGrid(g);
    glutSwapBuffers();
}


void reshapeCallback(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1100,900,0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

Button* ButtonPressed(int x, int y) {
    int buttonSize = windowH /9;
    int i = y / buttonSize;
    std::cout <<i <<": btn pressed"<< std::endl;
    return &gui->btns[i];
}

Tile* TilePressed(int x, int y) {
    int tileSize = windowH / rows;
    int i = x / tileSize;
    int j = y / tileSize;
    return &g->tiles[i][j];
}
int TileCord(int x) {
    int tileSize = windowH / rows;
    int i = x / tileSize;
    return i;
}
void ButtonToggle(Button* b) {

    if (b->state == 0) {
        b->state = 1;
        prevClicked->state = 0;
    }
    glutPostRedisplay();
    prevClicked = b;
    b->callbackFunction();
}



/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


void mouseCallback(int button, int state, int x, int y)
{
    if (x > windowH && x<windowW && y>-1 && y < windowH) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            ButtonToggle(ButtonPressed(x, y));

        }
    }
    if (x < windowH && y<windowH && x>-1 && y>-1) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            Tile* t = TilePressed(x, y);
            if (gameState.mapEditState == -1)   //->Start point
            {
                previousStartingPoint->state = 2;
                sx = TileCord(x);
                sy = TileCord(y);
                std::cout << sy << " " << sx;
                t->state = -1;                  //Red
                previousStartingPoint = t;
            }
            if (gameState.mapEditState == 0)    //->Ending point
            {
                    previousEndingPoint->state = 2;
                    ex = TileCord(x);
                    ey = TileCord(y);
                    std::cout << ey << " " << ex;
                t->state = 0;                   //Green
                previousEndingPoint = t;
            }
        }
    }
}

void mouseMotionCallback(int x, int y) {

    //Draw the non-traversable path and clear the non-traversable path 
    if (x < windowH && y<windowH && x>-1 && y>-1) {
        int tileSize = windowH / rows;
        int i = x / tileSize;
        int j = y / tileSize;
        if(gameState.mapEditState == 1)     //->Walled
            g->tiles[i][j].state = 1;       //Black
        if (gameState.mapEditState == 2)    //->Clear
            g->tiles[i][j].state = 2;       //White
        glutPostRedisplay();
    }
   
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{
    intiGameManager();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(windowW, windowH);
    glutInitWindowPosition(1400, 5);
    glutCreateWindow("Shortest Path Algo Simulation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeCallback);
    glutMouseFunc(mouseCallback);
    glutMotionFunc(mouseMotionCallback);
    init();
    glutMainLoop();
    return 0;
}