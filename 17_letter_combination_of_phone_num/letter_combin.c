#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char** result = malloc(20 * sizeof(char*));
    char* num_letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tux", "wxyz"};
    char* queue[100];
    int curr_pointer = 0;
    int queue_size = 0;
    queue[queue_size++] = strdup("");
    
    if (strlen(digits) == 0)
    {
        *returnSize = 0;    
        return result; 
    }

    while(curr_pointer < queue_size)
    {
        char* s = queue[curr_pointer++];
        // printf("s: %s, curr: %d; size: %d\n",s, curr_pointer-1, queue_size );

        // If complete word is generated, add to the result list
        if (strlen(s) == 2) {
            result[*returnSize] = s;
            (*returnSize)++;
        } 
        else if (strlen(s) == 1 && strlen(digits) == 1)
        {
            result[*returnSize] = s;
            (*returnSize)++;
        }
        else 
        {
            int index = strlen(s);
            const char* chars = num_letters[(digits[index]-'0')-2];
            // printf("Index: %d, %s\n", index, chars);
            for (int i = 0; chars[i] != '\0'; i++) {
                char* newStr = malloc(strlen(s) + 2);
                strcpy(newStr, s);
                newStr[strlen(s)] = chars[i];
                newStr[strlen(s) + 1] = '\0';
                queue[queue_size++] = newStr;
                // printf("queue[%d]: newStr: %s\n", queue_size-1, queue[queue_size-1]);
            }
            free(s);
        }
    }
   return result;

}

int main()
{
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//Input: digits = ""
//Output: []
//Input: digits = "2"
//Output: ["a","b","c"]
    char* digits = "23";
    int returnSize = 0;
    char** result = letterCombinations(digits, &returnSize);
    printf("[");
    for (int z = 0; z < returnSize; z++)
    {
        printf("%s ", result[z]);
    }
    printf(" ]\n");


    char* digits_1 = "2";
    int returnSize_1 = 0;
    char** result_1 = letterCombinations(digits_1, &returnSize_1);
    printf("[");
    for (int z = 0; z < returnSize_1; z++)
    {
        printf("%s ", result_1[z]);
    }
    printf(" ]\n");

    char* digits_2 = "";
    int returnSize_2 = 0;
    char** result_2 = letterCombinations(digits_2, &returnSize_2);
    printf("[");
    for (int z = 0; z < returnSize_2; z++)
    {
        printf("%s ", result_2[z]);
    }
    printf(" ]\n");


}