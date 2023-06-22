#include "deng_lu_界面.h"
int deng_lu_界面::deng_lu()
{
	IMAGE tu[11];
	initgraph(880, 500, 0);
	loadimage(tu, "背景图片.png", 880, 500);
	putimage(0, 0, tu);
	while (1)
	{
		if (jie.an_niu("学生登录", 300, 240, 500, 340))
			return 0;
		if (jie.an_niu("老师登录", 580, 240, 780, 340))
			return 1;
	}
	//return 0;
}

void deng_lu_界面::yun_shi_jiemian()
{
	IMAGE tu[11];
	initgraph(880, 500, 0);
	loadimage(tu, "背景图片.png", 880, 500);
	putimage(0, 0, tu);
}
