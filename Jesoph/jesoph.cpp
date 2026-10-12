#include<iostream>
using namespace std;

typedef struct LNode
{
	int date;
	struct LNode* next;
}LNode, * LinkList;

int main()
{
	LinkList L, r;
	L = new LNode;
	L->date = 1;
	L->next = L;
	r = L;

	int n, num;
	cin >> n >> num;
	for (int i = 2; i <= n; ++i)
	{
		LNode* s = new LNode;
		s->date = i;
		s->next = r->next;
		r->next = s;
		r = s;
	}

	while (r->next != r)
	{
		for (int i = 0; i < num - 1; ++i)
		{
			r = r->next;
		}
		L = r->next;
		r->next = L->next;
		cout << L->date << " ";
		delete L;

	}
	cout << endl << "Jesoph is No." << r->date;
	return 0;
}