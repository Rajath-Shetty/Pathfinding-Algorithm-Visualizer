#include <GL/glut.h>
#include "tile.h"
#include <iostream>


Tile::Tile(int ax, int ay, int asize, int  astate, int ahighlighted) {

	x = ax;
	y = ay;
	size = asize;
	state = astate;
	highlighted = ahighlighted;

}
void Tile::setTileColor() {
		
		
	if (state == 1)							//black
		glColor3f(0.0f, 0.0f, 0.0f);
	else if (state == -1)					//Blue
		glColor3f(0.0f, 0.0f, 1.0f);
	else if (state == 0)					//Green
		glColor3f(0.0f, 1.0f, 0.0f);
	else if (highlighted == -2)				//Final path
		glColor3f(0.0, 0.9, 0.9);
	else if (highlighted == -1)
		glColor3f(0.9, 0.3, 0.3);
	else if (state == 2)					//white
		glColor3f(1.0f, 1.0f, 1.0f);
	else
		glColor3f(0.0f, 0.0f, 1.0f);	//Blue
	
}

void drawTile(Tile *tile) {
	
	tile->setTileColor();
	glBegin(GL_QUADS);
	glVertex2f(tile->x			   , tile->y			 );
	glVertex2f(tile->x             , tile->y + tile->size);
	glVertex2f(tile->x + tile->size, tile->y + tile->size);
	glVertex2f(tile->x + tile->size, tile->y			 );
	glEnd();
	
	//Draw border for each tile 
	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(tile->x			   , tile->y			 );
		glVertex2f(tile->x             , tile->y + tile->size);
		glVertex2f(tile->x + tile->size, tile->y + tile->size);
		glVertex2f(tile->x + tile->size, tile->y			 );
	glEnd();
}

