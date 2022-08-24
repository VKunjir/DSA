#include<iostream>
using namespace std ;

class Stack
{
    private:
            int top, capacity;
            int *ptr ;
    public:
            Stack()
            {
                capacity = 0;
                top = -1 ;
                ptr = NULL ;
            }
            Stack(int cap)
            {
                top = -1 ;
                ptr = new int[cap] ;
                capacity = cap ;
            }
            void creatStack(int cap) ;
            bool isFull() ;
            bool isEmpty() ;
            void push(int data) ;
            void pop() ;
            int peek() ;
            void viewStack() ;
            ~Stack()
            {
                delete ptr ;
            }
};
void Stack :: creatStack(int cap)
{
    if(cap > 0){
        if(ptr != NULL)
            delete ptr ;
        top = -1 ;
        ptr = new int[cap] ;
        capacity = cap ;
    }
}
bool Stack :: isFull()
{
        return top+1 == capacity;
}
bool Stack :: isEmpty()
{
    return top == -1 ;
}
void Stack :: push(int data)
{
    if(!isFull())
    {
        cout << "\nStack overflow" ;
    }
    else
    {
        top++;
        ptr[top] = data ;
    }
}
void Stack :: pop()
{
    if(isEmpty())
        cout << "\nEmpty stack" ;
    else
        top-- ;
}
int Stack :: peek()
{
    if(isEmpty())
    {
        cout << "\nEmpty stack " ;
        return -1 ;
    }
    else
    {
        return ptr[top] ;
    }
}
void Stack :: viewStack()
{
    for(int i=0; i<=top ;i++)
    {
        cout << ptr[i] << " " ;
    }
    cout << "\n" ;
}
int main()
{
    Stack s1(5) ;
    s1.push(1) ;
    s1.viewStack() ;
    s1.push(2) ;
    s1.push(5) ;
    s1.viewStack() ;
    s1.pop() ;
    s1.viewStack() ;
    cout << s1.peek() ;
    return 0;
}