#include <stdio.h>
#include <stdlib.h>

// Define the ListNode structure
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to add two numbers represented by linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Initialize a dummy head node to simplify edge cases
    struct ListNode *dummyHead = malloc(sizeof(struct ListNode));
    struct ListNode *current = dummyHead;
    int carry = 0;
    
    // Traverse both linked lists
    while (l1 != NULL || l2 != NULL || carry != 0) {
        // Extract values from current nodes of l1 and l2, if they exist
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        
        // Calculate the sum and update the carry
        int sum = carry + x + y;
        carry = sum / 10;
        
        // Create a new node with the resulting digit and attach it to the result list
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        
        // Move to the next nodes in l1 and l2 if they exist
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    // Ensure the last node points to NULL
    current->next = NULL;
    
    // The result list starts from the node after the dummy head
    struct ListNode* result = dummyHead->next;
    
    // Free the dummy head node
    free(dummyHead);
    
    return result;
}

// Function to print the linked list (for testing purposes)
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

// Function to create a new ListNode (for testing purposes)
struct ListNode* newNode(int val) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    // Example to test the addTwoNumbers function
    struct ListNode* l1 = newNode(2);
    l1->next = newNode(4);
    l1->next->next = newNode(3);
    
    struct ListNode* l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    printList(result);  // Expected Output: 7 0 8
    
    return 0;
}
