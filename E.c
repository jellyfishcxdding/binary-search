#include <stdio.h>

long long mySum (long long n){
    return (n *(n+1)*(2*n+1))/6;
}


int main () {
    long long T;
    scanf("%lld", &T);
    for(int i =0 ; i<T; i++){
         long long x;
    scanf("%lld", &x);
        long long left = 0;
        long long right = 2000000;
        long long res = 0;
        while(left<=right){
            long long mid = left + (right-left)/2;
            if(mySum(mid)>= x){
                res = mid;
                right = mid-1;
            }
            else {
                left = mid +1;
            }
        }
        printf("Case #%d: %lld\n", i+1, res);
    }
   

    return 0;
}