#include<stdio.h>
void reverse_string(char str[], int f, int l){
    char t;
    while(f<l){
        t=str[f];
        str[f]=str[l];
        str[l]=t;
        f++;
        l--;
    }
}
int main(){
    char str[1000];
    scanf("%[^\n]s",str);
    int i=0, j =0;
    while(str[j]){
        for(j=i;str[j]&&str[j]!=' ';j++)
        reverse_string(str, i, j-1);
        i=j+1;
    }
        printf("%s ",str);
    return 0;
}