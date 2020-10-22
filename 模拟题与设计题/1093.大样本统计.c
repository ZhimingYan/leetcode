
double* sampleStats(int* count, int countSize, int* returnSize){
    double* ans = (double*)malloc(sizeof(double) * 5);
    *returnSize = 5;
    for(int i = 0; i < countSize; ++i) {
        if (count[i] != 0) {
            ans[0] = i;
            break;
        }
    }
    for(int i = countSize - 1; i >= 0; --i) {
        if (count[i] != 0) {
            ans[1] = i;
            break;
        }
    }
    long long int sum = 0;
    int num = 0;
    for (int i = 0; i < countSize; ++i) {
        if (count[i] != 0) {
            sum += count[i] * i;
            num += count[i];
        }
    }
    ans[2] = (double)sum / num; 
    if (num & 1) {
        int temp = 0;
        for (int i = 0; i < countSize; ++i) {
            if (count[i] == 0) {
                continue;
            }
            temp += count[i];
            if (temp >= num / 2) {
                ans[3] = i;
                break;
            }
        }
    } else {
        int temp = 0;
        int first = -1;
        int second = -1;
        for (int i = 0; i < countSize; ++i) {
            if (count[i] == 0) {
                continue;
            }
            temp += count[i];
            if (temp >= num / 2 && first == -1) {
                first = i;
            }
            if (temp >= num / 2 + 1) {
                second = i;
                break;
            }
        }
        ans[3] = (double)(first + second) / 2;
    }
    int most = 0;
    for (int i = 0; i < countSize; ++i) {
        if (count[i] == 0) {
            continue;
        }
        if (count[i] > most) {
            most = count[i];
            ans[4] = i;
        }
    }
    return ans;

}
