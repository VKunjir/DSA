#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class DynamicArray
{
    private: 
              int capacity ;
              int lastindex ;
              int *ptr ;
    protected: 
                void doubleArray() ;
                void halfArray() ;
    public:
                DynamicArray(int cap)
                {
                    lastindex = -1 ;
                    capacity = cap ;
                    ptr = new int [cap] ;
                }
                void append(int data) ;
                void insert(int index, int data) ;
                void deletefun(int index) ;
                void edit(int index, int data) ;
                int search(int data) ;
                int count() ;
                int getItem(int index) ;
                ~DynamicArray()
                {
                    delete []ptr ;
                }   
};
// double array function
void DynamicArray :: doubleArray()
{
    capacity *= 2 ;
    int *temp ;
    
    for(int i=0; i<= lastindex; i++)
        temp[i] = ptr[i] ;
    
    delete []ptr ;
    ptr = temp ;    
}
// Append function
void DynamicArray :: append(int data)
{
    if(lastindex +1 == capacity)
        doubleArray();
    
    lastindex += 1 ;
    ptr[lastindex] = data ;
}  
// insert function
void DynamicArray :: insert(int index,int data)
{
    if(index<0 || index >lastindex+1)
        cout << "\n Operation failed: Invalid index" ;
    else if(lastindex+1 == capacity)
    {
        doubleArray() ;
        for(int i=lastindex;i <=index ; i--)
        ptr[i+1] = ptr[i] ;
        ptr[index] = data ;
        lastindex ++ ;
    }
    else
    {
        for(int i=lastindex;i <=index ; i--)
        ptr[i+1] = ptr[i] ;
        ptr[index] = data ;
        lastindex ++ ;
    } 
}
// half function
void DynamicArray :: halfArray()
{
    capacity /= 2 ;
    int *temp ;
    temp = new int[capacity] ;

    for(int i=0; i<= lastindex; i++)
        ptr[i] = temp[i] ;

    delete []ptr ;
    ptr = temp ;
}
// delete function
void DynamicArray :: deletefun(int index)
{
    if(index<0 || index >lastindex)
        cout << "\n Operation failed: Invalid index" ;
    else
        {
            for(int i = index; i< lastindex ; i++)
                ptr[i] = ptr[i+1] ;
            
            lastindex--;
        }
        if(capacity/2 == lastindex)
            halfArray() ;
}
// edit function
void DynamicArray:: edit(int index, int data)
{
    if(index<0 || index >lastindex)
        cout << "\n Operation failed: Invalid index" ;
    else
        ptr[index] = data ;
}
// search function
int DynamicArray :: search(int data)
{
    for(int i=0; i<= lastindex ; i++)
    {
        if(ptr[i] == data)
            return i ;
    }
    return -1 ;
}
//count element function
int DynamicArray :: count()
{
    return (lastindex+1) ;
}
// get Item function
int DynamicArray :: getItem(int index)
{
    return(ptr[index]) ;
}
void viewArrayData(DynamicArray &arr)
{
    cout << "\n" ;
    for(int i=0; i< arr.count(); i++)
        cout << arr.getItem(i) << " " ;
}
int menu()
{
    int choice = 0 ;
    cout << "\n 1.Append" ;
    cout << "\n 2.Insert" ;
    cout << "\n 3.Delete" ;
    cout << "\n 4.Edit" ;
    cout << "\n 5.Search" ;
    cout << "\n 6.Exit" ;
    cout << "\n Enter your choice: " ;
    cin >> choice ;
    return choice ;
}
int main()
{
    system("clr") ;
    int index, data ;
    DynamicArray arr(5) ;
    while(1)
    {
        cout << "\n Total number of element is: " << arr.count() ;
        viewArrayData(arr);
        switch(menu())
        {
            case 1: 
                    cout << "\n Enter data to append: " ; 
                    cin >> data ;
                    arr.append(data);
                    break;
            case 2: 
                    cout << "\n Enter index to insert: " ; 
                    cin >> index ;
                    cout << "\n Enter data to insert: " ; 
                    cin >> data ;
                    arr.insert(index, data);
                    break ;
            case 3:
                    cout << "\n Enter data to delete: " ; 
                    cin >> index ;
                    arr.deletefun(index) ;
                    break;
            case 4:         
                    cout << "\n Enter index to edit: " ; 
                    cin >> index ;
                    cout << "\n Enter data to edit: " ; 
                    cin >> data ;
                    arr.edit(index, data) ;
                    break ;
            case 5: 
                    cout << "\n Enter data to search: " ; 
                    cin >> data ;
                    index = arr.search(data) ;
                    if(index == -1)
                        cout << "\n Data not found" ;
                    else
                        cout << "\n Data     found at index: " << index ;
                    break;
            case 6:
                    exit(0);
            default: 
                    cout << "\n Invalid input" ;
            }
    }
}