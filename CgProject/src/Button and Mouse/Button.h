#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

typedef void (*ButtonCallback)();
	class Button {
	public:
		char* label;
		int x;
		int y;
		int w;
		int state;
		int h;
		ButtonCallback callbackFunction;

		Button(char* alabel, int ax, int ay, int aw, int ah,int astate,ButtonCallback acallbackFunction);

		void setButtonColor(int mode);
	};
	void drawButton(Button* button);
	void Font(void* font, char* text, int x, int y);
#endif