int firstBadVersion(int n) {
    int min = 0 ;
    int max = n ;
    int mid;

    while(max > min){
        mid = (max - min) / 2;
        mid = min + mid; 
        if(isBadVersion(mid))
            max = mid;
        else
            min = mid+1;
    }
    return max;
}