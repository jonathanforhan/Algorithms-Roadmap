#include<iostream>
#include<limits.h>

using std::cout;

// Time O(1)
// Space O(n)

// basic stack
struct Stack {
    Stack* next;
    int val;
    int min;

    Stack(int val, int min) : val(val), min(min) {}
    ~Stack() { delete next; }
};

class MinStack {
public:
    MinStack() : head(nullptr), min((int)NULL) {}
    
    // main point of this problem is to cache the min in each stack item
    void push(int val) {
        if(head == nullptr) {
            this->min = val;
        } else {
            this->min = std::min(this->min, val);
        }
        Stack* newHead = new Stack(val, min);
        newHead->next = head;
        head = newHead;
    }
    
    void pop() {
        if(!head) return;

        head = head->next;
        if(head) {
            this->min = head->min;
        } else {
            this->min = (int)NULL;
        }
    }
    
    int top() {
        return head->val;
    }

    int getMin() {
        return this->min;
    }

private:
    Stack* head;
    int min;
};

int main() {
    MinStack* minStack = new MinStack();

    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << '\n';
    minStack->pop();
    cout << minStack->top()    << '\n';
    cout << minStack->getMin() << '\n';

    // expected -3, 0, -2 //

    delete minStack;
}
