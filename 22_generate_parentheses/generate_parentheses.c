#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For print out debug message
#define DEBUG 0

void dfs(char** result, int open, int close, char* buffer, int buffer_pointer, int* returnSize, int n)
{
#if DEBUG
    printf("Start dfs: open:%d, close:%d, buffer: %s, buf_ind: %d, returnSize: %d\n", open, close, buffer, buffer_pointer, *returnSize);
#endif
    // Completed parentheses, Base case and return
    if((open == n) && (close == n))
    {
        result[*returnSize] = (char*)calloc(2 * n + 1, sizeof(char));
        memcpy(result[*returnSize], buffer, 2 * n);
#if DEBUG
        printf("Function return result[%d]: %s\n", *returnSize,  result[*returnSize]);
#endif
        *returnSize = *returnSize + 1;
        return;
    }

    // Add open parentheses
    if(open < n)
    {
#if DEBUG
        printf("Add open parentheses: open: %d, close:%d, buffer: %s, buf_ind: %d, returnSize: %d\n", open, close, buffer, buffer_pointer, *returnSize);
#endif
        buffer[buffer_pointer] = '(';
        dfs(result, open + 1, close, buffer, buffer_pointer + 1, returnSize, n);
    }
    if(close < open)
    {
#if DEBUG
        printf("Add close parentheses: open: %d, close:%d, buffer: %s, buf_ind: %d, returnSize: %d\n", open, close, buffer, buffer_pointer, *returnSize);
#endif
        buffer[buffer_pointer] = ')';
        dfs(result, open, close + 1, buffer, buffer_pointer + 1, returnSize, n);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    char** result = (char**) malloc(100);
    char* buffer = (char*) calloc(100 , sizeof(char));
    dfs(result, 0, 0, buffer, 0, returnSize, n);
    free(buffer);
    return result;
}

void print_result(char** result, int returnSize, int n)
{
    printf("Result of n=%d [ ", n);
    for(int i = 0; i < returnSize; i++)
    {
        printf("%s ", result[i]);
    }
    printf("]\n");
}

/**
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/

int main()
{
    int returnSize = 0;
    char** result;
    int n = 3;
    result = generateParenthesis(n, &returnSize);
    print_result(result, returnSize, n);
    free(result);

    n = 2;
    char** result_1;
    returnSize = 0;
    result_1 = generateParenthesis(n, &returnSize);
    print_result(result_1, returnSize, n);
    free(result_1);
}