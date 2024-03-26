#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define NUMBER_OF_THEMES 6
#define UP_ARROW 80
#define DOWN_ARROW 72
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define ENTER_KEY 13
#define ESC_KEY 27

int themeForeColor;
int MenuStartSequeceOnOff;
extern void MenuStartSequece();
extern void MenuMainLoop();
extern void ReadSettings();

#endif // MENU_H_INCLUDED
