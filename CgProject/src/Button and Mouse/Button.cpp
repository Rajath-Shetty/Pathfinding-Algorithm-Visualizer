#include <GL/glut.h>
#include <iostream>
#include "Button.h"

Button::Button(char* alabel, int ax, int ay, int aw, int ah,int astate, ButtonCallback acallbackFunction) {
	label = alabel;
	x = ax;
	y = ay;
	w = aw;
	h = ah;
	state = astate;
	callbackFunction = acallbackFunction;
	
}

void Button::setButtonColor(int mode) {
	if (mode == 1)//clicked
		glColor3f(0.0f, 0.0f, 0.0f);
	else
		glColor3f(1.0f, 0.5f, 0.0f);
}
void drawButton(Button* b) {
	int fontx;
	int fonty;
	
	fontx = b->x + (b->w - glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)b->label)) / 2;
	fonty = b->y + (b->h + 10) / 2;



	if (b->state == 1)//clicked
		glColor3f(0.2f, 0.2f, 0.2f);
	else
		glColor3f(1.0f, 0.5f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(b->x, b->y);
	glVertex2f(b->x, b->y + b->h);
	glVertex2f(b->x + b->w, b->y + b->h);
	glVertex2f(b->x + b->w, b->y);
	glEnd();

	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(b->x, b->y);
	glVertex2f(b->x, b->y + b->h);
	glVertex2f(b->x + b->w, b->y + b->h);
	glVertex2f(b->x + b->w, b->y);
	glEnd();

	if (b->state == 1)//clicked
		glColor3f(1.0f, 1.0f, 1.0f);
	else
		glColor3f(0.0f, 0.0f, 0.0f);
	Font(GLUT_BITMAP_HELVETICA_10, b->label, fontx, fonty);
}

void Font(void* font, char* text, int x, int y)
{
	glRasterPos2i(x, y);

	while (*text != '\0')
	{
		glutBitmapCharacter(font, *text);
		++text;
	}
}
