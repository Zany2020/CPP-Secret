#pragma once
#include<iostream>
using namespace std;

typedef struct Term
{
	double coef;
	int expn;
}Term;

typedef struct PNode
{
	Term date;
	PNode* next;
}PNode, * Polynomial;

void CreatePolyn(Polynomial& L, int n);

void Traverse(const Polynomial& L);

void Reverse(Polynomial& L);

void Add(Polynomial& La, Polynomial& Lb, Polynomial& Lc);

void DestroyPolyn(Polynomial& L);

void CopyPolyn(const Polynomial& src, Polynomial& dest);

void Sub(Polynomial& La, Polynomial& Lb, Polynomial& Lc);

double Evaluate(const Polynomial& L, double x);