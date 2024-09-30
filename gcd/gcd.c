#include<stdio.h>
int gcd(int a,int b){
    int r;
    while(b>0){
	r=a%b;
	a=b;
	b=r;
    }
    return a;
}
int main(){
    int a=250,b=150;
    int g = gcd(a,b);
    printf("GCD(%d,%d): %d\n",a,b,g);
    return 0;
}
