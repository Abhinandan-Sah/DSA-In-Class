
import java.util.Scanner;

public class SegmentTree {
    Node root;
    static class Node{
        int data; 
        int startInterval, endInterval;
        Node left, right;
        Node(int startInterval, int endInterval){
            this.startInterval = startInterval;
            this.endInterval = endInterval;
        }
    }
    SegmentTree(int[] arr){
        this.root = buildTree(arr, 0, arr.length -1);
    }

    // T(N) = O(N)
    public Node buildTree(int[] arr, int startInterval, int endInterval){
        if(startInterval == endInterval){
            Node leaf = new Node(startInterval, endInterval);
            leaf.data = arr[startInterval];
            return leaf;
        }

        Node node = new Node(startInterval, endInterval);
        int mid = (startInterval + endInterval) /2;

        node.left = buildTree(arr, startInterval, mid);
        node.right = buildTree(arr, mid+1, endInterval);

        //backtracking from leaf node which data is calculated in top and going to the parent by adding the data of left and right child
        node.data = node.left.data + node.right.data;

        return node;
    }

    // hw : implement a range query function to get the sum of elements in a given range
    public int rangeQuery(int startInterval, int endInterval){
        return rangeQuery(root, startInterval, endInterval);
    }

    private int rangeQuery(Node root, int sIdx, int eIdx){
        if (root == null || root.startInterval > eIdx || root.endInterval < sIdx) {
            return 0; 
        }
        if (root.startInterval >= sIdx && root.endInterval <= eIdx) {
            return root.data; 
        }
        return rangeQuery(root.left, sIdx, eIdx) + rangeQuery(root.right, sIdx, eIdx);

    }

    public int update (int idx, int value){
        return update(root, idx, value);
    }

    public int update(Node node, int idx, int value){
        if(node.startInterval >= idx && idx <= node.endInterval ){
            if(node.startInterval==idx&& idx==node.endInterval){
                node.data = value;
            }else{
                int leftUpdate = update(node.left, idx, value);
                int rightUpdate = update(node.right, idx, value);
                node.data = leftUpdate + rightUpdate;
                return node.data;
            }
        }
        
        return node.data;  
    }

    public void display(){
        display(root);
    }
    public void display(Node root){
        if(root == null) return;
        String str = "";
        str = str + "Interval [" + root.startInterval + " - " + root.endInterval + "] | Data - " + root.data;
        System.out.println(str);
        str+="\n";
        if(root.left!= null){
            display(root.left);
        }
        if(root.right != null){
            display(root.right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[]   arr = new int[N];
        for(int i=0; i<N; i++){
            arr[i] = sc.nextInt(); // [2,1,3,-5,4,9,7,8]
        }
        SegmentTree segmentTree = new SegmentTree(arr);
        // segmentTree.display();
        // int sum = segmentTree.rangeQuery(2, 6);
        // System.out.println("Sum of elements in range [2, 6] is: " + sum);

        int updatedTree = segmentTree.update(3, -15);
        System.out.println(updatedTree);
    }
}
