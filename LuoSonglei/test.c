#include"utils.h"
void sort(int *nums, int numsSize)
{
    int m = 1;
    int tmp = 0;
    int v = 0;
    int closestSum = nums[0] + nums[1] + nums[2];
    for(;m < numsSize; m = 3*m + 1);
    for(; m > 0; m /= 3)
    for(int i = m; i < numsSize; i++)
    {
        int j = i;
        v = nums[i];
        while(j >= m && v < nums[j - m])
            {
                tmp = nums[j];
                nums[j] = nums[j-m];
                nums[j-m] = tmp; 
                j -= m;
            }
        nums[j] = v;
    }   
}
void sort1(int *nums, int numsSize)
{
    int h = 1;
    for(; h <= numsSize/9; h = 3 * h + 1);
    for(; h > 0; h /= 3)
    for(int i = h; i < numsSize; i++)
    {
        int tmp = nums[i];
        int j = i;
        while(j >= h && tmp < nums[j - h])//This condition is quite critical;
        {
            nums[j] = nums[j - h];
            j -= h;
        }
        nums[j] = tmp;
    }

}
void main()
{
    int numbers[SIZE];
    randomIntArray(numbers, SIZE, 0, MAX);
    printArray(numbers, SIZE);
    checkAscending(numbers, SIZE);
    printf("After sorting:\n***********************\n");
    sort(numbers, SIZE);
    printArray(numbers, SIZE);
    checkAscending(numbers, SIZE);

}
