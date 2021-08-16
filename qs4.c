#include <stdio.h>

void toUpper(char* s){
    for(int i =0;i<1000;i++){
        if(s[i]>=97 && s[i]<=122){
            s[i] -= 32;
        }
    }
}

void toLower(char* s){
    for(int i =0;i<1000;i++){
        if(s[i]>=65 && s[i]<=90){
            s[i] += 32;
        }
    }    
}
 
int main () {
    char s[1000];
    char *string = s;
    scanf("%s", string);
        //printf("%s", string);

    toUpper(string);
    printf("%s", string);
    printf("\n");
        
    toLower(string);
    printf("%s", string);
        
    return;
}