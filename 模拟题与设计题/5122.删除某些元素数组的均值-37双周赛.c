int cmp(const void *_a, const void *_b)
{
    int *a = (int *)_a;
    int *b = (int *)_b;
    return *a - *b;
}


double trimMean(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), cmp);
    int tmp = arrSize*0.05;
    
    int index1 = 0 + tmp;
    int index2 = arrSize - tmp;
    
    int sum = 0;
    for (int i = index1; i < index2; i++) {
        sum += arr[i];
    }
    
    return sum / ((double) (arrSize - 2*tmp));
}