#include<iostream>
using namespace std ;

class DCLL
{
    private: 
            struct node
            {
                int item ;
                node *prev, *next ;
            };
            node *start ;
    public:
            DCLL()
            {   start= NULL ;         }
            void insertAtFirst(int data) ;
            void insertAtLast(int data) ;
            void insertAfter(int value, int data) ;
            void deleteFirst() ;
            void deleteLast() ;
            void deleteNode(int value) ;
            int search(int data) ;
            void viewList() ;
            ~DCLL()
            {
                while(start)
                    deleteFirst() ;
            }
};
void DCLL :: insertAtFirst(int data) 
{
    node *n = new node ;
    n->item = data ;
    if(start == NULL)
    {
        n->next = n ;
        n->prev = n ;
        start = n ;
    }
    else
    {
        if(start->next == start)
        {
            n->prev = start ;
            n->next = start ;
            start->prev = n ;
            start->next = n ;
        }
        else
        {
                start->prev->next = n ;
                n->prev = start->prev ;
                n->next = start ;
                start->prev = n ;
        }
        start = n;
    }
}
void DCLL :: insertAtLast(int data)
{
    node *n = new node ;
    n->item = data ;
    if(start == NULL)
    {
        n->prev = n ;
        n->next = n ;
        start = n ;
    }
    else
    {
        if(start->prev == start)
        {
            n->prev = start ;
            start->next = n ;
            n->next = start ;
            start->prev = n ;
        }
        else
        {
            n->prev = start->prev ;
            start->prev->next = n ;
            n->next = start ;
            start->prev = n ;
        }
    }
}
void DCLL :: insertAfter(int value, int data)
{
    if(start)
    {
        node *n = new node ;
        n->item = data ;
        node *t = start->next ;
        if(start->next == start)
        {
            if(start->item == value)
            {
                n->prev = start ;
                start->next = n ;
                n->next = start ;
                start->prev = n ;
            }
            else{
                cout << "\nValue " << value << " not found" ;
                delete n ;
            }
        }
        else
        {
            while(t->next != start)
            {
                if(t->item == value)
                    break ;
                t=t->next ;
            }
            if(t->item == value)
            {
                n->next->prev = n;
                n->next = t->next ;
                t->next = n ;
                n->prev = t ;
            }
            else
            {
                cout << "\nValue " << value << " not found" ;
                delete n ;
            }
        }
    }
    else
    {
        cout <<"\nUnderfollow" ;
    }
}
void DCLL :: deleteFirst()
{
    if(start)
    {
        if(start->next == start)
        {
            delete start ;
            start = NULL ;
        }
        else
        {
            node *t = start->next  ;
            start->next->prev = start->prev ;
            start->prev->next = start->next ;
            delete start ;
            start = t ;
        }
    }
    else
        cout << "\n Empty list" ;
}
void DCLL :: deleteLast()
{
    if(start)
    {
        if(start->next == start)
        {
            delete start ;
            start = NULL ;
        }
        else
        {
            node *t = start->prev ;
            t->prev->next = start ;
            start->prev = t->prev ;
            delete t ;
        }
    }
    else
    {
        cout << "\nEmpty list " ;
    }
}
void DCLL :: deleteNode(int value)
{
    if(start)
    {
        if(start->next == start)
        {
            if(start->item == value)
            {
                delete start ;
                start  = NULL ;
            }
            else
            {
                cout << "\nValue " << value << " not found" ;
            }
        }
        else
        {
            node *t = start->next ;
            while(t != start)
            {
                if(t->item == value)
                    break ;
                t=t->next;
            }
            if(t->item == value)
            {
                t->prev->next = t->next ;
                t->next->prev = t->prev ;
                delete t ;
            }
            else
            {
                cout << "\nValue " << value << " not found" ;
            }
        }
    }
    else
    {
        cout << "\nUnderfollow" ;
    }
}
int DCLL :: search(int data)
{
    if(start)
    {
        if(start->next == start)
        {
            if(start->item == data)
                return 1;
            else
                return -1 ;
        }
        else
        {
            node *t =start->next ;
            while(t != start)
            {
                if(t->item == data)
                    return 1;
                t= t->next ;
            }
            if(t->item == data)
                return 1 ;
            else 
                return -1 ;
        }
        
    }
    else
        return -1;
}
void DCLL :: viewList()
{
    if(start)
    {
        node *t = start->next ;
        cout << start->item << " " ;
        while(t != start)
        {
            cout << t->item << " " ;
            t = t->next ;
        }
        cout << endl ;
    }
    else
        cout << "\n Empty list" ;
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
    DCLL list1;
    
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
                cout << "\n Enter value to delete  Node : " ;
                cin >> data ;
                list1.deleteNode(data) ;
                break ;
        case 7 :
                cout << "\n Enter data to search ";
                cin >> data ;
                int temp ;
                temp = list1.search(data) ;
                if(temp == 1)
                    cout << "Value "<< data << " found in list " ;
                else   
                    cout << "Value "<< data << " not found in list " ;
                break ;
        case 8:         exit(0) ;
        default:
                cout << "\n Invalid input : " ;
            
        }
    }
return 0;
}