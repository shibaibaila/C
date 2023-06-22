#include"����ͷ�ļ�.h"
#include"ϵͳ__����.h"
#include"teacher.h"
#include"teacher_���.h"
#include"deng_lu_����.h"
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

	//teacher_��� jie;
	ifstream ifs;
	ifs.open(file, ios::in);
	if (!ifs.is_open())
	{
		//jie.an_niu("�ļ�������", 200, 240, 500, 340);
		//cout << "�ļ�������" << endl;
		ifs.close();
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//jie.an_niu("�ļ�Ϊ��", 200, 240, 500, 340);
		//cout << "�ļ�Ϊ��" << endl;
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
	teacher_��� biao;

	biao.chu_shi_bj_jm();
	HWND hwndGraph = GetHWnd(); // ��ȡͼ�δ��ڵľ��
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);


	int a = 0;//Ҫ��ӵ�����
	int b = 0;//ȷ����Ӻ������
	int jii = 0;//����ʹ��һ�ν���ʱ��ʹ���������
	xi_tong r;
	int cinn = 0;//�����ж��Ƿ����˼���
	xi_tong** n = nullptr;

	string id;
	string name;
	int yw = -1, yy = -1, sx = -1;
	bool b00l = 0;
	while (1)
	{


		if (jii == 0)
		{
			if (biao.an_niu2("��Ҫ���������", 200, 0, 430, 80))
			{
				biao.she_zhi_kongzhitai(1200, 200, 200, 200);//���ÿ���̨��С��λ��
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> a;

				b = r.renshu + a;//ȷ����Ӻ������

				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				jii = 1;
				cinn = 1;
			}

			//if (jii == 0)
			//if (biao.an_niu("������ҳ", 920, 652, 1080, 700))//������ť ��������
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
			s = "��" + to_string(a--) + " ��:";
			biao.an_niu2(s, 200, 0, 430, 80);
		}*/
		int i = 0;

		int dianji = 0;//�����жϵ������
		for (i = 0; i < a;)//�������
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

			//int dianji = 0;//�����жϵ������
			if (jii != 0)
			{
				string s;
				s = "��" + to_string(i + 1) + " ��:";
				biao.an_niu2(s, 200, 0, 430, 80);
			}
			/*string id;
			string name;
			int yw=0, yy=0, sx=0;*/
			if (biao.an_niu2("������", 458, 80, 700, 160))//easyx  <----�и���ֵ����⣬������Ҫ�������������Ż���ʾͼ�����������
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> id;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;
				//biao.zao_zi_han_shu(id, 458, 80, 700, 160);
			}

			biao.zao_zi_han_shu3(id, 458, 80, 700, 160);
			if (biao.an_niu2("ѧ�ţ�", 458, 160, 700, 240))
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> name;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;

			}
			biao.zao_zi_han_shu3(name, 458, 160, 700, 240);
			if (biao.an_niu2("���ģ�", 458, 240, 700, 320))
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> yw;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;


			}
			if (yw >= 0)
				biao.zao_zi_han_shu3(to_string(yw), 458, 240, 700, 320);
			if (biao.an_niu2("��ѧ��", 458, 320, 700, 400))
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> sx;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;

			}
			if (sx >= 0)
				biao.zao_zi_han_shu3(to_string(sx), 458, 320, 700, 400);
			if (biao.an_niu2("Ӣ�", 458, 400, 700, 480))
			{
				ShowWindow(hwndConsole, SW_SHOW);
				cin >> yy;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji++;

			}
			if (yy >= 0)
				biao.zao_zi_han_shu3(to_string(yy), 458, 400, 700, 480);
			if (dianji == 5)//ֻ�е������� �����ռ�
			{
				xi_tong* ji = new teacher(id, name, yw, sx, yy);
				n[renshu + i] = ji;
				i++;
			}
			//EndBatchDraw();

			if (biao.an_niu("������ҳ", 920, 652, 1080, 700))//������ť ��������
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
			biao.an_niu("��ӳɹ�", 458, 240, 700, 320);
			biao.an_niu("����Enter����", 458, 320, 700, 400);
			system("pause");
			biao.chu_shi_jei_mian();
			break;
		}
		//if (biao.an_niu("������ҳ", 920, 652, 1080, 700))//������ť ��������
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
	teacher_��� biao;
	deng_lu_���� b;

	HWND hwndGraph = GetHWnd(); // ��ȡͼ�δ��ڵľ��
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
		if (biao.an_niu("����ѧ��", 500, 0, 700, 80))
		{
			//biao.chu_shi_bj_jm();//������һ����Ѱ��Ϣ�� Ӱ��
			ShowWindow(hwndConsole, SW_SHOW);
			cout << "����ѧ��:" << endl;
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
					biao.an_niu3("����", 344 + 124 * 0, 80, 468 + 124 * 0, 80 + 48);
					biao.an_niu3("ѧ��", 344 + 124 * 1, 80, 468 + 124 * 1, 80 + 48);
					biao.an_niu3("����", 344 + 124 * 2, 80, 468 + 124 * 2, 80 + 48);
					biao.an_niu3("��ѧ", 344 + 124 * 3, 80, 468 + 124 * 3, 80 + 48);
					biao.an_niu3("Ӣ��", 344 + 124 * 4, 80, 468 + 124 * 4, 80 + 48);
					biao.an_niu4(cheng_ji_shu_zu[ii]->name, 344 + 124 * 1, 80 + 48 + 48 * j1, 468 + 124 * 1, 80 + 96 + 48 * j1);
					biao.an_niu4(cheng_ji_shu_zu[ii]->xue_hao, 344 + 124 * 0, 80 + 48 + 48 * j1, 468 + 124 * 0, 80 + 96 + 48 * j1);
					biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->chinese), 344 + 124 * 2, 80 + 48 + 48 * j1, 468 + 124 * 2, 80 + 96 + 48 * j1);
					biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->math), 344 + 124 * 3, 80 + 48 + 48 * j1, 468 + 124 * 3, 80 + 96 + 48 * j1);
					biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->English), 344 + 124 * 4, 80 + 48 + 48 * j1, 468 + 124 * 4, 80 + 96 + 48 * j1);
					dian_ji = -1;//��û�����Ԫ��ʱ��һֱ�� -1
					
				}


			}
			if (dian_ji == 0)
			{
				biao.an_niu("û�и�ѧ��", 500, 160, 700, 240);
				biao.an_niu("Enter����", 500, 240, 700, 320);
				system("pause");
				biao.chu_shi_bj_jm();
			}

		}
		

		
			if (dian_ji == -1)
			{
				if (biao.an_niu("ȷ��ɾ��", 760, 652, 920, 700))
				{
					for (; j < renshu - 1; j++)
					{
						cheng_ji_shu_zu[j] = cheng_ji_shu_zu[j + 1];
					}
					dian_ji = 0;//Ŀ�����жϣ���û�����Ԫ��
					renshu--;
					wen_jian();
					biao.an_niu("ɾ���ɹ�",500, 160, 700, 240);
					biao.an_niu("Enter����", 500, 240, 700, 320);
					system("pause");
					biao.chu_shi_bj_jm();
					//break;
				}
			}
			
		
		
		if (biao.an_niu("������ҳ", 920, 652, 1080, 700))//������ť ��������
		{
			//b001 = 1;
			biao.chu_shi_jei_mian();
			break;
		}
	}
}

void teacher::xiu_gai()
{
	teacher_��� biao;
	deng_lu_���� b;

	HWND hwndGraph = GetHWnd(); // ��ȡͼ�δ��ڵľ��
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
		if(biao.an_niu("����ѧ��", 500, 0, 700, 80))
		{
			//biao.chu_shi_bj_jm();//������һ����Ѱ��Ϣ�� Ӱ��
			ShowWindow(hwndConsole, SW_SHOW);
			cout << "����ѧ��:" << endl;
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
					biao.an_niu3("����", 344 + 124 * 0, 80, 468 + 124 * 0, 80+48);
					biao.an_niu3("ѧ��", 344 + 124 * 1, 80, 468 + 124 * 1, 80+48);
					biao.an_niu3("����", 344 + 124 * 2, 80, 468 + 124 * 2, 80+48);
					biao.an_niu3("��ѧ", 344 + 124 * 3, 80, 468 + 124 * 3, 80+48);
					biao.an_niu3("Ӣ��", 344 + 124 * 4, 80, 468 + 124 * 4, 80+48);
					while (1)//ʹ���an_niu4 ʼ�մ�����Ч�������
					{
						int j = 0;
						if (biao.an_niu4(cheng_ji_shu_zu[ii]->name, 344 + 124 * 1, 80 + 48 + 48 * j, 468 + 124 * 1, 80 + 96 + 48 * j))
						{
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "��������:" << endl;
							cin >> shu_ru;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->name = shu_ru;
						}
						if (biao.an_niu4(cheng_ji_shu_zu[ii]->xue_hao, 344 + 124 * 0, 80 + 48 + 48 * j, 468 + 124 * 0, 80 + 96 + 48 * j))
						{
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "����ѧ��:" << endl;
							cin >> shu_ru;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->xue_hao = shu_ru;
						}
						if (biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->chinese), 344 + 124 * 2, 80 + 48 + 48 * j, 468 + 124 * 2, 80 + 96 + 48 * j))
						{
							int a;
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "�������ĳɼ�:" << endl;
							cin >> a;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->chinese = a;
						}
						if (biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->math), 344 + 124 * 3, 80 + 48 + 48 * j, 468 + 124 * 3, 80 + 96 + 48 * j))
						{
							int a;
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "������ѧ�ɼ�:" << endl;
							cin >> a;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->math = a;
						}
						if (biao.an_niu4(" " + to_string(cheng_ji_shu_zu[ii]->English), 344 + 124 * 4, 80 + 48 + 48 * j, 468 + 124 * 4, 80 + 96 + 48 * j))
						{
							int a;
							ShowWindow(hwndConsole, SW_SHOW);
							cout << "����Ӣ��ɼ�:" << endl;
							cin >> a;
							system("cls");
							ShowWindow(hwndConsole, SW_HIDE);

							cheng_ji_shu_zu[ii]->English = a;
						}
						if (biao.an_niu("�������", 760, 652, 920, 700))//������ť ��������
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
		if (biao.an_niu("������ҳ", 920, 652, 1080, 700))//������ť ��������
		{
			//b001 = 1;
			biao.chu_shi_jei_mian();
			break;
		}
	}
}

void teacher::cha_zhao()
{
	teacher_��� biao;
	deng_lu_���� b;
	
	HWND hwndGraph = GetHWnd(); // ��ȡͼ�δ��ڵľ��
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
			if (biao.an_niu("�������ң�", 300, 240, 500, 340))
			{

				ShowWindow(hwndConsole, SW_SHOW);
				cout << "��������:" << endl;
				cin >> name;
				system("cls");
				ShowWindow(hwndConsole, SW_HIDE);
				dianji = 1;
			}

			if (biao.an_niu("ѧ�Ų��ң�", 580, 240, 780, 340))
			{

				ShowWindow(hwndConsole, SW_SHOW);
				cout << "����ѧ��:" << endl;
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
					biao.an_niu3("����", 344 + 124 * 0, 0, 468 + 124 * 0, 48);
					biao.an_niu3("ѧ��", 344 + 124 * 1, 0, 468 + 124 * 1, 48);
					biao.an_niu3("����", 344 + 124 * 2, 0, 468 + 124 * 2, 48);
					biao.an_niu3("��ѧ", 344 + 124 * 3, 0, 468 + 124 * 3, 48);
					biao.an_niu3("Ӣ��", 344 + 124 * 4, 0, 468 + 124 * 4, 48);
				}
				if(cheng_ji_shu_zu[ii]->name==name)
				{
					biao.an_niu3(cheng_ji_shu_zu[ii]->name, 344 + 124 * 1, 48 + 48 * j, 468 + 124 * 1, 96 + 48 * j);
					biao.an_niu3(cheng_ji_shu_zu[ii]->xue_hao, 344 + 124 * 0, 48 + 48 * j, 468 + 124 * 0, 96 + 48 * j);
					biao.an_niu3(" " + to_string(cheng_ji_shu_zu[ii]->chinese), 344 + 124 * 2, 48 + 48 * j, 468 + 124 * 2, 96 + 48 * j);
					biao.an_niu3(" " + to_string(cheng_ji_shu_zu[ii]->math), 344 + 124 * 3, 48 + 48 * j, 468 + 124 * 3, 96 + 48 * j);
					biao.an_niu3(" " + to_string(cheng_ji_shu_zu[ii]->English), 344 + 124 * 4, 48 + 48 * j, 468 + 124 * 4, 96 + 48 * j);
					j++;//�ų����� ����
				}

			}
			dianji = 0;
			dianji_1 = 1;
			dianji_2 = 1;
			system("pause");

		}
		else if (dianji == 2)//����ط������⣬��֪��Ϊʲô ���ʼ���˽�������ʾ��Ϣ
		{
			//biao.chu_shi_bj_jm();
			if (dianji_3 == 1)
			{
				//biao.chu_shi_bj_��ֹ��Ч����();
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
					biao.an_niu3("����", 344 + 124 * 0, 0, 468 + 124 * 0, 48);
					biao.an_niu3("ѧ��", 344 + 124 * 1, 0, 468 + 124 * 1, 48);
					biao.an_niu3("����", 344 + 124 * 2, 0, 468 + 124 * 2, 48);
					biao.an_niu3("��ѧ", 344 + 124 * 3, 0, 468 + 124 * 3, 48);
					biao.an_niu3("Ӣ��", 344 + 124 * 4, 0, 468 + 124 * 4, 48);
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
	teacher_��� biao;

	biao.chu_shi_bj_jm();
	HWND hwndGraph = GetHWnd(); // ��ȡͼ�δ��ڵľ��
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);
	while(1)
	{
		if (biao.an_niu4("����", 300, 240, 500, 340))
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
		if (biao.an_niu4("˳��", 300, 240, 500, 340))
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

	teacher_��� biao;

	biao.chu_shi_bj_jm();
	HWND hwndGraph = GetHWnd(); // ��ȡͼ�δ��ڵľ��
	HWND hwndConsole = GetConsoleWindow();
	ShowWindow(hwndConsole, SW_HIDE);

	int b = 0;//b ���Ƶ�ǰҳ�棬
	int  b1 = 12;
	xi_tong** n = nullptr;

	int ye_ma = 1;//��ʾҳ��

	if (get_tongjirenshu() <= 0)
	{
		biao.an_niu("�ļ������ڻ�Ϊ��", 458, 320, 880, 400);
	}
	else
	{
		//int b = 0;//b ���Ƶ�ǰҳ�棬
		//int  b1 = 12;
		//xi_tong** n = nullptr;
		while (1)
		{
			//BeginBatchDraw();
			

			if (b > renshu)//�����һҳ������12��ʱ����ӡʣ��ĸ���
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
			biao.an_niu(" ��" + to_string(ye_ma)+"ҳ", 0, 652, 80, 700);
			if(renshu % 12==0)
				biao.an_niu(" ��" + to_string(renshu/12) + "ҳ", 80, 652, 180, 700);
			else
				biao.an_niu(" ��" + to_string(renshu / 12+1) + "ҳ", 80, 652, 180, 700);
			int ii = 0;
			//while (b>0)//�������һҳ��ѭ�����������һҳʱ��b����һ�����֣�Ȼ��Ὣ cheng_ji_shu_zu�� b--b+12 ֮�����Ϣ��ʾ�����������ѭ��ֻ����ʾ0--b1��ģ�0-b��������Ѿ����ͷ��ˣ����ԲŻ�ͻȻ��������
			{
				for (; ii < b1; ii++)
				{
					if (ii == 0)
					{
						biao.an_niu3("ѧ��", 344 + 124 * 0, 0, 468 + 124 * 0, 48);
						biao.an_niu3("����", 344 + 124 * 1, 0, 468 + 124 * 1, 48);
						biao.an_niu3("����", 344 + 124 * 2, 0, 468 + 124 * 2, 48);
						biao.an_niu3("��ѧ", 344 + 124 * 3, 0, 468 + 124 * 3, 48);
						biao.an_niu3("Ӣ��", 344 + 124 * 4, 0, 468 + 124 * 4, 48);
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

			if (biao.an_niu2("     �˳�", 920, 652, 1080, 700))
			{
				
				delete[]n;
				n = nullptr;
				biao.chu_shi_jei_mian();
				break;
			}
			if (12 <= b)
			{
				if (GetAsyncKeyState(VK_LEFT))  // ������Ƽ��Ƿ񱻰���
				{
					if (b >= 12)
						b -= 12;
					b1 = 12;//���� �ָ� b1��ֵ�����������һҳʱ��˵���������һҳ�ˣ���Ҫ ʹ����������ʾ 12����
					ye_ma--;
					biao.chu_shi_bj_jm();
				}

				if (biao.an_niu(" ��һҳ", 520, 652, 680, 700))
				{
					if (b >= 12)
						b -= 12;
					b1 = 12;//���� �ָ� b1��ֵ�����������һҳʱ��˵���������һҳ�ˣ���Ҫ ʹ����������ʾ 12����
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
				if (biao.an_niu(" ��һҳ", 720, 652, 880, 700))
				{
					//if (renshu - b >= 12)
						b += 12;
					
					ye_ma++;
					biao.chu_shi_bj_jm();
				}

				biao.an_niu("��< >��ҳ    ", 200, 652, 400, 700);
				
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
