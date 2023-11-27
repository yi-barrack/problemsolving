#include <stdio.h>

int main(){
    
    char a[1001], b[1001];
    
    scanf("%s", a);
    scanf("%s", b);
    
    int i=0, j=0;
    
    while(a[i] != '\0'){
        i++;
    }
    
    while(b[j] != '\0'){
        j++;
    }
    
    if(i>=j){
        printf("go");
    }
    else{
        printf("no");
    }
    
    return 0;
}