#include "Header.h"
int n = 8;
void vetuong_tren();
void vetuong_duoi();
void vetuong_phai();
void vetuong_trai();
void ve_ran(int toadox[], int toadoy[]);
void xoa_ran(int toadox[], int toadoy[]);
void khoitao(int toadox[], int toadoy[]);
void xuly(int toadox[], int toadoy[], int x, int y);
void them(int a[], int x);
void xoa(int a[], int vt);
bool kiemtra_tuong(int x0,int y0);
bool kiemtra_duoi(int toadox[], int toadoy[]);
bool kt(int toadox[], int toadoy[]);
int main()
{
	int check = 2;
	bool gameover = false;
	int toadox[100], toadoy[100];
	khoitao(toadox, toadoy);
	ve_ran(toadox,toadoy);
	int x = 50, y = 14;
	while (true)
	{
		vetuong_tren();
		vetuong_duoi();
		vetuong_trai();
		vetuong_phai();
		
		/*check: 0:di xuong
		1: di len
		2: qua phai
		3: qua trai
		*/
		if (_kbhit())
		{
			char kitu = _getch();
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && check != 0)
				{
					check = 1;
				}
				else if (kitu == 80 && check != 1)
				{
					check = 0;
				}
				else if (kitu == 77 && check != 3)
				{
					check = 2;
				}
				else if (kitu == 75 && check != 2)
				{
					check = 3;
				}
			}
		}
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		xoa_ran(toadox, toadoy);
		xuly(toadox, toadoy, x, y);
		gameover = kt(toadox, toadoy);
		if (gameover)
		{
			system("cls");
			gotoXY(50, 14);
			cout << "GAME OVER!!" << endl;
			cout << "\t\t\t\t\t";
			system("pause");
			break;
		}
		Sleep(50);
	}
	_getch;
	return 0;
}
void vetuong_tren()
{
	int x = 10, y = 1;
	while (x < 100)
	{
		gotoXY(x, y);
		cout << "-";
		x++;
	}
}
void vetuong_duoi()
{
	int x = 10, y = 28;
	while (x < 100)
	{
		gotoXY(x, y);
		cout << "-";
		x++;
	}
}
void vetuong_phai()
{
	int x = 100, y = 2;
	while (y < 28)
	{
		gotoXY(x, y);
		cout << "|" << endl;
		y++;
	}
}
void vetuong_trai()
{
	int x = 10, y = 2;
	while (y < 28)
	{
		gotoXY(x, y);
		cout << "|" << endl;
		y++;
	}
}
void ve_ran(int toadox[],int toadoy[])
{
	for (int i = 0;i < n;i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << "O";
		}
		else
		{
			cout << "o";
		}
		
	}
}
void xoa_ran(int toadox[], int toadoy[])
{
	for (int i = 0;i < n;i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
void khoitao(int toadox[], int toadoy[])
{
	int x = 50, y = 14;
	for (int i = 0;i < n;i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void xuly(int toadox[], int toadoy[], int x, int y)
{
	//them toa do dau mang
	them(toadox,x);
	them(toadoy, y);
	//xoa toa do cuoi mang
	xoa(toadox, n - 1);
	xoa(toadoy, n - 1);
	//ve ran
	ve_ran(toadox, toadoy);
}
void them(int a[] ,int x)
{
	for (int i = n;i > 0;i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	n++;

}
void xoa(int a[], int vt)
{
	for (int i = vt;i < n;i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
bool kiemtra_tuong(int x0,int y0)
{
	//tuong tren
	if (y0 == 1 && (x0 >= 10 && x0 <= 100))
		return true;
	//tuong duoi
	if (y0 == 28 && (x0 >= 10 && x0 <= 100))
		return true;
	//tuong phai
	if (x0 == 100 && (y0 >= 1 && y0 <= 28))
		return true;
	//tuong trai
	if (x0 == 10 && (y0 >= 1 && y0 <= 28))
		return true;
}
bool kiemtra_duoi(int toadox[],int toadoy[])
{
	for (int i = 1;i < n;i++)
	{
		if (toadox[0] == toadox[i] && toadoy[0] == toadoy[i])
			return true;
	}
	return false;
}
bool kt(int toadox[], int toadoy[])
{
	bool kt1 = kiemtra_tuong(toadox[0], toadoy[0]);
	bool kt2 = kiemtra_duoi(toadox, toadoy);
	if (kt1 == true || kt2 == true)
	{
		return true;
	}
	return false;
}