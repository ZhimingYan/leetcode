int Min(int a, int b)
{
    return a < b? a : b;
}

int findLengthOfShortestSubarray(int* arr, int arrSize){
    int n = arrSize;
    int l = 0, r =  n - 1;
    while(l + 1 < arrSize && arr[l + 1] >= arr[l]) l ++;
    if (l == arrSize - 1) {
        return 0;
    }
    while(r >= 0 && arr[r - 1] <= arr[r]) r --;
    //双指针算法
    int res = Min(n - l - 1, r);
    for(int i = 0, j = r;i <= l && j < n; i ++){
        while(j < n && arr[j] < arr[i]) j ++;
        if(j < n)
            res = Min(res, j - i - 1);
    }

    return res;
}
