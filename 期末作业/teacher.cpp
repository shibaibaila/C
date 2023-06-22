#include"函数头文件.h"
#include"系统__父类.h"
#include"teacher.h"
#include"teacher_表格.h"
#include"deng_lu_界面.h"
teacher::teacher(string id, string name, int yw, int sx, int yy)
{
	this->xue_hao = id;
	this->name = name;
	this->chinese = yw;
	this->math = sx;
	this->English = yy;
}
teacher::teacher()
{

	//teacher_表格 jie;
	ifstream ifs;
	ifs.open(file, ios::in);
	if (!ifs.is_open())
	{
		//jie.an_niu("文件不存在", 200, 240, 500, 340);
		//cout << "文件不存在" << endl;
		ifs.close();
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//jie.an_niu("文件为空", 200, 240, 500, 340);
		//cout << "文件为空" << endl;
		ifs.close();
	}
	renshu = get_tongjirenshu();
	cheng_ji_shu_zu = new xi_tong * [renshu];
	chushihua_yuangong();
}

int teacher::get_tongjirenshu()
{
	ifstream ifs;
	ifs.open(file, ios::in);
	string id;
	string name;
	int yw, yy, sx;
	int num = 0;
	while (ifs >> name && ifs >> id && ifs >> yw && ifs >> yy && ifs >> sx)
	{
		num++;
	}
	ifs.close();
	return num;

}

void teacher::chushihua_yuangong()
{
	ifstream ifs;
	ifs.open(file, ios::in);
	string id;
	string name;
	int yw, yy, sx;
	int num = 0;
	while (ifs >> name && ifs >> id && ifs >> yw && ifs >> yy && ifs >> sx)
	{
		xi_tong* r=NULL;
		r = new teacher(id, name, yw, yy, sx);
		cheng_ji_shu_zu[num] = r;
		num++;
	}
	ifs.close();
}

void teacher::wen_jian()
{
	ofstream ofs;
	ofs.open(file, ios::out);
	for (int i = 0; i < renshu; i++)
	{
		ofs << cheng_ji_shu_zu[i]->name << " "
			<< cheng_ji_shu_zu[i]->xue_hao << " "
			<< cheng_ji_shu_zu[i]->chinese << " "
			<< cheng_ji_shu_zu[i]->math << " "
			<< cheng_ji_shu_zu[i]->English << " " << endl;
	}
	ofs.close();
}

void teacher::zeng_jia()
{
	teacher_表格 biao;

	biao.chu_shi_bj_jm();
	HWND hwndGraph = GetHWnd(); // 获取图形窗口的句柄
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);


	int a = 0;//要添加的人数
	int b = 0;//确定添加后的人数
	int jii = 0;//用于使第一次进入时，使其可以输入
	xi_tong r;
	int cinn = 0;//用于判断是否点击了加人
	xi_tong** n = nullptr;

	string id;
	string name;
	int yw = -1, yy = -1, sx = -1;
	bool b00l = 0;
	while (1)
	{


		if (jii == 0)
		{
			if (biao.an_niu2("想要添加人数：", 200, 0, 430, 80))
			{
				biao.she_zhi_kongzhitai(1200, 200, 200, 200);//设置控制台大小和位置
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> a;

				b = r.renshu + a;//确定添加后的人数

				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				jii = 1;
				cinn = 1;
			}

			//if (jii == 0)
			//if (biao.an_niu("返回主页", 920, 652, 1080, 700))//给个按钮 让他返回
			//{
			//	b00l = 1;
			//	break;
			//}
		}

		/*xi_tong** n = new xi_tong * [b];
		if (cheng_ji_shu_zu != NULL)
		{
			for (int i = 0; i < renshu; i++)
			{
				n[i] = cheng_ji_shu_zu[i];
			}
		}*/
		/*if (jii!=0)
		{
			string s;
			s = "第" + to_string(a--) + " 人:";
			biao.an_niu2(s, 200, 0, 430, 80);
		}*/
		int i = 0;

		int dianji = 0;//用于判断点击次数
		for (i = 0; i < a;)//添加人数
		{
			if (i == 0)
			{
				delete[] n;
				n = nullptr;
				n = new xi_tong * [b];
			}
			if (cinn == 1)
			{
				/*delete[] n;
				n = new xi_tong * [b];*/
				if (cheng_ji_shu_zu != NULL)
				{
					for (int ij = 0; ij < renshu; ij++)
					{
						n[ij] = cheng_ji_shu_zu[ij];
					}
				}
				cinn = 2;
			}

			//BeginBatchDraw();

			//int dianji = 0;//用于判断点击次数
			if (jii != 0)
			{
				string s;
				s = "第" + to_string(i + 1) + " 人:";
				biao.an_niu2(s, 200, 0, 430, 80);
			}
			/*string id;
			string name;
			int yw=0, yy=0, sx=0;*/
			if (biao.an_niu2("姓名：", 458, 80, 700, 160))//easyx  <----有个奇怪的问题，，必须要有另外的输出，才会显示图，，在这段里
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> id;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;
				//biao.zao_zi_han_shu(id, 458, 80, 700, 160);
			}

			biao.zao_zi_han_shu3(id, 458, 80, 700, 160);
			if (biao.an_niu2("学号：", 458, 160, 700, 240))
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> name;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;

			}
			biao.zao_zi_han_shu3(name, 458, 160, 700, 240);
			if (biao.an_niu2("语文：", 458, 240, 700, 320))
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> yw;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;


			}
			if (yw >= 0)
				biao.zao_zi_han_shu3(to_string(yw), 458, 240, 700, 320);
			if (biao.an_niu2("数学：", 458, 320, 700, 400))
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> sx;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;

			}
			if (sx >= 0)
				biao.zao_zi_han_shu3(to_string(sx), 458, 320, 700, 400);
			if (biao.an_niu2("英语：", 458, 400, 700, 480))
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> yy;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;

			}
			if (yy >= 0)
				biao.zao_zi_han_shu3(to_string(yy), 458, 400, 700, 480);
			if (dianji == 5)//只有点击后才能 创建空间
			{
				xi_tong* ji = new teacher(id, name, yw, sx, yy);
				n[renshu + i] = ji;
				i++;
			}
			//EndBatchDraw();

			if (biao.an_niu("返回主页", 920, 652, 1080, 700))//给个按钮 让他返回
			{
				b00l = 1;
				break;
			}

		}

		if (i == a && i != 0)
		{
			cheng_ji_shu_zu = n;
			renshu = b;
			biao.chu_shi_bj_jm();
			ShowWindow(hwndConsole, SW_HIDE);
			wen_jian();
			biao.an_niu("添加成功", 458, 240, 700, 320);
			biao.an_niu("按任Enter继续", 458, 320, 700, 400);
			system("pause");
			biao.chu_shi_jei_mian();
			break;
		}
		//if (biao.an_niu("返回主页", 920, 652, 1080, 700))//给个按钮 让他返回
		//{
		//	b00l = 1;
		//	break;
		//}
		if (b00l == 1)
		{
			cleardevice();
			biao.chu_shi_jei_mian();
			ShowWindow(hwndConsole, SW_HIDE);
			break;
		}


	}
}


void teacher::shan_chu()
{
	teacher_表格 biao;
	deng_lu_界面 b;

	HWND hwndGraph = GetHWnd(); // 获取图形窗口的句柄
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);
	string id;
	string name;
	string shu_ru;
	int dian_ji = 0;
	int b001 = 0;
	biao.chu_shi_bj_jm();
	int j = 0;
	while (1)
	{
		if (biao.an_niu("输入学号", 500, 0, 700, 80))
		{
			//biao.chu_shi_bj_jm();//消除上一个搜寻信息的 影响
			ShowWindow(hwndConsole, SW_SHOW);
			cout << "输入学号:" << endl;
			cin >> id;
			system("cls");
			ShowWindow(hwndConsole, SW_HIDE);
			int ii = 0;
			//int j = 0;
			for (; ii < renshu; ii++)
			{
				if (cheng_ji_shu_zu[ii]->xue_hao == id)
				{
					j = ii;
					int j1 = 0;
					biao.an_niu3("姓名", 344 + 124 * 0, 80, 468 + 124 * 0, 80 + 48);
					biao.an_niu3("学号", 344 + 124 * 1, 80, 468 + 124 * 1, 80 + 48);
					biao.an_niu3("语文", 344 + 124 * 2, 80, 468 + 124 * 2, 80 + 48);
					biao.an_niu3("数学", 344 + 124 * 3, 80, 468 + 124 * 3, 80 + 48);
					biao.an_niu3("英语", 344 + 124 * 4, 80, 468 + 124 * 4, 80 + 48);
					biao.an_niu4(cheng_ji_shu_zu[ii]->name, 344 + 124 * 1, 80 + 48 + 48 * j1, 468 + 124 * 1, 80 + 96 + 48 * j1);
					biao.an_niu4(cheng_ji_shu_zu[ii]->xue_hao, 344 + 124 * 0, 80 + 48 + 48 * j1, 468 + 124 * 0, 80 + 96 + 48 * j1);
					biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->chinese), 344 + 124 * 2, 80 + 48 + 48 * j1, 468 + 124 * 2, 80 + 96 + 48 * j1);
					biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->math), 344 + 124 * 3, 80 + 48 + 48 * j1, 468 + 124 * 3, 80 + 96 + 48 * j1);
					biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->English), 344 + 124 * 4, 80 + 48 + 48 * j1, 468 + 124 * 4, 80 + 96 + 48 * j1);
					dian_ji = -1;//当没有这个元素时，一直是 -1
					
				}


			}
			if (dian_ji == 0)
			{
				biao.an_niu("没有该学生", 500, 160, 700, 240);
				biao.an_niu("Enter继续", 500, 240, 700, 320);
				system("pause");
				biao.chu_shi_bj_jm();
			}

		}
		

		
			if (dian_ji == -1)
			{
				if (biao.an_niu("确认删除", 760, 652, 920, 700))
				{
					for (; j < renshu - 1; j++)
					{
						cheng_ji_shu_zu[j] = cheng_ji_shu_zu[j + 1];
					}
					dian_ji = 0;//目的是判断，有没有这个元素
					renshu--;
					wen_jian();
					biao.an_niu("删除成功",500, 160, 700, 240);
					biao.an_niu("Enter继续", 500, 240, 700, 320);
					system("pause");
					biao.chu_shi_bj_jm();
					//break;
				}
			}
			
		
		
		if (biao.an_niu("返回主页", 920, 652, 1080, 700))//给个按钮 让他返回
		{
			//b001 = 1;
			biao.chu_shi_jei_mian();
			break;
		}
	}
}

void teacher::xiu_gai()
{
	teacher_表格 biao;
	deng_lu_界面 b;

	HWND hwndGraph = GetHWnd(); // 获取图形窗口的句柄
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);
	string id;
	string name;
	string shu_ru;
	int dian_ji = 0;
	int b001 = 0;
	biao.chu_shi_bj_jm();
	while (1)
	{
		if(biao.an_niu("输入学号", 500, 0, 700, 80))
		{
			//biao.chu_shi_bj_jm();//消除上一个搜寻信息的 影响
			ShowWindow(hwndConsole, SW_SHOW);
			cout << "输入学号:" << endl;
			cin >> id;
			system("cls");
			ShowWindow(hwndConsole, SW_HIDE);
			int ii = 0;
			for (; ii < renshu; ii++)
			{
				string c = cheng_ji_shu_zu[ii]->xue_hao;
				string c1 = cheng_ji_shu_zu[ii]->name;
				if (cheng_ji_shu_zu[ii]->xue_hao == id)
				{
					biao.an_niu3("姓名", 344 + 124 * 0, 80, 468 + 124 * 0, 80+48);
					biao.an_niu3("学号", 344 + 124 * 1, 80, 468 + 124 * 1, 80+48);
					biao.an_niu3("语文", 344 + 124 * 2, 80, 468 + 124 * 2, 80+48);
					biao.an_niu3("数学", 344 + 124 * 3, 80, 468 + 124 * 3, 80+48);
					biao.an_niu3("英语", 344 + 124 * 4, 80, 468 + 124 * 4, 80+48);
					while (1)//使点击an_niu4 始终处于有效的情况下
					{
						int j = 0;
						if (biao.an_niu4(cheng_ji_shu_zu[ii]->name, 344 + 124 * 1, 80 + 48 + 48 * j, 468 + 124 * 1, 80 + 96 + 48 * j))
						{
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "输入姓名:" << endl;
							cin >> shu_ru;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->name = shu_ru;
						}
						if (biao.an_niu4(cheng_ji_shu_zu[ii]->xue_hao, 344 + 124 * 0, 80 + 48 + 48 * j, 468 + 124 * 0, 80 + 96 + 48 * j))
						{
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "输入学号:" << endl;
							cin >> shu_ru;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->xue_hao = shu_ru;
						}
						if (biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->chinese), 344 + 124 * 2, 80 + 48 + 48 * j, 468 + 124 * 2, 80 + 96 + 48 * j))
						{
							int a;
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "输入语文成绩:" << endl;
							cin >> a;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->chinese = a;
						}
						if (biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->math), 344 + 124 * 3, 80 + 48 + 48 * j, 468 + 124 * 3, 80 + 96 + 48 * j))
						{
							int a;
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "输入数学成绩:" << endl;
							cin >> a;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->math = a;
						}
						if (biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->English), 344 + 124 * 4, 80 + 48 + 48 * j, 468 + 124 * 4, 80 + 96 + 48 * j))
						{
							int a;
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "输入英语成绩:" << endl;
							cin >> a;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->English = a;
						}
						if (biao.an_niu("点击保存", 760, 652, 920, 700))//给个按钮 让他保存
						{
							wen_jian();
							b001 = 1;
							biao.chu_shi_bj_jm();
							break;
						}
					}
					
					if (b001 == 1)
					{
						b001 = 0;
						break;
					}
				}
			}
		}
		if (biao.an_niu("返回主页", 920, 652, 1080, 700))//给个按钮 让他返回
		{
			//b001 = 1;
			biao.chu_shi_jei_mian();
			break;
		}
	}
}

void teacher::cha_zhao()
{
	teacher_表格 biao;
	deng_lu_界面 b;
	
	HWND hwndGraph = GetHWnd(); // 获取图形窗口的句柄
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);
	string id;
	string name;
	int dianji = 0;
	int dianji_1 = 1;
	int dianji_2 = 1;
	int dianji_3 = 1;

	while (1)
	{
		if(dianji==0)
		{
			if(dianji_1==1)
			{
				biao.chu_shi_bj_jm();
				dianji_1 = 0;

			}
			if (biao.an_niu("姓名查找：", 300, 240, 500, 340))
			{

				ShowWindow(hwndConsole, SW_SHOW);
				cout << "输入姓名:" << endl;
				cin >> name;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji = 1;
			}

			if (biao.an_niu("学号查找：", 580, 240, 780, 340))
			{

				ShowWindow(hwndConsole, SW_SHOW);
				cout << "输入学号:" << endl;
				cin >> id;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji = 2;
			}
		}
			
		else if (dianji == 1)
		{
			//biao.chu_shi_bj_jm();
			if (dianji_2 == 1)
			{
				biao.chu_shi_bj_jm();
				dianji_2 = 0;

			}

			for (int ii=0,j=0; ii < renshu; ii++)
			{
				if (ii == 0)
				{
					biao.an_niu3("姓名", 344 + 124 * 0, 0, 468 + 124 * 0, 48);
					biao.an_niu3("学号", 344 + 124 * 1, 0, 468 + 124 * 1, 48);
					biao.an_niu3("语文", 344 + 124 * 2, 0, 468 + 124 * 2, 48);
					biao.an_niu3("数学", 344 + 124 * 3, 0, 468 + 124 * 3, 48);
					biao.an_niu3("英语", 344 + 124 * 4, 0, 468 + 124 * 4, 48);
				}
				if(cheng_ji_shu_zu[ii]->name==name)
				{
					biao.an_niu3(cheng_ji_shu_zu[ii]->name, 344 + 124 * 1, 48 + 48 * j, 468 + 124 * 1, 96 + 48 * j);
					biao.an_niu3(cheng_ji_shu_zu[ii]->xue_hao, 344 + 124 * 0, 48 + 48 * j, 468 + 124 * 0, 96 + 48 * j);
					biao.an_niu3(" " + to_string(cheng_ji_shu_zu[ii]->chinese), 344 + 124 * 2, 48 + 48 * j, 468 + 124 * 2, 96 + 48 * j);
					biao.an_niu3(" " + to_string(cheng_ji_shu_zu[ii]->math), 344 + 124 * 3, 48 + 48 * j, 468 + 124 * 3, 96 + 48 * j);
					biao.an_niu3(" " + to_string(cheng_ji_shu_zu[ii]->English), 344 + 124 * 4, 48 + 48 * j, 468 + 124 * 4, 96 + 48 * j);
					j++;//排除跳格 问题
				}

			}
			dianji = 0;
			dianji_1 = 1;
			dianji_2 = 1;
			system("pause");

		}
		else if (dianji == 2)//这个地方有问题，不知道为什么 会初始不了界面与显示信息
		{
			//biao.chu_shi_bj_jm();
			if (dianji_3 == 1)
			{
				//biao.chu_shi_bj_防止无效界面();
				//cleardevice();
				biao.chu_shi_bj_jm();
				//biao.chu_shi_bj_jm();
				dianji_3 = 0;

			}
			int ii = 0;
			for (; ii < renshu; ii++)
			{
				if (ii == 0)
				{
					biao.an_niu3("姓名", 344 + 124 * 0, 0, 468 + 124 * 0, 48);
					biao.an_niu3("学号", 344 + 124 * 1, 0, 468 + 124 * 1, 48);
					biao.an_niu3("语文", 344 + 124 * 2, 0, 468 + 124 * 2, 48);
					biao.an_niu3("数学", 344 + 124 * 3, 0, 468 + 124 * 3, 48);
					biao.an_niu3("英语", 344 + 124 * 4, 0, 468 + 124 * 4, 48);
				}
				if (cheng_ji_shu_zu[ii]->xue_hao == id)
				{
					biao.an_niu3(cheng_ji_shu_zu[ii]->name, 344 + 124 * 1, 48 + 48 * ii, 468 + 124 * 1, 96 + 48 * ii);
					biao.an_niu3(cheng_ji_shu_zu[ii]->xue_hao, 344 + 124 * 0, 48 + 48 * ii, 468 + 124 * 0, 96 + 48 * ii);
					biao.an_niu3(" " + to_string(cheng_ji_shu_zu[ii]->chinese), 344 + 124 * 2, 48 + 48 * ii, 468 + 124 * 2, 96 + 48 * ii);
					biao.an_niu3(" " + to_string(cheng_ji_shu_zu[ii]->math), 344 + 124 * 3, 48 + 48 * ii, 468 + 124 * 3, 96 + 48 * ii);
					biao.an_niu3(" " + to_string(cheng_ji_shu_zu[ii]->English), 344 + 124 * 4, 48 + 48 * ii, 468 + 124 * 4, 96 + 48 * ii);
					dianji = 0;
					dianji_1 = 1;
					dianji_3 = 1;
					system("pause");
					break;
				}

			}
		}
	}


}

void teacher::pai_xv()
{
	teacher_表格 biao;

	biao.chu_shi_bj_jm();
	HWND hwndGraph = GetHWnd(); // 获取图形窗口的句柄
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);
	while(1)
	{
		if (biao.an_niu4("倒序", 300, 240, 500, 340))
		{
			//biao.chu_shi_bj_jm();
			for (int i = 0; i < renshu; i++)
			{
				for (int j = 0; j < renshu - i - i; j++)
				{
					if(cheng_ji_shu_zu[j]> cheng_ji_shu_zu[j+1])
					{
						xi_tong* r = cheng_ji_shu_zu[j];
						cheng_ji_shu_zu[j] = cheng_ji_shu_zu[j + 1];
						cheng_ji_shu_zu[j + 1] = r;
					}
				}
			}
			xian_shi();
			wen_jian();
			biao.chu_shi_bj_jm();
		}
		if (biao.an_niu4("顺序", 300, 240, 500, 340))
		{
			
			for (int i = 0; i < renshu; i++)
			{
				for (int j = 0; j < renshu - i - i; j++)
				{
					if (cheng_ji_shu_zu[j] < cheng_ji_shu_zu[j + 1])
					{
						xi_tong* r = cheng_ji_shu_zu[j];
						cheng_ji_shu_zu[j] = cheng_ji_shu_zu[j + 1];
						cheng_ji_shu_zu[j + 1] = r;
					}
				}
			}
			xian_shi();
			wen_jian();
			biao.chu_shi_bj_jm();
		}
	}


}

void teacher::xian_shi()
{

	teacher_表格 biao;

	biao.chu_shi_bj_jm();
	HWND hwndGraph = GetHWnd(); // 获取图形窗口的句柄
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);

	int b = 0;//b 控制当前页面，
	int  b1 = 12;
	xi_tong** n = nullptr;

	int ye_ma = 1;//显示页面

	if (get_tongjirenshu() <= 0)
	{
		biao.an_niu("文件不存在或为空", 458, 320, 880, 400);
	}
	else
	{
		//int b = 0;//b 控制当前页面，
		//int  b1 = 12;
		//xi_tong** n = nullptr;
		while (1)
		{
			//BeginBatchDraw();
			

			if (b > renshu)//当最后一页，不足12个时，打印剩余的个数
			{
				b = b - renshu;
				int i = 0; int j = renshu - b;
				for (; j < renshu; j++, i++)
				{
					if (i == 0)
					{
						
						n = new xi_tong * [b1];
					}

					if (cheng_ji_shu_zu != NULL)
					{
						//for (int i = 0; i < renshu; i++)
						{
							n[i] = cheng_ji_shu_zu[j];
						}
					}

				}
			}

			else
			{
				int i = 0,  j = b;
				for (; j < b + 12; j++, i++)
				{
					if (i == 0)
					{
						//delete[]n;
						n = new xi_tong * [b1];
					}

					if (cheng_ji_shu_zu != NULL)
					{
						//for (int i = 0; i < renshu; i++)
						{
							n[i] = cheng_ji_shu_zu[j];
						}
					}

				}
			}
			
			BeginBatchDraw();
			biao.an_niu(" 第" + to_string(ye_ma)+"页", 0, 652, 80, 700);
			if(renshu % 12==0)
				biao.an_niu(" 共" + to_string(renshu/12) + "页", 80, 652, 180, 700);
			else
				biao.an_niu(" 共" + to_string(renshu / 12+1) + "页", 80, 652, 180, 700);
			int ii = 0;
			//while (b>0)//用于最后一页的循环，，在最后一页时，b会变成一个数字，然后会将 cheng_ji_shu_zu的 b--b+12 之间的信息显示，但是下面的循环只会显示0--b1间的，0-b间的数据已经被释放了，所以才会突然跳出程序
			{
				for (; ii < b1; ii++)
				{
					if (ii == 0)
					{
						biao.an_niu3("学号", 344 + 124 * 0, 0, 468 + 124 * 0, 48);
						biao.an_niu3("姓名", 344 + 124 * 1, 0, 468 + 124 * 1, 48);
						biao.an_niu3("语文", 344 + 124 * 2, 0, 468 + 124 * 2, 48);
						biao.an_niu3("数学", 344 + 124 * 3, 0, 468 + 124 * 3, 48);
						biao.an_niu3("英语", 344 + 124 * 4, 0, 468 + 124 * 4, 48);
					}

					biao.an_niu3(n[ii]->name, 344 + 124 * 1, 48 + 48 * ii, 468 + 124 * 1, 96 + 48 * ii);
					biao.an_niu3(n[ii]->xue_hao, 344 + 124 * 0, 48 + 48 * ii, 468 + 124 * 0, 96 + 48 * ii);
					biao.an_niu3(" " + to_string(n[ii]->chinese), 344 + 124 * 2, 48 + 48 * ii, 468 + 124 * 2, 96 + 48 * ii);
					biao.an_niu3(" " + to_string(n[ii]->math), 344 + 124 * 3, 48 + 48 * ii, 468 + 124 * 3, 96 + 48 * ii);
					biao.an_niu3(" " + to_string(n[ii]->English), 344 + 124 * 4, 48 + 48 * ii, 468 + 124 * 4, 96 + 48 * ii);


					if (b > 0 && b < 12)
					{
						if(ii==b)
						{
							//system("pause");
							b = 0;
						}
					}

				}
			}

			if (biao.an_niu2("     退出", 920, 652, 1080, 700))
			{
				
				delete[]n;
				n = nullptr;
				biao.chu_shi_jei_mian();
				break;
			}
			if (12 <= b)
			{
				if (GetAsyncKeyState(VK_LEFT))  // 检测左移键是否被按下
				{
					if (b >= 12)
						b -= 12;
					b1 = 12;//用于 恢复 b1的值，，当点击上一页时，说明不是最后一页了，，要 使其能正常显示 12个人
					ye_ma--;
					biao.chu_shi_bj_jm();
				}

				if (biao.an_niu(" 上一页", 520, 652, 680, 700))
				{
					if (b >= 12)
						b -= 12;
					b1 = 12;//用于 恢复 b1的值，，当点击上一页时，说明不是最后一页了，，要 使其能正常显示 12个人
					ye_ma--;
					biao.chu_shi_bj_jm();
				}
				
			}
			if (b == 0 || b >= 12)
			{
				if (GetAsyncKeyState(VK_RIGHT))
				{
					//if (renshu - b >= 12)
						b += 12;
					/*else
						b = renshu - b;*/
					ye_ma++;
					biao.chu_shi_bj_jm();
				}
				if (biao.an_niu(" 下一页", 720, 652, 880, 700))
				{
					//if (renshu - b >= 12)
						b += 12;
					
					ye_ma++;
					biao.chu_shi_bj_jm();
				}

				biao.an_niu("或按< >翻页    ", 200, 652, 400, 700);
				
			}
			//EndBatchDraw();
			if (n != NULL)
			{
				delete[]n;
				n = nullptr;
			}
		}

	}
}


void teacher::tui_chu()
{
	exit(0);
}
