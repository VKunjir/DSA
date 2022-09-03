#include<iostream>
using namespace std;

class PQLL
{
            struct node
            {
                int prio, item ;
                node *next ;
            } ;
            node *start ;
    public:
            PQLL()
            {
                start = NULL ;
            }
            void push(int data,int priority) ;
            void pop() ;
            void viewQueue() ;
            ~PQLL()
            {
                while(start)
                    pop() ;
            }
};
void PQLL :: push(int data, int priority)
{
    node *n = new node ;
    n->item = data ;
    n->prio = priority ;
    if(start == NULL)
    {
        n->next = NULL ;
        start = n ;
    }
    else
    {
        node *t = start ;
        while(!(t->prio <= priority))
        {
            if(t->next == NULL)
                break ;
            else
                t = t->next ;
        }
        n->next = t->next ;
        t->next = n ;
    }
}
void PQLL :: pop()
{
    if(start)
    {
        node *t = start;
        start = t->next ;
        delete t ;
    }
    else
    {
        cout << "\nEmpty queue" ;
    }
}
void PQLL :: viewQueue()
{
    if(start)
    {
        node *t = start ;
        while(t)
        {
            cout << t->item << " " ;
            t = t->next ;
        }
        cout << endl ;
    }
    else
        cout << "\nEmpty queue" ;
}
int main()
{
    PQLL pq ;
    pq.push(10,5) ;
    pq.viewQueue() ;
    pq.push(20,3) ;
    pq.viewQueue() ;
    pq.push(30,3) ;
    pq.viewQueue() ;
    pq.push(40,2) ;
    pq.viewQueue() ;
    pq.pop() ;
    pq.viewQueue() ;
    return 0 ;
}