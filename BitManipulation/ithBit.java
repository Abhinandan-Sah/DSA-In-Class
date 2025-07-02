public class ithBit {
    public static int ithBit(int N, int i){
        // return (N & (1<<(i-1))) !=0 ? 1:0;
        return (N & (1<<(i))) !=0 ? 1:0;
    }
    public static void main(String[] args){
        // Scanner sc = new Scanner(System.in);
        // int N = sc.nextInt();
        System.out.println(ithBit(10, 2));
    }
}
