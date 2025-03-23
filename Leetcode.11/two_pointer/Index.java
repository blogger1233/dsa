public class Index{
    public static int min(int x,int y){
	return x<y?x:y;	
    }
    public static int max(int x,int y){
	return x>y?x:y;
    }
    public static void main(String[] args){
	int result=0;
	int[] arr ={1,8,6,2,5,4,8,3,7};
	int left = 0;
	int right = arr.length-1;
	while(left<right){
	    int area = (right-left)*min(arr[left],arr[right]);
	    result = max(area,result);
	    if(arr[left]<arr[right]){
		left++;
	    }
	    else{
		right--;
	    }
	}
	System.out.println("Max area: "+result);	
    }
}

