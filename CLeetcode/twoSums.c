#include<stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    
    int *array = (int *)malloc(sizeof(int) * 2);
            
    for(int i = 0; i < numsSize; i++)
    {
         for(int j = i + 1; j < numsSize; j++)
         {
             if(*(nums + i) + *(nums + j) == target)
             {
                 *array = i;
                 *(array + 1) = j;
             }
         }
    }   
    return array;
}

int main()
{
    int nums[4];

    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &nums[i]);
    }

    int *arr;
    int returnSize = 0;

    arr = twoSum(nums, 4, 9, &returnSize);
    
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d", *(arr + i));
    }
    
    return 0;
}
