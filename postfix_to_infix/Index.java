import java.util.Scanner;
public class Index{
    
    public static boolean isOperand(String c){
	if(c.equals("+")||c.equals("-")||c.equals("*")||c.equals("^")||c.equals("/")){
	    return true;
	}else{
	    return false;
	}
    }

    public static void postfix_to_infix(Stack s,String postfix){
	for(int i =0;i<postfix.length();i++){
	    if(isOperand(String.valueOf(postfix.charAt(i)))){
		String a = s.pop();
		String b = s.pop();
		String exp = "("+a+postfix.charAt(i)+b+")";
		s.push(exp);
	    }else{
		s.push(String.valueOf(postfix.charAt(i)));
	    }
	}
	System.out.println("result infix: "+s.pop());
    }

    public static void main(String[] args){
	
	Stack s = new Stack();
	System.out.print("Enter postfix experssion: ");
	Scanner input = new Scanner(System.in);
	String expression = input.nextLine();
	postfix_to_infix(s,expression);
	
    }
}
