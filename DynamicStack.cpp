// Implementation of Stack using Linked List ( Dynamic Implementation )
#include <iostream>
#include <string>
using namespace std;
class Node                      // class Node to creat data members of Nodes
{
    public:
    int data;        // Data member as an Integer
    Node* next;      // Data member as a pointer 
    public:
    Node(int val)       // Parametrized Constructor
    {
        data = val;
        next = NULL;
    }
};
class Stack        // Class Stack to perform Stack Implementation ( Last-In First-Out )
{
    public:
    Node* top;    // Data member as Top Node pointer
    Stack ()              // Parametrized Constructor
    {
        top = NULL;
    }
    void Push(int val)   // Adding Node to Stack from the Top Node pointer only.. O(1) time
    {
        Node* n = new Node(val);
        if(top == NULL)             // If Stack is Empty
        {
            top = n;       // New Node created becomes the Top Node
            return;        // Control moves out of the function
        }
        n -> next = top;     // The New Node becomes the top pointer ( LIFO ) 
        top = n;
    }
    public:
    void Pop()      // Removing Node from Stack is also done by Top pointer only.. O(1) time
    {
        if(top == NULL)   // If Stack is Empty then nothing can be popped out
        {
            cout << "Nothing can be popped out from the Stack right now !!" << endl;
            return;
        }
        Node* temp = top;      // Temporary Node created as Top pointer
        top = temp -> next;    // Top value shifted to the second Node
        delete temp;                     // Temporary Node deleted
    }
    public:
    void DisplayStack()   // Displaying all Nodes of Stack.. O(n) time
    {
        Node* temp = top;
        int iter = 1;             // Counter variable
        if(temp -> next == NULL)         // If there is only one Node in Stack
        {
            cout << temp -> data << " ---> Top" << endl;
            return;          // Control moving out of the function
        }
        for( ; temp -> next != NULL; temp = temp -> next, iter++)
        {
            if(iter == 1)          // Conditional statement for proper printing of Nodes
                cout << temp -> data << " ---> Top" << endl;
            if(iter != 1)          // Conditional statement for proper printing of Nodes
            {
                cout << "^" << endl;
                cout << temp -> data << endl;
            }
        }
        cout << "^" << endl;
        cout << temp -> data << " ---> Base" << endl;
    }
    public:
    void Peek()     // Peeking into the value corresponding to the Top pointer.. O(1) time
    {
        if(top == NULL)       // If Stack is empty then Nothing to peek inside
        {
            cout << "The Stack is Empty, so Nothing to peek into the Stack !!" << endl;
            return;
        }
        cout << "The Data of Node corresponding to the Top Pointer is : " << top -> data << endl;
    }
    public:
    void IsStackEmpty()    // Checking if Stack is Empty by top pointer.. O(1) time
    {
        if(top == NULL)
        {
            cout << "The Stack is Empty !!" << endl;
            return;
        }
        cout << "The Stack is not Empty !!" << endl;
    }
    public:
    void SizeOfStack()    // Evaluating Size of Stack by top pointer.. O(n) time
    {
        Node* temp = top;
        int iter = 0;
        for( ; temp -> next != NULL; temp = temp -> next, iter++);   // Traversing loop
        cout << "The Size of the Stack currently is : " << iter+1 << endl;
    }
};
int main()
{
    Stack stack;     // Object creation of Stack Data Type
    int s, x;
    cout << "Enter the number of Opeartions to be performed on Stack Data Structure : ";
    cin >> s;
    string str;    // String value by preprocessor directives
    for(int i = 1; i <= s; i++)
    {
        cout << "Write Push to Push Node, Pop to remove Node, Size to get Size, P to Peek into Top Pointer and Empty to check Empty Stack : ";
        cin >> str;
        if(str == "Push" || str == "PUSH" || str == "push")
        {
            cout << "Enter Node data to add to the Stack : ";
            cin >> x;
            stack.Push(x);            // Calling push function
            stack.DisplayStack();
        }
        if(str == "Pop" || str == "POP" || str == "pop")
        {
            stack.Pop();
            if(stack.top != NULL)           // If Stack is not Empty
                stack.DisplayStack();
            if(stack.top == NULL)           // Condition of Stack Underflow if Stack is Empty
                cout << "STACK UNDERFLOW !!" << endl;
        }
        if(str == "P" || str == "p")
            stack.Peek();
        if(str == "Empty" || str == "EMPTY" || str == "empty")
            stack.IsStackEmpty();
        if(str == "Size" || str == "SIZE" || str == "size")
            stack.SizeOfStack();
        cout << "The Total number of Operations performed so far are : " << i << endl;
    }
    return 0;  // End of the Program
}