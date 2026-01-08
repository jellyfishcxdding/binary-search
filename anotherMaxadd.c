#include <stdio.h>


int check(int panjang, long long jumlahKotak, long long limitJumlah, long long rentangKotak[] ){
    for(int i = panjang; i<=jumlahKotak; i++){
        long long maxGapBOx = rentangKotak[i] - rentangKotak[i-panjang];
        if(maxGapBOx<= limitJumlah){
            return 1;
        }
    }
    return 0;
}

int main (){
    long long N;
    scanf("%lld", &N);

    int angka[N];
    long long jumlahRentang[N+1];
    jumlahRentang[0] = 0;

    for(int i = 0; i<N; i++){
        scanf("%d", &angka[i]);
        jumlahRentang[i+1] = jumlahRentang[i] + angka[i];
    }


    int Q;
    scanf("%d", &Q);
    for(int i = 0; i<Q; i++){
        long long angkaQuery;
        scanf("%lld",&angkaQuery );


     int l = 1;
    int r = N;
    int jawaban = -1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(check(m,N,angkaQuery,jumlahRentang)){
            jawaban = m;
            l = m + 1;
        }
        else {
            r = m-1;
        }
    }

    printf("Case #%d: %d\n", i+1, jawaban);
}
  



    return 0;
}