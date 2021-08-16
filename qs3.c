#include <stdio.h>

int * value(int* a, int n){
    int count = 0;
    for(int i =0;i<n;i++){
        if(a[i] == 0){
            count +=1;
        }else{
            a[i] = 0;
        }
    }
    for(int i =count;i<n;i++){
        a[i] = 1;
    }
    return a;
}

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    int a[n];
    for(int i =0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int *b = value(a, n);
    for(int i =0;i<n;i++){
        printf("%d", b[i]);
    }
    return 0;
}
