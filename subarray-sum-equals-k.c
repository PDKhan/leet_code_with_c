#define MAX_SIZE    20000001
#define OFFSET      10000000

int subarraySum(int* nums, int numsSize, int k) {
    int map[MAX_SIZE] = {0};
    int sum = 0;
    int cnt = 0;

    map[OFFSET] = 1;

    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        cnt += map[sum - k + OFFSET];
        map[sum + OFFSET]++;
    }

    return cnt;
}
