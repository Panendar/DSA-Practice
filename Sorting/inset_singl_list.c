#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Insertion Sort for Linked List
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { // list is empty or has one node 
        return head;
    }

    struct ListNode dummy;
    dummy.next = NULL; // initialize the dummy node before the head node
    struct ListNode* current = head;

    while (current != NULL) {
        struct ListNode* next = current->next; // initialize the current->next to next
        
        // Find the correct position to insert current node
        struct ListNode* prev = &dummy;
        while (prev->next != NULL && prev->next->val < current->val) { // pre->next->val is value of unsorted array and current->val is the value of the sorted array
            prev = prev->next;
        }
        
        
        current->next = prev->next; // link current node to the next node in the sorted part
        prev->next = current; // swap the prev->next to the current node
        current = next;  //  current moves to the next node in the unsorted part
    }

    return dummy.next;
}

int main() {
    // Create linked list nodes like an array
    struct ListNode node5 = {5, NULL};
    struct ListNode node3 = {3, &node5};
    struct ListNode node1 = {1, &node3};
    struct ListNode node2 = {2, &node1};
    struct ListNode node4 = {4, &node2};
    
    struct ListNode* head = &node4;  // head points to first node: 4->2->1->3->5
    
    printf("Original unsorted list: 4->2->1->3->5\n");
    
    // Call insertion sort function
    head = insertionSortList(head);
    
    printf("Sorted list: ");
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("\n");
    
    return 0;
}