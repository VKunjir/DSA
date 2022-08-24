#include<iostream>
using namespace std ;

class CLL
{
    struct node{
        node *next ;
        int item ;
    };
    node *last ;
public :
    CLL()
    { last = NULL ;  }
    void viewList() ;
    void insertAtLast(int data) ;
    void insertAtFirst(int data) ;
    void insertAfter(int value, int data) ;
    void deleteLast() ;
    void deleteFirst() ;
    void deleteNode(int value) ;
    int search(int data) ;
    ~CLL()
    {
        while(last) 
        {
            deleteFirst() ;
        }
    }
    
};
void CLL :: insertAtLast(int data)
{
    node *n = new node ;
    n->item = data ;
    if(last == NULL)
    {
        n->next = n ;
    }
    else{
        n->next = last->next ;
        last->next = n;
    }
    last = n ;
}
// insert at first
void CLL :: insertAtFirst(int data)
{
    node *n = new node ;
    n->item = data ;
    if(last == NULL)
    {
        n->next = n ;
        last = n ;
    }
    else
    {
        n->next = last-> next ;
        last ->next = n ;
    }
}
// insert after a node
void CLL :: insertAfter(int value, int data)
{
    node *n, *t ;
    n = new node ;
    n-> item = data ;
    if(last == NULL){
        cout << "\n Empty list" ;
        delete n;}
    else
    {
        if(last->item == value)
        {
            n->next = last -> next ;
            last->next = n ;
            last = n ;
        }
        else
        {
            t = last ;
            while(t-> next != last)
            {
                t = t-> next ;
                if(t->item == value)
                {
                    n->next = t->next ;
                    t-> next = n ;
                    break;
                }
            }
        }
    }
}
// delete at last
void CLL :: deleteLast()
{
    node *t ;
    if(last != NULL)
    {
        t = last ;
        if(t -> next == last)
        {
            delete t ;
            last = NULL ;
        }
        else
        { 
            while(t->next != last)
                t = t-> next ;
            t->next = last-> next ;
            delete last ;
            last = t ;
        }
    }
    else
        cout << "\n " ;
}
// delete at first
void CLL:: deleteFirst()
{
    node *t  ;
    if(last)
    {
        if(last->next == last)
        {
            delete last ;
            last = NULL ;
        }
        else
        {
            t = last -> next ;
            last->next = t->next ;
            delete t ;
        }
    }
    else
        cout << "\n" ;
}
void CLL:: deleteNode(int value)
{
    if(last != NULL)
    {
        node *t1, *t2 ;
        t1 = last ;
        t2 = NULL ;
        if(t1->next == last)
        {
            if(t1->item == value)
            {
                delete last ;
                last = NULL ;
            }
            else{
                cout << "\n Value not found " ;
            }
        }
        else
        {
            while(t1->next != last)
            {
                if(t1->item == value)
                {   break;   }
                t2=t1;
                t1=t1->next;
            }
            if(t1 == last )
                cout << "\n Value not found " ;
            else
            {
                if(last->item == value)
                {
                    t2 = last ;
                    while(t2->next != last)
                        t2 = t2->next ;
                    t2 -> next = t1->next ;
                    delete t1 ;
                }
                else
                {
                    t2 -> next = t1->next ;
                    delete t1 ; 
                }
            }
        }
    }
    else
    {
        cout << "\nEmpty list" ;
    }
}
void CLL::viewList()
{
    if(last==NULL)
    {   cout<<"\nEmpty list";   }
    else
    {
        node *t;
        t=last->next;
        while(t!=last)
        {
            cout<<t->item<<"\t";
            t=t->next;
        }
        cout<<t->item<<endl;
    }
}
// search a element
int CLL :: search(int data)
{
    if(last)
    {
        node *t = last ;
        if(t->next == last)
        {
            if(t->item == data)
                return 1;
            else
                return -1;
        }
        else
        {
            while(t != last)
            {
                if(t->item == data)
                    return 1;
                t = t->next ;
            }
            return -1 ;
        }
    }
    else
    {
        cout << "\nEmpty list" ;
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
    CLL list1;
    
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