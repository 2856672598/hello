#include"ListQueue.h"
Queue* Init()
{
	Queue* tmp = malloc(sizeof(Queue));
	if (tmp)
	{
		tmp->Data = 0;
		tmp->next = NULL;
		return tmp;
	}
	return NULL;
}
Queue* Add(DataType n)
{
	Queue* tmp = malloc(sizeof(Queue));
	if (tmp)
	{
		tmp->Data = n;
		tmp->next = NULL;
		return tmp;
	}
	return NULL;
}
void Push(Queue** head,DataType n)
{
	//Queue* flag = Add(n);
	//Queue* cur = head;
	//if (flag)
	//{
	//	while (cur->next)
	//	{
	//		cur = cur->next;
	//	}
	//	cur->next = flag;
	//}
	Queue* tmp = Add(n);
	Queue* cur = *head;
	if (tmp)
	{
		if (*head == NULL)
			*head = tmp;
		else
		{
			while (cur && cur->next)
			{
				cur = cur->next;
			}
			cur->next = tmp;
		}
	}
}
void Pop(Queue** head)
{
	assert(*head);
	if (*head == NULL)
		*head = NULL;
	else
	{
		Queue* tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
void Print(Queue* head)
{
	//assert(head);
	if (head == NULL)
	{
		printf("����Ϊ��\n");
	}
	Queue* cur = head;
	while (cur)
	{
		printf("%d ", cur->Data);
		cur = cur->next;
	}
}
void Destory(Queue** head)
{
	free(*head);
	*head = NULL;
}