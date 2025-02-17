//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#define MAX 100
//typedef char TElemType;
//typedef struct Node
//{
//	TElemType data;
//	int parent;
//}Node;
//
//typedef struct Tree
//{
//	Node nodes[MAX];
//	int size;
//}Tree;
//void Init(struct Tree * Ptree, int size)
//{
//	Ptree->size = size;
//	printf("输入节点值及双亲节点在数组中的下标\n");
//	for (int i = 0; i < size; i++)
//	{
//		getchar();
//		scanf("%c %d", &Ptree->nodes[i].data, &Ptree->nodes[i].parent);
//	}
//}
//void Print(struct Tree tree)
//{
//	for (int i = 0; i < tree.size; i++)
//	{
//		printf("%d  %c  %d  %c\n", i, tree.nodes[i].data, tree.nodes[i].parent, tree.nodes[tree.nodes[i].parent].data);
//	}
//}
////查找双亲节点
//int Find(Tree tree, TElemType x)
//{
//	for (int i = 0; i < tree.size; i++)
//	{
//		if (tree.nodes[i].data == x)
//			return tree.nodes[i].parent;
//	}
//	return 0;
//}
//void text()
//{
//	struct Tree tree;
//	int size = 0;
//	printf("请输入节点数\n");
//	scanf("%d", &size);
//	Init(&tree, size);
//	//Print(tree);
//	char a;
//	getchar();
//	scanf("%c", &a);
//	int len = Find(tree, a);
//	printf("%c的双亲为%c,存储位置下标为%d\n", a, tree.nodes[len].data, len);
//}
//
//int main()
//{
//	text();
//	return 0;
//}



////孩子表示法
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
////#include<string.h>
//#include<stdlib.h>
//#define MAX 100
//typedef char TElem;
////孩子节点
//typedef struct Child
//{
//	struct Child* next;
//	int pos;
//}Child;
////节点
//typedef struct Tree
//{
//	TElem data;
//	struct Child* child;//孩子头节点
//}CTRoot;
//
////树
//typedef struct
//{
//	CTRoot nodes[MAX];
//	int size;//节点数
//}CTree;
//
//
//void Init(CTree* node, int size)
//{
//	node->size = size;
//	for (int i = 0; i < size; i++)
//	{
//		printf("请输入第%d节点的数据\n", i + 1);
//		getchar();
//		scanf("%c", &(node->nodes[i].data));
//		node->nodes[i].child = malloc(sizeof(Child));
//		node->nodes[i].child->next = NULL;
//
//		printf("请输入%c的孩子节点数量\n", node->nodes[i].data);
//		int count = 0;
//		scanf("%d", &count);
//		if (count != 0)
//		{
//			Child* p = node->nodes[i].child;
//			for (int j = 0; j < count; j++)
//			{
//				Child * New = malloc(sizeof(Child));
//				New->next = NULL;
//				printf("请输入%d个在顺序表中的位置\n", j + 1);
//				scanf("%d", &New->pos);
//				p->next = New;
//				p = New;
//			}
//		}
//	}
//}
//
//void Find(CTree node, TElem x)
//{
//	int flag = 0;
//	for (int i = 0; i < node.size; i++)
//	{
//		if (node.nodes[i].data == x)
//		{
//			Child* p = node.nodes[i].child->next;
//			while (p)
//			{
//				flag = 1;
//				printf("%c ", node.nodes[p->pos].data);
//				p = p->next;
//			}
//			if (flag == 0)
//				printf("%c为叶子节点\n", x);
//			return;
//		}
//	}
//	printf("%c节点不存在\n", x);
//}
////刷新缓冲区
//void MyFflush()
//{
//	int ch = 0;
//	while (ch = getchar() != '\n'&&ch != EOF);
//}
//void text()
//{
//	CTree node;
//	int size = 0;
//	printf("请输入节点总数\n");
//	scanf("%d", &size);
//	Init(&node, size);
//	while (1)
//	{
//		char ch;
//		printf("\n输入要查找子节点\n");
//		MyFflush();
//		scanf("%c", &ch);
//		Find(node, ch);
//	}
//}
//
//int main()
//{
//	text();
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//typedef int DataType;
//typedef struct Node
//{
//	struct Node* leftchild;
//	struct Node* rightchid;
//	DataType data;
//}Node;
//Node* BuyNode(DataType x)
//{
//	Node* newnode = malloc(sizeof(Node));
//	if (newnode)
//	{
//		//创建成功
//		newnode->data = x;
//		newnode->leftchild = NULL;
//		newnode->rightchid = NULL;
//	}
//	return newnode;
//}
//Node* CreateTree()
//{
//	int data = 0;
//	printf("节点信息:");
//	scanf("%d", &data);
//	if (data == -1)
//		return NULL;
//	Node* newnode = BuyNode(data);
//	printf("请输入%d左子树", data);
//	newnode->leftchild = CreateTree();
//	printf("请输入%d的右子树", newnode->data);
//	newnode->rightchid = CreateTree();
//	return newnode;
//}
//
////先序遍历
//void Preorder(Node* tree)
//{
//	if (tree == NULL)
//		return;
//	printf("%d ", tree->data);
//	Preorder(tree->leftchild);
//	Preorder(tree->rightchid);
//}
////中序
//void Inorder(Node* tree)
//{
//	if (tree == NULL)
//		return;
//	Inorder(tree->leftchild);
//	printf("%d ", tree->data);
//	Inorder(tree->rightchid);
//}
//void Postorder(Node* tree)
//{
//	if (tree == NULL)
//		return;
//	Postorder(tree->leftchild);
//	Postorder(tree->rightchid);
//	printf("%d", tree->data);
//}
//void Text()
//{
//	Node* tree = CreateTree();
//	//Preorder(tree);
//	//Inorder(tree);
//	Postorder(tree);
//}
//int main()
//{
//	Text();
//	return 0;
//}


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef char TDataType;
typedef struct TNode
{
	struct TNode* leftchild;
	struct TNode* rightchild;
	TDataType data;
}TNode;
TNode* CreateTree(TNode* root)
{
	return 0;
}
void PreOrder(TNode* root)
{
	TNode* cur = root;
	if (cur == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", cur->data);
	PreOrder(cur->leftchild);
	PreOrder(cur->rightchild);
}
void InOrder(TNode* root)
{
	TNode* cur = root;
	if (cur == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(cur->leftchild);
	printf("%c ", cur->data);
	InOrder(cur->rightchild);
}
void PostOrder(TNode* root)
{
	TNode* cur = root;
	if (cur == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(cur->leftchild);
	PostOrder(cur->rightchild);
	printf("%c ", cur->data);
}
int TreeLeafSize(TNode* root)
{
	if (root == NULL)
		return 0;
	if (root->leftchild == NULL && root->rightchild == NULL)
		return 1;
	return TreeLeafSize(root->leftchild) + TreeLeafSize(root->rightchild);
}

int TreeSize(TNode* root)
{
	if (root == NULL)
		return 0;
	return TreeSize(root->leftchild) + TreeSize(root->rightchild) + 1;
}

//int size = 0;
//int TreeSize(TNode* root)
//{
//	if (root == NULL)
//		return 0;
//	size++;
//	TreeSize(root->leftchild);
//	TreeSize(root->rightchild);
//
//	return size;
//}

int TreeDepth(TNode* root)
{
	if (root == NULL)
		return 0;
	if (root->leftchild == NULL && root->rightchild == NULL)
		return 1;
	return 1 + (TreeDepth(root->leftchild) > TreeDepth(root->rightchild) ?
		TreeDepth(root->leftchild) : TreeDepth(root->rightchild));
}
void text()
{
	TNode* p1 = malloc(sizeof(TNode));
	p1->data = 'a';
	TNode* p2 = malloc(sizeof(TNode));
	p2->data = 'b';
	TNode* p3 = malloc(sizeof(TNode));
	p3->data = 'c';
	TNode* p4 = malloc(sizeof(TNode));
	p4->data = 'd';
	TNode* p5 = malloc(sizeof(TNode));
	p5->data = 'e';
	TNode* p6= malloc(sizeof(TNode));
	p6->data = 'f';
	p1->leftchild = p2;
	p1->rightchild = p3;
	p2->leftchild = p4;
	p2->rightchild = p5;
	p4->leftchild = p4->rightchild = NULL;
	p5->leftchild = NULL;
	p5->rightchild = p6;
	p6->leftchild = p6->rightchild = NULL;
	p3->leftchild = p3->rightchild = NULL;

	//PreOrder(p1);
	//InOrder(p1);
	PostOrder(p1);
	//printf("\nTreeSize:%d\n", TreeSize(p1));
	//printf("\nTreeSize:%d\n", TreeSize(p1));
	////size = 0;
	//printf("TreeSize:%d\n", TreeSize(p1));
	//printf("TreeLeafSize:%d\n", TreeLeafSize(p1));
	printf("TreeDepth:%d\n", TreeDepth(p1));
}
int main()
{
	text();
	return 0;
}