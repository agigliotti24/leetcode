/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* res = NULL;
    bool flagNine = true;

    for (int i = 0; i < digitsSize; ++i) {
        if (digits[i] != 9) {
            flagNine = false;
            break;
        }
    }

    if (flagNine) {
        *returnSize = digitsSize + 1;
        res = (int*)malloc((digitsSize + 1) * sizeof(int));
        assert(res != NULL);
    } else {
        *returnSize = digitsSize;
        res = (int*)malloc((digitsSize) * sizeof(int));
        assert(res != NULL);
    }

    memset(res, 0, *returnSize * sizeof(int));

    int end = *returnSize - 1;
    for (int i = *returnSize - 1; i >= 0; --i) {
        if (flagNine) {
            if (i > 0)
                res[i] = digits[i - 1];
        } else
            res[i] = digits[i];

        if (i == end) {
            if (res[i] == 9) {
                res[i] = 0;
                end = i - 1;
            } else
                res[i] = res[i] + 1;
        }
    }

    return res;
}