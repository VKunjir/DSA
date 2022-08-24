#include<iostream>
#include<stdlib.h>
using namespace std ;

class DLL
{
        struct node
        {
            int item ;
            node *prev, *next ;
        };
        node *start ;
    public:
        DLL()
        {
            start = NULL;
        }
        void insertAtFirst(int data) ;
        void insertAtLast(int data) ;
        void insertAfter(int value, int data) ;
        void deleteFirst() ;
        void deleteLast() ;
        void deleteNode(int value) ;
        void viewList() ;
        void search(int data) ;
        ~DLL()
        {
            while(start)
                deleteFirst() ;
        }
};
void DLL :: insertAtLast(int data)
{
    node *n, *t ;
    n = new node ;
    n -> item = data ;
    n -> next = NULL ; 
    if(start == NULL)
    {
        n-> prev = NULL ;
        start = n ;
    }
    else
    {
        t = start ;
        while(t -> next != NULL)
            t = t -> next ;
        n -> prev = t ;
        t -> next = n ;  
    }
} 
void DLL :: insertAtFirst(int data)
{
    node *n = new node ;
    n -> item = data ;
    n-> prev = NULL ;
    if(start == NULL)
    {
        n -> next = NULL ;
        start = n ;
    }
    else
    {
        n -> next = start ;
        start = n ;
    }
}
void DLL :: insertAfter(int value, int data )
{
    node *t = start ;
    while(t)
    {
        if(t -> item == value)
            break ;
        t = t -> next ;
    }
    if(t == NULL)
        cout << "\n Value " << value << " not found in list " ;
    else 
    {
        node *n = new node ;
        n -> item = data ;
        if(t->next == NULL)
        {
            n->prev = NULL ;
            n->next = NULL ;
            t->next = n ;
        }
        else
        {
            n -> prev = t ;
            n -> next = t -> next ;
            t ->next->prev = n ;
            t -> next = n ; 
        }
    } 
}
void DLL :: deleteFirst()
{
    if(start == NULL)
        cout << "\n Empty list" ;
    else
    {
        node *t = start ;
        if(start -> next == NULL)
            start == NULL ;
        else
        {
            start = t-> next ;
            start -> prev = NULL ;
        }
        delete t ;
    }
}
void DLL :: deleteLast()
{
    node *t = start ;
    if(start == NULL)
        cout << "\n Empty List" ;
    else
    {
        if(start-> next == NULL)
            start = NULL ;
        else
        {
            while(t-> next != NULL)
                t = t-> next ;
            t->prev->next = NULL ;
        }        
        delete t ;
    }
}
void DLL :: deleteNode(int value)
{
    node *t =start ;
    if(t == NULL)
        cout << "\n Empty list" ;
    else
    {
        while(t)
        {
            if(t->item == value)
                break ;
            t = t->next ;
        }
        if(t == NULL)
            cout << "\n Value " << value << " not found in list " ;
        else
        {
            if(t->next == NULL)
            {
                if(t == start)
                    start = NULL ;
                else
                    t->prev->next = NULL ;
            }
            else
            {
                t->prev->next = t->next ;
                t->next->prev = t->prev ;
            }
            delete t;
        }
    }
}
void DLL :: viewList()
{
    node *temp = start ;
    while(temp)
    {
        cout << temp -> item << "\t" ;
        temp = temp -> next ;
    }
}
void DLL :: search(int data)
{
    if(start == NULL)
        cout << "\n Empty list " ;
    else
    {
        node *t = start;
        while(t)
        {
            if(t->item == data)
                break ;
            t= t->next ;
        }
        if(t == NULL)
        { 
             cout << "\n Value " << data <<" not found in list\n" ;
        }
        else
        {
            cout << "\n Value " << data <<" found in list\n" ;
        } 
    }
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
    cout << "\n 7. Search a data" ;
    cout << "\n 8. Exit" ;
    cout << "\n Enter your choice : " ;
    cin >> choice ;
    return choice ;
}
int main()
{
    int index, data ;
    DLL list1;
    
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
        case 7 :
                cout << "\n Enter data to search ";
                cin >> data ;
                list1.search(data) ;
                break ;
        case 8:         exit(0) ;
        default:
                cout << "\n Invalid input : " ;
            
        }
    }
return 0;
}