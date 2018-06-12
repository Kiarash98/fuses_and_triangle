//*********** Triangle program
//*********** Programmer: Kiarash

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

void impossible()
{
	cout<<"Impossible\n";
}

int main()
{
	int tri_number=1;
	double a,b,c;
	int x; // for unknown part
	while(true)
	{
		cin>>a>>b>>c;
		if(!(a||b||c))
			break;

		if(a == -1)
			x = 1;
		else if(b == -1)
		 	x = 2;
		else if(c == -1)
			x = 3;

		switch(x)
		{
			case 1:
				a = pow(c,2) - pow(b,2);
				if(a>0)
				{
					a = sqrt(a);
					cout<<"Triangle #"<<tri_number<<"\n";
					//cout<<"a = "<<int(1000*a)/1000.0<<"\n";
					printf("a = %.3f\n",a);
				}
				else
					impossible();
			break;
			case 2:
				b = pow(c,2) - pow(a,2);
				if(b>0)
				{
					b = sqrt(a);
					cout<<"Triangle #"<<tri_number<<"\n";
					printf("b = %.3f\n",b);
				}
				else
					impossible();
			break;
			case 3:
				c = sqrt( pow(a,2) + pow(b,2) );
				cout<<"Triangle #"<<tri_number<<"\n";
				printf("c = %.3f\n",c);
			break;
		}
		cout<<endl;
		tri_number++;
	}
	return 0;
}
