#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     struct ListNode *next;
};


typedef struct ListNode ListNode;

ListNode* createListNode(int val)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;

    return node;
}

void printListNode(ListNode* head)
{
    printf("[ ");
    while(head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("]\n");
}

struct ListNode* swapPairs(struct ListNode* head)
{
    ListNode* swapListNode = createListNode(0);
    ListNode* headSwapListNode = swapListNode;

    while(head)
    {
        if(head->next)
        {
            swapListNode->next = createListNode(head->next->val);
            swapListNode->next->next = createListNode(head->val);
            head = head->next->next;
            swapListNode = swapListNode->next->next;
        }
        else
        {
            swapListNode->next = createListNode(head->val);
            head = head->next;
            swapListNode = swapListNode->next;
        }
    }

    return headSwapListNode->next;
}

/*
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Input: head = []
Output: []

Input: head = [1]
Output: [1]

Input: head = [1,2,3]
Output: [2,1,3]
*/

int main()
{
    ListNode* headNode = createListNode(1);
    headNode->next = createListNode(2);
    headNode->next->next = createListNode(3);
    headNode->next->next->next = createListNode(4);
    printf("Input ListNode: ");
    printListNode(headNode);
    ListNode* swappedList = swapPairs(headNode);
    printf("Swapped ListNode: ");
    printListNode(swappedList);
    free(headNode);
    free(swappedList);

    ListNode* nullListNode = NULL;
    printf("Input ListNode: ");
    printListNode(nullListNode);
    ListNode* swappedNullList = swapPairs(nullListNode);
    printf("Swapped Null ListNode: ");
    printListNode(swappedNullList);
    free(nullListNode);
    free(swappedNullList);

    ListNode* oneListNode = createListNode(1);
    printf("Input ListNode: ");
    printListNode(oneListNode);
    ListNode* swappedOneListNode =  swapPairs(oneListNode);
    printf("Swapped One ListNode: ");
    printListNode(swappedOneListNode);
    free(oneListNode);
    free(swappedOneListNode);

    ListNode* oddListNode = createListNode(1);
    oddListNode->next = createListNode(2);
    oddListNode->next->next = createListNode(3);
    printf("Input ListNode: ");
    printListNode(oddListNode);
    ListNode* swappedoddList = swapPairs(oddListNode);
    printf("Swapped odd ListNode: ");
    printListNode(swappedoddList);
    free(oddListNode);
    free(swappedoddList);
}