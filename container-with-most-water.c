int maxArea(int* height, int heightSize) {
    int max = 0;
    int left = 0;
    int right = heightSize - 1;

    while(left < right){
        int len = right - left;
        int h;

        if(height[left] < height[right]){
            h = height[left];
            left++;
        }else{
            h = height[right];
            right--;
        }

        int area = len * h;

        if(max < area)
            max = area;
    }

    return max;
}
