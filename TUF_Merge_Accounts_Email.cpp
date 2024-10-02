#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class union_Set
{
    public:
    int n;
    vector<int> parent;
    vector<int> ranking;

    union_Set(){}
    union_Set(int n)
    {
        this->n = n;
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        ranking.resize(n,0);
    }
    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        else
            return parent[node] = findParent(parent[node]);
    }

    void union_by_rank(int u,int v)
    {
        int ult_p_u = findParent(u);
        int ult_p_v = findParent(v);

        if(ult_p_u!=ult_p_v)
        {
            if(ranking[ult_p_u]>=ranking[ult_p_v])
            {
                ranking[ult_p_u]+=1;
                parent[ult_p_v]=parent[ult_p_u];
            }
            else
            {
                ranking[ult_p_v]+=1;
                parent[ult_p_u]=parent[ult_p_v];
            }
        }
    }
    int noOfComponents()
    {
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    vector<vector<string>> Cust_Name_Email = {
                                                {"John","J1@com","J2@com","J3@com"},
                                                {"Tom","T1@com","T2@com"},
                                                {"John","J2@com","J5@com"},
                                                {"Tom","T3@com","T1@com"},
                                                {"Mary","M1@com","M2@com"}
                                        };
    map<string,int> EmailIndex;
    map<int,string> Name;

    int col_sz = Cust_Name_Email.size();
    int n = col_sz;
    union_Set S(col_sz);

    for(int i=0;i<col_sz;i++)
    {
        int row_sz = Cust_Name_Email[i].size();
        for(int j=0;j<row_sz;j++)
        {
            string data = Cust_Name_Email[i][j];

            if(j==0)
            {
                Name[i]=data;
            }
            else
            {
                auto itr = EmailIndex.find(data);

                if(itr==EmailIndex.end())
                {
                    EmailIndex[data]=i;
                }
                else
                {
                    int u = itr->second;
                    int v = i;
                    S.union_by_rank(u,v);
                }
            }
        }
    }

    vector<vector<string>> Res_Cust_Name_Email_List;

    // Find No of Components

    Res_Cust_Name_Email_List.resize(n);

    for(auto emailIdx:EmailIndex)  // Arranging Email List
    {
        string email = emailIdx.first;
        int Idx = emailIdx.second;

        int p = S.findParent(Idx);

        Res_Cust_Name_Email_List[p].push_back(email);
    }



    for(auto lst:Res_Cust_Name_Email_List)  // Sorting the email List
    {
        sort(lst.begin(),lst.end());
    }

    for(int i=0;i<n;i++)  // Inserting Name at the start
    {
        if(S.parent[i]==i)
        {
            string name = Name[i];
            Res_Cust_Name_Email_List[i].insert(Res_Cust_Name_Email_List[i].begin(),name);
        }
    }

    for(auto lst:Res_Cust_Name_Email_List)
    {
        cout << "--";
        for(auto data:lst)
        {
            cout << data << ",";
        }
        cout << "--" << endl;
    }

    return 0;
}
