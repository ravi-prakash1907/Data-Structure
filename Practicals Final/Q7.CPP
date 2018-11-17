/* Stack using array */

#include<iostream.h>
#include<conio.h> 
  
class Stack
{
    int top;
  public:
	int size;
    int a[20];

    Stack()  { top = -1; }
    void push(int x);
    void pop();
    void Display();
};

void Stack::push(int x)
{
    if (top >= (size-1))
    {
	cout << "Stack Overflow";
    }
    else
    {
	a[++top] = x;
	cout<<x <<"Pushed\n";
    }
}

void Stack::pop()
{
    if (top < 0)
    {
	cout << "Stack Underflow";
	return;
    }
    else
    {
	int x = a[top--];
	cout<<"\nPopped: "<<x;
    }
}

void Stack::Display()
{
    if (top < 0)
    {
	cout << "Stack Underflow";
	return;
    }
    cout<<"\nStack is:\n\n";
    for(int i=top; i>=0; i--)
	cout<<a[i]<<endl;
}

///////////////////////////////////////

void main()
{
  clrscr();
    Stack s;
    int x, choice;
    char ch;
    cout<<"Enter size of stack: ";
    cin>>s.size;

    here:
	clrscr();
	  cout<<"\nMENU:- \n"
	      <<"\n1) Push"
	      <<"\n2) Pop"
	      <<"\n3) Display\n\n";
	  cin>>choice;
	switch(choice)
	{
		case 1:  clrscr();
				 cout<<"\nEnter data: ";
				 cin>>x;
				 s.push(x);
				 break;

		case 2:  clrscr();
				 s.pop();
				 break;

		case 3:  clrscr();
				 s.Display();
				 break;

		default: "\nInvalid input!!";
	}

  cout<<"\n\nWanna try again??"
      <<"\nHit 'Y', else any other key: ";
  cin>>ch;

  if(ch == 'y' || ch == 'Y')
    goto here;

}