class stack{
    private: 
        int dataArray[25];
        int top;
        int maxSize;
    public:
        stack();
        void print();
        void printString();
        void push(int);
        int pop();
        int topper();
        int length();
};