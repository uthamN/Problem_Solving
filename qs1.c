#include <stdio.h>

int* reverse(int*a, int n){
    for(int i =0;i<n/2;i++){
        int t = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = t;
    }
    return a;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i =0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int *b = reverse(a, n);
    for(int i =0;i<n;i++){
        printf("%d ",b[i]);
    }
}


//given a string, reverse the words in the string;