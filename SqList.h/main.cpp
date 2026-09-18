#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"

int main()
{
	SqList L;
	ElemType e;
	InitList(L);

	for (int i = 1; i <= 5; ++i)
	{
		ListInsert(L, 1, i);
	}

	ListTraverse(L);

	GetElem(L, 4, e);
	cout << e << endl;

	ListInsert(L, 6, 6);
	ListTraverse(L);
	cout << endl;

	int pos;
	pos = LocateElem(L, 5);
	cout << pos << endl;
	pos = LocateElem(L, 6);
	cout << pos << endl;
	pos = LocateElem(L, 2);
	cout << pos << endl;

	for (int i = 7; i <= 11; ++i)
	{
		ListInsert(L, 2, i);
	}

	ListTraverse(L);

	ListDelete(L, 1, e);
	cout << e << endl;
	ListDelete(L, 1, e);
	cout << e << endl;

	ListTraverse(L);

	ListDelete(L, 9, e);
	cout << e << endl;
	cout << ListLength(L) << endl;
	
	ListTraverse(L);
	
	ClearList(L);
	cout << ListLength(L) << endl;

	Status res = ListInsert(L, 2, 10);
	if (res == OK)
		cout << "成功插入" << endl;
	else
		cout << "插入不成功" << endl;

	for (int i = 1; i <= 5; ++i)
	{
		ListInsert(L, ListLength(L) + 1, i);
	}

	ListTraverse(L);

	DestroyList(L);
	return 0;
}