#include<iostream>
using namespace std ;

class StackLL
{
            struct node
            {
                int item ;
                node *next ;
            };
            node *top;
    public:
            StackLL()
            {
                top = NULL ;
            }
            void push(int data) ;
            void pop() ;
            int peek() ;
            void viewStack() ;
            ~StackLL()
            {
                while(top)  
                    pop() ;
            }
};
void StackLL :: push(int data)
{
    node *n = new node ;
    n->item = data ;
    if(top)
    {
        n->next = top ;
        top = n ;
    }
    else
    {
        n->next = NULL ;
        top = n ;
    }
}
void StackLL :: pop()
{
    if(top)
    {
        node *t = top ;
        top = t->next ;
        delete t ;
    }
    else
        cout << "\nEmpty stack " ;
}
int StackLL :: peek()
{
    if(top) 
        return (top->item) ;
    else 
        return -1 ;
}
void StackLL :: viewStack()
{
    if(top)
    {
        node *t = top ;
        while(t)
        {
            cout << t->item << " " ;
            t = t->next ;
        }
        cout << endl ;
    }
    else
        cout << "\nEmpty stack " ;
}
int main()
{
    StackLL s;
    s.push(10);
    s.viewStack() ;
    s.push(20) ;
    s.push(30) ;
    s.viewStack();
    s.pop() ;
    s.viewStack() ;
    cout << s.peek() ;
    s.pop() ;
    s.pop() ;
    cout << s.peek() ;
    s.viewStack() ;
    return 0;
}