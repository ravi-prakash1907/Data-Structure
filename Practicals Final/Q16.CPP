#include<iostream.h>
#include<conio.h>

#define MAX 20
class  stack
{
	int top, rear, arr[MAX], size;

public:
	 stack(int s=MAX)
	 {
	 	size = s;
	 	top = rear = -1;
	 }

	 int sizeCurr()
	 {
	   return (top+1);
	 }

	 void push(int);
	 int pop();
	 void display();

};

void stack::push(int x)
{
	clrscr();
	if(top == size-1)
	{
		cout<<"\nStack Overflow!";
		getch();
		return;
	}
	else
	{
		arr[++top] = x;
		//cout<<"\nInserted "<<arr[top]<<endl;
		//getch();
	}
}

int stack::pop()
{
  int x;
	clrscr();
	if(top == -1)
	{
		cout<<"\nStack Underflow!";
		getch();
		return -1;
	}
	else
	{
		x = arr[top--];
		return x;
	}
}

void stack::display()
{
	clrscr();
	if(top == -1)
	{
		cout<<"\nStack Underflow!";
		getch();
		return;
	}
	else
	{
		cout<<"\n\nStack is: \n\n";
		for(int i=0; i<=top; i++)
			cout<<arr[i]<<"   ";
		cout<<"\t <- TOP";
	}
	getch();
}

///////////////////////////////////////////////

void reverse(stack &S, int n)
{
  clrscr();
    int i, j;
    stack S1(n);
    stack S2(n);
     for(i=0; i<n; i++)
       S1.push(S.pop());

     for(i=0; i<n; i++)
       S2.push(S1.pop());

     for(i=0; i<n; i++)
       S.push(S2.pop());

	cout<<"Reversed!!";
	getch();
};

///////////////////////////////////////////////

void main()
{
   int i, j, size, data, choice;
   char c;

//   here:
   clrscr();
    cout<<"\nEnter the size of stack: ";
    cin>>size;

    stack S(size);
      here:
	clrscr();
	  cout<<"\nMENU:- \n"
	      <<"\n1) Push"
	      <<"\n2) Reverse"
	      <<"\n3) Display\n\n";
	  cin>>choice;
	switch(choice)
	{
		case 1:  clrscr();
				 cout<<"\nEnter data: ";
				 cin>>data;
				 S.push(data);
				 break;

		case 2:  clrscr();
				 reverse(S, S.sizeCurr());
				 break;

		case 3:  clrscr();
				 S.display();
				 break;

		default: "\nInvalid input!!";
	}


	clrscr();
		cout<<"\nWanna try again?(Y/N)";
		cin>>c;

		if(c=='y' || c=='Y')
			goto here;

}
