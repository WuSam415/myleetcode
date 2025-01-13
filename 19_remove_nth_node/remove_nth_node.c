#include <stdio.h>
#include <stdlib.h>

/**
    Definition for singly-linked list.
 */
 typedef struct ListNode
 {
    int val;
    struct ListNode* next; 
 } ListNode;

 ListNode* createListNode(int val)
 {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;

    return node;
 }

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    ListNode* node = head;
    int len = 0;
    int target_node = 0;

    //Find out the length of the linked list
    while(node)
    {
        len++;
        node = node-> next;
    }

    target_node = len - n;

    //Remove the first node
    if(target_node == 0)
    {
        ListNode* newlist = head->next;
        free(head);

        return newlist;
    }

    node = head;
    // Traverse to the node before target node 
    for(int i = 0; i < target_node - 1; i++)
    {
        node = node->next;
    }

    ListNode* node_to_remove = node->next;
    node->next = node->next->next;
    free(node_to_remove);

    return head;
}

void print_linkedlist(ListNode* head)
{
    ListNode* node = head;
    while(node)
    {
        printf("%d", node->val);
        node = node->next;
    }
    printf("\n");
}

/*
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/
int main()
{
    //Create Linked list
    ListNode* head = createListNode(1);
    head->next = createListNode(2);
    head->next->next = createListNode(3);
    head->next->next->next = createListNode(4);
    head->next->next->next->next = createListNode(5);
    printf("Original list: ");
    print_linkedlist(head);

    int nth = 2;
    ListNode* newlist = removeNthFromEnd(head, nth);
    printf("New list after remove %d(th) node: ", nth);
    print_linkedlist(newlist);
}
