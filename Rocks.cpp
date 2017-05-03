#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<double> > grouping(vector<vector<double> > group, vector<double> &rocks)
{
	vector<vector<double> > g;
	for (int i = 0; i < group.size(); i++)
	{
		for (int k = find(rocks.begin(), rocks.end(), group[i].back()) - rocks.begin() + 1; k < rocks.size(); k++)
		{
			g.push_back(group[i]);
			g.back().push_back(rocks[k]);
		}
	}
	return g;
}

int main()
{
	vector<double> rocks;
	string input;
	ifstream fin;
	fin.open("input.txt");
	while (getline(fin, input))
	{
		string token;
		stringstream ss(input);
		while (ss >> token)
			rocks.push_back(strtod(token, 0));
		sort(rocks.begin(), rocks.end());
		vector<vector<double> > groups;
		vector<vector<double> > group;
		group.resize(rocks.size());
		for (int i = 0; i < rocks.size(); i++)
			group[i].push_back(rocks[i]);
		for (int k = 0; k < group.size(); k++)
			groups.push_back(group[k]);
		for (int i = 1; i < rocks.size() - 1; i++)
		{
			group = grouping(group, rocks);
			for (int k = 0; k < group.size(); k++)
				groups.push_back(group[k]);
		}
		vector<double> sums;
		double sum;
		for (int i = 0; i < groups.size(); i++)
		{
			sum = 0;
			for (int k = 0; k < groups[i].size(); k++)
				sum += groups[i][k];
			sums.push_back(sum);
		}
		sort(sums.begin(), sums.end());
		sum = 0;
		cout << "Rocks: ";
		for (int i = 0; i < rocks.size(); i++)
		{
			sum += rocks[i];
			cout << rocks[i] << " ";
		}
		cout << endl;
		bool one = false;
		bool two = false;
		sum = sum / 2;
		for (int i = 0; i < sums.size() - 1; i++)
		{
			if (sums[i] == sum)
				one = true;
			if (sums[i] == sums[i + 1])
				two = true;
		}
		cout << "All rocks: ";
		if (one)
			cout << "True" << endl;
		else
			cout << "False" << endl;
		cout << "Any rocks: ";
		if (two)
			cout << "True" << endl << endl;
		else
			cout << "False" << endl << endl;
		rocks.clear();
		group.clear();
		groups.clear();
		sums.clear();
	}
	fin.close();
	return 0;
}
