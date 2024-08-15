class Solution
{
void generateIndegree(vector<int>& Indegree,int N ,vector<vector<int>>& Adj)
    {
        for(int src=0;src<N;src++)
        {
            for(auto adjacent:Adj[src])
            {
                Indegree[adjacent] = Indegree[adjacent]+1;
            }
        }
    }
    bool bfs(vector<int>& Indegree,int N ,vector<vector<int>>& Adj)
    {
        queue<int> Q;
        vector<int>res;
        
        for(int src=0;src<N;src++)
	    {
	        if(Indegree[src]==0)
	        {
	            Q.push(src);
	        }
	    }
        
        while(!Q.empty())
        {
            int new_src = Q.front();
            res.push_back(new_src);
            Q.pop();
            for(auto adjacent:Adj[new_src])
            {
                Indegree[adjacent] = Indegree[adjacent]-1;
                
                if(Indegree[adjacent]==0)
                {
                    Q.push(adjacent);
                }
            }
        }
        
        if(res.size()!=N)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    vector<int> Indegree;
	    Indegree.resize(N,0);
	    
	    vector<vector<int>> Adj;
        Adj.resize(N);
        
        for(auto pre:prerequisites)
        {
            Adj[pre.first].push_back(pre.second);
        }
	    
	    generateIndegree(Indegree,N,Adj);
	    
	    bool res = bfs(Indegree,N,Adj);
	    if(res)
	       return res;
	    else
	        return false;
	    
	}
};
