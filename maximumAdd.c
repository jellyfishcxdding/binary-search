#include <stdio.h>



int check(int panjang,long long jumlahKOtak, long long limitJumlah, long long rentangKotak[]){
    for(int i = panjang; i<= jumlahKOtak; i++){
        long long jumlahRentang = rentangKotak[i]  - rentangKotak[i-panjang];
        if(jumlahRentang <=limitJumlah){
            return 1; //found flag
        }
    }
    return 0; //invalid
}



int main () {
    int T;
    scanf("%d", &T);
    for(int i = 0; i<T; i++){
          long long N,M;
        scanf("%lld %lld", &N, &M);
        int angka[N];

        long long JumlahRentang[N+1];

        JumlahRentang[0] = 0; //inisialisasi kayak int A= 0;
        for(int j = 0; j<N; j++){
            scanf("%d", &angka[j]);
            JumlahRentang[j+1] = JumlahRentang[j] + angka[j];
        }

        int left = 1;
        int right = N;
        int ans = -1;


        while(left <= right){
            int mid = left + (right-left)/2;
            if(check(mid, N,M,JumlahRentang)){
                ans = mid;
                left= mid+1;
            }
            else {
                right = mid-1;
            }

        }
        


        printf("Case #%d: %d\n", i+1, ans);
    }
  




    return 0;
}