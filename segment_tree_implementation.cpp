struct seg_tree {
    int size_arr = 1;
    vector<long long> sums;
    void init(int n) {
        while (size_arr < n) {
            size_arr *= 2;
        }
        sums.assign(4 * size_arr + 1, 0);
    }
 
    void build(int node, int left, int right, vector<int> &arr) {
        if (left == right) {
            sums[node] = arr[left];
        }
 
        else {
            int mid = (left + right) / 2;
            build(2 * node + 1, left, mid, arr);
            build(2 * node + 2, mid + 1, right, arr);
            sums[node] = min(sums[2 * node + 1], sums[2 * node + 2]);
        }
    }
 
    void build(vector<int> &arr) {
        build(0, 1, size_arr, arr);
    }
 
    void update(int node, int left, int right, int index, int value) {
        if (index < left || index > right) return;
        if (left == right) {
            sums[node] = value;
            return;
        }
 
        else {
            int mid = (left + right) / 2;
 
            update(2 * node + 1, left, mid, index, value);
            update(2 * node + 2, mid + 1, right, index, value);
 
            sums[node] = min (sums[2 * node + 1], sums[2 * node + 2]);
        }
    }
 
    void update(int index, int value) {
         update(0, 1, size_arr, index, value);
    }
 
    long long query(int node, int left, int right, int x, int y) {
        if (x > right || y < left) return 2e9;
        if (x <= left && right <= y) return sums[node];
 
        int mid = (left + right) / 2;
        long long a = query(2 * node + 1, left, mid, x, y);
        long long b = query(2 * node + 2, mid + 1, right, x, y);
 
        return min(a, b);
    }
 
    long long query(int x, int y) {
        return query(0, 1, size_arr, x, y);
    }
 
    //void debug() {
       // for (int i = 0; i < sums.size(); i ++) {
           // cout << i << ": " << sums[i] << endl;
        //}
    //}
 
 
};
