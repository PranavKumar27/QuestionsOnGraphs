// FInd shortest distance using MultiGraph

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

class Graph
{
    int V;
    vector<vector<pair<int,int>>> Adj;
    vector<vector<int>> Stage;
    public:
        Graph(int v)
        {
            V = v;
            Adj.resize(V);
        }
        void addEdge(int u,int v,int wt)
        {
            cout << __FUNCTION__ << endl;
            Adj[u].push_back({v,wt});
        }
        void addStage(vector<vector<int>>& nodes)
        {
            cout << __FUNCTION__ << endl;
            Stage = nodes;
        }
        int MultiGraphShortestPath(vector<int>& path)
        {
            cout  << __FUNCTION__ << endl;
            // Traverse Graph in reverse Direction
            // So we pick last node in vector Stage as destination,
            // find shortest diestance from 1 to N considering source 1 and destination as N
            vector<vector<pair<int,int>>> dist; // vector<vertex,cost,node1,node2... nodes>
            dist.resize(V);

            bool flag = false;
            int sz = Stage.size();
            cout << "sz=" << sz << endl;
            for(int indx=sz-1;indx>=0;indx--)
            {
                cout << "indx=" << indx << endl;
                vector<int> StageNodes = Stage[indx];

                vector<int> listOfNodes = StageNodes;
                for(auto ss:StageNodes)
                    cout << ss << "\t";
                cout << "flag=" << flag << endl;
                if(!flag)
                {
                    // Assume Destination node is in StageNodes and Set cost as zero
                    vector<int>::iterator itr = find(StageNodes.begin(),StageNodes.end(),V-1);
                    if(itr!=StageNodes.end())
                    {
                        dist[V-1].push_back({0,V-1});
                        flag = true;
                        cout << "Found Destination=" << *itr << endl;
                        //break;
                    }
                    else
                    {
                        cout << "Couldn't find Destination" << endl;
                        return -1;
                    }
                }
                else
                {
                    cout << "Inside else" << endl;
                    for(auto nodes:StageNodes)
                    {
                        int st = indx; // stage
                        cout << "st=" << st << "node=" << nodes << endl;
                        vector<pair<int,int>> minDist;
                        int mini_dist = INT_MAX;
                        int mini_node;
                        for(auto adjacent:Adj[nodes])
                        {
                            int v = adjacent.first;
                            int wt = adjacent.second;
                            cout << "v=" << v << " wt=" << wt << endl;
                            vector<pair<int,int>> _v_p = dist[v];
                            int cost = _v_p[0].first;
                            int d = wt + cost;
                            cout << "d=" << d << endl;
                            if(d<mini_dist)
                            {
                                mini_dist = d;
                                mini_node = v;
                            }
                        }
                        // find smallest distance
                        cout << "Min dist=" << mini_dist << " node=" << mini_node << endl;
                        dist[nodes].push_back({mini_dist,mini_node}); // Distance

                        for(auto ss:minDist)
                        {
                            cout << "dist=" << ss.first << "\t node=" << ss.second << endl;
                        }
                    }
                }


            }


            // Generating path

            cout << "size of dist=" << dist.size() << endl;

            vector<pair<int,int>> p = dist[0];
            int node = p[0].second;
            path.push_back(0);
            path.push_back(node);

            do
            {
                vector<pair<int,int>> p = dist[node];
                node = p[0].second;
                cout << "node=" << node << endl;
                path.push_back(node);

            } while (node!=V-1);


            cout << "Value of distances " << endl;
            for(int i=0;i<V;i++)
            {
                vector<pair<int,int>> _v_p = dist[i];
                cout << "dist=" << _v_p[0].first << "\t node=" << _v_p[0].second << endl;
            }

            vector<pair<int,int>> ans = dist[0];

            return ans[0].first;

        }

};

int main()
{

    Graph g(12);

    g.addEdge(0,1,9);
    g.addEdge(0,2,7);
    g.addEdge(0,3,3);
    g.addEdge(0,4,2);

    g.addEdge(1,5,4);
    g.addEdge(1,6,2);
    g.addEdge(1,7,1);

    g.addEdge(2,5,2);
    g.addEdge(2,6,7);

    g.addEdge(3,7,11);

    g.addEdge(4,6,11);
    g.addEdge(4,7,8);

    g.addEdge(5,8,6);
    g.addEdge(5,9,5);

    g.addEdge(6,9,3);

    g.addEdge(7,9,5);
    g.addEdge(7,10,6);

    g.addEdge(8,11,4);

    g.addEdge(9,11,2);

    g.addEdge(10,11,5);


    vector<int> v1 = {0};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3 = {5,6,7};
    vector<int> v4 = {8,9,10};
    vector<int> v5 = {11};
    vector<vector<int>> Stage = {v1,v2,v3,v4,v5};

    g.addStage(Stage);

    int res;
    vector<int> path;
    res = g.MultiGraphShortestPath(path);
    cout << "Shortest Path Distance =" << res << endl;

    cout << "Path=\t";
    for(auto s:path)
    {
        cout << s << "\t";
    }
    cout << endl;

    return 0;
}
