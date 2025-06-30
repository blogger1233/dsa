public class Index{
    public static int[] distinctElements(int[] arr){

	int[] res = new int[arr.length];
	int count = 0;
	for(int i =0;i<arr.length;i++){
	    boolean distinct=true;
	    for(int j =0;j<i;j++){
		if(res[j]==arr[i]){
		    distinct = false;
		    break;
		}
	    }
	    
	    if(distinct){
		res[count]= arr[i];
		count++;
	    }

	}
	int[] distinctElements = new int[count];
	System.arraycopy(res,0,distinctElements,0,count);
	return distinctElements;
    }



    public static void main(String[] args){
	int[] arr = {1,2,3,3,3,4,5,6,7,8,9,9,9,9,9,10};
	int[] result = distinctElements(arr);
	System.out.print("Result: ");
	for(int i =0;i<result.length;i++){
	    System.out.print(result[i]+" ");
	}
    }
}
