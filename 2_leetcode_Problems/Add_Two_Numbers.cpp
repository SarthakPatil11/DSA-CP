#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} *tail = nullptr;

struct ListNode *push(struct ListNode *head, int ele)
{
    ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = ele;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    return head;
}

void printLL(struct ListNode *head)
{
    struct ListNode *travler = head;
    while (travler != NULL)
    {
        cout << travler->val << "-->";
        travler = travler->next;
    }
    cout << "NULL." << endl;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr || l2 == nullptr)
        return nullptr;

    ListNode *head = nullptr, *temp = nullptr, *tail = nullptr, *next1 = nullptr, *next2 = nullptr;
    int val = 0, sum = 0, carry = 0, l1val = 0, l2val = 0;

    while (l1 != nullptr || l2 != nullptr)
    {
        // Sum calculator
        if (l1 == nullptr)
        {
            l1val = 0;
            next1 = nullptr;
        }
        else
        {
            l1val = l1->val;
            next1 = l1->next;
        }

        if (l2 == nullptr)
        {
            l2val = 0;
            next2 = nullptr;
        }
        else
        {
            l2val = l2->val;
            next2 = l2->next;
        }

        sum = l1val + l2val + carry;

        if (sum > 9)
        {
            val = sum % 10;
            carry = sum / 10;
        }
        else
        {
            val = sum;
            carry = 0;
        }

        // LL creation
        temp = new ListNode;
        temp->val = val;
        temp->next = nullptr;

        if (head == nullptr)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }

        l1 = next1;
        l2 = next2; // seg fault
    }
    if (carry != 0)
    {
        temp = new ListNode;
        temp->val = carry;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
    
    return head;
}

int main(void)
{
    ListNode *l1 = nullptr;
    l1 = push(l1, 9);
    l1 = push(l1, 9);
    l1 = push(l1, 9);
    l1 = push(l1, 9);
    l1 = push(l1, 9);
    l1 = push(l1, 9);
    l1 = push(l1, 9);
    printLL(l1);

    ListNode *l2 = nullptr;
    l2 = push(l2, 9);
    l2 = push(l2, 9);
    l2 = push(l2, 9);
    l2 = push(l2, 9);
    printLL(l2);

    ListNode *ans = nullptr;
    ans = addTwoNumbers(l1, l2);
    printLL(ans);
    return 0;
}

/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;                       //travling l1 and geting values.
            int y = l2 ? l2->val : 0;                       //travling l2 and geting values.
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);            //creating new LL.
            curr = curr->next;                              //further are just incrementetions.
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }
};
*/