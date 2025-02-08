class NumberContainers {
    typedef priority_queue<int, vector<int>, greater<int>> minheap;

public:
    NumberContainers() {}

    void change(int idx, int num) {
        mppinditonum[idx] = num;
        mppnumtoindi[num].push(idx);
    }

    int find(int num) {
        if (mppnumtoindi.find(num) == mppnumtoindi.end()) {
            return -1;
        }

        auto& minHeap = mppnumtoindi[num];

        while (!minHeap.empty()) {
            int idx = minHeap.top();

            if (mppinditonum[idx] == num) {
                return idx;
            }

            minHeap.pop();
        }

        return -1;
    }

private:
    unordered_map<int, minheap> mppnumtoindi;
    unordered_map<int, int> mppinditonum;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(num);
 */