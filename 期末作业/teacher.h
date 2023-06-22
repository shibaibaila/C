#pragma once
#include"函数头文件.h"
#include"系统__父类.h"
#include"teacher_表格.h"
class teacher :public xi_tong
{
public:
	teacher(string id, string name, int yw, int sx, int yy);
	teacher();

	int get_tongjirenshu();//统计学生人数
	void chushihua_yuangong();
	void wen_jian();//用于保存 删除或保存的 剩余的 信息

	void zeng_jia();
	void shan_chu();
	void xiu_gai();
	void cha_zhao();
	void pai_xv();
	void xian_shi();
	void tui_chu();
};