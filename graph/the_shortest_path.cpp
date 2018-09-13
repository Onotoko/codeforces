#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
const int INF = 1e9;

vector<vector<pair<int, int> > >  graph;
vector<int> dist;
unordered_map<string, int>name_to_id;

struct option
{
	bool operator() (const pair<int, int>&a, const pair<int, int>&b) const
	{
		return a.second > b. second;
	}
};

void Dijsktra(int s, int e)
{
	priority_queue<pair<int, int>, vector<pair<int, int> > , option > pq;
	pq.push(make_pair(s,0));
	dist[s] = 0;
	while(!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();
		int u = top.first;
		int w = top.second;
		if(u == e)
			break;
		for(int i = 0; i < graph[u].size(); ++i)
		{
			pair<int, int> neighbor = graph[u][i];
			if(dist[neighbor.first] >  w + neighbor.second)
			{
				dist[neighbor.first] = w + neighbor.second;
				pq.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
			}
		}
	}

}
int main()
{
	int nb_cities, t;
	string name_city;
	int route, path, dest, cost;
	string start, end;
	unordered_map<string, int>::iterator it1, it2;
	cin>>t;
	while(t--)
	{
		cin>>nb_cities;
		graph = vector<vector<pair<int, int> > > (nb_cities+1, vector<pair<int, int> > ());
		for(int i = 1; i <= nb_cities; i++)
		{
			cin>>name_city;
			name_to_id[name_city] = i;
			cin >> path;
			while(path--)
			{
				cin>>dest>>cost;
				graph[i].push_back(pair<int, int>(dest, cost));

			}

		}
		//Calculate Dijsktra for all graph
		cin>>route;
		while(route--)
		{
			dist = vector<int>(nb_cities+1, INF);

			cin>>start>>end;
			Dijsktra(name_to_id[start],name_to_id[end]);
			cout<<dist[name_to_id[end]]<<"\n";
		}

	}

	return 0;
}