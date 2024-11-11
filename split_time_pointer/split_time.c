#include<stdio.h>
void split_time(long total_sec,int *hr,int *min,int *sec){
    *hr=total_sec/3600;
    total_sec -=*hr*3600;
    *min = total_sec/60;
    total_sec-=*min*60;
    *sec = total_sec;
}
int main(){
	int hr,min,sec;
	long total_sec=41423;
	split_time(total_sec,&hr,&min,&sec);
	printf("%2d:%2d:%2d\n",hr,min,sec);
	return 0;
}
