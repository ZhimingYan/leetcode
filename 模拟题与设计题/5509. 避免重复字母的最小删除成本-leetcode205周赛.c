int GetMax(int a , int b) 
{
    return a > b? a : b;
}
int minCost(char * s, int* cost, int costSize){
    int res = 0;
    for(int i= 0; i < costSize;) {
        int sum = cost[i];
        int max = cost[i];
        while ( i + 1 < costSize && s[i] == s[i+1]) {
            sum += cost[i+1];
            max = GetMax(max, cost[i+1]); 
            i++;
        }
        i++;
        res = res + sum - max;
    }
    return res;
}