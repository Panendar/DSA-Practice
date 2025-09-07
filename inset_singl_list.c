#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct  ListNode* insertionSortList(struct ListNode* head){   // head is the pointer to the first node of the linked list
    if (head == NULL || head -> next == NULL){ // empty list or single node in the list 
        return head;
    }

    struct ListNode dummy; // Create a dummy node for simplify the insertion process
    dummy.next = head; // Fake header node

    struct ListNode* current = head;

    while ( current){
        struct ListNode* next = current -> next; // Creating the Next pointer to store the next node value after current

        struct ListNode* prev = &dummy; //Starting from the fake / dummy node 
        while (prev -> next && prev  -> next -> val < current -> val){ //prev  -> next -> val this is in the unsorted part of the list & current -> val is the value of the current node
            prev = prev -> next; // Move to the next node in the sorted part of the list
            prev -> next = current;
        }
        current -> next = prev -> next; // connecting the current node to next node and previous to next node in the sorted part of the list
        prev -> next = current; // connecting the previous node to the current node
        current = next; // Move to the next node in the unsorted part of the list
    }

    return dummy.next;
    
    int main(){
        / Return the sorted list, which starts from the node after the dummy node
}