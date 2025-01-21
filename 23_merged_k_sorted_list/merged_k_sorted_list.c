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

void printlist(ListNode* headnode)
{
    printf("[ ");
    while(headnode)
    {
        printf("%d ", headnode->val);
        headnode = headnode->next;
    }
    printf(" ]\n");
}

ListNode* mergeTwoList(ListNode* list1, ListNode* list2)
{
    ListNode* mergedList = (ListNode*) malloc(sizeof(ListNode));
    ListNode* mergedListHead;
    mergedList = createListNode(0);
    mergedListHead = mergedList;

    while(list1 || list2)
    {
        if(list1 == NULL)
        {
            mergedList->next = list2;
            return mergedListHead->next;
        }

        if(list2 == NULL)
        {
            mergedList->next = list1;
            return mergedListHead->next;
        }

        if(list1->val < list2->val)
        {
            mergedList->next=createListNode(list1->val);
            mergedList = mergedList->next;
            list1 = list1->next;
        }
        else
        {
            mergedList->next=createListNode(list2->val);
            mergedList = mergedList->next;
            list2 = list2->next;
        }
    }

    return mergedListHead->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    ListNode* mergedKList = (ListNode*) malloc(sizeof(ListNode));
    mergedKList = NULL;

    for(int i = 0; i < listsSize; i++)
    {
        mergedKList = mergeTwoList(mergedKList, lists[i]);
    }

    return mergedKList;
}

/*
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/
int main()
{
    ListNode** linklist_list = (ListNode**)malloc( 3 * sizeof(ListNode*));
    ListNode* list1_head = createListNode(1);
    list1_head->next = createListNode(4);
    list1_head->next->next = createListNode(5);

    ListNode* list2_head = createListNode(1);
    list2_head->next = createListNode(3);
    list2_head->next->next = createListNode(4);

    ListNode* list3_head = createListNode(2);
    list3_head->next = createListNode(6);

    linklist_list[0] = list1_head;
    linklist_list[1] = list2_head;
    linklist_list[2] = list3_head;

    int listsSize = 3;
    printf("Final result: ");
    printlist(mergeKLists(linklist_list, listsSize));
    free(linklist_list);
    free(list1_head);

    ListNode** null_linklist_list = NULL;
    int listsSize_null = 0;
    printf("Final result of NULL list: ");
    printlist(mergeKLists(null_linklist_list, listsSize_null));

    ListNode** linklist_list_1 = (ListNode**)malloc(sizeof(ListNode*));
    int listsSize_1 = 1;
    linklist_list_1[0] = NULL;
    printf("Final result of list with null node: ");
    printlist(mergeKLists(linklist_list_1, listsSize_1));
    free(linklist_list_1);
}