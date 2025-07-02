public class setithBit {
    public static int setithBit(int N, int i){
        return (N | (1<<(i)));
    }
    public static void main(String[] args){
        System.out.println(setithBit(10, 2));
    }

}

