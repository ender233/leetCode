#include <iostream>
#include <stack>
using namespace std;

struct MinStack {
    MinStack() {}

    std::stack<int> valueStack_;
    std::stack<int> minStack_;

    void push(int x) {
        valueStack_.push(x);

        if(minStack_.empty()
                || x <= minStack_.top())
            minStack_.push(x);
    }

    void pop() {
        int minTop = minStack_.top();
        int valueTop = valueStack_.top();
        if(valueTop == minTop)
            minStack_.pop();
        valueStack_.pop();
    }

    int top() {
        return valueStack_.top();
    }

    int getMin() {
        return minStack_.top();
    }
};

int main() {
    MinStack *obj = new MinStack();
    obj->push(2);
    obj->push(3);
    obj->push(1);

    int minvalue = obj->getMin();
    std::cout<<"minValue:"<<minvalue<<std::endl;

    obj->pop();
    minvalue = obj->getMin();
    std::cout<<"minValue:"<<minvalue<<std::endl;
    return 0;
}