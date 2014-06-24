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
    ListNode *insertionSortList(ListNode *head) {
		/* there is no need to sort if the whole list has no node or only one node. */
		if (head != NULL && head->next != NULL) {
			/* step 1: partition the whole list into two parts, one is sorted,
			   the ohther is unsorted. */
			ListNode* unsortedHead = head->next;
			ListNode* sortedHead = head;
			head->next = NULL;

			/* compare every node in the unsorted list to the sorted list. */
			ListNode* pUnsorted = unsortedHead;
			while (pUnsorted) {
				/* pCompare is used as a temp to compare to the sorted list. */
				ListNode* pCompare = pUnsorted;
				/* iterate first in order to prevent breaking to list. */
				pUnsorted = pUnsorted->next;
				
				/* compare pCompare to sorted list untill find out the node
				   which is larger than pCompare. */
				ListNode* pSorted = sortedHead;
				ListNode* prePSorted = NULL;
				while (pSorted && pSorted->val < pCompare->val) {
					prePSorted = pSorted;
					pSorted = pSorted->next;
				}

				/* ok, the node which is larger than pCompare has found,
				   if this node isnt the head, insert pCompare node in
				   middle of this node and its prenode. */
				if (prePSorted) {
					prePSorted->next = pCompare;
					pCompare->next = pSorted;
				}
				/* if this node is the head, insert pComapre in front of head,
				   so pCompare is the new head. */
				else {
				sortedHead = pCompare;
				pCompare->next = pSorted;
				}
			}
			/* after all the processings, we finally have sorted the list
			whose head is pointed by sortedHead poniter. */
			head = sortedHead;
		}
		/* no matter the list has no node, only one node or many nodes, return head
		   is always right because every probability has been concerned. */
		return head;
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
	test = testSort.insertionSortList(test);
	test2 = testSort.insertionSortList(test2);

	printList(test);
	printList(test2);
}