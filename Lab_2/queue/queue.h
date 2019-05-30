class queue{
    private: 
        int myend;
        int maxsize;
        int data[25];
    public:
        queue();
        void print();
        void printString();
        void enqueue(int);
        int dequeue();
        bool isFull();
        bool isEmpty();
        int length();
};