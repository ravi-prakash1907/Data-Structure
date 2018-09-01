#include<iostream.h>
#include<conio.h>

int fact1(int n)
{
 if(n>1)
 {
    return(n*fact1(n-1));
 }
 else
 {
    return 1;
 }
}

void fact2(int n)
{
  int m=1;
  for(int i=1;i<=n;i++)
    m*=i;
  cout<<m;
}

void main()
{
    int n,ch;
  here:
  clrscr();
    cout<<"Choose (to find factorial of no., using):-\n\n"
	<<"\n1) Recursion"
	<<"\n2) Iteration\n";
    cin>>ch;
   clrscr();
    cout<<"Enter no of terms: ";
    cin>>n;

   cout<<"\nFactorial: \n";
    if(ch==1)
    {
	cout<<fact1(n);
    }

    if(ch==2)
    {
       fact2(n);
    }

  cout<<"\n\nEnter 1 to enter again, 2 to exit.";
  cin>>ch;

  if(ch==1)
  goto here;
}
