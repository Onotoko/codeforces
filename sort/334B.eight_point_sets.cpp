#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Point{
	int x;
	int y;
	bool operator<(const Point& p) const
	{
		if(x == p.x)
		{
			if(y == p.y)
				return false;
			return y < p.y;
		}
		return x<p.x;
	}
};
int main()
{
	vector<Point>eight_sets;
	Point p;
	int x,y;

	//Read data
	for(int i = 0; i < 8; i++)
	{
		cin>>x>>y;
		p.x = x;
		p.y = y;
		eight_sets.push_back(p);
	}

	//Sort data
	sort(eight_sets.begin(), eight_sets.end());
	//Compare condition to print output
	int x1 = (eight_sets[0].x + eight_sets[1].x + eight_sets[2].x)/3;
	int y11 = eight_sets[2].y - eight_sets[1].y;
	int y12 = eight_sets[1].y - eight_sets[0].y;

	int x2 = (eight_sets[3].x + eight_sets[4].x)/2;
	int y2 = eight_sets[4].y - eight_sets[3].y;

	int x3 = (eight_sets[5].x + eight_sets[6].x + eight_sets[7].x)/3;
	int y31 = eight_sets[7].y - eight_sets[6].y;
	int y32 = eight_sets[6].y - eight_sets[5].y;
	if(x1 == eight_sets[0].x && x2 == eight_sets[3].x && x3 == eight_sets[5].x)
	{
		if(y11 > 0 && y12 > 0 && y2 > 0 && y31 > 0 && y32 > 0)
		{
			if( eight_sets[3].y == eight_sets[0].y && eight_sets[4].y == eight_sets[2].y
				&& eight_sets[0].y == eight_sets[5].y && eight_sets[1].y== eight_sets[6].y && eight_sets[2].y == eight_sets[7].y)
				cout<<"respectable";
			else
				cout<<"ugly";
		}
		else
			cout<<"ugly";

	}
	else
	{
		cout<<"ugly";
	}
	return 0;
}


/*
#include <iostream>
#include <algorithm>

using namespace std;

struct point
{
    int x;
    int y;
};

bool cmp(const point& left, const point& right)
{
    return (left.x < right.x)
        || (left.x == right.x && left.y < right.y);
}

int main()
{
    point p[8];
    for (int i = 0; i < 8; ++i)
    {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + 8, cmp);
    if (   p[0].x == p[1].x && p[1].x == p[2].x
        && p[2].x != p[3].x
        && p[3].x == p[4].x
        && p[4].x != p[5].x
        && p[5].x == p[6].x && p[6].x == p[7].x
        && p[0].y == p[3].y && p[3].y == p[5].y
        && p[5].y != p[1].y
        && p[1].y == p[6].y
        && p[6].y != p[2].y
        && p[2].y == p[4].y && p[4].y == p[7].y)
    {
        cout << "respectable" << endl;
    }
    else
    {
        cout << "ugly" << endl;
    }
    return 0;
}
/*