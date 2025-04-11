int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;
    int* result = NULL;

    *returnSize = 0;

    while(left < right){
        int sum = numbers[left] + numbers[right];

        if(sum == target){
            result = (int*)malloc(2*sizeof(int));
            *returnSize = 2;
            result[0] = left + 1;
            result[1] = right + 1;
            break;
        }else if(sum < target)
            left++;
        else
            right--;
    }

    return result;
}
