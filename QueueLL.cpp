#include<iostream>
using namespace std ;

class QueueLL
{
            struct node
            {
                int item ;
                node *next ;
            };
            node *front, *rear ;
    public :
            QueueLL()
            {
                front = rear = NULL ;
            }
            void push(int data) ;
            void pop() ;
            int Front() ;
            int back() ;
            void viewQueue() ;
            ~QueueLL()
            {
                while(front)
                    pop() ;
            }
};
void QueueLL ::push(int data)
{
    node *n = new node ;
    n->item = data ;
    n->next = NULL ;
    if(rear == NULL)
    {
        front = rear = n ;
    }
    else
    {
        rear->next = n ;
        rear = n ;
    }
}
void QueueLL :: pop()
{
    if(front == NULL)
    {
        cout << "\nEmpty queue" ;
    }
    else
    {
        if(front == rear)
        {
            delete front ;
            front = rear = NULL ;
        }
        else
        {
            node *t = front ;
            front = t->next ;
            delete t ;
        }
    }
}
int QueueLL :: Front()
{
    if(front == NULL)
        return -1 ;
    else 
        return (front->item) ;
}
int QueueLL :: back()
{
    if(rear == NULL)
        return -1 ;
    else  
        return (rear->item) ;
}
void QueueLL :: viewQueue()
{
    if(front == NULL )
        cout << "\nEmpty queue" ;
    else
    {
            node *t = front ;
            while(t)
            {
                cout << t->item << " " ;
                t = t->next ;
            }
            cout << endl ;
    }
}
int main()
{
    QueueLL s;
    s.push(11) ;
    s.viewQueue() ;
    s.push(22) ;
    s.viewQueue();
    s.push(33) ;
    s.viewQueue() ;
    s.pop() ;
    s.viewQueue() ;
    return 0;
}