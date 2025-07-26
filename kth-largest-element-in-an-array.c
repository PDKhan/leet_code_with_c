int pop(int* heap, int* size){
    int idx = 0;
    int ret = heap[idx];

    heap[idx] = heap[--(*size)];

    while(1){
        int smallest = idx;
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;

        if(left < *size && heap[left] < heap[smallest])
            smallest = left;
        
        if(right < *size && heap[right] < heap[smallest])
            smallest = right;
        
        if(smallest != idx){
            int tmp = heap[idx];
            heap[idx] = heap[smallest];
            heap[smallest] = tmp;
            idx = smallest;
        }else
            break;
    }

    return ret;
}

void push(int* heap, int* size, int capacity, int val){
    if(*size == capacity){
        if(heap[0] < val)
            pop(heap, size);
        else
            return;
    }

    int idx = (*size)++;

    heap[idx] = val;

    while(idx > 0){
        int parent = (idx - 1) / 2;

        if(heap[parent] > heap[idx]){
            int tmp = heap[idx];
            heap[idx] = heap[parent];
            heap[parent] = tmp;
            idx = parent;
        }else
            break;
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int heap[k];
    int h_len = 0;
    int ret;

    for(int i = 0; i < numsSize; i++)
        push(heap, &h_len, k, nums[i]);

    return pop(heap, &h_len);
}
