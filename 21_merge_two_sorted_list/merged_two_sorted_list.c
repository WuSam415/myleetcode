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
    ListNode* listnode = (ListNode*)malloc(sizeof(ListNode));
    listnode->val = val;
    listnode->next = NULL;

    return listnode;
}

void print_listnode(ListNode* listnode)
{
    ListNode* head = listnode;
    printf("[");
    while(head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("]\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    ListNode* mergedList = createListNode(0);
    ListNode* mergedListhead = mergedList;
    printf("List_1: ");
    print_listnode(list1);
    printf("List_2: ");
    print_listnode(list2);

    while(list1 || list2)
    {
        if (!list1)
        {
            mergedList->next = list2;
            return mergedListhead->next;
        }

        if (!list2)
        {
            mergedList->next = list1;
            return mergedListhead->next;
        }

        if (list1 && list2)
        {
            if(list1->val == list2->val)
            {
                mergedList->next = createListNode(list1->val);
                mergedList = mergedList->next;
                mergedList->next = createListNode(list2->val);
                mergedList = mergedList->next;
                list1 = list1->next;
                list2 = list2->next;
            }
            else if (list1->val < list2->val)
            {
                mergedList->next = createListNode(list1->val);
                mergedList = mergedList->next;
                list1 = list1->next;
            }
            else
            {
                mergedList->next = createListNode(list2->val);
                mergedList = mergedList->next;
                list2 = list2->next;
            }
        }

    }

    // Return the second Node.
    return mergedListhead->next;

}

/*
*
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Input: list1 = [], list2 = []
Output: []
Input: list1 = [], list2 = [0]
Output: [0]
*/
int main()
{
    // Create List1
    ListNode* list1 = createListNode(1);
    list1->next = createListNode(2);
    list1->next->next = createListNode(4);
    // Create List2
    ListNode* list2 = createListNode(1);
    list2->next = createListNode(3);
    list2->next->next = createListNode(4);

    ListNode* mergedlist = mergeTwoLists(list1, list2);
    printf("Merged List: ");
    print_listnode(mergedlist);

    ListNode* emptylist = mergeTwoLists(NULL,NULL);
    printf("Merged List: ");
    print_listnode(emptylist);

    ListNode* mergedList_1 = mergeTwoLists(NULL,createListNode(0));
    printf("Merged List_1: ");
    print_listnode(mergedList_1);

    free(list1);
    free(list2);
    free(emptylist);
    free(mergedlist);
    free(mergedList_1);
}