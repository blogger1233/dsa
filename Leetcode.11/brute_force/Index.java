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
	for(int i=1;i<arr.length;i++){
	    for(int j=i+0;j<arr.length;j++){
		int area = (j-i)*min(arr[i],arr[j]);
		result = max(area,result);	
	    }
	}	
	System.out.println("Max area: "+result);	
    }
}
