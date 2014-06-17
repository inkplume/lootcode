#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
		/* Only when we have more than 2 nodes, we enable the sort. */
		if (head != NULL && head->next != NULL) {
			/* If there is only one node, calling findMidstNode()
			   will lead to a runtime error in the following procedure. 
			   How can you partition only one node into two partes?
			   Absolutely you can't! */
			ListNode* midst = findMidstNode(head);
			/* Partition the whole link list into two partes completely,
			   each of them is end with a NULL point, so that these two
			   link list are totally independent and dont have relationship
			   any more. */
			ListNode* left = head;
			ListNode* right = midst->next;
			midst->next = NULL;
			/* call sortList() recursively, dont forget assign
			   the return value to left or right. */
			if (left->next != NULL) left = sortList(left);
			if (right->next != NULL) right = sortList(right);
			/* merge two individual link list, each of them has sorted.
			   And dont forget assgin the return value to head. */
			head = merge(left, right);
		}
		/* If there are more than two nodes, we return the sorted link list's head.
		   If there are only one node , in this situation, just return head is right.
		   If the link list is empty, in this situation, head == NULL, return head is
		   right too. No matter what the input link list is, we can ensure the robust.*/
        return head;
    }
    
private:
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL) return right;
        else if (right == NULL) return left;

        ListNode* mergeHead = NULL;

        if (left->val < right->val) {
            mergeHead = left;
            mergeHead->next = merge(left->next, right);
        }
        else {
            mergeHead = right;
            mergeHead->next = merge(left, right->next);
        }

        return mergeHead;
    }
        
    ListNode* findMidstNode(ListNode* head) {
        ListNode* twoStep = head;
        ListNode* oneStep = head;
        while(twoStep->next != NULL) {
            twoStep = twoStep->next;
            if (twoStep->next != NULL) twoStep = twoStep->next;
            else break;
            oneStep = oneStep->next;
        }
        return oneStep;
    }
};

void printList(ListNode* head) {
	ListNode* index = head;
	while (index != NULL) {
		cout << index->val << " ";
		index = index->next;
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	int val[10] = {10, 1, 7, 2, 5, 9, 4, 6, 8, 3};
	ListNode* test = new ListNode(val[0]);
	ListNode* index = test;
	for (int i = 1; i < 10; ++i) {
		index->next = new ListNode(val[i]);
		index = index->next;
	}

	printList(test);

	ListNode* test2 = new ListNode(1);

	Solution testSort;
	test = testSort.sortList(test);
	test2 = testSort.sortList(test2);

	printList(test);
	printList(test2);
}

