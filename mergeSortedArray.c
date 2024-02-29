void printList(int* nums, int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", nums[i]);

    printf("\n");
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (n == 0)
        return;

    int i = 0;  // index for res
    int j = 0;  // index for left
    int k = 0;  // index for right

    int res[n + m];

    while (j < m || k < n) {
        if(j < m && k < n) {                // Look through both arrays
            if(nums1[j] < nums2[k])
                res[i++] = nums1[j++];
            else
                res[i++] = nums2[k++];
        } else if (j < m && k >= n) {       // Look through left array only
            res[i++] = nums1[j++];
        } else {                            // Look through right array only
            res[i++] = nums2[k++];
        }
    }

    printList(res, n + m);

    for (int i = 0; i < n + m; ++i)
        nums1[i] = res[i];
}
