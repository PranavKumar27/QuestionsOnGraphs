class Solution
{
    void bfs(int V,vector<vector<int>>& Adj,vector<int>& SafeNodes)
    {
        // generate Indegree
        vector<int>Indegree;
        Indegree.resize(V,0);
        
        for(int src=0;src<V;src++)
        {
            for(auto adjacent:Adj[src])
            {
                Indegree[adjacent]++;
            }
        }
        
        queue<int> q;
        
        for(int src=0;src<V;src++)
        {
            if(Indegree[src]==0)
            {
                q.push(src);
            }
        }
        
        while(!q.empty())
        {
            int vertex = q.front();
            q.pop();
            SafeNodes.push_back(vertex);
            
            for(auto adjacent:Adj[vertex])
            {
                Indegree[adjacent] = Indegree[adjacent]-1;
                if(Indegree[adjacent]==0)
                {
                    q.push(adjacent);
                }
            }
        }
        
        sort(SafeNodes.begin(),SafeNodes.end());
        
    }
  public:
  
    vector<int> eventualSafeNodes(int V, vector<int> Adj[]) {
        // code here
       vector<vector<int>> Transpose;  // Transform the existing Edges by reversing the edges
       Transpose.resize(V);
       
       for(int src=0;src<V;src++)
       {
            for(auto adjacent:Adj[src])
            {
               Transpose[adjacent].push_back(src);
            } 
       }
       
       vector<int> SafeNodes;
       
       bfs(V,Transpose,SafeNodes);
       
       return SafeNodes;
       
        
    }

}
