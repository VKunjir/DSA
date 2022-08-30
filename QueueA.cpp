#include<iostream>
using namespace std ;

class QueueA
{
    private:
            int rear, front, capacity ;
            int *ptr ;
    public:
        QueueA()
        {
            rear = front = -1 ;
            ptr = NULL ;
            capacity = 0;
        }
            void createQueue(int cap) ;
            bool isFull() ;
            bool isEmpty() ;
            void push(int data) ;
            void pop() ;
            int Front() ;
            int back() ;
            void viewQueue() ;
        ~QueueA()
        {
            delete ptr ;
        }
};
void QueueA :: createQueue(int cap)
{
    capacity = cap ;
    ptr = new int[cap] ;
    front = rear = -1 ;
}
bool QueueA :: isFull()
{
    if(front==0 && rear==capacity-1 || rear==front-1)
        return 1;
    else 
        return 0;
}
bool QueueA :: isEmpty()
{
    return (front == -1 && rear == -1) ;
}
void QueueA :: push(int data)
{
    if(ptr)
    {
        if(isFull())
        {
            cout << "\nQueue overflow " ;
        }
        else
        {
            if(isEmpty())
            {
                front = rear = 0;
                ptr[front] = data ;
            }
            else if(rear == capacity -1)
            {
                rear = 0;
                ptr[rear] = data ;
            }
                
            else
            {
                rear++ ;
                ptr[rear] = data ;
            }
        }
    }
    else
        cout << "\nNo queue is created " ;
}
void QueueA :: pop()
{
    if(isEmpty())
        cout << "\nEmpty list " ;
    else if(rear == front)
            {
                rear=front=-1 ;
            }
    else if(front == capacity-1)
            front = 0 ;
    else
            front++ ;
            
    
}
int QueueA :: Front()
{
    if(isEmpty())
        return -1 ;
    else
        return ptr[front] ;
}
int QueueA :: back()
{
    if(isEmpty())
        return -1 ;
    else
        return ptr[rear] ;
}
void QueueA :: viewQueue() 
{
    if(isEmpty())
        cout << "\nEmpty queue" ;
    else
    {
        if(front == 0)
        {
            for(int i=0; i<=rear; i++)
            {
                cout << ptr[i] << " " ;
            }
            cout << endl ;
        }
        else
        {
            for(int j=front; j < capacity; j++)
                cout << ptr[j] << " " ;
            for(int k=0; k<=rear ; k++)
                cout << ptr[k] << " " ;
            cout << endl ;
        }
    }
}
int main()
{
    QueueA a;
    a.createQueue(3) ;
    a.push(1) ;
    a.viewQueue() ;
    a.push(2) ;
    a.viewQueue() ;
    a.push(3) ;
    a.viewQueue() ;
    a.pop() ;
    cout << a.Front() << " " << a.back() << endl ;
    a.push(4) ;
    a.viewQueue() ;
    a.push(5) ;
    a.pop();
    a.pop();
    a.pop();
    a.pop();

    return 0 ;
}