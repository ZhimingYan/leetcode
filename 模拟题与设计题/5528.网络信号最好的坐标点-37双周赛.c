

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

double sqrtD(int ax,int ay, int bx, int by)
{
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
int* bestCoordinate(int** towers, int towersSize, int* towersColSize, int radius, int* returnSize){
    
    int index = 0;
    int max = -1;
    for (int i = 0; i < towersSize; i++) {
        int sum = 0;
        for (int j = 0; j < towersSize; j++) {
            double dist = sqrtD(towers[i][0], towers[i][1], towers[j][0], towers[j][1]);
            if (dist > radius) {
                continue;
            }
            sum += (int)(towers[j][2]/(double)(1 + dist));
        }
        if (sum < max) {
            continue;
        }
        if (sum > max) {
            index = i;
            max = sum;
            
        } else if (sum == max) {
            if (towers[i][0] < towers[index][0]) {
                index = i;
            } else if (towers[i][0] == towers[index][0]) {
                if (towers[i][1] < towers[index][1]) {
                    index = i;
                }
            }
        }
    }
    
    int * res = (int *)malloc(2 * sizeof(int));
    res[0] = towers[index][0];
    res[1] = towers[index][1];
    *returnSize = 2;
    return res;
    
}