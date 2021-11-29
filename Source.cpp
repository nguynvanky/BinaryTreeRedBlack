//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <Windows.h>
//#include <sstream>
//using namespace std;
//#define MAX 50
//struct BAC { // cau 8
//	int v;
//	int bac;
//};
//struct Graph {
//	int dinh;
//	int flag; // 1 la co huong, 0 la vo huong
//	int a[MAX][MAX];
//};
//
//// Khai bao nguyen mau ham
//void TextColor(int color); // tô màu khi xuất ma trận
//void docFile(Graph& g, string filename);
//void xuatMaTran(Graph g);
//void menu();
//void tinh_Bac_All_Dinh(Graph g, int Bac[]);
//int tinh_Bac_Dinh(Graph g, int v);
//void dinhKe_V(Graph g, int v);
//void dinhKe_ALL(Graph g);
//int soCanh_DoThi(Graph g);
//// floyd
//void Floyd(Graph g, int D[][MAX], int Q[][MAX]);
//void DuongDi(int Q[][MAX], int n, int dinhdau, int dinhcuoi);
//void KhoiTao_Q(int Q[][MAX], Graph g);
//void KhoiTao_D(int D[][MAX], Graph g);
//void xuat(int a[][MAX], int n);
//
//int main()
//{
//	string filename;
//	Graph g;
//	int chon;
//	int Bac[MAX], canh;
//	int Q[MAX][MAX], D[MAX][MAX];
//	int batdau, ketthuc;
//	menu();
//	do {
//		printf(" Chon: ");
//		cin >> chon;
//		switch (chon)
//		{
//		case 1:
//			printf("Nhap ten file: ");
//			cin >> filename;
//			docFile(g, filename);
//			break;
//		case 2:
//			xuatMaTran(g);
//			break;
//		case 3:
//			dinhKe_ALL(g);
//			break;
//		case 4:
//			tinh_Bac_All_Dinh(g, Bac);
//			canh = soCanh_DoThi(g);
//			printf(" So canh cua do thi : %d\n", canh);
//			break;
//		case 5:
//			break;
//		case 6:
//			break;
//		case 7:
//			Floyd(g, D, Q);
//			printf("Nhap diem bat dau: ");
//			scanf_s("%d", &batdau);
//			printf("Nhap diem ket thuc: ");
//			scanf_s("%d", &ketthuc);
//			DuongDi(Q,g.dinh, batdau, ketthuc);
//			printf("\n");
//			break;
//		default:
//			break;
//		}
//	} while (chon != 0);
//	system("pause");
//	return 0;
//}
//void TextColor(int color)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}
//void docFile(Graph& g, string filename)
//{
//	ifstream f(filename, ios_base::in);
//	if (f.fail())
//	{
//		printf("File khong ton tai\n");
//		g.flag = -1;
//		return;
//	}
//	f >> g.flag;
//	f >> g.dinh;
//	for (int i = 0; i < g.dinh; i++)
//	{
//		for (int j = 0; j < g.dinh; j++)
//		{
//			f >> g.a[i][j];
//		}
//	}
//	f.close();
//}
//void xuatMaTran(Graph g)
//{
//	if (g.flag == 1)
//	{
//		printf(" Do thi co huong\n");
//	}
//	else if (g.flag == 0)
//	{
//		printf(" Do thi vo huong\n");
//
//	}
//	else
//	{
//		printf(" Do thi khong ton tai\n");
//	}
//	printf(" So dinh cua do thi: %d\n", g.dinh);
//	printf(" ");
//	for (int i = 0; i < g.dinh; i++)
//	{
//		printf("%4d", i);
//	}
//	cout << endl << endl;;
//	for (int i = 0; i < g.dinh; i++)
//	{
//		TextColor(7);
//		printf("%d", i);
//		TextColor(11);
//		for (int j = 0; j < g.dinh; j++)
//		{
//			if (g.a[i][j] == 100)
//				printf("%4c", 236); // dấu vô cực mã ascii
//			else
//				printf("%4d", g.a[i][j]);
//		}
//		printf("\n\n");
//	}
//	TextColor(7);
//}
//void menu()
//{
//	printf(" 1. Doc file ma tran trong so\n");
//	printf(" 2. Xuat do thi\n");
//	printf(" 3. Xay dung danh sach ke cua do thi\n");
//	printf(" 4. Xac dinh bac cua tung dinh va so canh cua do thi\n");
//	printf(" 5. Kiem tra va xuat chu trinh hoac duong di Euler\n");
//	printf(" 6. Xuat cay khung nho nhat\n");
//	printf(" 7. Thuat toan floyd\n");
//
//}
//int tinh_Bac_Dinh(Graph g, int v)
//{
//	int dem = 0;
//	if (g.flag == 0)
//	{
//		for (int i = 0; i < g.dinh; i++)
//		{
//			{
//				if (g.a[v][i] != 0 && g.a[v][i] != 100)
//					dem++;
//			}
//		}
//		return dem;
//	}
//	return -1;
//}
//void tinh_Bac_All_Dinh(Graph g, int Bac[])
//{
//	for (int i = 0; i < g.dinh; i++)
//	{
//		Bac[i] = 0;
//		Bac[i] = tinh_Bac_Dinh(g, i);
//		printf(" Bac dinh %d = %d\n", i, Bac[i]);
//	}
//}
//void dinhKe_V(Graph g, int v)
//{
//	cout << " Tap ke dinh " << v << " : ";
//	for (int i = 0; i < g.dinh; i++)
//	{
//		if (g.a[v][i] != 0 && g.a[v][i] != 100)
//		{
//			cout << i + 1 << " ";
//		}
//	}
//	cout << endl;
//}
//void dinhKe_ALL(Graph g)
//{
//	for (int i = 0; i < g.dinh; i++)
//	{
//		dinhKe_V(g, i);
//	}
//}
//int soCanh_DoThi(Graph g)
//{
//	int dem = 0;
//	if (g.flag == 0)
//	{
//		for (int i = 0; i < g.dinh; i++)
//		{
//			for (int j = 0; j < g.dinh; j++)
//			{
//				// Đồ thị vô hướng có tính chất đối xứng nên chỉ cần đếm tam giác trên hoặc dưới đường chéo chính
//				if (i < j)
//				{
//					if (g.a[i][j] != 0 && g.a[i][j] != 100)
//						dem++;
//				}
//			}
//		}
//	}
//	else if (g.flag == 1)
//	{
//		for (int i = 0; i < g.dinh; i++)
//		{
//			for (int j = 0; j < g.dinh; j++)
//			{
//				if (g.a[i][j] != 0 && g.a[i][j] != 100)
//					dem++;
//			}
//		}
//	}
//	return dem;
//}
//// Floyd
//#pragma region Floyd
//void xuat(int a[][MAX], int n)
//{
//	printf(" ");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%4d", i);
//	}
//	cout << endl << endl;;
//	for (int i = 0; i < n; i++)
//	{
//		TextColor(7);
//		printf("%d", i);
//		TextColor(11);
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] == 100)
//				printf("%4c", 236); // dấu vô cực mã ascii
//			else
//				printf("%4d", a[i][j]);
//		}
//		printf("\n\n");
//	}
//	TextColor(7);
//}
//void KhoiTao_D(int D[][MAX], Graph g)
//{
//	for (int i = 0; i < g.dinh; i++)
//	{
//		for (int j = 0; j < g.dinh; j++)
//		{
//			D[i][j] = g.a[i][j];
//		}
//	}
//}
//void KhoiTao_Q(int Q[][MAX], Graph g)
//{
//	for (int i = 0; i < g.dinh; i++)
//	{
//		for (int j = 0; j < g.dinh; j++)
//		{
//			if (g.a[i][j] != 0 && g.a[i][j] != 100)
//				Q[i][j] = j;
//			else
//				Q[i][j] = 0;
//		}
//	}
//}
//void DuongDi(int Q[][MAX], int n, int dinhdau, int dinhcuoi)
//{
//	if (Q[dinhdau][dinhcuoi] == 0)
//	{
//		cout << "Khong co duong di" << endl;
//		return;
//	}
//	cout << dinhdau << "-->";
//	if (dinhcuoi == Q[dinhdau][dinhcuoi])
//		cout << dinhcuoi;
//	else
//	{
//		DuongDi(Q, n, Q[dinhdau][dinhcuoi], dinhcuoi);
//	}
//}
//void Floyd(Graph g, int D[][MAX], int Q[][MAX])
//{
//	KhoiTao_D(D, g);
//	KhoiTao_Q(Q, g);
//	for (int k = 0; k < g.dinh; k++)
//	{
//		for (int i = 0; i < g.dinh; i++)
//		{
//			for (int j = 0; j < g.dinh; j++)
//			{
//				if (D[i][j] > D[i][k] + D[k][j])
//				{
//					if (D[i][k] + D[k][j] != 0)
//					{
//						D[i][j] = D[i][k] + D[k][j];
//						Q[i][j] = Q[i][k];
//					}
//				}
//			}
//		}
//		printf("D%d = \n", k);
//		xuat(D, g.dinh);
//		printf("\n");
//		printf("Q%d = \n", k);
//		xuat(Q, g.dinh);
//		printf("\n");
//	}
//}
//#pragma endregion