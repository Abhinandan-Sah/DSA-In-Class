import java.util.Scanner;

public class UniqueElement {
    public static int unique(int[] arr){
        int unique= 0;
        for(int elt: arr){
            unique = elt ^ unique;
            System.out.println(unique);

        }
        return unique;
    }
    public static void main(String[] args){
        // Scanner sc = new Scanner(System.in);
        // int N = sc.nextInt();
        int[] arr = {2, 4, 3, 5, 3, 4, 2};
        System.out.println("Final Answer"+unique(arr));
    }
}
