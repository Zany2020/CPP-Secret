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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
		ListNode* head = new ListNode(0);
		ListNode* tail = head;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            //tail->val = l1->val + l2->val;
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			//tail->val += val1 + val2;
			int sum = val1 + val2 + carry;
			tail->val = sum % 10;
			carry = sum / 10;

			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
			
			if(l1 || l2 || carry)
			{
				tail->next = new ListNode(0);
				tail = tail->next;
			}
		}
            
   //         if(tail->val >= 10)
   //         {
   //             tail->val -= 10;
   //             tail->next = new ListNode(1);
   //         }          
			//l1 = l1->next;
			//l2 = l2->next;
			//tail = tail->next;
   //     }
   //     if (l1 && !l2)
   //     {
			//tail->next = l1 + 1;
   //         if(tail->next->val >= 10)
   //         {
   //             tail->next->val -= 10;
   //             tail->next->next = new ListNode(1);
			//}
   //     }
   //     if (!l1 && l2)
   //     {
			//tail->next = l2;
   //         if (tail->next->val >= 10)
   //         {
   //             tail->next->val -= 10;
   //             tail->next->next = new ListNode(1);
   //         }
   //     }

        return head;
    }
};
int main()
{

	return 0;
}