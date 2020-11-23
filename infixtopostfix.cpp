#include<iostream>
#include<cstring>
using namespace std;

class node
{   public:
	char data;
	node *next;
};
class stack
{
	node *top;
	public:
		stack(){top=NULL;}
		void push(char x)
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
		{   char x=-1;
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
		void display()
		{  cout<<"stack:";
		   node *p=top;
		   while(p!=NULL)
		   {cout<<p->data<<" ";
		    p=p->next;}
		   cout<<endl;
		}
	  char* intopost(char *infix)
{     int i=0,j=0;
      char *postfix;
      int len=strlen(infix);
      postfix=new char[len+1];
      
	  while(infix[i]!='\0')
	  {
	  	if(isoperand(infix[i]))
	  	{
	  	 postfix[j++]=infix[i++];
		  }
		  else
		  {
		  	if(pre(infix[i])>pre(top->data))
		  	push(infix[i++]);
		  	else
		  	postfix[j++]=pop();
		  }
	  }
	  while(top!=NULL)
	  postfix[j++]=pop();
	  postfix[j]='\0';
	  return postfix;
}
int isoperand(char x)
{
	if(x=='+'||x=='-'||x=='*'||x=='/')
	return 0;
	else 
	return 1;
}
int pre(char x)
{
	if(x=='+'||x=='-')
	return 1;
	else if(x=='*'||x=='/')
	return 2;
	return 0;
}
};

 int main()
 {
 	stack stk;
 	stk.push('#');
 	stk.display();
 	char*infix="a+b*c-d/e";
 	char*postfix=stk.intopost(infix);
 	cout<<"postfix of the given expression is: "<<postfix<<endl;
	 		
 	return 0;
 }

