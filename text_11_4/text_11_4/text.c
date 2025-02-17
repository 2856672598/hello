#include"heap.h"

void text()
{
	Heap h;
	HeapInit(&h);
	int arr[] = { 3,7,1,56,345,7687,434,2,10 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		HeapPush(&h, arr[i]);
		AdjustUp(h._a, h.size - 1);
	}
	Print(&h);
	while (h.size != 0)
	{
		HeapPop(&h);
		Print(&h);
	}
}

void text1()
{
	Heap h;
	HeapInit(&h);
	int arr[] = { 3,7,1,56,345,7687,434,2,10 };
	//入堆
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		HeapPush(&h, arr[i]);
		AdjustUp(h._a, h.size - 1);
	}

	while (!HeapEmpty(&h))
	{
		printf("%d ", h._a[0]);
		HeapPop(&h);
	}
	HeapDestroy(&h);
}

void text2()
{
	int arr[] = { 1,3,5,7,2,4,6,8 };
	int k = 4;
	textTopK(arr, sizeof(arr) / sizeof(arr[0]), k);
}

void text3()
{
	int arr[] = { 1,3,5,7,2,4,6,8 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
}

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
BTNode* BuyNode(BTDataType val)
{
	BTNode* newnode = malloc(sizeof(BTNode));
	newnode->_data = val;
	newnode->_left = newnode->_right = NULL;
	return newnode;
}

BTNode* CreatBinaryTree()
{
	BTNode* nodeA = BuyNode('A');
	BTNode* nodeB = BuyNode('B');
	BTNode* nodeC = BuyNode('C');
	BTNode* nodeD = BuyNode('D');
	BTNode* nodeE = BuyNode('E');
	BTNode* nodeF = BuyNode('F');
	nodeA->_left = nodeB;
	nodeA->_right = nodeC;
	nodeB->_left = nodeD;
	nodeC->_left = nodeE;
	nodeC->_right = nodeF;
	return nodeA;
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	PreOrder(root->_left);
	PreOrder(root->_right);
}

void PostOrder(BTNode* root){	if (root == NULL)	{		printf("NULL ");		return;	}	PostOrder(root->_left);	PostOrder(root->_right);	printf("%c ", root->_data);}int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left)
		return left;
	BTNode* right = BinaryTreeFind(root->_right, x);
	if (right)
		return right;
	return NULL;
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}



bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			while (!QueueEmpty(&q))
			{
				BTNode* cur = QueueFront(&q);
				QueuePop(&q);
				if (cur != NULL)
				{
					QueueDestroy(&q);
					return false;
				}
			}
		}
		// 孩子带进队列
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	QueueDestroy(&q);
	return true;
}

void text4()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);

	printf("节点个数：%d\n", BinaryTreeSize(root));
	printf("叶子节点个数：%d\n", BinaryTreeLeafSize(root));

	BTNode*ret = BinaryTreeFind(root, 'A');
	if (ret == NULL)
		printf("没找到\n");
	else
		printf("%c", ret->_data);
}

int main()
{
	//text();
	//text1();

	//text2();
	//text3();

	text4();
	return 0;
}
