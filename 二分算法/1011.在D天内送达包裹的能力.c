int shipWithinDays(int* weights, int weightsSize, int D){
    int i,max;
    int sum = 0;
    max = weights[0];
    for(i=0; i<weightsSize; i++){
        if(weights[i]>max)
            max = weights[i];
        sum += weights[i];
    }
    int mid, day, temp;
    while(max < sum){
        mid = (max+sum)/2;
        temp = 0;
        day = 1;
        for(i=0; i<weightsSize; i++){
            temp += weights[i];
            if(temp>mid){
                day++;
                temp = weights[i];
            }
        }
        if(day > D)
            max = mid+1;
        else
            sum = mid;
    }
    return max;
}
