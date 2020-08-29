int findLonelyPixel(char** picture, int pictureSize, int* pictureColSize){
    int res = 0;
    for (int i = 0; i < pictureSize; i++) {
        for (int j = 0; j < pictureColSize[0]; j++) {
            if(picture[i][j] == 'B') {
                int r = 0;
                for (int k = 0;  k < pictureSize; k++) {
                    if ((k != i) && picture[k][j] == 'B') {
                        r++;
                    }
                }
                if ( r > 0) {
                    break;
                }
                for (int l = 0;  l < pictureColSize[0]; l++) {
                    if ((l != j) && picture[i][l] == 'B') {
                        r++;
                    }
                }
                if (r > 0) {
                    continue;
                }
                    res++;   
              
            }
        }
    }
    return res;
}