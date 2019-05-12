#include <iostream>

using namespace std;

int parent[10] = {0,};

bool connected(int beg, int end)
{
	if(parent[beg] == parent[end])
		return true;
	else
		return false;
}

void Union(int size, int beg, int end)
{
	int pb = parent[beg];
	int pe = parent[end];

	for (int i=0; i<size; i++)
	{
		if(parent[i] == pb) parent[i] = pe;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int n = 0;

	cin >> n;

	for (int i=0; i<n; i++)
	{
		parent[i] = i;
	}

	for(int i = 0; i<n;i++)
	{
		int beg = 0;
		int end = 0;

		cin >> beg;
		cin >> end;

		if(!connected(beg, end))
		{
			Union(n, beg, end);
			cout << "Connected " << beg << " " << end << endl;
		}
	}

	for(int i = 0; i<n;i++)
		cout << parent[i] << '\t';

	cout << endl;
	return 0;
}
