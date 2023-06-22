#pragma once
#include"函数头文件.h"
#include"系统__父类.h"

class teacher_表格
{
public:

	int gai_yan_se(int, int, int, int);//修改颜色，使其变色
	int zao_zi_han_shu(string, int, int, int, int);//在一定范围内 显示文字
	int zai_fan_wei_nei(int, int, int, int);//判断鼠标在一定范围内
	int an_niu(string a, int l, int t, int r, int b);//当 点击这个时候，进入相应的程序
	int zao_zi_han_shu2(string biao_ti, int l, int t, int r, int b);//用于调整文字位置，方便输入
	int an_niu2(string a, int l, int t, int r, int b);//用于输入信息,使其 偏左显示

	int zao_zi_han_shu3(string biao_ti, int l, int t, int r, int b);//用于显示 在输入成绩后的 信息位置

	int zao_zi_han_shu4(string biao_ti, int l, int t, int r, int b);
	int an_niu3(string a, int l, int t, int r, int b);//用于输出成绩

	int an_niu4(string a, int l, int t, int r, int b);//用于 点击后 修改信息

	int  an_niu5(string a, int l, int t, int r, int b);//最后 退出时，显示 谢谢

	void she_zhi_kongzhitai(int x,int y,int w,int h);//用于设置 控制台的大小
	void chu_shi_jei_mian();//显示初始界面,是哪个有 输入，删除 选项的
	void chu_shi_bj_jm();//初始背景，，是 显示成绩单的位置
	void chu_shi_bj_防止无效界面();//有些时候，电脑会出现一些奇怪的 出现不了窗口的问题，所以要在这里重新创建窗口
	void teacher_jei_mian();//


};
