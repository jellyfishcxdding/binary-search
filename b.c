#include <stdio.h>
#include <string.h>
// #include <stdlib.h> (kebanyakan mikir jir)

int binarySearch(int arr[],int left, int right, int target){
    int res = -1;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(arr[mid]== target){
            res =  mid;
            right = mid-1;
        }
        else if(arr[mid] < target){
            left = mid +1;
        }
        else{
            right = mid-1;
        }
    }
    return res;
}

int main () {
    int N,M;
    scanf("%d %d", &N, &M);
    int num[N];
    //inputing the number
    for(int i = 0; i<N;i++){
        scanf("%d", &num[i]);
    }

    // inputing the number that u want to find
    int findNum;

    for(int j = 0;j<M; j++){
         scanf("%d", &findNum);

         int posisi = binarySearch(num,0, N-1, findNum);
         if(posisi == -1){
            printf("-1\n");
         }
         else {
            printf("%d\n", posisi+1);
         }


    }




    return 0;

}
