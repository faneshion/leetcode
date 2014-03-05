//当数字里面存在0的时候，此方法不对
bool isPalindrome(int x) {
    if(x<0)
        return false;
    if(x<10)
        return true;
    while(x){
        if((int)x/((int)pow((double)10,(int)log10((double)x))) != (int)(x%10))
            return false;
        x = x % (int)(pow((double)10,(int)log10((double)x)));
        x = x/10;
    }
    return true;
}
//此法可行
bool isPalindrome(int x) {
        if(x<0)
            return false;
        int tmp = 0;
        int m = x;
        while(m){
            tmp = tmp*10+m%10;
            m = m/10;
        }
        return true?false:tmp == m;
    }