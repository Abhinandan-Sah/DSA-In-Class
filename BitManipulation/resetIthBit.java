public class resetIthBit {
    public static int resetithBit(int N, int i){
        return (N ^(1<<(i-1)));
    }
    public static void main(String[] args){
        System.out.println(resetithBit(75, 4));
    }

}



