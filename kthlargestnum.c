#include <stdio.h>

int findKthLargest(int nums[], int numsSize, int k)
{
    int i, j, max, temp;

    for (i = 0; i < k; i++)
    {
        max = i;

        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[j] > nums[max])
                max = j;
        }

        temp = nums[i];
        nums[i] = nums[max];
        nums[max] = temp;
    }

    return nums[k - 1];
}

int main()
{
    int nums[] = {3, 2, 1, 5, 6, 4};
    int numsSize = 6;
    int k = 2;

    printf("Kth largest element = %d\n",
           findKthLargest(nums, numsSize, k));

    return 0;
}