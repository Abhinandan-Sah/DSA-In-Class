import java.util.Scanner;
public class BitManipulation{

    public static boolean isOdd(int N){
        return ((N & 1) == 1);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        System.out.println(isOdd(N));
    }
}