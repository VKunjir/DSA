#include<iostream>
using namespace std ;

class LinkedList
{
    int count ;
    struct Node
    {
        int item ;
        Node *next ;
    };
    Node *start, *last ;
    LinkedList()
    {
        count = 0;
        start = NULL ;
        last = NULL ;
    }
    public :
    void insertAtFirst(int data);
    void insertAtLast(int data) ;
    void insertAfter(int value, int data) ;
    void delFirst() ;
    void delLast() ;
    void delNode(int data) ;
    void viewItem() ;
    void search(int data);
    
};
// insert at last
void LinkedList:: insertAtLast(int data)
{
    if(last == NULL)
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
    if(last == NULL)
    {
        start = new Node ;
        start->item = data ;
        start->next = NULL;
        last = start ; 
        count += 1;       
    }
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
    if(start == NULL)
    {
        cout << "\n Operation Failled: Empty list " ;
    }
    else 
    {
        Node *temp = start ;
        for(int i=0 ; i < count; i++)
        {
            if(temp -> item == data)
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
            else
            {
                cout << "\nOperation Failled: Value not found" ;
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
        start = temp -> next
        delete temp ;
        if(start == NULL)
        {
            last= NULL
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
            {
                temp = temp->next ;
            }
            last = temp ;
            temp = temp-> next ;
            delete temp;
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
        cout << "\n Operation Failled: Empty list" ;
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
                count << "\n " << data << " is present in list " ;
                break ; 
            }
        }
    }
}