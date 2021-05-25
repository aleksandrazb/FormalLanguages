#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int dl_slowa=0;
	string slowo;
	
	cout << "Wpisz slowo\n";
	getline(cin, slowo);
	
	dl_slowa=slowo.length();
	
	vector<string> podslowo;
	string POMpodslowo[100][100];
	
	for(int i=0; i<100; i++)
	{
		POMpodslowo[i][0]="";
	}
	
	int p=0, k=0;
	
	for(int i=0;i<dl_slowa;i++)
	{
		for(int j=i+1;j<=dl_slowa;j++)
		{
			k=0;
			for(int pom=i;pom<j;pom++)
			{
				POMpodslowo[p][k]=slowo[pom];
				k++;
			}
			p++;
		}
	}
	
	string tmp;
	
	for(int i=0;i<p;i++)
	{
		tmp="";
		for(int j=0;j<dl_slowa;j++)
		{
			tmp=tmp+POMpodslowo[i][j];
		}
		if(!tmp.empty())
		{
			podslowo.push_back(tmp);
		}
		
	}
	
	podslowo.push_back("");
	
	sort(podslowo.begin(), podslowo.end());
	
	int u=podslowo.size();
	
	for(int i=1; i<u; i++)
	{
		if(podslowo[i]==podslowo[i-1])
		{
			podslowo.erase(podslowo.begin()+i-1);
			i--;
			u--;
		}
	}
	
	int ilosc_podslow=0;
	
	for(int i=0; i<podslowo.size(); i++)
	{
		ilosc_podslow++;
		cout << i+1 << ".\t'" << podslowo[i] << "'\n";
	}
	
	cout << "\n\nLiczba podslow " << ilosc_podslow;
	
	return 0;
}
