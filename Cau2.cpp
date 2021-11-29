//#include <conio.h>
//#include <stdio.h>
//#include <queue>
//#include <stack>
//#include <Windows.h>
//#include <iostream>
//#include <fstream>
//using namespace std;
//
///* Khai báo kiểu dữ liệu của Node */
//
///* Khai báo thuộc tính color */
//enum EColor { RED, BLACK };
//
///* Khai báo cấu trúc node */
//struct Phone {
//	char seri[15];
//	char ten_DT[25];
//	char hang[10];
//	float giaban;
//	int namsanxuat;
//};
//typedef Phone ItemType;
//struct BRTNode
//{
//	Phone Info;
//	EColor Color;
//	BRTNode* Left, * Right, * Parent;
//};
//
///* Khai báo cấu trúc cây Đỏ-Đen */
//struct BRTree
//{
//	BRTNode* Root;
//};
////==================================================
//BRTNode* createBRTNode(ItemType x);
//void set_Color(int colorBackground, int colorText);
//void initBRTree(BRTree& brt);
//int demNam(BRTNode* root, int nam);
//
//void swapColors(EColor& color1, EColor& color2);
//void swapInfos(ItemType& info1, ItemType& info2);
//
//BRTNode* BRTInsert(BRTNode* root, BRTNode* pNew);
//void rotateLeft(BRTNode*& root, BRTNode*& p);
//void rotateRight(BRTNode*& root, BRTNode*& p);
//void fixViolation(BRTNode*& root, BRTNode*& p);
//void insert(BRTNode*& root, ItemType Info);
//
//bool isOnLeft(BRTNode* p);
//bool hasRedChild(BRTNode* p);
//BRTNode* findUncle(BRTNode* p);
//BRTNode* findSibling(BRTNode* p);
//BRTNode* findSuccessor(BRTNode* p);
//void fixDoubleBlack(BRTNode*& root, BRTNode* p);
//
////==================================================
//BRTNode* createBRTNode(ItemType x)
//{
//	BRTNode* p = new BRTNode;
//	if (p == NULL)
//	{
//		printf("\nKhong the cap phat nut moi!");
//		_getch();
//		return NULL;
//	}
//	p->Info = x;		// Gán dữ liệu mới cho nút
//	p->Color = RED;		// Gán màu đỏ (Red) mặc định
//	p->Left = NULL;		// Chưa có nút con trái
//	p->Right = NULL;	// Chưa có nút con phải
//	p->Parent = NULL;	// Chưa có nút cha
//	return p;
//}
////==================================================
//void set_Color(int colorBackground, int colorText) {
//	HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hColor, colorBackground * 16 + colorText);
//	/*
//	0 = Black       8 = Gray
//	1 = Blue        9 = Light Blue
//	2 = Green       A = Light Green
//	3 = Aqua        B = Light Aqua
//	4 = Red         C = Light Red
//	5 = Purple      D = Light Purple
//	6 = Yellow      E = Light Yellow
//	7 = White       F = Bright White
//	=> set_Color(X); -> X = a*16 + b, a (background) và b (character)
//	*/
//}
//void showBRTNode(BRTNode* p)
//{
//	if (p->Color == RED)
//		set_Color(15, 12);	//Light Red=12 (C), Bright White=15 (F)
//	else if (p->Color == BLACK)
//		set_Color(15, 0);	//Black=0, Bright White=15 (F)
//	_cprintf("%-20s%-25s %-15s %-10.2f %-5d\n", p->Info.seri, p->Info.ten_DT, p->Info.hang, p->Info.giaban, p->Info.namsanxuat);
//	set_Color(14, 2);		//Light Yellow=14 (E), Green=2
//}
////==================================================
///* Initalize BRTree */
//void initBRTree(BRTree& brt)
//{
//	brt.Root = NULL;
//}
//
///* Hoán vị màu (Color) */
//void swapColors(EColor& color1, EColor& color2)
//{
//	EColor temp = color1;
//	color1 = color2;
//	color2 = temp;
//}
//
///* Hoán vị giá trị */
//void swapInfos(ItemType& info1, ItemType& info2)
//{
//	ItemType temp = info1;
//	info1 = info2;
//	info2 = temp;
//}
//
///* Một hàm đệ quy để thực hiện việc duyệt thứ tự RNL */
//void showBRTree_InOrder(BRTNode* root)
//{
//	if (root == NULL) return;
//
//	showBRTree_InOrder(root->Right);
//	showBRTNode(root); //printf("%4d", root->Info);
//	showBRTree_InOrder(root->Left);
//}
//
//
//
///* insert BRTNode */
//BRTNode* BRTInsert(BRTNode* root, BRTNode* pNew)
//{
//	/* Nếu cây trống thì trả về một BRTNode mới */
//	if (root == NULL) return pNew;
//
//	/* Nếu không thì tiếp tục duyệt xuống dưới cây */
//	if (_strcmpi(pNew->Info.seri, root->Info.seri) < 0)
//	{
//		root->Left = BRTInsert(root->Left, pNew);
//		root->Left->Parent = root;
//	}
//	else if (_strcmpi(pNew->Info.seri, root->Info.seri) > 0)
//	{
//		root->Right = BRTInsert(root->Right, pNew);
//		root->Right->Parent = root;
//	}
//
//	/* Trả về con trỏ BRTNode */
//	return root;
//}
//
///* Thuật toán xoay trái */
//void rotateLeft(BRTNode*& root, BRTNode*& p)
//{
//	BRTNode* pRight = p->Right;
//
//	p->Right = pRight->Left;
//
//	if (p->Right != NULL)
//		p->Right->Parent = p;
//
//	pRight->Parent = p->Parent;
//
//	if (p->Parent == NULL)
//		root = pRight;
//
//	else if (p == p->Parent->Left)
//		p->Parent->Left = pRight;
//
//	else
//		p->Parent->Right = pRight;
//
//	pRight->Left = p;
//	p->Parent = pRight;
//}
//
///* Thuật toán xoay phải */
//void rotateRight(BRTNode*& root, BRTNode*& p)
//{
//	BRTNode* pLeft = p->Left;
//
//	p->Left = pLeft->Right;
//
//	if (p->Left != NULL)
//		p->Left->Parent = p;
//
//	pLeft->Parent = p->Parent;
//
//	if (p->Parent == NULL)
//		root = pLeft;
//
//	else if (p == p->Parent->Left)
//		p->Parent->Left = pLeft;
//
//	else
//		p->Parent->Right = pLeft;
//
//	pLeft->Right = p;
//	p->Parent = pLeft;
//}
//
///* Sửa lại cấu trúc khi chèn BRTNode vào hoặc xóa node */
//void fixViolation(BRTNode*& root, BRTNode*& pt)
//{
//	BRTNode* pParent = NULL;
//	BRTNode* pGrandParent = NULL;
//
//	if (!pt || !pt->Parent) return; //Nút rỗng thì dừng
//
//	while ((pt != root) && (pt->Color != BLACK) && (pt->Parent->Color == RED))
//	{
//		pParent = pt->Parent;
//		pGrandParent = pt->Parent->Parent; //Nút ông
//
//		if (!pGrandParent) break; //Nút ông bị rỗng
//
//		/* Trường hợp A:
//		node cha của pt là con trái của node ông của pt */
//		if (pParent == pGrandParent->Left)
//		{
//			BRTNode* pUncle = pGrandParent->Right;
//
//			/* Trường hợp: 1
//			node chú của pt là node đỏ khi này chỉ cần đổi màu cho node đó thành đen */
//			if (pUncle != NULL && pUncle->Color == RED)
//			{
//				pGrandParent->Color = RED;
//				pParent->Color = BLACK;
//				pUncle->Color = BLACK;
//				pt = pGrandParent;
//			}
//
//			else
//			{
//				/* Trường hợp: 2
//				pt là node con phải của node cha nó ta thực hiện xoay trái */
//				if (pt == pParent->Right)
//				{
//					rotateLeft(root, pParent);
//					pt = pParent;
//					pParent = pt->Parent;
//				}
//
//				/* Trường hợp: 3
//				pt là con trái của node cha nó ta thực hiện xoay phải */
//				rotateRight(root, pGrandParent);
//				swapColors(pParent->Color, pGrandParent->Color);
//				pt = pParent;
//			}
//		}
//
//		/* Trường hợp: B
//		node cha của pt là con phải của node cha của pt */
//		else
//		{
//			BRTNode* pUncle = pGrandParent->Left;
//
//			/* Trường hợp: 1
//			node chú của pt là node đỏ khi này chỉ cần đổi màu cho node đó thành đen */
//			if ((pUncle != NULL) && (pUncle->Color == RED))
//			{
//				pGrandParent->Color = RED;
//				pParent->Color = BLACK;
//				pUncle->Color = BLACK;
//				pt = pGrandParent;
//			}
//			else
//			{
//				/* Trường hợp: 2
//				pt là con trái của node cha nó ta thực hiện xoay phải */
//				if (pt == pParent->Left)
//				{
//					rotateRight(root, pParent);
//					pt = pParent;
//					pParent = pt->Parent;
//				}
//
//				/* Trường hợp: 3
//				pt là node con phải của node cha nó -> nên thực hiện xoay trái */
//				rotateLeft(root, pGrandParent);
//				swapColors(pParent->Color, pGrandParent->Color);
//				pt = pParent;
//			}
//		}
//	}
//
//	root->Color = BLACK;
//}
//
///* Chèn một node mới với dữ liệu đã cho */
//void insert(BRTNode*& root, ItemType Info)
//{
//	BRTNode* pNew = createBRTNode(Info);
//
//	/* Thực hiện chèn như bình thường */
//	root = BRTInsert(root, pNew);
//
//	/* Sửa lại lỗi của quy tắc cây đỏ đen */
//	fixViolation(root, pNew);
//}
//
///* Kiểm tra xem node hiện tại có phải là node con trái của node cha không */
//bool isOnLeft(BRTNode* p)
//{
//	return p == p->Parent->Left;
//}
//
///* Trả về con trỏ tới node chú (Uncle) */
//BRTNode* findUncle(BRTNode* p) {
//	// Nếu không có node cha hoặc node ông, thì không có node chú
//	if (p->Parent == NULL || p->Parent->Parent == NULL)
//		return NULL;
//
//	if (isOnLeft(p->Parent))
//		// node chú bên phải
//		return p->Parent->Parent->Right;
//	else
//		// node chú bên trái
//		return p->Parent->Parent->Left;
//}
//
///* Trả về con trỏ cho node anh chị em */
//BRTNode* findSibling(BRTNode* p) {
//	// node anh rỗng nếu không tồn tại node cha 
//	if (p->Parent == NULL)
//		return NULL;
//
//	if (isOnLeft(p))
//		return p->Parent->Right;
//	else
//		return p->Parent->Left;
//}
//
///* Tìm nút không có nút con bên trái trong cây con của nút đã cho */
//BRTNode* findSuccessor(BRTNode* p) {
//	BRTNode* temp = p;
//
//	while (temp->Left != NULL)
//		temp = temp->Left;
//
//	return temp;
//}
//
///* Kiểm tra có node hiện tại có node con là nút đỏ hay không */
//bool hasRedChild(BRTNode* p) {
//	return (p->Left != NULL && p->Left->Color == RED) ||
//		(p->Right != NULL && p->Right->Color == RED);
//}
//
//void fixDoubleBlack(BRTNode*& root, BRTNode* p) {
//	// p là node gốc thì return
//	if (p == root) return;
//
//	BRTNode* pSibling = findSibling(p);
//	BRTNode* pParent = p->Parent;
//	if (pSibling == NULL) {
//		// Không có sibiling, màu đen kép được đẩy lên 
//		fixDoubleBlack(root, pParent);
//	}
//	else {
//		if (pSibling->Color == RED) {
//			// Anh chị em màu đỏ 
//			pParent->Color = RED;
//			pSibling->Color = BLACK;
//			if (isOnLeft(pSibling)) {
//				// trường hợp left 
//				rotateRight(root, pParent);
//			}
//			else {
//				// trường hợp right 
//				rotateLeft(root, pParent);
//			}
//			fixDoubleBlack(root, p);
//		}
//		else {
//			// Anh chị em đen 
//			if (hasRedChild(pSibling)) {
//				// Ist nhất 1 trẻ em màu đỏ 
//				if (pSibling->Left != NULL && pSibling->Left->Color == RED) {
//					if (isOnLeft(pSibling)) {
//						// left left 
//						pSibling->Left->Color = pSibling->Color;
//						pSibling->Color = pParent->Color;
//						rotateRight(root, pParent);
//					}
//					else {
//						// right left 
//						pSibling->Left->Color = pParent->Color;
//						rotateRight(root, pSibling);
//						rotateLeft(root, pParent);
//					}
//				}
//				else {
//					if (isOnLeft(pSibling)) {
//						// left right 
//						pSibling->Right->Color = pParent->Color;
//						rotateLeft(root, pSibling);
//						rotateRight(root, pParent);
//					}
//					else {
//						// right right 
//						pSibling->Right->Color = pSibling->Color;
//						pSibling->Color = pParent->Color;
//						rotateLeft(root, pParent);
//					}
//				}
//				pParent->Color = BLACK;
//			}
//			else {
//				// Hai con đen 
//				pSibling->Color = RED;
//				if (pParent->Color == BLACK)
//					fixDoubleBlack(root, pParent);
//				else
//					pParent->Color = BLACK;
//			}
//		}
//	}
//}
//
//int demNam(BRTNode* root, int nam)
//{
//	BRTNode* temp = root;
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int demTrai = demNam(root->Left, nam);
//	int demPhai = demNam(root->Right, nam);
//	if (root->Info.namsanxuat == nam)
//		return 1 + demTrai + demPhai;
//	else
//		return 0 + demTrai + demPhai;
//}
//
//
////==================================================
//void createBRTreeFromFile(BRTree& brt)
//{
//	initBRTree(brt);
//	char filename[50];
//	FILE* f;
//	printf("Nhap ten file: ");
//	gets_s(filename);
//	fopen_s(&f, filename, "rt");
//	if (!f)
//	{
//		printf("File khong ton tai\n");
//		return;
//	}
//	int n;
//	fscanf(f, "%d\n", &n);
//	ItemType x;
//	for (int i = 0; i < n; i++)
//	{
//		fscanf(f, "%[^#]#", &x.seri);
//		fscanf(f, " %[^#]#%[^#]#%f#%d\n", &x.ten_DT, &x.hang, &x.giaban, &x.namsanxuat);
//		insert(brt.Root, x);
//	}
//}
///* Hàm main để thực hiện kiểm tra kết quả */
//void main()
//{
//	BRTree brtree;
//	initBRTree(brtree);
//	createBRTreeFromFile(brtree);
//	printf("\nOutput: RNL\n");
//	showBRTree_InOrder(brtree.Root);
//	int nam, dem = 0;
//	printf("Nhap nam: ");
//	scanf_s("%d", &nam);
//	dem = demNam(brtree.Root, nam);
//	printf("So dien thoat co nam san xuat la %d: %d\n", nam, dem);
//	_getch();
//}