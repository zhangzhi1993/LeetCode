#include <iostream>
#include <stdio.h>
#include <vector>
#include "PrintUtils.cpp"
using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *header = new ListNode(0);
        ListNode *node = header;
        int nCarry = 0;
        while (l1 && l2)
        {
            int nValue = nCarry + l1->val + l2->val;
            node->val = nValue % 10;
            nCarry = nValue / 10;
            std::cout << node->val  << " " << nCarry << std::endl;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 || l2 || nCarry)
            {
                ListNode *newNode = new ListNode(nCarry);
                node->next = newNode;
                node = node->next;
            }
            
        }
        while (l1)
        {
            int nValue = nCarry + l1->val;
            node->val = nValue % 10;
            nCarry = nValue / 10;
            l1 = l1->next;
            if (l1 || nCarry)
            {
                ListNode *newNode = new ListNode(nCarry);
                node->next = newNode;
                node = node->next;
            }
        }
        while (l2)
        {
            int nValue = nCarry + l2->val;
            node->val = nValue % 10;
            nCarry = nValue / 10;
            l2 = l2->next;
            if (l2 || nCarry)
            {
                ListNode *newNode = new ListNode(nCarry);
                node->next = newNode;
                node = node->next;
            }
        }
        // return header;
        if (node->next && node->next->val == 0)
        {
            delete node->next;
            node->next = NULL;
        }
        return header;
    }
};

ListNode* vectToList(vector<int> vec)
{
    ListNode *l1h = NULL;
    ListNode *l1;
    if (vec.size() > 0)
    {
        l1h = new ListNode(vec[0]);
        l1 = l1h;
    }

    for (int i = 1; i < vec.size(); i++)
    {
        ListNode *node1 = new ListNode(0);
        l1->next = node1;
        l1 = node1;
        l1->val = vec[i];
    }
    return l1h;
}

int main(int argc, char const *argv[])
{
    vector<int> vec1 = {5, 4, 4, 9, 8};
    vector<int> vec2 = {5, 5, 5, 0, 0, 9};

    ListNode *l1h = vectToList(vec1);
    ListNode *l2h = vectToList(vec2);

    PrintUtils::printf(l1h);
    PrintUtils::printf(l2h);
    Solution sol;
    ListNode *res = sol.addTwoNumbers(l1h, l2h);
    PrintUtils::printf(res);
    getchar();
    return 0;
}
