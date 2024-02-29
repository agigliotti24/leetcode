void printList(int* nums, int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", nums[i]);

    printf("\n");
}

void mergeSort(int* left, int* right, int l, int r) {
    // if(left == NULL) return right;
    // if(right == NULL) return left;

    printf("left ");
    printList(left, l);
    printf("right ");
    printList(right, r);

    int* res = (int*)malloc(sizeof(int) * (l + r));

    int i = 0; // index for res
    int j = 0; // index for left
    int k = 0; // index for right

    while (j < l || k < r) {
        if (j < l && left[j] < right[k]) {
            res[i] = left[j];
            ++j;
        } else {
            res[i] = right[k];
            ++k;
        }
        ++i;
    }

    printList(res, l + r);
}

void split(int* nums, int size) {
    if (size == 1)
        return;

    int mid = size / 2;
    printf("size %d\n", size);
    printf("mid %d\n", mid);
    int* left = (int*)malloc(sizeof(int) * mid);
    int* right = (int*)malloc(sizeof(int) * (size - mid));

    for (int i = 0; i < mid; ++i)
        left[i] = nums[i];
    for (int i = 0; i < size - mid; ++i)
        right[i] = nums[i + mid];

    // printf("left ");
    // printList(left, mid);
    // printf("right ");
    // printList(right, size-mid);

    split(left, mid);
    split(right, size - mid);

    mergeSort(left, right, mid, size - mid);

    free(left);
    free(right);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // for (int i = 0; i < n; ++i)
    //     nums1[m + i] = nums2[i];

    // split(nums1, n + m);

    int i = 0; // index for res
    int j = 0; // index for left
    int k = 0; // index for right

    int* res = (int*)malloc(sizeof(int) * (n + m));

    printf("nums1Size %d\n", m);
    printf("nums2Size %d\n", n);

    while (j < m || k < n) {
        // printf("i %d\n", i);
        // printf("j %d\n", j);
        // printf("k %d\n", k);
        if (j < m && nums1[j] < nums2[k]) {
            printf("j %d\n", j);
            printf("k %d\n", k);
            res[i] = nums1[j];
            ++j;
        } else {
            printf("k %d\n", k);
            res[i] = nums2[k];
            ++k;
        }
        ++i;
    }

    printList(res, n + m);

    for (int i = 0; i < n + m; ++i)
        nums1[i] = res[i];

    free(res);
}
