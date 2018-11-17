#include<iostream.h>
#include<conio.h>

int fab1(int n)
{
 if(n==1)
 {
    return 1;
 }
 if(n==0)
 {
    return 0;
 }
 else
 {
    return(fab1(n-1)+fab1(n-2));
 }
}

void fab2(int n)
{
 int a=1,b=1,c=1;
 for(int i=3;i<n;i++)
 {
   c=a+b;
   a=b;
   b=c;
   cout<<c<<"  ";
 }
}

void main()
{

    int i=0,n,ch,temp;
  here:
  clrscr();
    cout<<"Choose:-\n\n"
	<<"\n1) Recursion"
	<<"\n2) Iteration\n";
    cin>>ch;
   clrscr();
    cout<<"Enter no of terms: ";
    cin>>n;
    if(ch==1)
    {
      cout<<"\nFebonaki series is as follows (recursion):-\n";
      while(i<n)
      {
	cout<<fab1(i)<<"  ";
	i++;
      }
    }

    if(ch==2)
    {
       cout<<"\nFebonaki series is as follows (iteration):-\n";
       if(n==1)
	 cout<<"0";
       if(n==2)
	 cout<<"0  1";
       if(n==3)
	 cout<<"0  1  1";
       if(n>3)
       {
	 cout<<"0  1  1  ";
	 fab2(n);
       }
    }

  cout<<"\n\nEnter 1 to enter again, 2 to exit.";
  cin>>ch;

  if(ch==1)
  goto here;
}
