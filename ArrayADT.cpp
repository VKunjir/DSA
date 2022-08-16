#include<iostream>
using namespace std ;

class ArrayADT
{
    private:
        int capacity ;
        int *ptr ;
    public:
        int lastindex ;
        ArrayADT(int cap)
        {
            lastindex = -1 ;
            capacity = cap ;
            ptr = new int[cap] ;
        }

        void append(int data) ;
        void insert(int index, int data) ;
        void deletefun(int index) ;
        void edit(int index, int data) ;
        int search(int data) ;
        int count() ;
        int getItem(int index) ;
        ~ArrayADT()
        {
            delete []ptr ;
        } 
};
// append function
void ArrayADT :: append(int data)
{
    if(lastindex+1 == capacity)
        cout << "\nOperation Failled: Data overloading" ;
    else{
        lastindex += 1 ;
        ptr[lastindex] = data ;
    }
}
// insert function
void ArrayADT :: insert(int index, int data)
{
    if(index <0 || index >capacity)
        cout << "\n Operation Failled: Invalid index" ;
    else if(lastindex+1 == capacity )
        cout << "\n Operation Failled: Data overloading" ;
    else
    {
        for(int i=lastindex; i>= index; i--)
            ptr[i+1] = ptr[i] ;
        
        ptr[index] = data ;
        lastindex ++ ;
    }
}
// deletion function 
void ArrayADT:: deletefun(int index)
{
    if(index<0 || index >lastindex)
        cout << "\n Operation Failled: Invalid index" ;
    else
    {
        for(int i=index; i<lastindex ;i++)
            ptr[i] = ptr [i+1] ;
        
        lastindex-- ;
    }
}
// edit function
void ArrayADT :: edit(int index, int data)
{
    if(index <0 || index > lastindex)
        cout << "\n Operation Failled: Invalid index" ;
    else    
        ptr[index] = data ;
}
// search function
int ArrayADT :: search(int data)
{
    for(int i =0; i<= lastindex; i++)
    {
        if(ptr[i] == data)
            return i;
    }
    return -1 ;
}
// count function
int ArrayADT :: count()
{
    return (lastindex+1);
}
// get Item function
int ArrayADT :: getItem(int index)
{
       return(ptr[index]) ;
}
int menu()
{
    int choice ;
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
void viewArrayData(ArrayADT &arr)
{
    cout <<"\n" ;
    for(int i=0; i<=arr.lastindex; i++)
        cout << arr.getItem(i) << " " ;
}
int main()
{
    int index , data ;
    ArrayADT arr(5) ;
    while(true)
    {
        cout << "\n" ;
        cout << "\n Total element in array: " << arr.count() ;
        viewArrayData(arr) ;
        switch(menu())
        {
            case 1:
                    cout << "\n Enter data to append: ";
                    cin >> data ;
                    arr.append(data) ;
                    break ;
            case 2:
                    cout << "\n Enter index to append: ";
                    cin >> index ;
                    cout << "\n Enter data to insert: ";
                    cin >> data ;
                    arr.insert(index, data) ;
                    break ;
            case 3: 
                    cout << "\n Enter index to delete: ";
                    cin >> index ;
                    arr.deletefun(index) ;
                    break ;
            case 4:
                    cout << "\n Enter index to edit: ";
                    cin >> index ;
                    cout << "\n Enter data to edit: ";
                    cin >> data ;
                    arr.edit(index,data) ;
                    break ;
            case 5:
                    cout << "\n Enter data to search: ";
                    cin >> data ;
                    index = arr.search(data) ;
                    if(index == -1)
                        cout <<"\n Enter data not found in list" ;
                    else 
                        cout << "\n Enter data is at index: " << index ;
                        break ;
            case 6:
                exit(0) ;
            default: 
                    cout << "\n Invalid choice " ;      
        }
    } 
  return 0 ;
}