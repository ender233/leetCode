#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class MyQueue
{
public:
    std::stack<int> left_;
    std::stack<int> right_;
    MyQueue() {
    }
    void push(int x) {
        left_.push(x);
    }

    int pop() {
        int pop = peek();
        right_.pop();
        return pop;
    }

    int peek() {
        int pop(0);
        if(!right_.empty()) {
            pop = right_.top();
        }
        else {
            while(!left_.empty()) {
                right_.push(left_.top());
                left_.pop();
            }
            pop = right_.top();
        }
        return pop;
    }

    bool empty() {
        return left_.empty() &&
                right_.empty();
    }
};

int main() {
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);

    int top = obj->peek();
    std::cout << "top:" << top << std::endl;
}