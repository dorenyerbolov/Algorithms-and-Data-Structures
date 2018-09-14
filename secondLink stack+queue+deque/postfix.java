import java.util.Scanner;
import java.util.Stack;


public class sequence {
    public static void main(String args[]){

        Scanner scan = new Scanner(System.in);
        Scanner sc = new Scanner(scan.nextLine());

        Stack<Integer> myStack = new Stack<>();

        int sum;

        while(sc.hasNext()){
            if(sc.hasNextInt()){
                myStack.push(sc.nextInt());
            }
            else {
                int n = myStack.pop();
                int m = myStack.pop();
                char sign = sc.next().charAt(0);
                switch(sign) {
                    case '*':
                        myStack.push(sum = (m * n));
                        break;
                    case '+':
                        myStack.push(sum = (m + n));
                        break;
                    case '-':
                        myStack.push(sum = (m - n));
                        break;
                    default:
                        break;
                }
            }
        }

        System.out.print(myStack.peek());
    }
}
