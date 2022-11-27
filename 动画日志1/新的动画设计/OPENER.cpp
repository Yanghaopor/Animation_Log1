#include "stdio.h"
#include "iostream"
#include "conio.h"
#include "string"
#include "easyx.h"
#include "graphics.h"
#include "windows.h"
using namespace std;
struct xy
{
	int x=0, y=0;
	IMAGE op;
};
struct imper
{
	xy ui[999];
};
int level()
{

}
int techar()
{
	clearcliprgn();
	imper ui;
	initgraph(800, 400, EX_SHOWCONSOLE);
	loadimage(&ui.ui[0].op, L"0001.jpg");
	loadimage(&ui.ui[1].op, L"0002.jpg");
	loadimage(&ui.ui[2].op, L"0003.jpg");
	loadimage(&ui.ui[3].op, L"0004.jpg");
	loadimage(&ui.ui[4].op, L"0005.jpg");
	loadimage(&ui.ui[5].op, L"0006.jpg");
	settextcolor(RGB(255, 255, 255));
	settextstyle(40, 20, L"Œ¢»Ì—≈∫⁄");
	for (int i = -800; i <= 0; i ++)
	{
		Sleep(10);
		cleardevice();
		BeginBatchDraw();
		putimage(0, 0, &ui.ui[0].op);
		putimage(i, 385, &ui.ui[1].op);
		putimage(0, 0, &ui.ui[2].op);
		putimage(150, -20, &ui.ui[3].op);
		settextcolor(RGB(255, 255, 255));
		EndBatchDraw();
		cout << i << endl;
	}
	return 3;
}
void Map(imper *ui)
{
	clearcliprgn();
	initgraph(1000, 600, EX_SHOWCONSOLE);
	settextcolor(RGB(255, 255, 255));
	settextstyle(40,20, L"Œ¢»Ì—≈∫⁄");
	while(true)
	{
		while(true)
		{
			MOUSEMSG opmsg = GetMouseMsg();
			int i = -200, i1 = -200, i2 = -200;
			while (true)
			{
				MOUSEMSG opmsg = GetMouseMsg();
				switch (opmsg.uMsg)
				{
				case WM_LBUTTONDOWN:
					cout << "ok" << endl;
					if(opmsg.x<=210&& opmsg.y < 90)
					{
						int o=techar();
						clearcliprgn();
						initgraph(1000, 600, EX_SHOWCONSOLE);
						settextcolor(RGB(255, 255, 255));
						settextstyle(40, 20, L"Œ¢»Ì—≈∫⁄");
						cout << o << endl;
					}
					break;
				default:
					break;
				}
				//i
				if (opmsg.x <= 210 && opmsg.y < 90&&i<40)
				{
					i=i+20;
					cout << i << endl;
				}
				if(opmsg.x > 210 || opmsg.y > 80 )
				{
					if (i > -200)
					{
						i = i - 20;
						cout << i << endl;
					}
					cout << i << endl;
				}
				//i1
				if(opmsg.x<210&&opmsg.y>90&&opmsg.y<150&&i1<40)
				{
					i1 = i1 + 20;
				}
				if(opmsg.x > 210|| opmsg.y < 90|| opmsg.y > 150)
				{
					if (i1 > -200)
					{
						i1 = i1 - 20;
						cout << i1 << endl;
					}
				}
				//i2
				if (opmsg.x < 210 && opmsg.y>150 && opmsg.y < 200 && i2 < 40)
				{
					i2 = i2 + 20;
				}
				if (opmsg.x > 210 || opmsg.y < 150 || opmsg.y > 200)
				{
					if (i2> -200)
					{
						i2 = i2 - 20;
						cout << i2 << endl;
					}
				}
				
				cleardevice();
				BeginBatchDraw();
				BeginBatchDraw();
				putimage(0, 0, &ui->ui[4].op);
				setbkmode(TRANSPARENT);
				outtextxy(i, 40, L"ø™ º”Œœ∑");
				outtextxy(i1, 100, L"”Œœ∑…Ë÷√");
				outtextxy(i2, 180, L"ÕÀ≥ˆ”Œœ∑");
				EndBatchDraw();
				EndBatchDraw();
				cout << opmsg.x << "," << opmsg.y << endl;
			}
		}
	}
}
void main() 
{
	imper ui;
	initgraph(800,400,EX_SHOWCONSOLE);
	loadimage(&ui.ui[0].op, L"0001.jpg");
	loadimage(&ui.ui[1].op, L"0002.jpg");
	loadimage(&ui.ui[2].op, L"0003.jpg");
	loadimage(&ui.ui[3].op, L"0004.jpg");
	loadimage(&ui.ui[4].op, L"0005.jpg");
	loadimage(&ui.ui[5].op, L"0006.jpg");
	for(int i=-800;i<=0;i++)
	{
		Sleep(10);
		cleardevice();
		BeginBatchDraw();
		putimage(0, 0, &ui.ui[0].op);
		putimage(i, 385, &ui.ui[1].op);
		putimage(0, 0, &ui.ui[2].op);
		putimage(150,-20, &ui.ui[3].op);
		EndBatchDraw();
		cout << i << endl;
	}
	clearcliprgn();
	Map(&ui);
	getchar();
}