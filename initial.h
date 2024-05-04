#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<windows.h>
#include<mmsystem.h>

const int Lenx[10] = { 0,5,8,10,12,15,16 };
const int Hint[10] = { 0,3,5,6,8,10,12 };
const int Leny[10] = { 0,5,8,10,10,15,16 };
const int MAXWID = 960, MAXLEN = 1200, PROLEN = 1000, PROWID = 800;
int TCH_Length(TCHAR str[]) {
	int i = 0; while (str[i]) i++;
	return i;
}
bool level[10] = { false,true, false, false, false, false,false }; int prog(1);
ExMessage m;
COLORREF bkcol = BLACK, txtcol = RGB(40, 255, 10);
double dist2(int x, int y, int a, int b) {
	return (x - a) * (x - a) + (y - b) * (y - b);
}
IMAGE Locked_barrer, background,conquer,main_bk,opt_bk,sel_on,sel_off;
COLORREF Diverse_col(COLORREF col) {
	if (GetRValue(col) + GetBValue(col) < GetGValue(col)) {
		return RED;
	}
	return GREEN;
}