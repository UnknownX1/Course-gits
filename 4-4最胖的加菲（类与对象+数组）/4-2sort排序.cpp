#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Cat
{
private:
	int weight;
	string name;
public:
	int getWeight();
	string getName();
	void set(int wei, string na);
};

int Cat::getWeight()
{
	return weight;
}

string Cat::getName()
{
	return name;
}
void Cat::set(int wei, string na)
{
	weight = wei;
	name = na;
}

bool cmp(Cat a,Cat b)
{
	return a.getWeight() < b.getWeight();
} 

int main()
{
	int n;
	cin >> n;
	Cat* cat = new Cat[n];
	for (int i = 0; i < n; i++)
	{
		int weight;
		string name;
		cin >> name >> weight;
		cat[i].set(weight, name);
	}
	
	sort(cat, cat+n ,cmp);
	
	for (int i = 0; i < n; i++)
	{
		string tmp = cat[i].getName();
		cout << tmp;
		if (i < n - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}
