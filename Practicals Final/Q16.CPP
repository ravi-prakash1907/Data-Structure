#include<iostream.h>
#include <conio.h>
#define max 10
class mystack
{
	int st[max];
	int st2[max];
	int top;
	public:
		mystack()
		{
			top=-1;
		}

	void push()
	{
		int x;
		cout<<"enter element x\n";
		cin>>x;
		if(top==max-1)
		{
			cout<<"can't insert\n";
		}
		else
		{
			top++;
			st[top]=x;
		}
	}

	int pop()
	{
		int t;
		if(top==-1)
		{
			cout<<"stack is empty\n";
			return 0;
		}
		else
		{
			t=st[top];
			top--;
			return t;
		}
	}

	void clear()
	{
		while(top!=-1)
		{
			pop();
		}
		cout<<"empty stack\n";
	}

	void display()
	{
		cout<<"Stack is:"<<endl;
		for(int i=0;i<=top;i++)	{
			cout<<st[i]<<" ";
		}
	}
	void reverse()
	{
		int toptop=top;
		for(int i=0;i<=toptop;i++)
		{
			st2[i]=pop();
		}
		cout<<"reversed stack: "<<endl;
		for(i=0;i<=toptop;i++)
		{
			cout<<st2[i]<<" ";
		}
	}
};
int main()
{
	clrscr();
	char ch;
	int choice;
	mystack s1;
		cout<<endl<<"Operations on stack"<<endl<<endl;
		cout<<"1.pushing a element\n";
		cout<<"2.popping the element\n";
		cout<<"3.clear the stack\n";
		cout<<"4.reverse stack\n";
		do{
		cout<<"enter the choice: ";
		cin>>choice;
		switch(choice)
		{	case 1:
			s1.push();
			s1.display();
			break;
			case 2:
			s1.pop();
			break;
			case 3:
			s1.clear();
			s1.display();
			break;
			case 4:
			s1.reverse();
			break;
			default:
			cout<<"wrong choice";
		}
		cout<<"\ndo you want to enter more operations\n";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
return 0;
}
