class Solution
{
  public:
bool dfs(vector<bool>& visited,vector<bool>& dfsVisited,vector<int>& SafeNodes,int src,vector<int> Adj[])
    {
        if(visited[src]==false)
        {
            visited[src] = true;
            dfsVisited[src]=true;
        }

        for(auto adjacent:Adj[src])
        {
            if(!visited[adjacent])
            {
                int res = dfs(visited,dfsVisited,SafeNodes,adjacent,Adj);
                if(res)
                {
                    return res;
                }
            }
            else if(dfsVisited[adjacent])
            {
                return true;
            }
        }
        SafeNodes.push_back(src);
        dfsVisited[src]=false;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> Adj[]) {
        // code here
        vector<bool> visited;
        visited.resize(V,false);

        vector<bool> dfsVisited;
        dfsVisited.resize(V,false);

        vector<int> SafeNodes;
        
        bool res = false;
        for(int x=0;x<V;x++)
        {
            //cout << "x=" << x << endl;
            if(!visited[x])
            {
                res = dfs(visited,dfsVisited,SafeNodes,x,Adj);
            }
        }
        sort(SafeNodes.begin(),SafeNodes.end());
        return SafeNodes;
        
    }
};
