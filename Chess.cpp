#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct pos
{
	int row;
	int col;
	pos(string i)
	{
		col = i.at(0) - 'a';
		row = i.at(1) - '1';
	}

	void set(string i)
	{
		col = i.at(0) - 'a';
		row = i.at(1) - '1';
	}
};

pos getPos()
{
	pos p("a1");
	while (true)
	{
		cout << "Input position in chess format. (ex. a1, h8, g4)" << endl;
		string input;
		cin >> input;
		p.set(input);
		if (p.row < 8 && p.row >= 0 && p.col < 8 && p.col >= 0)
			return p;
		else
			cout << "Invalid position" << endl;
	}
}

string whatPos(int row, int col)
{
	string s;
	s = 'a' + col;
	s += '1' + row;
	return s;
}

vector<string> findRook(int row, int col)
{
	vector<string> p;
	int crow = row - 1;
	while (crow >= 0)
	{
		p.push_back(whatPos(crow, col));
		crow--;
	}
	crow = row + 1;
	while (crow < 8)
	{
		p.push_back(whatPos(crow, col));
		crow++;
	}
	crow = row;
	int ccol = col - 1;
	while (ccol >= 0)
	{
		p.push_back(whatPos(row, ccol));
		ccol--;
	}
	ccol = col + 1;
	while (ccol < 8)
	{
		p.push_back(whatPos(row, ccol));
		ccol++;
	}
	return p;
}

vector<string> findKnight(int row, int col)
{
	vector<string> p;
	int crow = row + 2;
	int ccol = col + 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row + 2;
	ccol = col - 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row - 2;
	ccol = col - 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row - 2;
	ccol = col + 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row + 1;
	ccol = col + 2;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row + 1;
	ccol = col - 2;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row - 1;
	ccol = col - 2;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row - 1;
	ccol = col + 2;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	return p;
}

vector<string> findBishop(int row, int col)
{
	vector<string> p;
	int crow = row - 1;
	int ccol = col - 1;
	while (crow >= 0 && ccol >= 0)
	{
		p.push_back(whatPos(crow, ccol));
		crow--;
		ccol--;
	}
	crow = row - 1;
	ccol = col + 1;
	while (crow >= 0 && ccol < 8)
	{
		p.push_back(whatPos(crow, ccol));
		crow--;
		ccol++;
	}
	crow = row + 1;
	ccol = col + 1;
	while (crow < 8 && ccol < 8)
	{
		p.push_back(whatPos(crow, ccol));
		crow++;
		ccol++;
	}
	crow = row + 1;
	ccol = col - 1;
	while (crow < 8 && ccol >= 0)
	{
		p.push_back(whatPos(crow, ccol));
		crow++;
		ccol--;
	}
	return p;
}

vector<string> findQueen(int row, int col)
{
	vector<string> r = findRook(row, col);
	vector<string> b = findBishop(row, col);
	for (int i = 0; i < b.size(); i++)
		r.push_back(b[i]);
	return r;
}

vector<string> findKing(int row, int col)
{
	vector<string> p;
	int crow = row + 1;
	int ccol = col + 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row + 1;
	ccol = col;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row + 1;
	ccol = col - 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row;
	ccol = col + 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row;
	ccol = col - 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row - 1;
	ccol = col - 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row - 1;
	ccol = col;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	crow = row - 1;
	ccol = col + 1;
	if (crow < 8 && crow >= 0 && ccol < 8 && ccol >= 0)
		p.push_back(whatPos(crow, ccol));
	return p;
}

void posible()
{
	string input;
	vector<string> p;
	pos start("a1");
	while (true)
	{
		cout << "Select type of piece" << endl << "r - rook" << endl << "n - knight" << endl
			<< "b - bishop" << endl << "q - queen" << endl << "k - king" << endl << "a - abort" << endl;
		cin >> input;
		switch (input[0])
		{
		case 'r':
			cout << "Input starting position" << endl;
			start = getPos();
			p = findRook(start.row, start.col);
			for (int i = 0; i < p.size(); i++)
				cout << p[i] << " ";
			cout << endl;
			return;
			break;
		case 'n':
			cout << "Input starting position" << endl;
			start = getPos();
			p = findKnight(start.row, start.col);
			for (int i = 0; i < p.size(); i++)
				cout << p[i] << " ";
			cout << endl;
			return;
			break;
		case 'b':
			cout << "Input starting position" << endl;
			start = getPos();
			p = findBishop(start.row, start.col);
			for (int i = 0; i < p.size(); i++)
				cout << p[i] << " ";
			cout << endl;
			return;
			break;
		case'q':
			cout << "Input starting position" << endl;
			start = getPos();
			p = findQueen(start.row, start.col);
			for (int i = 0; i < p.size(); i++)
				cout << p[i] << " ";
			cout << endl;
			return;
			break;
		case'k':
			cout << "Input starting position" << endl;
			start = getPos();
			p = findKing(start.row, start.col);
			for (int i = 0; i < p.size(); i++)
				cout << p[i] << " ";
			cout << endl;
			return;
			break;
		case 'a':
			return;
			break;
		default:
			cout << "invalid input" << endl;
			break;
		}
	}
}

string routeKnight(pos start, pos target, vector<vector<bool> > &board, int &max, int n)
{
	if (start.row == target.row && start.col == target.col)
	{
		max = n;
		return whatPos(start.row, start.col);
	}
	else if ((start.row >= 8 && start.row < 0 && start.col >= 8 && start.col < 0) || board[start.row][start.col] || n >= max)
		return "fail";
	else
	{
		vector<string> s = findKnight(start.row, start.col);
		if (find(s.begin(), s.end(), whatPos(target.row, target.col)) != s.end())
			return whatPos(start.row, start.col) + " " + routeKnight(target, target, board, max, n + 1);
		board[start.row][start.col] = true;
		vector<string> t = findKnight(target.row, target.col);
		vector<string> common;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		set_intersection(s.begin(), s.end(), t.begin(), t.end(), back_inserter(common));
		if (!common.empty())
		{
			pos next(common[0]);
			board[start.row][start.col] = false;
			return whatPos(start.row, start.col) + " " + routeKnight(next, target, board, max, n + 1);
		}
		else
		{
			string fin = "fail";
			string check;
			pos other("a1");
			for (int i = 0; i < s.size(); i++)
			{
				other.set(s[i]);
				check = routeKnight(other, target, board, max, n + 1);
				if ((fin.length() > check.length() || fin.compare("fail") == 0) && check.compare("fail") != 0)
					fin = check;
			}
			board[start.row][start.col] = false;
			if (fin.compare("fail") != 0)
				return whatPos(start.row, start.col) + " " + fin;
			else
				return fin;
		}
	}
}

void route()
{
	string input;
	pos start("a1");
	pos target("a1");
	vector<string> s;
	vector<string> t;
	vector<string> common;
	string str;
	vector<vector<bool> > board;
	int max;
	while (true)
	{
		cout << "Select type of piece" << endl << "r - rook" << endl << "n - knight" << endl
			<< "b - bishop" << endl << "q - queen" << endl << "k - king" << endl << "a - abort" << endl;
		cin >> input;
		switch (input[0])
		{
		case 'r':
			cout << "Input starting position" << endl;
			start = getPos();
			cout << "Input target position" << endl;
			target = getPos();
			cout << "Route: ";
			s = findRook(start.row, start.col);
			if (start.row == target.row && start.col == target.col)
				cout << whatPos(start.row, start.col) << endl;
			else if (find(s.begin(), s.end(), whatPos(target.row, target.col)) != s.end())
				cout << whatPos(start.row, start.col) << " " << whatPos(target.row, target.col) << endl;
			else
			{
				t = findRook(target.row, target.col);
				sort(s.begin(), s.end());
				sort(t.begin(), t.end());
				set_intersection(s.begin(), s.end(), t.begin(), t.end(), std::back_inserter(common));
				if (common.empty())
					cout << "fail" << endl;
				else
					cout << whatPos(start.row, start.col) << " " << common[0] << " " << whatPos(target.row, target.col) << endl;
			}
			return;
			break;
		case 'n':
			cout << "Input starting position" << endl;
			start = getPos();
			cout << "Input target position" << endl;
			target = getPos();
			board.resize(8);
			for (int i = 0; i < 8; i++)
				board[i].resize(8, false);
			max = 8;
			str = routeKnight(start, target, board, max, 1);
			if (str.compare("fail") == 0)
			{
				bool done = false;
				while (!done)
				{
					cout << "Could not find a solution with 8 moves" << endl << "Do you wish to examine up to 16 moves" << endl << "y/n" << endl;
					cin >> input;
					switch (input[0])
					{
					case 'y':
						max = 16;
						str = routeKnight(start, target, board, max, 1);
						if (str.compare("fail") == 0)
						{
							while (!done)
							{
								cout << "Could not find a solution with 16 moves" << endl << "Do you wish to examine up to 64 moves" << endl << "y/n" << endl;
								cin >> input;
								switch (input[0])
								{
								case 'y':
									max = 64;
									str = routeKnight(start, target, board, max, 1);
									done = true;
									break;
								case 'n':
									done = true;
									break;
								default:
									break;
								}
							}
						}
					case 'n':
						done = true;
						break;
					default:
						break;
					}
				}
			}
			cout << "Route: " << str << endl;
			return;
			break;
		case 'b':
			cout << "Input starting position" << endl;
			start = getPos();
			cout << "Input target position" << endl;
			target = getPos();
			cout << "Route: ";
			s = findBishop(start.row, start.col);
			if (start.row == target.row && start.col == target.col)
				cout << whatPos(start.row, start.col) << endl;
			else if (find(s.begin(), s.end(), whatPos(target.row, target.col)) != s.end())
				cout << whatPos(start.row, start.col) << " " << whatPos(target.row, target.col) << endl;
			else
			{
				t = findBishop(target.row, target.col);
				sort(s.begin(), s.end());
				sort(t.begin(), t.end());
				set_intersection(s.begin(), s.end(), t.begin(), t.end(), std::back_inserter(common));
				if (common.empty())
					cout << "fail" << endl;
				else
					cout << whatPos(start.row, start.col) << " " << common[0] << " " << whatPos(target.row, target.col) << endl;
			}
			return;
			break;
		case 'q':
			cout << "Input starting position" << endl;
			start = getPos();
			cout << "Input target position" << endl;
			target = getPos();
			cout << "Route: ";
			s = findQueen(start.row, start.col);
			if (start.row == target.row && start.col == target.col)
				cout << whatPos(start.row, start.col) << endl;
			else if (find(s.begin(), s.end(), whatPos(target.row, target.col)) != s.end())
				cout << whatPos(start.row, start.col) << " " << whatPos(target.row, target.col) << endl;
			else
			{
				t = findQueen(target.row, target.col);
				sort(s.begin(), s.end());
				sort(t.begin(), t.end());
				set_intersection(s.begin(), s.end(), t.begin(), t.end(), std::back_inserter(common));
				if (common.empty())
					cout << "fail" << endl;
				else
					cout << whatPos(start.row, start.col) << " " << common[0] << " " << whatPos(target.row, target.col) << endl;
			}
			return;
			break;
		case 'k':
			cout << "Input starting position" << endl;
			start = getPos();
			cout << "Input target position" << endl;
			target = getPos();
			cout << "Route: ";
			while (start.row != target.row || start.col != target.col)
			{
				cout << whatPos(start.row, start.col) << " ";
				if (start.row < target.row)
				{
					start.row++;
					if (start.col < target.col)
						start.col++;
					else if (start.col > target.col)
						start.col--;
				}
				else if (start.row > target.row)
				{
					start.row--;
					if (start.col < target.col)
						start.col++;
					else if (start.col > target.col)
						start.col--;
				}
				else
				{
					if (start.col < target.col)
						start.col++;
					else if (start.col > target.col)
						start.col--;
				}
			}
			cout << whatPos(start.row, start.col) << endl;
			return;
			break;
		case 'a':
			return;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	}
}

int main()
{
	string input;
	bool quit = false;
	while (!quit)
	{
		cout << "Choose an option" << endl << "p - posible moves" << endl << "r - route between 2 positions" << endl << "q - quit" << endl;
		cin >> input;
		switch (input[0])
		{
		case 'p':
			posible();
			break;
		case 'r':
			route();
			break;
		case 'q':
			quit = true;
			break;
		default:
			cout << "invalid input" << endl;
		}
	}

	return 0;
}