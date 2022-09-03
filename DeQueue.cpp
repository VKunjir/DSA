#include<iostream>
using namespace std ;

class TWStack
{
            int top1,top2, capacity ;
            int *ptr ;
    public:
            TWStack(int cap)
            {
                capacity = cap ;
                top1 = -1;
                top2 = cap  ;
                ptr = new int[cap] ;
            }
            bool isEmpty() ;
            bool isFull() ;
            void push_front(int data) ;
            void push_back(int data) ;
            void pop_front() ;
            void pop_back() ;
            void viewStack() ;
            ~TWStack()
            {
                while(!isEmpty())
                {
                    pop_back() ;
                    pop_front() ;
                }
            }
};
bool TWStack :: isEmpty()
{
    if(top1 == -1 && top2 == capacity)
        return true ;
    else
        return false ;
}
bool TWStack :: isFull()
{
    if(top1 == top2-1)
        return true ;
    else    
        return false ;
}
void TWStack :: push_front(int data) 
{
    if(!isFull())
    {
        top1++ ;
        ptr[top1] = data ;
    }
    else
        cout << "\nStack Overflow " ;
}
void TWStack :: push_back(int data)
{
    if(!isFull())
    {
        top2--;
        ptr[top2] = data ;
    }
    else
        cout << "\nStack Overflow" ;
}
void TWStack :: pop_front()
{
    if(isEmpty())
        cout << "\nStack is empty" ;
    else if(top1 == -1)
        cout << "\n" ;
    else
        top1-- ; 
}
void TWStack :: pop_back()
{
    if(isEmpty())
        cout << "\nStack is empty" ;
    else if(top2 == capacity)
        cout << "\n" ;
    else
        top2++ ; 
}
void TWStack :: viewStack()
{
    cout << "\n ";
    if(isEmpty())
        cout << "\nEmpty stack" ;
    else
    {
        for(int i=top1; i>= 0; i--)
            cout << ptr[i] << "\t" ;
        for(int j=capacity-1 ; j>=top2 ;j--)
            cout << ptr[j] << "\t" ;
        cout << "\n ";
    }
}
int main()
{
    TWStack st(6) ;
    st.viewStack() ;
    st.push_front(10) ;
    st.viewStack() ;
    st.push_back(20) ;
    st.viewStack() ;
    st.push_front(5) ;
    st.push_back(30) ;
    st.viewStack() ;
    st.pop_front() ;
    st.viewStack() ;
    st.pop_back() ;
    st.viewStack() ;

    return 0 ;
}