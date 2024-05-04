#pragma once
#include "initial.h"

class rec_button {
private:
	int Lx, Ly, Rx, Ry;
	COLORREF basiccol, textcol, clickcol, linecol, rescol;

public:
	rec_button(int lx, int ly, int rx, int ry, COLORREF A, COLORREF B, COLORREF C, COLORREF D, COLORREF E) {
		Lx = lx; Ly = ly; Rx = rx; Ry = ry;
		basiccol = A; textcol = B; clickcol = C; linecol = D; rescol = E;
		setfillcolor(basiccol);
		setlinecolor(linecol);
		fillrectangle(Lx, Ly, Rx, Ry);
	}
	bool click(int X, int Y, bool Clicked) {
		if (Clicked) {
			if ((X >= Lx && X <= Rx) && (Y >= Ly && Y <= Ry)) {
				setfillcolor(clickcol);
				setlinecolor(linecol);
				fillrectangle(Lx, Ly, Rx, Ry);
				return true;
			}
		}
		return false;
	}
	void reset() {
		setfillcolor(basiccol);
		setlinecolor(linecol);
		fillrectangle(Lx, Ly, Rx, Ry);
	}
	void writetext(TCHAR txt[]) {
		settextcolor(txtcol);
		settextstyle(Ry - Ly, (Rx - Lx) / TCH_Length(txt), _T("Cosolas"));
		outtextxy(Lx, Ly, txt);
	}
};
class c_button {
private:
	int X, Y;double R;
	COLORREF basiccol, textcol, clickcol, linecol, rescol;

public:
	c_button(int x,int y,double r, COLORREF A, COLORREF B, COLORREF C, COLORREF D, COLORREF E) {
		X = x; Y = y; R = r;
		basiccol = A; textcol = B; clickcol = C; linecol = D; rescol = E;
		setfillcolor(basiccol);
		setlinecolor(linecol);
		fillcircle(X, Y, R);
	}
	bool click(int x, int y, bool Clicked) {
		if (Clicked) {
			if (dist2(x, y, X, Y) <R*R) {
				setfillcolor(clickcol);
				setlinecolor(linecol);
				fillcircle(X,Y,R);
				return true;
			}
		}
		return false;
	}
	void reset() {
		setfillcolor(basiccol);
		setlinecolor(linecol);
		fillcircle(X, Y, R);
	}
	void writetext(TCHAR* txt) {
		settextcolor(txtcol);
		settextstyle(R*1.414, (R*2) / TCH_Length(txt), _T("Cosolas"));
		outtextxy((int)(X-(R*1.414/2)), (int)(Y - (R * 1.414 / 2)),txt);
	}
};
