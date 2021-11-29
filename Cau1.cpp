#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<queue>


using namespace std;
typedef int ItemType;

struct Tnode
{
	ItemType info;
	Tnode* Left;
	Tnode* Right;
};

struct BStree
{
	Tnode* Root;
};

void InitBStree(BStree& bst)
{
	bst.Root = NULL;
}


Tnode* createTNode(ItemType x)
{
	Tnode* p = new Tnode;
	if (p == NULL)
	{
		return NULL;
	}
	p->info = x;
	p->Right = NULL;
	p->Left = NULL;
	return p;
}

int insertTnode(Tnode*& root, Tnode* p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		return 1;

	}
	if (root->info == p->info)
		return 0;
	if (p->info < root->info)
		insertTnode(root->Left, p);
	else
		insertTnode(root->Right, p);
	return 1;
}

void showNode(Tnode* p)
{
	printf("%-5d ", p->info);

}
// Duyet cay theo chieu rong
void levelOrder(Tnode* root)
{
	if (root == NULL) return;

	queue <Tnode*> q;
	q.push(root);

	while (!q.empty()) {
		Tnode* p;
		p = q.front();
		q.pop();
		printf("%-5d", p->info);
		if (p->Left != NULL)
			q.push(p->Left);
		if (p->Right != NULL)
			q.push(p->Right);
	}
}
void traverseNLR(Tnode* root)
{
	if (root == NULL)
		return;
	showNode(root);
	traverseNLR(root->Left);
	traverseNLR(root->Right);
}
void createBSTree_FromFile(BStree& bst, char fileName[])
{ //Ham tao cay NPTK tu file
	FILE* f;
	fopen_s(&f, fileName, "rt");
	if (!f)
	{
		printf("Mo file khong thanh cong\n");
		return;
	}
	int n;
	fscanf(f, "%d", &n);
	ItemType x;
	InitBStree(bst);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%d", &x);
		Tnode* p = createTNode(x);
		insertTnode(bst.Root, p);
	}
	fclose(f);
}


Tnode* findTNodeReplace(Tnode*& p)
{
	Tnode* f = p;
	Tnode* q = p->Right;
	while (q->Left != NULL)
	{
		f = q;
		q = q->Left;
	}
	p->info = q->info;

	if (f == p)
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q;
}

int deleteTNodeX(Tnode*& root, ItemType x)
{ //Hàm xóa nút có giá trị là x
	if (root == NULL) //Khi cây rỗng
		return 0; //Xóa không thành công
	if (root->info > x)
		return deleteTNodeX(root->Left, x);
	else if (root->info < x)
		return deleteTNodeX(root->Right, x);
	else
	{
		Tnode* p = root;
		if (root->Left == NULL)
		{
			root = root->Right;
			delete p;
		}
		else if (root->Right == NULL)
		{
			root = root->Left;
			delete p;
		}
		else
		{
			Tnode* q = findTNodeReplace(p);
			delete q;
		}
		return 1;
	}
}
int Max(Tnode* root, int k)
{
	if (root->Right != NULL || k == 0)
	{
		return root->info;
	}
	else
	{
		k--;
		Max(root->Right, k);
	}
}
int  tongNut_NhoHonX(Tnode* root, int x)
{
	if (root == NULL)
		return 0;
	else
	{
		int l = tongNut_NhoHonX(root->Left, x);
		int r = tongNut_NhoHonX(root->Right, x);
		if (root->info < x)
			return root->info + r + l;
		else
			return 0 + r + l;
	}
}
int demNutMucK_1Con_BoiSo7(Tnode* root, int k)
{
	if (!root) return 0;
	if (root->info % 7 == 0 && k == 0 && (root->Left == NULL && root->Right != NULL || root->Left != NULL && root->Right == NULL))
		return 1;
	k--;//muc k giam dan ve 0
	int nl = demNutMucK_1Con_BoiSo7(root->Left, k);
	int nr = demNutMucK_1Con_BoiSo7(root->Right, k);
	return nl + nr;
}

void menu()
{
	cout << "----------------------------MENU----------------------------" << endl;
	printf("0.Thoat chuong trinh\n");
	printf("1.nhap va xuat file theo NLR\n");
	printf("2. NLR\n");
	printf("3.Duyet cay theo chieu rong, tu tren xuong, tu trai sang phai\n");

	printf("4.Tong cac nut nho hon x\n");
	printf("5.Dem so nut o muc K co 1 con va la boi so 7\n");
	printf("6.Xuat ra so chinh phuong lon nhat\n");
	printf("7.Xoa cac gia tri nho hon y\n");
	cout << "------------------------------------------------------------" << endl;
}
void xoa_Nut_NhoHonY(Tnode*& root, int y)
{
	if (root != NULL)
	{
		xoa_Nut_NhoHonY(root->Left, y);
		xoa_Nut_NhoHonY(root->Right, y);
		if (root->info < y)
			deleteTNodeX(root, root->info);
	}
	return;
}
int main()
{
	menu();
	BStree bst;
	InitBStree(bst);
	char filename[30];
	int chon;
	int k, x, y, tong, dem = 0;
	do
	{
		printf("\nchon:");
		scanf_s("%d", &chon);
		switch (chon)
		{
		case 0:
			printf("quit\n");
			break;
		case 1:
			cin.ignore();
			printf("Nhap ten file: ");
			gets_s(filename);
			createBSTree_FromFile(bst, filename);
			traverseNLR(bst.Root);
			break;
		case 2:
			traverseNLR(bst.Root);
			break;
		case 3:
			levelOrder(bst.Root);
			break;
		case 4:
			printf("Nhap x = ");
			scanf_s("%d", &x);
			tong = tongNut_NhoHonX(bst.Root, x);
			printf("Tong nut cac nut be hon %d la: %d\n", x, tong);
			break;
		case 5:
			printf("Nhap k = ");
			scanf_s("%d", &k);
			dem = demNutMucK_1Con_BoiSo7(bst.Root, k);
			printf("So luong nut o muc %d co 1 con va la boi so 7 la: %d\n", k, dem);
			break;
		case 6:
			printf("em khong biet lam\n");
			break;
		case 7:
			printf("Nhap y = ");
			scanf_s("%d", &y);
			xoa_Nut_NhoHonY(bst.Root, y);
			break;
		}
	} while (chon != 0);
	return 0;
}