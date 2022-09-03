#include<iostream>
#include<string.h>
#include<math.h>
using namespace std ;

class Stack
{
            int top , capacity;
            char *ptr ;
    public :
            Stack(int cap)
            {
                capacity = cap ;
                ptr = new char[cap] ;
                top = -1 ;
            }
            void push(char data) ;
            void pop() ;
            char peek() ;
            void viewStack() ;
            ~Stack()
            {
                delete ptr ;
            }
};
void Stack :: push(char data)
{
    if( top < capacity )
    {
        top++ ;
        ptr[top] = data ;
    }
    else
        cout << "\nStack overflow" ;
}
void Stack :: pop()
{
    if(top > -1)
    {
        top-- ;
    }
    else
    {
        cout << "Stack is Empty " ;
    }
}
char Stack :: peek()
{
    if(top > -1)
    {
        return(ptr[top]) ;
    }
    else
    {
        return ('\0') ;
    }
}
int Priority(char data) 
{
    if(data == '(')
        return 1 ;
    else if(data == ')')
        return 2 ;
    else if(data == '^')
        return 3 ;
    else if(data == '/' || data == '*')
        return 4 ;
    else if(data == '+' || data == '-') 
        return 5 ;
    else 
        return 6 ;
}
int main()
{
    Stack s(20), st(20) ;
    s.push('(') ;
    string Q,P ;
    string :: iterator it ;
    int temp;
    cout << "\nEnter a Infix Expression : " ;
    cin >> Q ;
    Q.push_back(')') ;
    it= Q.begin() ;
    
    while(it != Q.end())
    {
        switch(Priority(*it))
        {
            case 1:
                    s.push(*it) ;
                    break ;
            case 2:
                    while(Priority(s.peek()) != 1)
                    {
                        P.push_back(s.peek()) ;
                        s.pop() ;
                    }
                    s.pop() ;
                    break ;
            case 3:
                    while(Priority(s.peek()) == 3)
                    {
                        P.push_back(s.peek()) ;
                        s.pop() ;
                    }
                    s.push(*it) ;
                    break ;
            case 4:
                   temp = Priority(s.peek()) ;
                   while(temp >= 3 && temp <= 4)
                    {
                        P.push_back(s.peek()) ;
                        s.pop() ;
                        temp = Priority(s.peek()) ;
                    } 
                    s.push(*it) ;
                    break ;
            case 5:
                    temp = Priority(s.peek()) ;
                   while(temp >= 3 && temp <= 5)
                    {
                        P.push_back(s.peek()) ;
                        s.pop() ;
                        temp = Priority(s.peek()) ;
                    } 
                    s.push(*it) ;
                    break ;
            case 6 :
                    P.push_back(*it) ;
                    break ;
            default :
                    cout << "\nSomething went wrong!!!, I am exiting" ;
                    exit(0) ;
        }
        it++ ;
    }
    cout << "\nRequires Postfix Expresion is : " ;
    for(it= P.begin(); it != P.end(); it++)
    {
        cout << *it << " " ;
    }
    cout << endl ;
    int VALUE, x, y ;
    P.push_back(')') ;
    it = P.begin() ;
    while(*it != ')')
    {
        switch(Priority(*it))
        {
            case 3:
                    x = st.peek() - '0' ;
                    cout << "X = " << x << endl ;
                    st.pop() ;
                    y = st.peek() - '0' ;
                    cout << "Y = " << y << endl ;
                    st.pop() ;
                    temp = pow(y,x) ;
                    st.push(temp) ;
                    cout << "Peek = " << (int)st.peek() << endl ;
                    break ;
            case 4:
                    x = st.peek() - '0' ;
                    cout << "X = " << x << endl ;
                    st.pop() ;
                    y = st.peek() - '0' ;
                    cout << "Y = " << y << endl ;
                    st.pop() ;
                    if(*it == '/')
                        temp = y/x ;
                    else
                        temp = y*x ;
                    st.push(temp) ;
                    cout << "Peek = " << (int)st.peek() << endl ;
                    break ;
            case 5:
                    x = st.peek() - '0' ;
                    cout << "X = " << x << endl ;
                    st.pop() ;
                    y = st.peek() - '0' ;
                    cout << "Y = " << y << endl ;
                    st.pop() ;
                    if(*it == '+')
                        temp = y+x ;
                    else
                        temp = y-x ;
                    st.push(temp) ;
                    cout << "Peek = " << (int)st.peek() << endl ;
                    break;
            case 6:
                    st.push(*it) ;
                    break ;
            default:
                    cout << "\nSomething went wrong!!, I am exiting " ;
                    exit(0) ;
        }
        it++ ;
    }
    VALUE = (int)st.peek() ;
    cout << "Final value of the expression is " << VALUE << endl ;
    return 0 ;
}









/*float VALUE, X, Y, tp ; 
    P.push_back(')') ;
    it = P.begin() ;
    while(*it != ')')
    {
        switch(Priority(*it))
        {
            case 3:
                    X = (float)s1.peek() ;
                    s1.pop() ;
                    Y = (float)s1.peek() ;
                    s1.pop() ;
                    tp = pow(Y,X) ;
                    s1.push((char)tp) ;
                    break ;
            case 4:
                    X = (float)(s1.peek() - '0') ;
                    cout << "X = " << X << endl ;
                    s1.pop() ;
                    Y = (float)(s1.peek() - '0') ;
                    cout << "Y = " << Y << endl ;
                    s1.pop() ;
                    if(*it == '/')
                    {
                        tp = Y/X ;
                    }
                    else
                    {
                        tp = Y*X ;
                    }
                    s1.push((char)tp) ;
                    break ;
            case 5:
                    X = (float)(s1.peek() - '0') ;
                    cout << "X = " << X << endl ;
                    s1.pop() ;
                    Y = (float)(s1.peek() - '0') ;
                    cout << "Y = " << Y << endl ;
                    s1.pop() ;
                    if(*it == '+')
                    {
                        tp = Y+X ;
                    }
                    else
                    {
                        tp = Y-X ;
                    }
                    s1.push((char)tp) ;
                    break ;
            case 6:
                    s1.push(*it) ;
                    break ;
            default :
                    cout << "\nSomething went wrong!!, I am exiting " ;  
                    exit(0) ;
        }
        it++ ;
    }
    VALUE = s1.peek() ;
    cout << "\nValue of Postfix expression is : " << VALUE << endl ;*/
