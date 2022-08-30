#include<iostream>
using namespace std ;

class PAQueue
{
    private: 
            int row, col, front, rear ;
            int **ptr;
    public:     
            PAQueue()
            {
                row = col = 0 ;
                ptr = NULL ;
            }
            void createPQueue(int r, int c) ;
            bool isEmpty(int prio) ;
            bool isFull(int prio) ;
            void push(int data, int prio) ;
            void pop() ;
            void viewPQueue() ;
            ~PAQueue()
            {
                for(int i=0; i<row ; i++)
                    delete [] ptr[i] ;
                delete []ptr ;
            }
};
void PAQueue :: createPQueue(int r, int c)
{
    row = r ;
    col = c+2 ;
    ptr = new int*[row] ;
    for(int i=0; i<row; i++)
    {    ptr[i] = new int[col] ;    }

    for(int i=0; i<row ; i++)
    {
        ptr[i][col-2] = ptr[i][col-1] = -1 ;
    }
}
bool PAQueue :: isEmpty(int prio)
{
    if( prio>0 && prio <= row)
    {
        front = ptr[prio][col-2] ;
        rear = ptr[prio][col-1] ;
        if(front== -1 && rear == -1)
            return true ;
        else 
            return false ;
    }
    else
    {
        cout << "\nInvalid priority number " ;
        return false ;
    }
}
bool PAQueue :: isFull(int prio)
{
    if(prio>0 && prio<=row)
    {
        front = ptr[prio][col-2] ;
        rear = ptr[prio][col-1] ;
        if(front == 0 && rear == col-3 || rear==front-1)
            return true ;
        else
            return false ;
    }
    else
    {
        cout << "\nInvalid priority number" ;
        return false ;
    }
}
void PAQueue :: push(int data, int prio)
{
    if(prio<=0 || prio > row)
        cout << "\nInvalid priority number " ;
    else if(isFull(prio-1))
       cout << "\nPriority array in fulled" ;
    else 
    {
        front = ptr[prio-1][col-2] ;
        rear = ptr[prio-1][col-1] ;
        if(front == -1 && rear == -1)
        {
            ptr[prio-1][col-2] = ptr[prio-1][col-1] = 0 ;
            ptr[prio-1][0] = data ;
        }
        else if(rear == col-3)
        {
            ptr[prio-1][col-1] = 0;
            ptr[prio-1][0] = data ;
        }
        else
        {
            ptr[prio-1][col-1] += 1 ;
            rear = ptr[prio-1][col-2] ;
            ptr[prio-1][rear] = data ;
        }
    }   
}
void PAQueue :: pop()
{
    for(int i=row-1; i>=0; i--)
    {
        front = ptr[i][col-2] ;
        rear = ptr[i][col-1] ;
        if(!isEmpty(i))
        {
            if(front == 0 && rear==0)
            {
                ptr[i][col-2] = ptr[i][col-1] = -1 ;
                break ;
            }
            else if(front-1 == rear)
            {
                ptr[i][col-2] = ptr[i][col-1] ;
                break ;
            }
            else{
                ptr[i][col-2] += 1;
                break ;
            }
        }
    }
}
void PAQueue :: viewPQueue()
{
    for(int i=row-1; i>=0; i--)
    {
        front = ptr[i][col-2] ;
        rear = ptr[i][col-1] ;
        cout << front << rear ;
        if(!isEmpty(i))
        {
            if(front == rear)
            {
                cout << ptr[front][rear] << endl ;
            }
            else if(front == 0)
            {
                for(int j=0; j<=rear ; j++)
                    cout << ptr[i][j] << " "  ;
                cout << endl ;
            }
            else
            {
                for(int j=front; j<=col-3 ; j++)
                    cout << ptr[i][j] << " "  ;
                for(int j=0; j<=rear ; j++)
                    cout << ptr[i][j] << " "  ;
                cout << endl ;
            }
        }
    }
    cout << endl ;
}
int main()
{
    PAQueue pq ;
    pq.createPQueue(3,3) ;
    //pq.viewPQueue() ;
    //pq.push(10,2) ;
    //pq.viewPQueue() ;
    /*pq.push(20,3) ;
    pq.viewPQueue() ;
    pq.push(30,1) ;
    pq.viewPQueue() ;
    pq.pop() ;
    pq.viewPQueue() ;*/
    return 0 ;
}














































/*#include<iostream>
using namespace std ;

class PriorityQueue
{
            int row, col, front, rear ;
            int **ptr ;
    public:
            PriorityQueue()
            {
                row = col = 0 ;
                ptr = NULL ;
            }
            void createPQueue(int r, int c) ;
            bool isEmpty(int num) ;
            bool isFull(int num) ;
            void push(int data, int pri) ;
            void pop() ;
            void viewPQueue() ;
            ~PriorityQueue()
            {
                for(int i=0; i<row ; i++)
                    delete [] ptr[i] ;
                delete []ptr ;
            }
};
bool PriorityQueue :: isFull(int num)
{
    front = ptr[num][col-2] ;
    rear = ptr[num][col-1] ;
    if(front == 0 && rear == col-3 || rear == front-1)
        return true ;
    else
        return false ;
}
bool PriorityQueue :: isEmpty(int num)
{
    front = ptr[num][col-2] ;
    rear = ptr[num][col-1] ;
    if(front == -1 && rear == -1)
        return true ;
    else
        return false ;
}
void PriorityQueue :: createPQueue(int r, int c)
{
    row = r ;
    col = c+2 ;
    ptr = new int*[row] ;
    for(int i=0; i<row ; i++)
    {
        ptr[i] = new int[col] ;
    }
    for(int i=0; i<row; i++)
    {
        for(int j=col-2; j<col ; j++)
        {
            ptr[i][j] = -1 ;
        }
    }
}
void PriorityQueue :: push(int data, int pri)
{
    if(pri > row)
        cout << "\nPriority out of range" ;
    else
    {
        front = ptr[pri-1][col-2] ;
        rear = ptr[pri-1][col-1] ;
        if(isFull(pri-1))
            cout << "\nData Overflow" ;
        else if(isEmpty(pri-1))
        {
            ptr[pri-1][col-2] = ptr[pri-1][col-1] = 0;
            ptr[0][0] = data ;
        }
        else if(rear == col-3)
        {
            ptr[pri-1][col-1] = 0 ;
            ptr[pri-1][0] = data ;
        }
        else
        {
            ptr[pri-1][col-1]++ ;
            rear = ptr[pri-1][col-1] ;
            ptr[pri-1][rear] = data ;
        }
    }
}
void PriorityQueue :: pop()
{
        int i ;
        for(i=row-1; i>=0 ; i--)
        {
            front = ptr[i][col-2] ;
            rear = ptr[i][col-1] ;
            if(!isEmpty(i))
            {
                if(front == rear)
                {
                    ptr[i][col-2] = ptr[i][col-1] = -1 ;
                    break;
                }
                else if(front == col-3)
                {
                    ptr[i][col-2] = 0 ;
                    break ;
                }
                else
                {
                    ptr[i][col-2]++ ;
                    break ;
                }
            }
        }
        if(i==-1)
            cout << "\nNo data in list " ;
        else
            cout << "\nData deleted successfully" ;
}
void PriorityQueue :: viewPQueue()
{
    for(int i=row-1; i>=0; i--)
    {
        if(isEmpty(i))
        {
            front = ptr[i][col-2] ;
            rear = ptr[i][col-1] ;
            if(front == 0) 
            {
                for(int k=0;k<=rear; k++)
                cout << ptr[i][k] << " " ;
                cout << endl ;
            }
            else
            {
                for(int k=front; k<= col-3; k++)
                    cout << ptr[i][k] << " " ;
                for(int j=0; j<=rear ; j++)
                    cout << ptr[i][j] << " " ;
                cout << endl ; 
            }
        }
    }
}
int main()
{
    PriorityQueue pq ;
    pq.createPQueue(5,7) ;
    pq.push(100,3) ;
    pq.viewPQueue() ;
    /*pq.push(90,4);
    pq.viewPQueue() ;
    pq.push(80,4) ;
    pq.viewPQueue() ;
    pq.push(60,1) ;
    pq.viewPQueue() ;
    pq.pop() ;
    pq.viewPQueue() ;
    return 0;
} */