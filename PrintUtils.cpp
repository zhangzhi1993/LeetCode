#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class PrintUtils
{
private:
    /* data */
public:

    template<class T>
    static void printf(T t)
    {
        std::cout << t << std::endl;
    } 
    
    static void printf(ListNode* l)
    {
        while (l)
        {
            std::cout << l->val << " ";
            l = l->next;
        }
        std::cout << std::endl;
    }

    template<class T>
    static void printf(vector<T> vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            std::cout << vec.at(i) << " ";
        }
        std::cout << std::endl;
    }

    template<class T>
    static void printf(vector<vector<T>> vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            printf(vec.at(i));
        }
    }
};

