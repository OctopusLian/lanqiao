#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(int argc, char** argv)
{
	map<int,string> maptime;
	maptime[0]="zero";
	maptime[1]="one";
	maptime[2]="two";
	maptime[3]="three";
	maptime[4]="four";
	maptime[5]="five";
	maptime[6]="six";
	maptime[7]="seven";
	maptime[8]="eight";
	maptime[9]="nine";
	maptime[10]="ten";
	maptime[11]="eleven";
	maptime[12]="twelve";
	maptime[13]="thirteen";
	maptime[14]="fourteen";
	maptime[15]="fifteen";
	maptime[16]="sixteen";
	maptime[17]="seventeen";
	maptime[18]="eighteen";
	maptime[19]="nineteen";
	maptime[20]="twenty";
	maptime[30]="thirty";
	maptime[40]="forty";
	maptime[50]="fifty";
	int h,m;
	cin>>h>>m;
	if(m==0)
	{
		if(h<=20)
		{
			cout<<maptime[h]<<" o'clock";
		}
		else
		{
			cout<<maptime[20]<<" "<<maptime[h-20]<<" o'clock";
		}
	}
	else
	{
		if(h<=20)
		{
			cout<<maptime[h]<<" ";
		}
		else
		{
			cout<<maptime[20]<<" "<<maptime[h-20]<<" ";
		}
		if(m<=20)
		{
			cout<<maptime[m]<<" ";
		}
		else
		{
			int k=m%10;
			cout<<maptime[m-k]<<" "<<maptime[k]<<" ";
		}
	}
	return 0;
}