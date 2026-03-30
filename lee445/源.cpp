#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>


 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution 
{
private:
    //void change(ListNode* head)
	ListNode* change(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur)
        {
            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
		l1 = change(l1);
		l2 = change(l2);

		ListNode* head = nullptr;
		ListNode* tail = nullptr;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int sum = n1 + n2 + carry;
            if(!head)
				head = tail = new ListNode(sum % 10);
            else
            {
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
            }
            carry = sum / 10;
            if(l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;

        }        
        head = change(head);
        return head;
    }
};
int main()
{
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while (res)
    {
        std::cout << res->val << " ";
        res = res->next;
    }
}