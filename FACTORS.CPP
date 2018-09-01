/*	FACTORS	*/
#include<iostream.h>
#include<conio.h>

void factors(int);

void main()
{
 clrscr();
  int num;
  cout<<"Enter the no.: ";
  cin>>num;
  factors(num);
 getch();
}

void factors(int x)
{
 int i;
 for(i=1;i<x;i++)
 {
  if(x%i==0)
    cout<<i<<endl;
 }
}