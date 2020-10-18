/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmpFunc(const void *ta, const void *tb)
{
    char *a = *(char **)ta;
    char *b = *(char **)tb;
    // printf("%s %s %d\n", a, b, ret);
    return strcmp(a, b) > 0;
}

void findProducts(char **ret, char ** products, int productsSize, char * searchWord, int *size)
{
    // printf("%s \n", searchWord);
    for (int i = 0; i < productsSize; ++i) {
        char *s = strstr(products[i], searchWord);
        if (s == products[i]) {
            ret[*size] = malloc(sizeof(char) * (strlen(products[i]) + 1));
            strcpy(ret[(*size)++], products[i]);
        }
        if (*size == 3) {
            break;
        }
    }
}

char *** suggestedProducts(char ** products, int productsSize, char * searchWord, int* returnSize, int** returnColumnSizes){
    qsort(products, productsSize, sizeof(char *), cmpFunc);
    
    int len = strlen(searchWord);
    *returnColumnSizes = malloc(sizeof(int) * len);
    char ***ret = malloc(sizeof(char **) * len);
    char tmp = 0;
    for (int i = 0; i < len; ++i) {
        ret[i] = malloc(sizeof(char *) * 3);
        if (i + 1 < len) {
            tmp = searchWord[i + 1];
            searchWord[i + 1] = 0;
        }

        (*returnColumnSizes)[i] = 0;
        findProducts(ret[i], products, productsSize, searchWord, &(*returnColumnSizes)[i]);

        if (i + 1 < len) {
            searchWord[i + 1] = tmp;
        }
    }
    *returnSize = len;
    return ret;
}
