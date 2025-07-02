public class rightmostSetbit {
    // Method to find the position of the rightmost set bit (1-based index)
    public static int finder(int N) {
        return Integer.numberOfTrailingZeros(N & (-N)) +1;
        
        // O(N) time complexity
        // if (N == 0) return 0; // No set bits in 0
        // int position = 1;
        // while ((N & 1) == 0) {
        //     N >>= 1;
        //     position++;
        // }
        // return position;
    }

    public static void main(String[] args) {
        System.out.println(finder(72)); // Output: 4 (72 = 1001000 in binary)
    }
}
