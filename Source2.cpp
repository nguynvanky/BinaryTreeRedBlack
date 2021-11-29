#include"Tree.h"
#include<iostream>
#include<time.h>

using namespace std;

void Menu();
void themPhanTuRand(Node*& root);
void themPhanTuNhap(Node*& root);
int TimNutX(Node*& root, int x);
int TimGiaTriLonNhat(Node* root);
int TimGiaTriNhoNhat(Node* root);
int TongDuong(Node* root);
int TongAm(Node* root);
int DemNutTrongCayDeQuy(Node* root);
int DemSoNguyenTo(Node* root);
int TongDoan(Node* root, int a, int b);
int DemDoan(Node* root, int a, int b);
int DemGiaTriLonHonXTaiDoan(Node* root, int a, int b, int x);
void XuatPhanTuOMucK(Node* root, int k);
int DemNutLaChan(Node* root);
int DemNutCo1NutCon(Node* root);
Node* findMin(Node* root);
void XoaNodeX(Node*& root, int x);
void XoaToanBoNut(Node* root);
//dem nut muc k
int demNutMucK(Node* root, int k);
//tinh tong node muc k chi co 1 con 
int tongMucK1Con(Node* root, int k);

void main()
{
	Node* root = NULL;  // Khoi tao node;
	int Lua = 0;
	do
	{
		Menu();
		cin >> Lua;
		system("cls");
		switch (Lua)
		{
		case 1:
		{
			themPhanTuRand(root);
			break;
		}
		case 2:
		{
			themPhanTuNhap(root);
			break;
		}
		case 3:
		{
			if (root == NULL)
			{
				cout << "Cay rong\n";
				break;
			}
			cout << "Cac phan tu trong cay theo LNR: ";
			LNR(root);
			cout << "\nCac phan tu trong cay theo RNL: ";
			RNL(root);
			break;
		}
		case 4:
		{
			int x;
			cout << "Nhap vao phan tu can tim: "; cin >> x;
			if (TimNutX(root, x) == NULL)
			{
				cout << "Khong tim thay phan tu " << x << " trong cay\n";
			}
			else
				cout << "Tim thay phan tu " << x << " trong cay\n";
			break;
		}
		case 5:
		{

			int x;
			cout << "Nhap vao phan tu can them: "; cin >> x;
			ThemPhanTuVaoCay(root, x);
			break;
		}
		case 6:
		{
			cout << "Gia tri lon nhat la: " << TimGiaTriLonNhat(root);
			break;
		}
		case 7:
		{
			cout << "Gia tri nho nhat la: " << TimGiaTriNhoNhat(root);
			break;
		}
		case 8:
		{
			cout << "Tong cac phan tu duong trong cay: " << TongDuong(root);
			break;
		}
		case 9:
		{
			cout << "Tong cac phan tu am trong cay: " << TongAm(root);
			break;
		}
		case 10:
		{
			cout << "So luong nut trong cay la: " << DemNutTrongCayDeQuy(root);
			break;
		}
		case 11:
		{
			cout << "So luong phan tu la so nguyen to trong cay la: " << DemSoNguyenTo(root);
			break;
		}
		case 12:
		{
			int a, b;
			cout << "Nhap vao a: ";
			cin >> a;
			cout << "\nNhap vao b: ";
			cin >> b;
			cout << "Tong doan: " << TongDoan(root, a, b);
			break;
		}
		case 13:
		{
			int a, b;
			cout << "Nhap vao a: ";
			cin >> a;
			cout << "\nNhap vao b: ";
			cin >> b;
			cout << "So phan tu trong doan la: " << DemDoan(root, a, b);
			break;
		}
		case 14:
		{
			int a, b, x;
			cout << "Nhap vao a: ";
			cin >> a;
			cout << "\nNhap vao b: ";
			cin >> b;
			cout << "\nNhap vao x: ";
			cin >> x;
			cout << "So phan tu lon hon x la: " << DemGiaTriLonHonXTaiDoan(root, a, b, x);
			break;
		}
		case 15:
		{
			int k;
			cout << "Nhap vao muc k can xuat: ";
			cin >> k;
			XuatPhanTuOMucK(root, k);
			break;
		}
		case 16:
		{
			cout << "So Nut La Chan la: " << DemNutLaChan(root);
			break;
		}
		case 17:
		{
			cout << "So luong nut co 1 nut con: " << DemNutCo1NutCon(root);
			break;
		}
		case 18:
		{
			int x;
			cout << "Nhap vao gia tri node can so: "; cin >> x;
			XoaNodeX(root, x);
			break;
		}
		case 19:
		{
			XoaToanBoNut(root);
			root = NULL;
			break;
		}
		case 20:
		{
			int k;
			cout << "Nhap muc k can dem : ";
			cin >> k;
			cout << "Muc " << k << " co " << demNutMucK(root, k) << " nut";
			break;
		}
		case 21:
		{
			int k;
			cout << "Nhap muc k can dem : ";
			cin >> k;
			cout << "Muc " << k << " co " << tongMucK1Con(root, k) << " nut co 1 con";
			break;
		}
		}
	} while (Lua != 0);
}
void Menu()
{
	cout << "\n---------Menu-----------\n";
	cout << "1. Tao Cay ngau nhien\n";
	cout << "2. Tao cay nhap tay \n";
	cout << "3. Xuat cay\n";
	cout << "4. Tim x\n";
	cout << "5. Them phan tu x vao cay\n";
	cout << "6. Tim phan tu co gia tri lon nhat\n";
	cout << "7. Tim phan tu co gia tri nho nhat\n";
	cout << "8. Tong cac phan tu duong la\n";
	cout << "9. Tong cac phan tu am la\n";
	cout << "10. Dem nut trong cay\n";
	cout << "11. Dem phan tu la so nguyen to trong cay\n";
	cout << "12. Tinh Tong Doan\n";
	cout << "13. Dem phan tu trong doan\n";
	cout << "14. Dem phan tu lon hon x\n";
	cout << "15. Xuat phan tu o muc k\n";
	cout << "16. Dem phan tu la node la chan\n";
	cout << "17. Dem nut chi co 1 nut con\n";
	cout << "18. Xoa nut x\n";
	cout << "19. Xoa all nut\n";
	cout << "20. Dem nut muc k\n";
	cout << "21. Tinh tong nut co 1 con o muc k\n";
	cout << "Nhap so tuong ung de chon: ";
}

void themPhanTuRand(Node*& root)
{
	srand(time_t(NULL));
	root = NULL; // Khoi tao cay
	int n, x;
	cout << "Nhap vao so luong nut can them: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		x = rand() % 100;
		ThemPhanTuVaoCay(root, x);
	}
}
void themPhanTuNhap(Node*& root)
{
	int n, x;
	cout << "Nhap vao so luong nut can them: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vao phan tu can them: ";
		cin >> x;
		ThemPhanTuVaoCay(root, x);
	}
}
int TimNutX(Node*& root, int x)
{
	if (root == NULL)
		return NULL;
	else
	{
		if (root->info == x)
			return root->info;
		else
			if (x < root->info)
				return TimNutX(root->left, x);
			else
				TimNutX(root->right, x);
	}
	return root->info;
}
int TimGiaTriLonNhat(Node* root)
{
	if (root->right == NULL)
		return root->info;
	else
		return TimGiaTriLonNhat(root->right);
}
int TimGiaTriNhoNhat(Node* root)
{
	if (root->left == NULL)
		return root->info;
	else
		return TimGiaTriNhoNhat(root->left);
}
int TongDuong(Node* root)
{
	if (root == NULL)
		return NULL;
	else
	{
		int l = TongDuong(root->left);
		int r = TongDuong(root->right);
		if (root->info > 0)
			return (root->info + l + r);
		else
			return (l + r);
	}
}
int TongAm(Node* root)
{
	if (root == NULL)
		return NULL;
	else
	{
		int l = TongAm(root->left);
		int r = TongAm(root->right);
		if (root->info < 0)
			return (root->info + l + r);
		else
			return (l + r);
	}
}
int DemNutTrongCayDeQuy(Node* root)
{
	if (root == NULL)
		return NULL;
	else
	{
		return 1 + DemNutTrongCayDeQuy(root->left) + DemNutTrongCayDeQuy(root->right);
	}
}
int KiemTraSoNguyenTo(int x)
{
	if (x <= 1)
		return 0; // khong phai la so nguyen to
	else
	{
		for (int i = 2; i <= x / 2; i++)
		{
			if (x % i == 0)
				return 0;
		}
	}
	return 1; // la so nguyen to;
}
int DemSoNguyenTo(Node* root)
{
	if (root == NULL)
		return NULL;
	else
	{
		int l = DemSoNguyenTo(root->left);
		int r = DemSoNguyenTo(root->right);
		if (KiemTraSoNguyenTo(root->info) == 1)
			return (1 + l + r);
		else
			return (l + r);
	}
}
int TongDoan(Node* root, int a, int b)
{
	if (root == NULL)
		return NULL;
	else
	{
		int l = TongDoan(root->left, a, b);
		int r = TongDoan(root->right, a, b);
		if (root->info >= a && root->info <= b)
			return (root->info + l + r);
		else
			return (l + r);
	}
}
int DemDoan(Node* root, int a, int b)
{
	if (root == NULL)
		return NULL;
	else
	{
		int l = DemDoan(root->left, a, b);
		int r = DemDoan(root->right, a, b);
		if (root->info >= a && root->info <= b)
			return (1 + l + r);
		else
			return (l + r);
	}
}
int DemGiaTriLonHonXTaiDoan(Node* root, int a, int b, int x)
{
	if (root == NULL)
		return NULL;
	else
	{
		int l = DemGiaTriLonHonXTaiDoan(root->left, a, b, x);
		int r = DemGiaTriLonHonXTaiDoan(root->right, a, b, x);
		if (root->info >= a && root->info <= b)
		{
			if (root->info > x)
				return (1 + l + r);
		}
		else
			return (l + r);
	}
	return 0;
}
void XuatPhanTuOMucK(Node* root, int k)
{
	if (root == NULL)
		return;
	if (k == 0)
		cout << root->info << "\n";
	k--;
	XuatPhanTuOMucK(root->left, k);
	XuatPhanTuOMucK(root->right, k);
}
int DemNutLaChan(Node* root)
{
	if (root == NULL)
		return NULL;
	int l = DemNutLaChan(root->left);
	int r = DemNutLaChan(root->right);
	if (root->left == NULL && root->right == NULL)
	{
		if (root->info % 2 == 0)
			return (1 + l + r);
	}
	return (l + r);
}
int DemNutCo1NutCon(Node* root)
{
	if (root == NULL)
		return NULL;
	int l = DemNutCo1NutCon(root->left);
	int r = DemNutCo1NutCon(root->right);
	if (root->left != NULL && root->right == NULL)
		return (1 + l + r);
	else if (root->right != NULL && root->left == NULL)
		return (1 + l + r);
	return (l + r);


}
void XoaToanBoNut(Node* root)
{
	if (root != NULL)
	{
		XoaToanBoNut(root->left);
		XoaToanBoNut(root->right);
		delete(root);
	}
}
void XoaNodeX(Node*& root, int x)
{
	//1. Tim node co gia tri x
	if (x < root->info)
		XoaNodeX(root->left, x);
	else if (x > root->info)
		XoaNodeX(root->right, x);
	else //tim thay
	{
		//2. Xoa node x
		//x la node la
		if (root->left == NULL && root->right == NULL)
		{
			Node* tmp = root;
			root = NULL;
			delete tmp;
		}
		//x la node co 1 con phai
		else if (root->left == NULL)
		{
			Node* tmp = root;
			root = root->right;
			delete tmp;
		}
		//x la node co 1 con trai
		else if (root->right == NULL)
		{
			Node* tmp = root;
			root = root->left;
			delete tmp;
		}
		//x la node co 2 con
		else
		{
			//Tim node the mang
			Node* rp = findMin(root->right);
			//chep gia tri node the mang len x
			root->info = rp->info;
			//xoa node the mang
			XoaNodeX(root->right, rp->info);
		}
	}

}
Node* findMin(Node* root)
{
	if (root == NULL) return NULL;

	while (root->left != NULL)
		root = root->left;
	return root;
}

//dem nut muc k
int demNutMucK(Node* root, int k)
{
	if (!root) return 0;
	if (k == 0 && !root->left && !root->right)
		return 1;
	k--;//muc k giam dan ve 0
	int nl = demNutMucK(root->left, k);
	int nr = demNutMucK(root->right, k);
	return nl + nr;
}
//tinh tong node muc k chi co 1 con 
int tongMucK1Con(Node* root, int k)
{
	if (!root) return 0;
	if ((k == 0) && ((!root->left && root->right) || (root->left && !root->right)))
		return root->info;
	k--;
	int nl = tongMucK1Con(root->left, k);
	int nr = tongMucK1Con(root->right, k);
	return nl + nr;
}