#pragma once
//数据结构定义
#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

//基础操作的声明
typedef struct
{
	ElemType* elem;
	int length;
}SqList;

Status InitList(SqList& L);  //初始化InitList(&L)

Status DestroyList(SqList& L);  //销毁

Status ClearList(SqList& L);  //清空  

Status ListTraverse(const SqList& L);  //遍历

Status GetElem(const SqList& L, int i, ElemType& e);  //获取元素

int LocateElem(const SqList& L, ElemType e);  //查找 

Status ListInsert(SqList& L, int i, ElemType e);  //插入

Status ListDelete(SqList& L, int i, ElemType& e);  //删除

int ListLength(const SqList& L);  //长度

Status ListEmpty(const SqList& L);  //判空 



