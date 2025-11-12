# include<iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        this->next = NULL;
    }
};


void reverseLL(ListNode* start, ListNode* end) {
  
    ListNode* prev = NULL;
    ListNode* curr = start;
    ListNode* stop = end->next; 

    while (curr != stop) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

ListNode* reverseLinkedListKGroup(ListNode* head, int k) {
    if (!head || k <= 1) return head;

    ListNode* start = head;
    ListNode* end = head;
    ListNode* prevStart = NULL;
    ListNode* newHead = NULL;
    int count = 1;

    while (end) {
        if (count % k == 0) {
            ListNode* nextGroup = end->next;

            reverseLL(start, end);

            // If first group, update head
            if (newHead == NULL)
                newHead = end;

			
            if (prevStart)
                prevStart->next = end;


            start->next = nextGroup;

            prevStart = start;
            start = nextGroup;
            end = nextGroup;
        } else {
            end = end->next;
        }
        count++;
    }

    if (newHead == NULL)
        newHead = head;

    return newHead;
}
