#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
class queue
{
    private:
    node*front;
    node*rear;
    public:
    queue()
    {
        front=NULL;
        rear=NULL;
    }
    int empty()
    {
        if(front==NULL)
        return(1);
        else
        return(0);
    }
    void enqueue(int x)
    {
        node*p=new node(x);
        if(empty())
        {
            front=p;
            rear=p;
        }
        else
        {
            rear->next=p;
            rear=p;
        }
    }
    int dequeue()
    {
        int x=front->data;
        node*p=front;
        front=front->next;
        delete p;
        return(x);
    }
    int peek()
    {
        return(front->data);
    }
    void display()   
    {
        node*q=front;
        while(q!=NULL)
        {
            cout<<"\t"<<q->data;
            q=q->next;
        }
    }   
};
int main()
{
    queue q;
    int x;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    
    x=q.peek();
    cout<<"Top element is"<<x<<endl;
    x=q.dequeue();
    cout<<"Removed"<<x<<endl;
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    return 0;
}

/*PS D:\Piyush Hase> g++ queue_linked_list.cpp -o out
PS D:\Piyush Hase> ./out                           
        10      20      30Top element is10
Removed10
        20      30
*/