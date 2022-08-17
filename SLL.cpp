#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std ;

class SLL
{
    struct node
    {
        int item ;
        node *next ;
    };
    public :
        node *start ;
        SLL(): start(NULL)
        {   }

        void viewList() ;
        void insertAtLast(int data) ;
        void insertAtFirst(int data) ;
        void insertAfter(int value, int data) ;
        void deleteFirst() ;
        void deleteLast() ;
        void deleteNode(int value) ;
        ~SLL();
};
void SLL:: insertAtLast(int data)
{
    node *n = new node ;
    n -> item = data ;
    n -> next = NULL ;
    node *t ;
    if(start == NULL)
        start = n ;
    else
    {
        t = start ;
        while(t->next != NULL)
            t= t -> next; 
        t->next = n ;

    }
}
void SLL:: insertAtFirst(int data)
{
    node *n = new node ;
    n -> item = data;
    n -> next = start ;
    start = n;
}
void SLL :: insertAfter(int value, int data)
{
    node *t, *n;
    t = start ;
    while(t)
    {
        if(t -> item == value)
            break ;
        t = t -> next ;
    }
    if(t != NULL)
    {
        n = new node ;
        n -> item = data ;
        n -> next = t -> next ;
        t -> next = n ;
    }
    else 
        cout << "\n No such value " << value << " found" << endl ;
}
void SLL :: deleteFirst()
{
    node * temp ;
    if(start == NULL)
        cout << "\n Empty list ";
    else
    {
        temp = start ;
        start = temp -> next ;
        delete temp ;
    }
}
void SLL :: deleteLast()
{
    node *t1, *t2 ;
    if( start == NULL)
      cout << "\n Empty list ";
    else
    {
        t1 = start ;
        t2 = NULL ;
        while(t1 -> next != NULL)
        {
            t2 = t1 ;
            t1 = t1 -> next ;
        }
        if(t2 == NULL)
            start = NULL ;
        else 
            t2 -> next = NULL ;
        delete t1 ;
    }  
}
void SLL :: deleteNode(int data)
{
    node *t1, *t2 ;
    t1 = start ;
    t2 = NULL ;
    while(t1)
    {
        if(t1 -> item == data)
            break;
        t2 = t1 ;
        t1 = t1 -> next ;
    }
    if(t1 == NULL)
        cout << "\n The value " << data << " is not int the list" ;
    else
    {
        if(t2 == NULL)
            start = NULL ;
        else
            t2  -> next = t1 -> next ;
        delete t1 ;
    }
}
void SLL :: viewList()
{
    node *temp = start ;
    while(temp)
    {
        cout << temp -> item << "\t" ;
        temp = temp -> next ;
    }
}
SLL :: ~SLL()
{
    while(start)
        deleteFirst() ;
}

int menu()
{
    int choice ;
    cout << "\n" ;
    cout << "\n 1. Insert at First " ;
    cout << "\n 2. Insert at Last" ;
    cout << "\n 3. Insert after a node" ;
    cout << "\n 4. Delete at First" ;    
    cout << "\n 5. Delete at Last" ;
    cout << "\n 6. Delete a node" ;
    cout << "\n 7. Exit" ;
    cout << "\n Enter your choice : " ;
    cin >> choice ;
    return choice ;
}
int main()
{
    int index, data ;
    SLL list1;
    
    while(true)
    {
        cout << "\n " ;
        list1.viewList() ;
        switch(menu())
        {
        case 1: 
                cout << "\n Enter data to insert at first : " ;
                cin >> data;
                list1.insertAtFirst(data) ;
                break ;
        case 2: 
                cout << "\n Enter data to insert at last : " ;
                cin >> data ;
                list1.insertAtLast(data) ;
                break ;
        case 3: 
                cout << "\n Enter value to insert at after a node : " ;
                cin >> index ;
                cout << "\n Enter data to insert at after a node : " ;
                cin >> data ;
                list1.insertAfter(index, data) ;
                break ;
        case 4: 
                list1.deleteFirst() ;
                break ;
        case 5:    
                list1.deleteLast(); 
                break ;
        case 6: 
                cout << "\n Enter data to delete  Node : " ;
                cin >> data ;
                list1.deleteNode(data) ;
                break ;
        case 7: 
                exit(0) ;
        default:
                cout << "\n Invalid input : " ;
            
        }
    }
return 0;
}