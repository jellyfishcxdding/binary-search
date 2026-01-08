#include <stdio.h>

long long A[100005]; 

int main() {
    int n;
    scanf("%d", &n);

    long long num;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num);
        if (i == 0) {
            A[i] = num;
        } else {
            A[i] = A[i-1] + num;
        }
    }
    
    int q;
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        long long m;
        scanf("%lld", &m);
        
        
        int left = 0, right = n - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] <= m) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        

        if (ans == -1) {
            printf("Case #%d: -1\n", i + 1);
        } else {
            printf("Case #%d: %d\n", i + 1, ans + 1);
        }
    }
    
    return 0;
}