#include "button.h"

int mainstage();
void about();
void mainselect();
void levelselect();
void setup(int);
bool problem(int);

int main() {
	initgraph(MAXLEN, MAXWID);
	loadimage(&Locked_barrer, _T("locked_barrer.jpg"), 100, 100, false);
	loadimage(&background, _T("bk.jpg"), MAXLEN, MAXWID, false);
	loadimage(&conquer, _T("Conquer.jpg"), 1000, 850, false);
	loadimage(&main_bk, _T("main_bk.jpg"), MAXLEN, MAXWID, false);
	loadimage(&sel_on, _T("switch_on.jpg"), 300, 300, false);
	loadimage(&sel_off, _T("switch_off.jpg"), 300, 300, false);
	loadimage(&opt_bk, _T("opt.jpg"), 600, 300);
	std::cout << "Game name :" << "My Sense of Color is Amazing!" << '\n';
	std::cout << "Programmed in C++ ,based on EasyX 2023, Run on WINDOWS" << '\n';
	std::cout << "You may try to click swiftly,avoiding slice when click ,to avoid sensed errors" << '\n';
	std::cout << "Current Progress :" << prog << '\n';
	if (prog == 7) std::cout << "All stages cleared." << '\n';
	char ope[2];
	while (1) {
		std::cout << "Press 'S' to start game" << '\n';
		std::cout << "Press 'E' to exit" << '\n';
		std::cin >> ope;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cout << "Illegal input" << '\n';
		}
		else if (ope[0] == 'S'||ope[0]=='s') mainselect();
		else if (ope[0] == 'E'||ope[0]=='e') break;
	}
	std::cout << "Game Ended" << '\n';
	return 0;
}
int mainstage() {
	Sleep(50);
	setbkcolor(bkcol);
	cleardevice();
	putimage(0, 0, &main_bk);
	setbkmode(TRANSPARENT);
	settextcolor(txtcol);
	settextstyle(200, 40, _T("Conrolas"));
	outtextxy(18, 0, _T("My Sense of Colour is Amazing"));
	rec_button START(400, 300, 800, 500, RGB(10, 215, 237), RGB(224, 237, 5), RGB(237, 85, 60), RED, RGB(230, 88, 237));
	TCHAR tx[6] = _T("START"); START.writetext(tx);
	rec_button EXIT(790, 800, 1200, 960, RGB(10, 215, 237), RGB(224, 237, 5), RGB(237, 85, 60), RED, RGB(230, 88, 237));
	TCHAR tX[5] = _T("EXIT"); EXIT.writetext(tX);
	rec_button ABOUT(0, 800, 410, 960, RGB(10, 215, 237), RGB(224, 237, 5), RGB(237, 85, 60), RED, RGB(230, 88, 237));
	TCHAR TX[6] = _T("ABOUT"); ABOUT.writetext(TX);
	flushmessage();
	while (1) {
		m = getmessage(EX_MOUSE);
		if (START.click(m.x, m.y, m.lbutton)) return 1;
		else if (EXIT.click(m.x, m.y, m.lbutton || m.rbutton)) { cleardevice(); return 0; }
		else if (ABOUT.click(m.x, m.y, m.lbutton || m.rbutton)) return 3;
	}
}

/*
Lv 1. [120,150]
Lv 2. [100,120]
Lv 3. [75,100]
Lv 4. [60 75]
Lv 5. [50,60]
Lv 6. [35,50]
*/
const int Dif[2][7] = { {0,40,30,25,20,15,12},{0,60,45,30,25,20,16} };
void setup(int k) {
	for (int i = 1; i <= 12; i++) {
		bool ope = problem(k);
		if (!ope) {
			levelselect();
			return;
		}
	}
	cleardevice();
	putimage(100, 110, &conquer);
	settextstyle(100, 0, _T("Conrolas"));
	outtextxy(0, 0, _T("Congragulations!"));
	if (prog < k+1) prog = k+1;
	Sleep(1500);
	levelselect();
}
bool problem(int k) {//[ Dif[0][k],Dif[1][k] ]
	srand(time(NULL));
	cleardevice();
	bool hinted(false);
	int Val = (rand() % (Dif[1][k] - Dif[0][k] + 1)) + Dif[0][k];
	int cR = rand() % 256;
	int cG = rand() % 256;
	int cB = rand() % 256;
	int cX = (rand() % (Lenx[k]));//[1,Lenx[k]]
	int cY = (rand() % (Leny[k]));//[1,Leny[k]]
	int vR = (rand() % Val);
	int vG = rand() % (Val - vR),vB;// [0, Val - vR]
	if (Val - vR - vG + cB > 255) vB = cB - (Val - vR - vG);
	else vB = cB + Val - vR - vG;
	if (vR + cR > 255) vR = cR - vR;
	else vR = cR + vR;
	if (vG + cG > 255) vG = cG - vG;
	else vG = cG + vG;
	setfillcolor(RGB(cR, cG, cB));
	setlinecolor(BLACK);
	for (int x = 0; x < PROLEN; x+=PROLEN/Lenx[k]) {
		for (int y = 0; y < PROWID; y += PROWID / Leny[k]) {
			fillrectangle(x, y, x + PROLEN / Lenx[k], y + PROWID / Leny[k]);
		}
	}
	setfillcolor(RGB(vR, vG, vB));
	fillrectangle(cX * (PROLEN / Lenx[k]), cY * (PROWID / Leny[k]), (cX+1)* (PROLEN / Lenx[k]), (cY+1) * (PROWID / Leny[k]));
	rec_button hint(1080, 200, 1175, 340, RGB(10, 215, 237), RGB(224, 237, 5), RGB(237, 85, 60), RED, RGB(230, 88, 237));
	TCHAR TCH[5] = _T("HINT"); hint.writetext(TCH);
	rec_button exit(960, 820, 1200, 960, RGB(10, 215, 237), RGB(224, 237, 5), RGB(237, 85, 60), RED, RGB(230, 88, 237));
	TCHAR RTH[5] = _T("EXIT"); exit.writetext(RTH);
	Sleep(100);
	while (1) {
		flushmessage();
		m = getmessage();
		if (hint.click(m.x, m.y, m.lbutton)&&!hinted) {
				hinted = true;
				int sx = max(0, cX - Hint[k] + 1), sy = max(0, cY - Hint[k] + 1), ex = min(Lenx[k]-1 - Hint[k]+1,cX), ey = min(Leny[k]-1 - Hint[k]+1, cY);
				int myx = (rand() % (ex - sx + 1)) + sx, myy = (rand() % (ey - sy + 1)) + sy;
				setlinecolor(Diverse_col(RGB(cR, cG, cB))); setlinestyle(BS_SOLID, 5);
				rectangle(myx * (PROLEN / Lenx[k]), myy * (PROWID / Leny[k]), (myx + Hint[k]) * (PROLEN / Lenx[k]), (myy + Hint[k]) * (PROWID / Leny[k]));
				setlinestyle(BS_SOLID, 1); setlinecolor(BLACK);
				Sleep(54);
		}
		else if (exit.click(m.x, m.y, m.lbutton)) {
			Sleep(100);
			return false;
		}
		else if (m.x<=PROLEN&&m.y<=PROWID&&m.lbutton) {
			if (m.x >= cX * (PROLEN / Lenx[k]) && m.y >= cY * (PROWID / Leny[k]) && m.x <= (cX + 1) * (PROLEN / Lenx[k]) && m.y <= (cY + 1) * (PROWID / Leny[k])) {
				return true;
			}
			else {
				settextstyle(60, 0, _T("Consolas"));
				int base;
				if (cX <= Lenx[k] / 2) base = PROWID / 2;
				else base = 0;
				setlinecolor(Diverse_col(RGB(cR, cG, cB))); setlinestyle(BS_SOLID, 5);
				rectangle(cX * (PROLEN / Lenx[k]), cY * (PROWID / Leny[k]), (cX + 1) * (PROLEN / Lenx[k]), (cY + 1) * (PROWID / Leny[k]));
				setlinestyle(BS_SOLID, 1); setlinecolor(BLACK);
				settextcolor(Diverse_col(RGB(cR, cG, cB)));
				TCHAR str[50];
				_stprintf(str, _T("Normal Color RGB: (%d ,%d ,%d)"), cR, cG, cB);
				outtextxy(100, base, str);
				_stprintf(str, _T("Target Color RGB: (%d ,%d ,%d)"), vR, vG, vB);
				outtextxy(100, base+60, str);
				_stprintf(str, _T("Target Position : (%d , %d)"), cY+1, cX+1);
				outtextxy(100, base+150, str);
				_stprintf(str, _T("Click Anywhere To Continue _"));
				outtextxy(100, base+220, str);
				Sleep(100);
				flushmessage();
				while (1) {
					m = getmessage(EX_MOUSE);
					if(m.lbutton) return false;
				}
			}
			
		}
	}
}
void about() {
	cleardevice();
	settextcolor(txtcol);
	settextcolor(RGB(20, 255, 270));
	settextstyle(200, 40, _T("Conrolas"));
	outtextxy(18, 0, _T("My Sense of Colour is Amazing"));
	settextstyle(50, 0, _T("Conrolas"));
	outtextxy(20, 250, _T("Programmer : Kinv Tsuki"));
	outtextxy(20, 300, _T("Designer :Kinv Tsuki"));
	outtextxy(20, 350, _T("Version :v 1.0"));
	outtextxy(20, 400, _T("Thank You For Playing"));
	outtextxy(20, 480, _T("Feedback mail address: 2134361910@qq.com"));
	outtextxy(500, 700, _T("Click anywhere to return_"));
	Sleep(200);
	flushmessage();
	while (1) {
		m = getmessage(EX_MOUSE);
		if (m.lbutton || m.rbutton) {
			return;
		}
	}
}

void mainselect() {
	std::cout << "Current progress: Barrier " << prog << '\n';
	int ope = mainstage();
	if (ope == 1) {
		levelselect();
	}
	else if (ope == 3) {
		about();
		mainselect();
	}
	else return;
}
void levelselect() {
	setbkcolor(bkcol);
	cleardevice();
	putimage(0, 0, &background);
	for (int i = 1; i <= prog; i++) level[i] = true;
	std::vector<c_button> Bar;
	for (int x = 300; x <= 600; x += 300) {
		for (int y = 300; y <= 900; y += 300) {
			int bnum = (x / 600) * 3 + y / 300;
			if (!level[bnum]) {
				putimage(y, x, &Locked_barrer);
			}
			else {
				c_button r(y + 50, x + 50, 50, RGB(10, 215, 237), RGB(224, 237, 5), RGB(237, 85, 60), RED, RGB(230, 88, 237));
				Bar.push_back(r);
				r.reset();
				TCHAR C[2];
				_stprintf(C, _T("%d"), bnum);
				r.writetext(C);
			}
		}
	}
	rec_button exit(900, 800, 1200, 960, RGB(10, 215, 237), RGB(224, 237, 5), RGB(237, 85, 60), RED, RGB(230, 88, 237));
	TCHAR TX[5] = _T("Back"); exit.writetext(TX);
	settextstyle(40, 0, _T("Consolas"));
	if (prog == 7) outtextxy(300, 700, _T("All Barriers Solved !"));
	int sel(0);
	while (1) {
		flushmessage();
		m = getmessage(EX_MOUSE);
		for (std::vector<c_button>::iterator it = Bar.begin(); it != Bar.end(); it++) {
			c_button p = *it;
			if (p.click(m.x, m.y, m.lbutton)) {
				sel = it - Bar.begin() + 1;
			}
		}
		if (sel) break;
		if (exit.click(m.x, m.y, m.lbutton)) break;
	}
	if (!sel) mainselect();
	else setup(sel);
}