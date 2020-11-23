#include<iostream>
using namespace std;
struct stack 
{
	int size;
	int top;
	int *s;
};
void push(struct stack *st,int x)
{  
    if(st->top==st->size-1)
    { cout<<"stack overflow"<<endl;
	}
	else
	{st->top++;
	 st->s[st->top]=x;
    }
}
void display(struct stack st)
{   cout<<"stack elements: "<<endl;
	for(int i=st.top;i>=0;i--)
	{ 
	cout<<st.s[i]<<endl;}
}
int pop(struct stack *st)
{   int x=-1;
    if(st->top==-1)
    cout<<"stack underflow"<<endl;
    else
  { x=st->s[st->top];
    st->top--;}
    return x;
}
int isfull(struct stack st)
{
	if(st.top==st.size-1)
	return 1;
	else
	return 0;
}
int isempty(struct stack st)
{ 
	if(st.top==-1)
	return 1;
	else
	return 0;
}
int peek(struct stack st,int pos)
{
	if(st.top-pos+1<0)
	cout<<"invalid position"<<endl;
	else
	return 
	st.top-pos+1;
}
int stacktop(struct stack st)
{
	if(st.top==-1)
	return -1;
	else
	return st.s[st.top];
}
int main()
{ struct stack st;
  st.size=5;
  st.s=new int[st.size];
  st.top=-1;	
  push(&st,1);
  push(&st,2);
  push(&st,3);
  push(&st,4);
  push(&st,5);
  display(st);
  cout<<"pop element:"<<pop(&st)<<endl;
  display(st);
  cout<<"isfull?"<<isfull(st)<<endl;
  cout<<"isempty?"<<isempty(st)<<endl;
  cout<<"index:"<<peek(st,3)<<endl;
  cout<<"stacktop:"<<stacktop(st)<<endl;
  return 0;
}
