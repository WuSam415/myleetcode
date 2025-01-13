#include <stdio.h>
#include <stdlib.h>

int comparor(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) 
{
    qsort(nums, numsSize, sizeof(nums[0]), comparor);
    const int column_size = 4;
    int** result = (int**)malloc(30 * sizeof(int*));
    int* return_column_size = (int*)malloc(30 * sizeof(int));
    int result_index = 0;
    for(int i = 0; i < numsSize - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i-1])
            continue;

        for(int j = i + 1; j < numsSize - 2; j++)
        {
            if (j > 1 && nums[j] == nums[j-1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;
            while(right > left)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target)
                {
                    int* quadruplets = (int*)malloc(column_size * sizeof(int));
                    quadruplets[0] = nums[i];
                    quadruplets[1] = nums[j];
                    quadruplets[2] = nums[left];
                    quadruplets[3] = nums[right];
                    result[result_index] = quadruplets;
                    return_column_size[result_index] = column_size;
                    result_index++;
                    left++;
                    right--;
                    
                    while(right > left && nums[right] == nums[right+1])
                        right--;

                    while(right > left && nums[left] == nums[left-1])
                        left++;
                }
                else if(target > sum)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    *returnColumnSizes = return_column_size;
    *returnSize = result_index;
    return result;
}

/*
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

int main()
{
    int nums[] = {1,0,-1,0,-2,2};
    int numsSize = 6;
    int target = 0;
    int returnSize = 0;
    int* returnColumnSizes;
    int** result;
    result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);
    printf("returnSize: %d\n", returnSize);
    for(int i = 0; i < returnSize; i++)
    {
        printf("returnColumnSizes[%d]: %d\n", i, returnColumnSizes[i]);
        printf("result(%d): [ ", i);
        for(int k = 0; k < returnColumnSizes[i]; k++)
        {
            printf("%d ", result[i][k]);
        }
        printf("]\n");
    }

    printf("=================================\n");
    int nums_1[] = {2,2,2,2,2};
    int numsSize_1 = 5;
    int target_1 = 8;
    int returnSize_1 = 0;
    int* returnColumnSizes_1;
    int** result_1;

    result_1 = fourSum(nums_1, numsSize_1, target_1, &returnSize_1, &returnColumnSizes_1);
    printf("returnSize_1: %d\n", returnSize_1);
    
    for(int a = 0; a < returnSize_1; a++)
    {
        printf("returnColumnSizes_1[%d]: %d\n", a, returnColumnSizes_1[a]);
        printf("result_1(%d): [ ", a);
    
    for(int b = 0; b < returnColumnSizes[a]; b++)
    {
        printf("%d ", result_1[a][b]);
    }
        printf("]\n");
    }

    free(returnColumnSizes);
    free(result);
    free(returnColumnSizes_1);
    free(result_1);
}