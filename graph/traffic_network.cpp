#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
const int INF = 0x3f3f3f3f;



struct option
{
	bool operator() (const pair<int, int>&a, const pair<int, int>&b) const
	{
		return a.second > b. second;
	}
};

void Dijsktra(int s, int e, vector<int> &dist, vector<vector<pair<int, int> > > & graph)
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
		// if(w > dist[u])
		// 	continue;
		// if(u == e)
		// 	break;
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
	// return dist[e];

}
int main()
{
	int n,m,k,s,t, tc;
	int u, v, w, shortest;
	int res;
	vector<int> dist_s;
	vector<int> dist_t;
	vector<vector<pair<int, int> > >  graph_s;
	vector<vector<pair<int, int> > >  graph_t;

	cin>>tc;
	while(tc--)
	{
		cin>>n>>m>>k>>s>>t;
		graph_s = vector<vector<pair<int, int> > > (n+1, vector<pair<int, int> > ());
		graph_t = vector<vector<pair<int, int> > > (n+1, vector<pair<int, int> > ());

		dist_s = vector<int>(n+1, INF);
		dist_t = vector<int>(n+1, INF);
		//one way road
		for(int i = 0; i < m; i++)
		{
			cin>>u>>v>>w;
			graph_s[u].push_back(pair<int, int>(v, w));

			graph_t[v].push_back(pair<int, int>(u, w));

		}
		Dijsktra(s,t, dist_s, graph_s);
		Dijsktra(t,s, dist_t, graph_t);
		res = dist_s[t];
		//two way road
		for(int i = 0; i < k ; i++)
		{
			cin>>u>>v>>w;

			shortest = min(dist_s[u] + dist_t[v] + w, dist_s[v] + dist_t[u] + w);
			res = min(shortest, res);

		}

		if(res == INF)
			cout<<-1<<"\n";
		else
			cout<<res<<"\n";
	}

	return 0;
}