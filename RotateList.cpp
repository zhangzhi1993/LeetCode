#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"
using namespace std;



class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0;
        ListNode* pLast = head;
        while (pLast != NULL && pLast->next != NULL)
        {
            pLast = pLast->next;
            size++;
        }
        size++;
        PrintUtils::printf(size);
        k = k % size;
        if (k == 0)
            return head;
        ListNode* pNext = head;
        int n = size - k;
        while (--n)
        {
            pNext = pNext->next;
        }
        pLast->next = head;
        ListNode* pRes = pNext->next;
        pNext->next = NULL;
        return pRes;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    ListNode *next = head;
    for (int i = 1; i < 5; i++)
    {
        next->val = i+1;
        ListNode *node = new ListNode(0);
        next->next = node;
        next = node;
    }
    next->next = NULL;
    Solution sol;
    sol.rotateRight(head, 3);
    getchar();
    return 0;
}