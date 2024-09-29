class MinStack {
    stack<long long> st; // Stack to store elements
    long long mini; // Variable to store the minimum value

public:
    /** initialize your data structure here. */
    MinStack() {
        // Initialize the minimum value to the maximum possible integer
        mini = LLONG_MAX;
    }

    void push(int value) {
        // Convert the input value to long long to handle large values
        long long val = value;
        if (st.empty()) {
            // If stack is empty, push the value and set it as the minimum
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                // If the new value is less than the current minimum,
                // push a modified value (2*val - mini) and update the minimum
                st.push(2 * val - mini);
                mini = val;
            } else {
                // Otherwise, just push the value
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return; // If the stack is empty, do nothing

        long long el = st.top(); // Get the top element of the stack
        st.pop(); // Remove the top element from the stack

        if (el < mini) {
            // If the popped value is less than the current minimum,
            // it means the actual value was modified during push.
            // Update the minimum to the previous minimum value
            mini = 2 * mini - el;
        }
    }

    int top() {
        if (st.empty()) return -1; // If the stack is empty, return -1

        long long el = st.top(); // Get the top element of the stack
        // If the top value is less than the current minimum,
        // it means the actual top value is the current minimum
        if (el < mini) return mini;
        return el; // Return the top element as it is greater than or equal to the current minimum
    }

    int getMin() {
        return mini; // Return the current minimum value
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
