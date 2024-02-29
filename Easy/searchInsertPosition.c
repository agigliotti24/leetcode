int binarySearch(int *array, int left, int right, int target) {
   
    if(left <= right) {
        int mid = ((right - left) / 2) + left;

        if(array[mid] == target)
            return mid;
        
        if(array[mid] < target)
            return binarySearch(array, mid+1, right, target);
        
        if(array[mid] > target)
            return binarySearch(array, left, mid-1, target);
    }

    return left;
    
}

int searchInsert(int* nums, int numsSize, int target) {

    int left = 0;
    int right = numsSize-1;

    return binarySearch(nums, left, right, target);
}