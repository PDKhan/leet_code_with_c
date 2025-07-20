#define TABLE_SIZE 100003

int hash_idx(int val){
    return ((val % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int hash[TABLE_SIZE] = {0};

    for(int i = 0; i < numsSize; i++){
        int idx = hash_idx(nums[i]);

        if(hash[idx]){
            if(abs(hash[idx] - 1 - i) <= k)
                return true;
        }

        hash[idx] = i + 1;
    }

    return false;
}