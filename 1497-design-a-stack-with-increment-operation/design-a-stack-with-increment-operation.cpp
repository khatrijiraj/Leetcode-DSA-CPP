#include <iostream>
#include <vector>

class CustomStack {
private:
    vector<int> stack;
    vector<int> increments;
    int maxSize;

public:
    CustomStack(int maxSize) { this->maxSize = maxSize; }

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
            increments.push_back(0);
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1;
        }

        int index = stack.size() - 1;
        int value = stack.back() + increments[index];
        stack.pop_back();

        if (index > 0) {
            increments[index - 1] += increments[index];
        }

        increments.pop_back();
        return value;
    }

    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());
        if (limit > 0) {
            increments[limit - 1] += val;
        }
    }
};

/**
 * Example usage:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k, val);
 */
