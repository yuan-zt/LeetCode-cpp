class MyQueue {
public:
    stack<int> s1;
      
    MyQueue() {       
    }
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        stack<int> s2;
        int size=s1.size();
        for(int i=0;i<size-1;i++){
            s2.push(s1.top());
            s1.pop();
        }
        int a=s1.top();
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return a;
    }

    int peek() {
        stack<int> s2;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int a=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return a;
    }
    bool empty() {
        return s1.empty();
    }
};
