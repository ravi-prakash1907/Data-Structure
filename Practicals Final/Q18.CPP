		/*	   WAP to implement Linear Search using templates	   */

#include<iostream.h>
#include<conio.h>

void main()
{
   int arr[20][20], size, i, j, dig[20];
   char c;

   here:
   clrscr();
    cout<<"\nEnter the size of symmetric matrics: ";
    cin>>size;

    cout<<"\nEnter the complete matrix: \n\n";
    for(i=0; i<size; i++)
	for(j=0; j<size; j++)
		cin>>arr[i][j];

    clrscr();
	cout<<"Your diagonal matrix is: \n\n";
    for(i=0; i<size; i++)
    {
	for(j=0; j<size; j++)
		cout<<arr[i][j]<<"\t";
	cout<<"\n";
    }

    for(i=0; i<size; i++)
	dig[i] = arr[i][i];

    cout<<"\n\nDigonaal in 1-D array is: ";
     for(i=0; i<size; i++)
	cout<<dig[i]<<"\t";

	getch();
	clrscr();
		cout<<"\nWanna try again?(Y/N)";
		cin>>c;

		if(c=='y' || c=='Y')
			goto here;

}