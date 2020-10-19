

int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    int sum = 0;
    for (int i = 0; i < k; i ++) {
        sum += arr[i];
    }
    printf("%d\n", sum);
    int res = 0;
    for (int i = 0 , j = i + k; j < arrSize; i++,j++) {
        if (sum / k >= threshold) {
            res ++;
        }
        sum -= arr[i];
        sum += arr[j];
        printf("%d\n", sum);
    }
    if (sum / k >= threshold) {
            res ++;
    }
    
    return res;
}