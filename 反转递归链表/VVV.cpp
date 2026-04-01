#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	ListNode* newHead = reverseList(head->next);//得到了最后的节点-》新head
	head->next->next = head;
	head->next = NULL;

	return newHead;//每次都返回同一个节点，没关系，因为head—>next是递进的，1，2，3，4，5。5的结束了返回上一个递归，head变为4，依次逐个进行。
	//ps：head一开始是1，第一次递归后head变为2，第二次递归后head变为3，第三次递归后head变为4，第四次递归后head变为5，此时返回5，依次逐个进行。
}


int main()
{
	ListNode* head = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	ListNode* reversedHead = reverseList(head);
	while (reversedHead != NULL)
	{
		std::cout << reversedHead->val << " ";
		reversedHead = reversedHead->next;
	}
	std::cout << std::endl;
	return 0;
}