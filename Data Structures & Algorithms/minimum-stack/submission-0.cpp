class MinStack {
public:
            stack<int> mainStack; 
        stack<int> minStack; 
    MinStack() {

    }
    
    void push(int val) {
        if (this -> minStack.empty() or this -> minStack.top() >= val){
            minStack.push(val);
        }
        this -> mainStack.push(val);
    }
    
    void pop() {
        if (this -> mainStack.top() == this -> minStack.top()){
            this -> minStack.pop();
        }
        this -> mainStack.pop();
    }
    
    int top() {
        return this -> mainStack.top();
    }
    
    int getMin() {
        return this -> minStack.top();
    }
};
