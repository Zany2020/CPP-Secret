#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"
//基本操作的实现

Status InitList(SqList& L) 
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
	{
		exit(OVERFLOW);
	}
	L.length = 0;
	return OK;
}

Status DestroyList(SqList& L)
{
	if (L.elem)
		delete[] L.elem;
	L.elem = NULL;
	L.length = 0;
	return OK;
}

Status ListInsert(SqList& L, int i, ElemType e)
{
	if (L.length >= MAXSIZE)
		return ERROR;
	if (i < 1 || i > L.length + 1)
		return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

Status ListTraverse(const SqList& L)
{
	for (int i = 1; i <= L.length; ++i)
		cout << L.elem[i - 1] << " ";
	cout << endl;
	return OK;
}

Status GetElem(const SqList& L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}

Status ClearList(SqList& L)
{
	L.length = 0;
	return OK;
}

int LocateElem(const SqList& L, ElemType e)
{
	for(int i = 0; i < L.length ; ++i)
	{
		if (L.elem[i] == e)
			return i + 1;
	}
	return 0;
}

Status ListDelete(SqList& L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	
	for (int j = i; j <= L.length - i; ++j)
	{
		L.elem[i - 1 + j] = L.elem[i - 1 + j + 1];
	}
	L.length--;
	return OK;
}

int ListLength(const SqList& L)
{
	return L.length;
}

Status ListEmpty(const SqList& L)
{
	if (L.length == 0)
		return OK;
    else
 		return ERROR;
}