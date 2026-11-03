#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Status;
typedef const char* QElemType;   // 存名字
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef struct QNode
{
	QElemType data;  
	struct QNode* Next;
}QNode, * QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;


Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->Next = NULL;
	return OK;
}

Status QueueEmpty(LinkQueue Q)
{
	return Q.front == Q.rear;
}

//尾插
Status EnQueue(LinkQueue* Q, QElemType e) 
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->Next = NULL;

	Q->rear->Next = p;
	Q->rear = p;
	return OK;
}

//删除头元素
Status DeQueue(LinkQueue* Q, QElemType* e)
{
	if (QueueEmpty(*Q))
		return ERROR;
	QueuePtr p = Q->front->Next;
	*e = p->data;
	Q->front->Next = p->Next;

	// 如果删的是最后一个结点，rear要指向头结点
	if (Q->rear == p)
		Q->rear = Q->front;

	free(p);
	return OK;
}

Status GetHead(LinkQueue Q, QElemType* e)
{
	if (QueueEmpty(Q)) return ERROR;
	*e = Q.front->Next->data;
	return OK;
}


Status ClearQueue(LinkQueue* Q)
{
	QueuePtr p, q;
	p = Q->front->Next;
	while (p != NULL)
	{
		q = p->Next;
		free(p);
		p = q;
	}
	Q->front->Next = NULL;
	Q->rear = Q->front;
	return OK;
}

Status DestroyQueue(LinkQueue* Q)
{
	ClearQueue(Q);
	free(Q->front);
	Q->front = Q->rear = NULL;
	return OK;
}

int QueueLength(LinkQueue Q)
{
	int cnt = 0;
	QueuePtr p = Q.front->Next;
	while (p != NULL)
	{
		cnt++;
		p = p->Next;
	}
	return cnt;
}


void QueueTraverse(LinkQueue Q)
{
	QueuePtr p = Q.front->Next;
	if (p == NULL)
	{
		printf("队列为空\n");
		return;
	}
	while (p != NULL)
	{
		printf("%s ", p->data);
		p = p->Next;
	}
	printf("\n");
}


void DancePartner(LinkQueue * boys, LinkQueue* girls)
{
	QElemType boy, girl;
	while (!QueueEmpty(*boys) && !QueueEmpty(*girls))
	{
		DeQueue(boys, &boy);
		DeQueue(girls, &girl);
		printf("%s和%s配对成功！\n", boy, girl);
	}

	if(!QueueEmpty(*boys))
	{
		printf("剩余男生：");
		QueueTraverse(*boys);
	}

	if(!QueueEmpty(*girls))
	{
		printf("剩余女生：");
		QueueTraverse(*girls);
	}

	else
		printf("所有人都配对成功！\n");

}

int main()
{
	LinkQueue manQueue, womanQueue;
	InitQueue(&manQueue);
	InitQueue(&womanQueue);

	// 男士入队
	EnQueue(&manQueue, "张三");
	EnQueue(&manQueue, "李四");
	EnQueue(&manQueue, "王五");
	// 女士入队
	EnQueue(&womanQueue, "小红");
	EnQueue(&womanQueue, "小丽");

	printf("男士队列："); QueueTraverse(manQueue);
	printf("女士队列："); QueueTraverse(womanQueue);
	printf("\n");

	DancePartner(&manQueue, &womanQueue);

	DestroyQueue(&manQueue);
	DestroyQueue(&womanQueue);
	return 0;
}