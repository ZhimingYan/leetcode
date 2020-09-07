bool containsPattern(int* arr, int arrSize, int m, int k){
    for (int l = 0; l < arrSize; l++) {
        for (int i = l , j = i + m;  l + m * k <= arrSize && j < l + m * k; i++ , j++) {
            if (arr[i] != arr[j]) {
                break;
            }
            if (j == m * k + l - 1) {
                return true;
            }
        }
    }
    return false;
}