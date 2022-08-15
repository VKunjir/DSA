#include<iostream>
using namespace std ;

class DoubleADT
{
    int capacity, lastindex ;
    int *ptr ;
    
    public:

    void createArray(int cap) ;
    void append(int data) ;
    void doubleArray() ;
    void halfArray() ;

    void del(int index) ;
    void edit(int index, int data) ;
    int search(int data) ;
    int count() ;
    int getItem(int index) ;


    DoubleADT()
    {
        capacity = 0 ;
        lastindex = -1 ;
    }
    ~DoubleADT()
    {
        delete(ptr) ;
    }
};
int DoubleADT :: getItem(int index)
{
    if(index >0 && index <= lastindex)
        return (ptr[index]);
    else
        return 0;
}
int DoubleADT :: count()
{
    return (lastindex+1) ;
}
int DoubleADT :: search(int data)
{
    for(int i=0; i <= lastindex; i++)
    {
        if(ptr[i] == data)
            return(i);
    }
    return -1 ;
}
void DoubleADT :: edit(int index, int data)
{
    if(index < 0 || index > lastindex+1)
    {
        cout << "\nOperation Failled: Invalid index" ;
    }
    else
    {
        ptr[index] = data ;
    }
}
void DoubleADT :: del(int index)
{
    if(index<0 || index > lastindex+1 )
    {
        cout << "\nOperation Fallied: Invalid index " ;
    }
    else 
    {
        for(int i=index; i< lastindex ; i++)
        {
            ptr[i+1] = ptr[i] ;
        }
        if(lastindex == capacity/2)
        {
            halfArray();
        }
        lastindex -= 1 ;
    }
}
void DoubleADT :: halfArray()
{
    capacity /= 2;
    int *ptr1 = new int[capacity] ;
    for(int i = 0; i <=lastindex ; i++ )
    {
        ptr1[i] = ptr[i] ;
    }
    delete []ptr ;
    ptr = ptr1 ;
}

void DoubleADT :: doubleArray()
{
    int *ptr1 ;
    capacity *= 2 ;
    ptr1 = new int[capacity] ;
    for(int i=0; i<= lastindex ; i++)
    {
        ptr1[i] = ptr[i] ;
    }
    delete []ptr ;
    ptr = ptr1 ;
}
void DoubleADT :: insert(int index, int data)
{
    if(index<0 || index > lastindex+1)
    {
        cout << "\nOperation Fallied: Invalid index " ;
    }
    else if(lastindex +1 == capacity)
    {
        doubleArray() ;
        for(int i = lastindex; i < index; i--)
        {
            ptr[i+1] = ptr[i] ;
        }
        ptr[index] = data ;
        lastindex += 1 ;
    }
    else
    {
        for(int i = lastindex; i < index; i--)
        {
            ptr[i+1] = ptr[i] ;
        }
        ptr[index] = data ;
        lastindex += 1 ;
    }
}

void DoubleADT :: append(int data)
{
    if(lastindex + 1 == capacity)
    {
        // calling doubleArray function
        doubleArray() ;
        lastindex += 1 ;
        ptr[lastindex] = data ;
    }
    else{
        lastindex += 1 ;
        ptr[lastindex] = data ; 
    }
}

void DoubleADT :: createArray(int cap)
{
    if(capacity == 0){
    ptr = new int[cap] ;
    capacity = cap ;
    }
    else{
        cout << "\n Array is been already created";
    }
}