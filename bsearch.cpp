

	#include<iostream>
	using namespace std;

	int AR[100];
	int bsearch(int N, int VAL);
	void sort(int n);
	void accept(int n);
	int main()
	{
		int n,val;
		int found;
	
		cout<<"Enter number of elements you want to insert ";
		cin>>n;
		accept(n);

		sort(n);

		cout<<"\nEnter the number you want to search ";
		cin>>val;

		found=bsearch(n,val);

		if(found!=0)
			cout<<"\nItem found at: "<<found+1<<" position\n";
		else
			cout<<"\nItem not found";
	
		return 0;
	}

	void accept(int n)
	{

		cout<<"Enter elements\n";
		for(int i=0;i<n;i++)
		{
			cout<<"Enter element: "<<i+1<<":";
			cin>>AR[i];
		}
	}

	int bsearch(int N, int VAL)
	{
		int Mid,Lbound=0,Ubound=N-1;
		while(Lbound<=Ubound)
		{
			Mid=(Lbound+Ubound)/2;
			if(VAL>AR[Mid])
				Lbound=Mid+1;
			else if(VAL<AR[Mid])
				Ubound=Mid-1;
			else
				return Mid;
		}
		return 0;
	}


	void sort(int n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{		
				if(AR[j]>AR[j+1])
				{
					int temp=AR[j];
					AR[j]=AR[j+1];
					AR[j+1]=temp;
				}
			}
		}

		cout<<"Sorted array is:";
		for(int i=0;i<n;i++)
		{
			cout<<AR[i]<<"  ";
		}
	}

	/*
	[ccoew@localhost ~]$ g++ bsearch.cpp
	[ccoew@localhost ~]$ ./a.out
	Enter number of elements you want to insert 7
	Enter elements
	Enter element: 1:3
	Enter element: 2:4
	Enter element: 3:5
	Enter element: 4:11
	Enter element: 5:2
	Enter element: 6:67
	Enter element: 7:89
	Sorted array is:2  3  4  5  11  67  89  
	Enter the number you want to search 11

	Item found at: 5 position
	[ccoew@localhost ~]$ ./a.out
	Enter number of elements you want to insert 6
	Enter elements
	Enter element: 1:34
	Enter element: 2:22
	Enter element: 3:45
	Enter element: 4:12
	Enter element: 5:22
	Enter element: 6:34
	Sorted array is:12  22  22  34  34  45  
	Enter the number you want to search 87

	Item not found[ccoew@localhost ~]$ ^C
	*/
