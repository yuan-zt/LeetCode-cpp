class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;

    MyStack() {

    }

    void push(int x) {
        queue2.push(x);
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        swap(queue1, queue2);
    }

    int pop() {
        int r = queue1.front();
        queue1.pop();
        return r;
    }
    
    int top() {
        int r = queue1.front();
        return r;
    }
    
    bool empty() {
        return queue1.empty();
    }
};
