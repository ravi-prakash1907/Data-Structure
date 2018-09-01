#include<iostream.h>
#include<conio.h>

template <class T> class arr
{
  int a[5][5], i, j;

  public:
	 arr()
	 {
	   reset();
	 }

	 void getDataL();
	 void getDataU();
	 void getDataD();
	 void disp();
	 void reset();
};

template <class T>
void arr<T>::getDataL()
{
  cout<<"\n Enter the elements (non zero) of lower triangle, row wise: \n";
  for(i=0; i<5; i++)
     for(j=0; j<5; j++)
       if(i>j || i==j)
	  cin>>a[i][j];
}

template <class T>
void arr<T>::getDataU()
{
  cout<<"\n Enter the elements (non zero) of upper triangle, row wise: \n";
  for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			if(i<j || i==j)
				cin>>a[i][j];
}

template <class T>
void arr<T>::getDataD()
{
  cout<<"\n Enter the elements (non zero) of tri-diagonal, row wise: \n";
  for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			if(i==j-1 || i==j || i==j+1)
				cin>>a[i][j];
}

template <class T>
void arr<T>::disp()
{

  clrscr();
  cout<<"\n Matrix is: \n\n";
  for(i=0; i<5; i++)
  {
		  cout<<"\n\t";

		for(j=0; j<5; j++)
	{
			if(a[i][j] != 0)
				cout<<a[i][j]<<"   ";
			else
				cout<<"    ";
	}
  }
  reset();
}

template <class T>
void arr<T>::reset()
{
 for(i=0; i<5; i++)
    for(j=0; j<5; j++)
      a[i][j] = 0;
}

void main()
{
clrscr();
   int choice, x;

	arr<int> mat;
	char ch;


	  cout<<"\n\t THIS PROGRAM IMPLEMENTS SPARSE MATRICES USING AN ARRAY OF SIZE 5x5 ";
      cout<<"\n\t--------------------------------------------------------------------\n";
  here:
	clrscr();
	  cout<<"\nMENU:- \n"
	      <<"\n1) Lower Tringle Matrix / Triangular Matrix"
	      <<"\n2) Lower Tringle Matrix"
	      <<"\n3) Tri-diagonal Matrix\n\n";
	  cin>>choice;
	switch(choice)
	{
		case 1:  clrscr();
			 mat.getDataL();
			 getch();
			 mat.disp();
			 break;

		case 2:  clrscr();
			 mat.getDataU();
			 getch();
			 mat.disp();
			 break;

		case 3:  clrscr();
			 mat.getDataD();
			 getch();
			 mat.disp();
			 break;

		default: "\nInvalid input!!";
	}

  cout<<"\n\nWanna try again??"
      <<"\nHit 'Y', else any other key: ";
  cin>>ch;

  if(ch == 'y' || ch == 'Y')
    goto here;
}
