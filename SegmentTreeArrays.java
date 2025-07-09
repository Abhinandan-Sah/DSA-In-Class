class SegmentTreeArrays {
    int[] tree;
    int n;
    SegmentTreeArrays(int[] arr) {
        n = arr.length;
        tree = new int[4 * n];
        build(arr, 0, n - 1, 1);
    }
    void build(int[] arr, int l, int r, int node) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, l, mid, 2 * node);
        build(arr, mid + 1, r, 2 * node + 1);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int query(int ql, int qr) {
        return query(0, n - 1, 1, ql, qr);
    }
    int query(int l, int r, int node, int ql, int qr) {
        if (qr < l || r < ql) return 0; // No overlap
        if (ql <= l && r <= qr) return tree[node]; // Total overlap
        int mid = (l + r) / 2;
        int left = query(l, mid, 2 * node, ql, qr);
        int right = query(mid + 1, r, 2 * node + 1, ql, qr);
        return left + right;
    }
    void update(int index, int value) {
        update(0, n - 1, 1, index, value);
    }
    void update(int l, int r, int node, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(l, mid, 2 * node, idx, val);
        else update(mid + 1, r, 2 * node + 1, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    public static void main(String[] args) {
        int[] arr = {2, 4, 5, 7, 1, 3};
        SegmentTreeArrays st = new SegmentTreeArrays(arr);
        System.out.println(st.query(1, 3));              // Output: 4+5+7 = 16
        st.update(2, 10);                       // arr[2] = 10
        System.out.println(st.query(1, 3));             // Output: 4+10+7 = 21
    }
}