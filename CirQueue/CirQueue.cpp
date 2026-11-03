#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 10

typedef int Status;
typedef int QElemType;

typedef struct
{
	QElemType* base;//动态分配存储空间
	int front;
	int rear;
} SqQueue;

Status InitQueue(SqQueue* Q)
{
	Q->base = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
	if (!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue Q)
{
	return Q.front == Q.rear ? OK : ERROR;
}

Status QueueFull(SqQueue Q)
{
	return (Q.rear + 1) % MAXSIZE == Q.front ? OK : ERROR;
	//循环队列特有操作
	//循环队列无头尾节点，front和rear是下标，rear指向队尾元素的下一个位置，front指向队头元素
	
	//例如：MAXSIZE=5：下标 0,1,2,3,4
	//front = 0，rear = 4
	//`(4 + 1) % 5 = 0`，等于 front → 判定满，下标 4 不放元素
}

Status EnQueue(SqQueue* Q, QElemType e)
{
	if(QueueFull(*Q))
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	//rear 向后 + 1，取模 MAXSIZE 实现循环，到数组末尾自动回到下标 0
	return OK;
}

Status DeQueue(SqQueue* Q, QElemType* e)
{
	if (QueueEmpty(*Q))
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	//front 向后 + 1，取模 MAXSIZE 实现循环，到数组末尾自动回到下标 0
	return OK;
}


Status GetHead(SqQueue Q, QElemType* e)
//只读数据、不改队列,直接传Q
{
	if (QueueEmpty(Q))
		return ERROR;
	*e = Q.base[Q.front];
	return OK;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

void QueueTraverse(SqQueue Q) 
{
	if (QueueEmpty(Q)) 
	{
		printf("队列为空\n");
		return;
	}
	int i = Q.front;
	while (i != Q.rear)
	{
		printf("%d ", Q.base[i]);
		i = (i + 1) % MAXSIZE;  // 环形移动下标
	}
	printf("\n");
}

Status ClearQueue(SqQueue* Q) 
{
	Q->front = Q->rear = 0;
	return OK;
	///原有数据会被后续入队覆盖
}

Status DestroyQueue(SqQueue* Q) 
{
	free(Q->base);
	Q->base = NULL;
	Q->front = Q->rear = 0;
	return OK;
}



//--------------------------

void  printYangHui(SqQueue* Q, int n)
{
	EnQueue(Q, 1);

	for (int i = 1; i <= n; ++i)
	{
		int prev = 0;//prev：上一个出队的值，初始0
		for (int j = 0; j < (n - i) * 2; ++j)
			printf(" ");
			//打印前置空格（每行少两个）
		
		int len = QueueLength(*Q);
		for (int j = 0; j < len; ++j)
		{
			QElemType val;
			DeQueue(Q, &val);
			printf("%4d", val);
			EnQueue(Q, prev + val);
			prev = val;
		}

		//行末尾补1；
		EnQueue(Q, 1);
		printf("\n");
	}
}

int main()
{
	SqQueue Q;
	InitQueue(&Q);

	int n = 6;  // 可修改打印的行数

	printYangHui(&Q, n);

	DestroyQueue(&Q);
	return 0;
}