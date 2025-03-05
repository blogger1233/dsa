public class Stack{
    private int top;
    private int maxsize=100;
    private String[] arr;
    public Stack(){
	top = -1;
	arr = new String[maxsize];
    }
    private boolean isEmpty(){
	if(top == -1){
	    return true;
	}else{
	    return false;
	}
    }
    private boolean isFull(){
	if(top == maxsize){
	    return true;
	}else{
	    return false;
	}
    }
    public void push(String element){
	if(isFull()){
	    return;
	}
	top++;
	arr[top]=element;
    }
    public String pop(){
	if(isEmpty()){
	   return null;
	}
	 String element =arr[top];
	 top--; 
	 return element;
    }
}
