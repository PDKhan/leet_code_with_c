void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int idx1 = m-1;
    int idx2 = n-1;
    int pos = nums1Size - 1;

    while(idx2 >= 0)
    {
        if(idx1 >= 0 && nums1[idx1] > nums2[idx2])
            nums1[pos--] = nums1[idx1--];
        else
            nums1[pos--] = nums2[idx2--];
    }
}