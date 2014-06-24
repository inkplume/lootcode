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
    ListNode *partition(ListNode *head, int x) {
		/* there is no need to partition if the whole list has no node
		   or only one node. */
		if (head && head->next) {
			/* step 1: partition the whole list into two complete individual
			   lists, one is beforeList whose nodes are all less than x, the
			   other is afterList whose nodes are greater than x. */
			ListNode* beforeHead = NULL;
			ListNode* beforeTail = NULL;
			ListNode* afterHead = NULL;
			ListNode* afterTail = NULL;
			/* traversal the whole list. */
			ListNode* pNode = head;
			while (pNode) {
				/* if current node is less than x. */
				if (pNode->val < x) {
					/* if beforeList is not empty, add current node after the
					   tail of the beforeList. */
					if (beforeHead) {
						beforeTail->next = pNode;
						beforeTail = beforeTail->next;
						
					}
					/* if beforeList is empty, add current node as a head of the
					   beforeList, is this situation, beforeHead == beforeTail. */
					else {
						beforeHead = pNode;
						beforeTail = beforeHead;
					}
					/* when current node has been added into beforeList, we need to
					   move forward the current node first, then set the next node
					   of beforeTail as NULL in order to flag that this is the end
					   of the beforeList. */
					pNode = pNode->next;
					beforeTail->next = NULL;
				}
				/* if current node is greater than x. */
				else {
					if (afterHead) {
						afterTail->next = pNode;
						afterTail = afterTail->next;
					}
					else {
						afterHead = pNode;
						afterTail = afterHead;
					}
					pNode = pNode->next;
					afterTail->next = NULL;
				}
			}
			/* WARNNING */
			/* if all the nodes in this linked list are greater than x,
			   the beforeHead will be empty. if this happened,
			   set head = afterHead directly. and if all the nodes are
			   less than x, the afterHead will be empty, set
			   beforeTail->next = afterHead directly is ok. and in the
			   rest situation, set beforeTail->next = afterHead. */
			if (beforeHead) {
				beforeTail->next = afterHead;
				head = beforeHead;
			}
			else head = afterHead;	
		}
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
	int val[6] = {1, 4, 3, 2, 5, 2};
	ListNode* test = new ListNode(val[0]);
	ListNode* index = test;
	for (int i = 1; i < 6; ++i) {
		index->next = new ListNode(val[i]);
		index = index->next;
	}

	printList(test);

	ListNode* test2 = new ListNode(1);

	Solution testSort;

	try	{
		test = testSort.partition(test, 3);
		printList(test);
		test = testSort.partition(test, 1);
		printList(test);
		test = testSort.partition(test, 10);
		printList(test);
		test = testSort.partition(NULL, 3);
		printList(test);
		test2 = testSort.partition(test2, 1);
		printList(test2);
		
	}
	catch (exception* e) {
		cout << e->what() << endl;
	}
	catch (...) {
		cout << "something happened" << endl;
	}
	return 0;
}