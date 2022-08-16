#include<iostream>
using namespace std ;

class LinkedList
{
    struct Node
    {
        int item ;
        Node *next ;
    };
    Node *start, *last ;
    public :
    int count ;
    void insertAtFirst(int data);
    void insertAtLast(int data) ;
    void insertAfter(int value, int data) ;
    void delFirst() ;
    void delLast() ;
    void delNode(int data) ;
    void viewItem() ;
    void search(int data);
    LinkedList()
    {
        count = 0;
        start = NULL ;
        last = NULL ;
    }
    ~LinkedList()
    {
        delete start ; 
        delete last ;
    }
    
};
// insert at last
void LinkedList:: insertAtLast(int data)
{
    if(start == NULL)
    {
        start = new Node ;
        start->item = data ;
        start->next = NULL;
        last = start ;  
        count += 1;      
    }
    else
    {
        Node *n = new Node;
        n -> item = data ;
        n -> next = NULL ;
        last -> next = n ;
        last = n ;
        count += 1;
    }
}
// insert at first
void LinkedList:: insertAtFirst(int data)
{
    if(start == NULL)
    {
        start = new Node ;
        start->item = data ;
        start->next = NULL;
        last = start ; 
        count += 1;       
    }
    else
    {
        Node *n = new Node ;
        n -> item = data ;
        n -> next = start ;
        start = n ;
        count += 1;
    }
}
// insert after node
void LinkedList:: insertAfter(int value, int data)
{
    int i;
    if(start == NULL)
    {
        cout << "\n Operation Failled: Empty list " ;
    }
    else 
    {
        Node *temp = start ;
        for(i=0 ; i < count; i++)
        {
            if(temp -> item == value)
            {
                Node *n = new Node ;
                n -> item = data ;
                n -> next = temp -> next ;
                temp -> next = n ;
                count += 1 ;
                break;
            }
            temp = temp -> next ;
        }
        if(i == count-1)
        {
            if(temp != last)
            {
                last = temp -> next ;
            }
        }
    }
}
void LinkedList:: delFirst()
{
    if(start == NULL)
    {
        cout << "\nOperation Failled: Empty list" ;
    }
    else
    {
        Node *temp ;
        temp = start ;
        start = temp -> next ;
        delete temp ;
        count-- ;
        if(start == NULL)
        {
            last= NULL ;
        }
    }
}
void LinkedList :: delLast()
{
    if(last == NULL)
    {
        cout << "\nOperation Failled: Empty list" ;
    }    
    else
    {
        if(start == last)
        {
            delete start;
            start = last = NULL ;
        }
        else
        {
            Node *temp ;
            temp = start ;
            for(int i =0; i< count-2; i++)
                temp = temp->next ;
            last = temp ;
            temp = temp-> next ;
            delete temp;
            count-- ;
        }
    }
}
void LinkedList :: delNode(int data)
{
    if(last == NULL)
    {
        cout << "\n Operation Failled: Empty list" ;
    }
    else
    {
        Node *temp1,*temp2 ;
        temp1 = start ;
        temp2 = NULL ;
        for(int i = 0; i < count ; i++)
        {
            if(temp1 -> item == data)
            {
                if(temp2 != NULL)
                    temp2 -> next = temp1 -> next ;
                delete temp1 ;
                count-- ;
                break ;
            }
            temp2 = temp1 ;
            temp1 = temp1->next ;
        }
        if(temp2 == NULL)
        {
            last = start = NULL ;
        }
    }
}
void LinkedList :: viewItem()
{
    if(start == NULL)
    {
        cout << "\n" ;
    }
    else
    {
        Node * temp ;
        temp = start ;
        for(int i = 0; i< count; i++)
        {
            cout << " " << temp->item ;
            temp = temp -> next ;
        }
    }
}
void LinkedList:: search(int data) 
{
    if(last == NULL)
    {
        cout << "\n Operation Failled: Empty list" ;
    }
    else
    {
        Node * temp ;
        temp = start ;
        for(int i = 0; i< count; i++)
        {
            if(temp -> item == data)
            {
                cout << "\n " << data << " is present in list " ;
                break ; 
            }
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
    cout << "\n 7. Exit" ;
    cout << "\n Enter your choice : " ;
    cin >> choice ;
    return choice ;
}
int main()
{
    int index, data ;
    LinkedList list1;
    
    while(true)
    {
        cout << "\nTotal number of element are : " << list1.count ;
        cout << "\n " ;
        list1.viewItem() ;
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
                list1.delFirst() ;
                break ;
        case 5:    
                list1.delLast(); 
                break ;
        case 6: 
                cout << "\n Enter data to delete  Node : " ;
                cin >> data ;
                list1.delNode(data) ;
                break ;
        case 7: 
                exit(0) ;
        default:
                cout << "\n Invalid input : " ;
            
        }
    }
return 0;
}