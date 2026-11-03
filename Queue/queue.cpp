#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef int QElemType;

//队列结点
typedef struct QNode
{
	QElemType date;
	struct QNode* Next; //->指向下一个结点，连接链表
}QNode, * QueuePtr; 

typedef struct
{
	QueuePtr front;//队头指针
	QueuePtr rear;//
} LinkQueue;

Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	//强制转换，把 `void*` → `QueuePtr`（也就是 `QNode*`）
	//malloc在堆上开辟一块大小等于 `QNode`（队列结点）的内存
	if (!Q->front)
	{
		exit(OVERFLOW);
	}
	Q->front->Next = NULL;
	return OK;
}

//判断是否为空
Status QueueEmpty(LinkQueue Q)
{
	return Q.front == Q.rear ? OK : ERROR;
}

//元素e加入队尾
Status EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
	{
		exit(OVERFLOW);
	}
	p->date = e;
	p->Next = NULL;
	Q->rear->Next = p;
	Q->rear = p;
	return OK;
	//front(头结点) → ... → 旧rear结点 → NULL
	//先进先出
}

//删除第一个数据结点
Status DeQueue(LinkQueue* Q, QElemType* e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}

	QueuePtr p = Q->front->Next;
	*e = p->date;
	//把要删除结点里的数据取出，通过指针 e 带回调用函数
	Q->front->Next = p->Next;
	//头节点无数据，直接指向下一个结点
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

Status GetHead(LinkQueue Q, QElemType* e)
{
	if (Q.front == Q.rear)
	{
		return ERROR;
	}

	*e = Q.front->Next->date;
	return OK;
}

int QueueLength(LinkQueue Q)
{
	int len = 0;
	QueuePtr p = Q.front->Next;
	while (p)
	{
		++len;
		p = p->Next;
	}
	return len;
}

void QueueTraverse(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		printf("队列为空\n");
		return;
	}
	QueuePtr p = Q.front->Next;
	while (p)
	{
		printf("%d ", p->date);
		p = p->Next;
	}
	printf("\n");
}


Status ClearQueue(LinkQueue* Q)
{
	QueuePtr p = Q->front->Next;
	while (p)
	{
		QueuePtr temp = p->Next;
		free(p);
		p = temp;
	}

	Q->front->Next = NULL;
	Q->rear = Q->front;  // 队尾回指头结点
	return OK;
}

Status DestroyQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->Next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

int main()
{
	LinkQueue Q;
	QElemType e;


	// 1. 初始化队列
	InitQueue(&Q);
	printf("队列初始化完成\n\n");

	// 2. 入队 1 2 3 4 5
	printf("依次入队：1 2 3 4 5\n");
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	EnQueue(&Q, 4);
	EnQueue(&Q, 5);
	printf("遍历队列：");
	QueueTraverse(Q);
	printf("\n");

	// 3. 第一次出队
	DeQueue(&Q, &e);
	printf("出队元素：%d\n", e);
	printf("出队后队列：");
	QueueTraverse(Q);
	printf("\n");

	// 4. 第二次出队
	DeQueue(&Q, &e);
	printf("出队元素：%d\n", e);
	printf("出队后队列：");
	QueueTraverse(Q);
	printf("\n");

	// 5. 入队 6 7
	printf("依次入队：6 7\n");
	EnQueue(&Q, 6);
	EnQueue(&Q, 7);
	printf("入队后队列：");
	QueueTraverse(Q);
	printf("\n");

	// 6. 取队头 + 求长度
	GetHead(Q, &e);
	printf("当前队头元素：%d\n", e);
	printf("队列元素个数：%d\n", QueueLength(Q));
	printf("\n");

	// 7. 清空队列
	printf("执行清空队列...\n");
	ClearQueue(&Q);
	printf("清空后遍历：");
	QueueTraverse(Q);
	printf("队列是否为空：%s\n", QueueEmpty(Q) ? "是" : "否");
	printf("\n");

	// 8. 销毁队列
	DestroyQueue(&Q);
	printf("队列已销毁\n");

	return 0;
}