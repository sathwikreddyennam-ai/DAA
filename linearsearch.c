#include<stdio.h>
int main(){
    int arr[]={10,20,30,40,50};                            
    int n=30;
                                                                            
    int i=0;
    for(i=0;i<5;i++){
        if (arr[i]==n){
        printf("element found at position %d" ,i+1);
        return 0;
    }
    }
    
    printf("not found");
    return 0;
    
}
