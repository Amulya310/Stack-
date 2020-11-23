#include<iostream>
using namespace std;

class node
{   public:
	int data;
	node *next;
};
class stack
{
	node *top;
	public:
		stack(){top=NULL;}
		void push(int x)
		{   node *t=new node;
			if(t==NULL)
			cout<<"stack overflow!!!"<<endl;
			else
			{
				t->data=x;
				t->next=top;
				top=t;
			}
		}
		int pop()
		{   int x=-1;
			if(top==NULL)
			cout<<"stack is empty!!!"<<endl;
			else
			{
			  node *p=top;
			  x=top->data;
			  top=top->next;
			  delete(p);	
			}
			return x;
		}
		int stacktop();
		void peek(int x);
		
		void display()
		{  cout<<"stack:";
		   node *p=top;
		   while(p!=NULL)
		   {cout<<p->data<<" ";
		    p=p->next;}
		   cout<<endl;
		}
};
int stack::stacktop()
{
	if(top)
	return top->data;
	else
	return -1;
	
}
void stack::peek(int x)
{
	node *p=top;
	int i;
	for(i=0;p!=NULL&&i<x-1;i++)
	p=p->next;
	cout<<p->data;
 } 
 int main()
 {
 	stack stk;
 	stk.push(10);
 	stk.push(20);
 	stk.push(30);
    stk.push(40);
 	stk.display();
 	cout<<"pop element: "<<stk.pop()<<endl;
 	stk.display();
 	cout<<"element at top: "<<stk.stacktop()<<endl;
 	cout<<"element at asked position: ";
	stk.peek(3);	
	 		
 	return 0;
 }

