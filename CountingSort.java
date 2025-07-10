import java.util.Arrays;

public class CountingSort {

    // T.C = N + k ie.(largest no. in arr)  //it it  out-place algo but it can be In-place
    public int[] countingSort(int[] arr){
        int N = arr.length;
        int max = Arrays.stream(arr).max().getAsInt();

        int[] count = new int[max + 1];
        int[] solution = new int[N];

        // Count frequency of each number
        for (int i = 0; i < N; i++) {
            count[arr[i]]++;
        }

        // Prefix sum
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = N - 1; i >= 0; i--) {
            int idx = --count[arr[i]];
            solution[idx] = arr[i];
        }

        return solution;
    }

    public static void main(String[] args) {
        int[] arr = {2, 5, 3, 0, 2, 3, 0, 3};
        CountingSort countingSort = new CountingSort();
        int[] solution = countingSort.countingSort(arr);

        for (int num : solution) {
            System.out.print(num + " ");
        }
    }
}
