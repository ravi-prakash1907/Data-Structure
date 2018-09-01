#include<iostream.h>
#include<conio.h>

int gcd1(int a,int b)
{
 if(b==0)
 {
    return(a);
 }
 else
 {
    return gcd1(b,a%b);
 }
}

void gcd2(int a,int b)
{
  int i,m=1;
  if(a<b)
  {
    for(i=1;i<=a;i++)
    {
       if(a%i==0&&b%i==0)
	 m=i;
    }
  }
  else  if(a>b)
  {
    for(i=1;i<=b;i++)
    {
       if(a%i==0&&b%i==0)
	 m=i;
    }
  }
  else
    m=a;

  cout<<m;
}

void main()
{
    int a,b,ch;
  here:
  clrscr();
    cout<<"Choose (to find GCD of 2 nos., using):-\n\n"
	<<"\n1) Recursion"
	<<"\n2) Iteration\n";
    cin>>ch;
   clrscr();
    cout<<"Enter 2 nos. of terms: ";
    cin>>a>>b;

   cout<<"\nGCD is: \n";
    if(ch==1)
    {
	cout<<gcd1(a,b);
    }

    if(ch==2)
    {
       gcd2(a,b);
    }

  cout<<"\n\nEnter 1 to enter again, 2 to exit.";
  cin>>ch;

  if(ch==1)
  goto here;
}