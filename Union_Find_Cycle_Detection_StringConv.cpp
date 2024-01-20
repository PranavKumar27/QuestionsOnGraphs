#include <iostream>
#include <vector>
#include <map>

using namespace std;

// This Problem is inspired from gfg: https://www.geeksforgeeks.org/check-if-one-string-can-be-converted-to-another/

class Disjoint
{
   int n;
   vector<int> size_;
   vector<int> parent;
   public:
       Disjoint(int n)
       {
           this->n = n;
           size_.resize(n,1);
           parent.resize(n);
           fillParent();
       }
       void fillParent()
       {
           for(int i=0;i<n;i++)
            parent[i]=i;
       }
       int find_(int s)
       {
           if(parent[s]==s)
            return s;
           else
           {
               int res = find_(parent[s]);
               parent[s] = res;
               return res;
           }
       }

       bool unionBySize(int u,int v)
       {
           int ultimate_p_u = find_(u);
           int ultimate_p_v = find_(v);

           if(ultimate_p_u == ultimate_p_v)
           {
               cout << "Cycle Detected" << endl;
               return true;
           }
           if(size_[ultimate_p_u] < size_[ultimate_p_v])
           {
               parent[ultimate_p_u] = ultimate_p_v;
               size_[ultimate_p_v] += size_[ultimate_p_u];
           }
           else
           {
               parent[ultimate_p_v] = ultimate_p_u;
               size_[ultimate_p_u] += size_[ultimate_p_v];
           }
       }
};

void convertCharToInt(string s1,string s2, map<int,int>& Mp)
{
    // Assume s1 and s2 is of same Length
    char a = 'a';
    for(int i=0;i<s1.size();i++)
    {
        if(Mp.find(s1[i]-a) == Mp.end())
        {
           Mp[s1[i]-a] = s2[i]-a;
        }
        else if(s1[i]-a != s2[i]-a)
        {
            cout << "Can't Proceed as Multiple char of s1 points to s2" << endl;
            return;
        }
    }
}

int main()
{
    int n=26;
    Disjoint d(n);
    /*
    //Normal Cycle Check
    int n=3;
    Disjoint d(n);
    bool res = false;
    res = d.unionBySize(0,1);
    res = d.unionBySize(1,2);
    res = d.unionBySize(2,3);
    res = d.unionBySize(0,1);

    if(!res)
    {
        cout << "No Cycle Detected" << endl;
    }

    */
    string s1 = "abdc";
    string s2 = "bcda";

    map<int,int> Mp;
    convertCharToInt(s1,s2,Mp);

    bool res = false;
    for(auto edges:Mp)
    {
        int u = edges.first;
        int v = edges.second;
        res = d.unionBySize(u,v);
    }
    if(!res)
    {
        cout << "No Cycle Detected" << endl;
    }

    return 0;
}


