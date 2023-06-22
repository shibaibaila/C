#include "teacher_表格.h"
#include"系统__父类.h"
#include"teacher.h"
ExMessage msg = { 0 };
int teacher_表格::gai_yan_se(int l, int t, int r, int b)
{
	setlinestyle(PS_SOLID, 2);
	if (zai_fan_wei_nei(l, t, r, b))
	{
		setfillcolor(RGB(192, 255, 62));//要先改颜色，再造方块
		fillrectangle(l, t, r, b);
		return 1;
	}
	else
	{
		setfillcolor(RGB(255, 233, 131));//按钮 的 颜色
		fillrectangle(l, t, r, b);
		//zao_zi_han_shu("说明", l, t, r, b);

	}

	return 0;
}
int teacher_表格::zao_zi_han_shu(string biao_ti, int l, int t, int r, int b)
{
	setbkmode(TRANSPARENT);//背景 模式,,可使 字体的颜色改变
	settextstyle(25, 0, _T("粗体"));
	settextcolor(WHITE);//显示的 字体颜色
	int h = (b - t - 28) / 2;
	int w = (r - l - 101) / 2;
	outtextxy(w + l, h + t, biao_ti.c_str());

	return 0;
}
int teacher_表格::zai_fan_wei_nei(int l, int t, int r, int b)
{
	if (msg.x > l && msg.x<r && msg.y>t && msg.y < b)
	{
		return 1;
	}
	return 0;
}

int teacher_表格::zao_zi_han_shu2(string biao_ti, int l, int t, int r, int b)
{
	setbkmode(TRANSPARENT);//背景 模式,,可使 字体的颜色改变
	settextstyle(25, 0, _T("粗体"));
	settextcolor(WHITE);//显示的 字体颜色
	int h = (b - t - 28) / 2;
	int w = (r - l - 188) / 2;
	outtextxy(w + l, h + t, biao_ti.c_str());

	return 0;
}

int teacher_表格::zao_zi_han_shu3(string biao_ti, int l, int t, int r, int b)
{
	setbkmode(TRANSPARENT);//背景 模式,,可使 字体的颜色改变
	settextstyle(25, 0, _T("粗体"));
	settextcolor(WHITE);//显示的 字体颜色
	int h = (b - t - 28) / 2;
	int w = (r - l - 8) / 2;
	outtextxy(w + l, h + t, biao_ti.c_str());

	return 0;
}


int teacher_表格::an_niu(string a, int l, int t, int r, int b)
{
	//ExMessage msg = { 0 };//不可以再在这里 加上，，会使获取的 鼠标位置错误
	//while (1)
	{
		//int dianji = 0;
		MOUSEMSG key;
		key = GetMouseMsg();
		BeginBatchDraw();
		setlinecolor(WHITE);//-----------开始 建造小按钮
		peekmessage(&msg);
		if (gai_yan_se(l, t, r, b))
		{

			if (key.uMsg == WM_LBUTTONDOWN)//---------------------点击后，，进入游戏
			{
				return 1;
			}
		}
		zao_zi_han_shu(a, l, t, r, b);
		EndBatchDraw();
		system("cls");
		msg.message = 0;
	}

	return 0;
}

int teacher_表格::an_niu2(string a, int l, int t, int r, int b)
{
	//while (1)
	{
		int dianji = 0;
		MOUSEMSG key = GetMouseMsg();
		BeginBatchDraw();
		setlinecolor(WHITE);//-----------开始 建造小按钮
		peekmessage(&msg);
		if (gai_yan_se(l, t, r, b))
		{

			if (key.uMsg == WM_LBUTTONDOWN)//---------------------点击后，，进入输入信息
			{
				return 1;
			}
		}
		zao_zi_han_shu2(a, l, t, r, b);
		EndBatchDraw();
		system("cls");
		msg.message = 0;
	}

	return 0;
}

int teacher_表格::zao_zi_han_shu4(string biao_ti, int l, int t, int r, int b)
{
	setbkmode(TRANSPARENT);//背景 模式,,可使 字体的颜色改变
	settextstyle(25, 0, _T("粗体"));
	settextcolor(WHITE);//显示的 字体颜色
	int h = (b - t - 28) / 2;
	int w = (r - l - 48) / 2;
	outtextxy(w + l, h + t, biao_ti.c_str());

	return 0;
}

int teacher_表格::an_niu3(string a, int l, int t, int r, int b)
{
	{
		//int dianji = 0;
		//MOUSEMSG key = GetMouseMsg();
		//BeginBatchDraw();
		setlinecolor(WHITE);//-----------开始 建造小按钮
		//peekmessage(&msg);
		//if (gai_yan_se(l, t, r, b))
		{

			//if (key.uMsg == WM_LBUTTONDOWN)//---------------------点击后，，进入输入信息
			//{
			//	return 1;
			//}
		}
		setfillcolor(RGB(255, 233, 131));//按钮 的 颜色
		fillrectangle(l, t, r, b);

		zao_zi_han_shu4(a, l, t, r, b);
		//EndBatchDraw();
		system("cls");
		msg.message = 0;
	}

	return 0;
}

int teacher_表格::an_niu4(string a, int l, int t, int r, int b)
{
	{
		//int dianji = 0;
		MOUSEMSG key = GetMouseMsg();
		BeginBatchDraw();
		setlinecolor(WHITE);//-----------开始 建造小按钮
		peekmessage(&msg);
		if (gai_yan_se(l, t, r, b))
		{

			if (key.uMsg == WM_LBUTTONDOWN)//---------------------点击后，，进入输入信息
			{
				return 1;
			}
		}
		//setfillcolor(RGB(255, 233, 131));//按钮 的 颜色
		//fillrectangle(l, t, r, b);

		zao_zi_han_shu4(a, l, t, r, b);
		EndBatchDraw();
		system("cls");
		msg.message = 0;
	}
	return 0;
}

int teacher_表格::an_niu5(string a, int l, int t, int r, int b)
{
	setfillcolor(RGB(255, 233, 131));//按钮 的 颜色
	fillrectangle(l, t, r, b);
	setbkmode(TRANSPARENT);//背景 模式,,可使 字体的颜色改变
	settextstyle(48, 0, _T("粗体"));
	settextcolor(WHITE);//显示的 字体颜色
	int h = (b - t - 28) / 2;
	int w = (r - l - 188) / 2;
	outtextxy(w + l, h + t, a.c_str());
	return 0;
}


void teacher_表格::chu_shi_jei_mian()
{
	IMAGE tu[11];
	initgraph(1080, 700, 1);
	loadimage(tu, "背景图片.png", 1080, 700);
	loadimage(&tu[1], "背景图片.png", 1080, 700);
	putimage(0, 0, tu);
	teacher kong;//用于创建对象
	setbkmode(TRANSPARENT);//背景 模式,,可使 字体的颜色改变
	setfillcolor(RGB(248, 255, 131));//要先改颜色，再造方块
	HWND hwndGraph = GetHWnd(); // 获取图形窗口的句柄
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);//关闭控制台
	//fillrectangle(500,100,700,200);
	while (1)
	{
		if (an_niu("输入成绩", 500, 80, 700, 160))//造出
		{
			kong.zeng_jia();
		}

		if (an_niu("删除成绩", 500, 160, 700, 240))//没有错误
		{
			kong.shan_chu();
		}
		if (an_niu("查找成绩", 500, 240, 700, 320))//造出
		{
			kong.cha_zhao(); 
		}
		if (an_niu("显示成绩", 500, 320, 700, 400))//造出
		{
			kong.xian_shi();
		}
		if (an_niu("修改成绩", 500, 400, 700, 480))//这个没有错误
		{
			kong.xiu_gai();
		}
		if (an_niu("排序成绩", 500, 480, 700, 560))
		{
			kong.pai_xv();
		}
		if (an_niu("退出页面", 500, 560, 700, 640))//完成
		{
			kong.tui_chu();
		}
	}

}





void teacher_表格::she_zhi_kongzhitai(int x,int y,int width,int height)
{
	HWND hwndConsole = GetConsoleWindow();
	//BOOL result = SetWindowPos(hwndConsole, HWND_TOPMOST, x, y, width, height, SWP_NOMOVE | SWP_NOSIZE);
	BOOL result = SetWindowPos(hwndConsole, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
	//SetWindowPos(hwndConsole, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

}

void teacher_表格::chu_shi_bj_jm()
{
	IMAGE tu[11];
	//initgraph(1080, 700, 1);
	loadimage(tu, "背景图片.png", 1080, 700);
	loadimage(&tu[1], "背景图片.png", 1080, 700);
	putimage(0, 0, tu);
}


void teacher_表格::chu_shi_bj_防止无效界面()
{
	IMAGE tu[11];
	initgraph(1080, 700, 1);
	loadimage(tu, "背景图片.png", 1080, 700);
	loadimage(&tu[1], "背景图片.png", 1080, 700);
	putimage(0, 0, tu);
}

void teacher_表格::teacher_jei_mian()
{


}