#include <stdio.h>


int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) {
        return 0;
    }
    int count = 0;
    int count2 = numsSize - 1;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            if (count2 > i) {
                nums[i] = nums[count2];
                count2--;
                count++;
                i--;
            }
            else {
                count++;
                break;
            }
        }
        if (count2 == i) {
            break;
        }
    }
    // if(i<count2){
    //     return numsSize - count+1;
    // }
    return numsSize - count;
}


#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int tmp1 = 0;
    int realsize = numsSize;
    for (int i = 0; i < numsSize - 1; i++) {
        if (i == realsize - 1) {
            return realsize;
        }
        if (nums[i] == nums[i + 1]) {
            for (int tmp2 = i + 1; tmp2 <= realsize - 1; tmp2++) {
                nums[tmp2 - 1] = nums[tmp2];
            }
            realsize--;
            i--;
        }
    }
    return realsize;
}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (n == 0 && m == 0) {
        return;
    }
    if (n == 0) {
        return;
    }
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
        return;
    }
    int tmp_arr[m+n];
    int p1 = 0, p2 = 0, p3 = 0;
    while (p1 < m && p2 < n) {
        if (nums1[p1] < nums2[p2]) {
            tmp_arr[p3] = nums1[p1];
            p1++;
            p3++;
        }else {
            tmp_arr[p3] = nums2[p2];
            p2++;
            p3++;
        }
    }
    if (p1 == m) {
        for (int i = p3; i < m + n; i++) {
            tmp_arr[i] = nums2[p2];
            p2++;
        }
    }
    else if(p2 == n) {
        for (int i = p3; i < m + n; i++) {
            tmp_arr[i] = nums1[p1];
            p1++;
        }
    }
    for (int i = 0; i < m + n; i++) {
        nums1[i] = tmp_arr[i];
    }
}