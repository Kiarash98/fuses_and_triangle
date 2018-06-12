//*********** Fuse blowning check program
//*********** Programmer: Kiarash

#include <iostream>
#define max_fuse_quantity 20
using namespace std;

struct Fuse
{
	int power;
	bool on;
};

int main()
{
	/* n as fuse quantity
	** m as on-off set's quantity
	** c as maximum power capasity */
	int n,m,c;
	Fuse fuse[max_fuse_quantity];
	int fuse_index;
	int power_consumption;
	int max_power_consumption;
	int sequence_number = 1;
	bool isblown;
	bool end=0;
	while(!end)
	{
		cin>>n>>m>>c;
		if(n>=20 || n<0 || m<0 || c<0)
		{
			cout<<"Invalid!\n";
			break;
		}
		if( !(n||m||c) )
		{
			end =1;
			continue;
		}
		isblown = 0;
		for(int i=0;i<n;i++)
		{
			cin >> fuse[i].power;
			fuse[i].on = 0;
		}
		cout<<"Sequence "<<sequence_number<<"\n";
		max_power_consumption = 0;
		for(int i=0;i<m;i++)
		{
			cin>>fuse_index;
			fuse_index--;
			fuse[fuse_index].on = !fuse[fuse_index].on;
			power_consumption = 0;
			for(int j=0;j<n;j++)
				power_consumption += fuse[j].on * fuse[j].power;
			if(max_power_consumption<power_consumption)
				max_power_consumption = power_consumption;
			if(power_consumption>c)
			{
				isblown = 1;
				cout<<"Fuse was blown.\n";
				sequence_number++;
				break;
			}
		}
		if(!isblown)
		{
			cout<<"Fuse was not blown.\n";
			cout<<"Maximal power consumption was "<<max_power_consumption<<" amperes.\n";
			sequence_number++;
		}
		cout<<"\n";
	}
	return 0;
}
