/*
类似于最长上升子序列或者最大上升子序列的和
*/

typedef struct tagPerson{
    int age;
    int score;
}Person;
int cmp (const void *_a,const void *_b) {
    Person *a = (Person *)_a;
    Person *b = (Person *)_b;
    if (a->age == b->age) {
        return a->score - b->score;
    }
    return a->age - b->age;
}

int max(int a, int b) {
    return a > b? a : b;
}
int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize){
    Person *arr = (Person *) malloc(sizeof(Person) * scoresSize);
    for (int i = 0; i < scoresSize; i++) {
        arr[i].age = ages[i];
        arr[i].score = scores[i];
    }
    qsort(arr, scoresSize, sizeof(Person), cmp);
    
    // for (int i = 0 ; i < scoresSize; i++) {
    //     printf(" %d , %d \n", arr[i].age, arr[i].score);
    // }
    
    int *f = (int *)malloc(sizeof(int) * agesSize);
    memset(f, 0, sizeof(int)*agesSize);
    
    int res = 0;
    for (int i = 0; i < agesSize; i ++ ) {
        f[i] = arr[i].score;
        for (int j = 0; j < i; j ++ )
            if (arr[i].score >= arr[j].score)
                f[i] = max(f[i], f[j] + arr[i].score);
            res = max(res, f[i]);
    }
    
    return res;
}