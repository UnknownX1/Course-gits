#include <iostream>
#include <string>
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
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (cat[j].getWeight() > cat[j + 1].getWeight())
			{
				Cat temp;
				temp = cat[j];
				cat[j] = cat[j + 1];
				cat[j + 1] = temp;
			}
		}
	}
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