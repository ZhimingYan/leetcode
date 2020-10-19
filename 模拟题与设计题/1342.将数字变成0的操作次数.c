int numberOfSteps (int num){
    int res = 0;
    if (num == 0) {
        return res;
    }
    while (num != 1) {
        while(num % 2 == 0) {
            num /= 2;
            res++;
        }
        if (num == 1) {
            break;
        }
        num -= 1;
        res++;
    }
    return res + 1;
}