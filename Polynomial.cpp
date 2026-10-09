#include "Polynomial.h"

void CreatePolyn(Polynomial& L, int n)
{
	L = new PNode;
	L->next = NULL;
	PNode* r = L;
	for (int i = 0; i < n; ++i)
	{
		PNode* s = new PNode;
		cin >> s->date.coef >> s->date.expn;
		s->next = r->next;
		r->next = s;
		r = s;
	}
	//顺序插入,1->2->3->4
}

void Traverse(const Polynomial& L)
{
	PNode* p = L->next;
	while (p)
	{
		cout << "(" << p->date.coef << "," << p->date.expn << ")";
		p = p->next;
	}
	cout << endl;

}

void Reverse(Polynomial& L)
{
	PNode* p, * q;
	p = L->next;
	L->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		q->next = L->next;
		L->next = q;
	}
	//往前插,L   ->4->3->2->   1
}

void CopyPolyn(const Polynomial& src, Polynomial& dest)
{
	DestroyPolyn(dest);
	dest = new PNode;
	dest->next = nullptr;
	PNode* tail = dest;
	PNode* p = src->next;   // 只读源链表，不会破坏A
	while (p != nullptr)
	{
		PNode* newp = new PNode;
		newp->date = p->date;
		newp->next = nullptr;
		tail->next = newp;
		tail = newp;
		p = p->next;
	}
}
void DestroyPolyn(Polynomial& L)
{
	PNode* p = L, * q;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	L = nullptr;
}

void Add(Polynomial& La, Polynomial& Lb, Polynomial& Lc)
{
	DestroyPolyn(Lc);
	
	PNode* pa = La->next;
	PNode* pb = Lb->next;
	//遍历

	Lc = new PNode;
	Lc->next = NULL;
	PNode* pc = Lc;//尾节点

	while (pa && pb)
	{
		if (pa->date.expn > pb->date.expn)
		{
			PNode* newp = new PNode;
			newp->date = pa->date;
			newp->next = NULL;
			pc->next = newp;//插到pc后面
			pc = newp;
			pa = pa->next;
		}

		else if (pa->date.expn < pb->date.expn)
		{
			PNode* newp = new PNode;
			newp->date = pb->date;
			newp->next = NULL;
			pc->next = newp;
			pc = newp;
			pb = pb->next;
		}

		else
		{
			double sum = pa->date.coef + pb->date.coef;
			if (sum != 0)
			{
				PNode* newp = new PNode;
				newp->date.coef = sum;
				newp->date.expn = pa->date.expn;//pb的也一样
				newp->next = NULL;
				pc->next = newp;
				pc = newp;
			}
			pa = pa->next;
			pb = pb->next;
		}
	}

	while (pa)
	{
		PNode* newp = new PNode;
		newp->date = pa->date;
		newp->next = NULL;
		pc->next = newp;
		pc = newp;
		pa = pa->next;
	}

	while (pb)
	{
		PNode* newp = new PNode;
		newp->date = pb->date;
		newp->next = NULL;
		pc->next = newp;
		pc = newp;
		pb = pb->next;
	}
}

void Sub(Polynomial& La, Polynomial& Lb, Polynomial& Lc)
{
	DestroyPolyn(Lc);
	
	PNode* pa = La->next;
	PNode* pb = Lb->next;
	//遍历
	Lc = new PNode;
	Lc->next = NULL;
	PNode* pc = Lc;//尾节点
	while (pa && pb)
	{
		if (pa->date.expn > pb->date.expn)
		{
			PNode* newp = new PNode;
			newp->date = pa->date;
			newp->next = NULL;
			pc->next = newp;//插到pc后面
			pc = newp;
			pa = pa->next;
		}
		else if (pa->date.expn < pb->date.expn)
		{
			PNode* newp = new PNode;
			newp->date.coef = -pb->date.coef; 
			newp->date.expn = pb->date.expn;
			newp->next = NULL;
			pc->next = newp;
			pc = newp;
			pb = pb->next;
		}
		else
		{
			double diff = pa->date.coef - pb->date.coef;
			if (diff != 0)
			{
				PNode* newp = new PNode;
				newp->date.coef = diff;
				newp->date.expn = pa->date.expn;
				newp->next = NULL;
				pc->next = newp;
				pc = newp;
			}
			pa = pa->next;
			pb = pb->next;
		}
	}
	while (pa)
	{
		PNode* newp = new PNode;
		newp->date = pa->date;
		newp->next = NULL;
		pc->next = newp;
		pc = newp;
		pa = pa->next;
	}
	while (pb)
	{
		PNode* newp = new PNode;
		newp->date.coef = -pb->date.coef; 
		newp->date.expn = pb->date.expn;
		newp->next = NULL;
		pc->next = newp;
		pc = newp;
		pb = pb->next;
	}
}

double Evaluate(const Polynomial& L, double x)
{
	double result = 0.0;
	PNode* p = L->next;
	while (p)
	{
		result += p->date.coef * pow(x, p->date.expn);
		p = p->next;
	}
	return result;
}