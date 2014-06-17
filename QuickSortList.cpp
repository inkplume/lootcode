/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 using namespace std;
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL) return NULL;
        quick(head, NULL);
        
        return head;
    }
    
private:
    void quick(ListNode* begin, ListNode* end) {
        if (begin == end) return;
        //ListNode* leftEnd = partition(head);
        ListNode* mid = partition(begin, end);
        //ListNode* rightbegin = leftEnd->next->next;
        if (mid != begin)
            quick(begin, mid);
        if (mid->next != end)
            quick(mid->next, end);
    }

    ListNode *partition(ListNode* begin, ListNode* end) {//[begin,end)
        if (begin == end) return NULL;
        int val = begin->val;
        ListNode* small = begin;
        ListNode* it = begin->next;
        //ListNode* preMid = NULL;
        while (it != end) {
            if (it->val < val) {
                //preMid = small;
                small = small->next;
                if (small != it) {int temp = small->val; small->val = it->val; it->val = temp;}
            }
            it = it->next;
        }
        int temp = small->val;
        small->val = begin->val;
        begin->val = temp;
        return small;
    }
};