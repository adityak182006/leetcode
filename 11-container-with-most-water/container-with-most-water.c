int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_water = 0;

    while (left < right) {
        // Calculate the current area: height is limited by the shorter line
        int current_height = MIN(height[left], height[right]);
        int current_width = right - left;
        int current_water = current_height * current_width;

        max_water = MAX(max_water, current_water);

        // Move the pointer that points to the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;

    
}