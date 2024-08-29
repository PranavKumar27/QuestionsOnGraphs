#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool findAtoZCharforAnyIndex(string InitialWord,set<string>& S,int Index,string& newWord)
{
    for(char value = 'a';value<='z';value++)
    {
        newWord[Index] = value;
        if(S.find(newWord)!=S.end())
        {
            cout << "Found a match new Word =" << newWord << endl;
            cout << "Old size of Set =" << S.size() << endl;
            S.erase(newWord);
            cout << "New size of Set =" << S.size() << endl;
            return true;
        }

    }
    return false;
}


void bfs(vector<string>& WordList,string startWord,string endWord)
{
    set<string> S;
    cout << __FUNCTION__ << endl;
    for(auto data:WordList)
    {
        S.insert(data);
        cout << "Inserted into set data=" << data << endl;
    }

    queue<pair<string,int>> q;
    q.push({startWord,1});

    while(!q.empty())
    {
        pair<string,int> p = q.front();
        q.pop();
        string InitialWord = p.first ;
        int level = p.second;

        cout << "Popped from queue Word =" << InitialWord << "  At level=" << level << endl;

        if(InitialWord == endWord)
        {
            cout << "Found a Match at Level =" << level << endl;
            return;
        }
        int sizeOfWord = InitialWord.size();

        for(int i=0;i<sizeOfWord;i++)
        {
            string newWord = InitialWord;
            bool res = findAtoZCharforAnyIndex(InitialWord,S,i,newWord);
            if(res)
            {
               q.push({newWord,level+1});
               cout << "New Word to be pushed =" << newWord << endl;
            }

        }
    }

}


int main()
{
    vector<string> WordList = {"hot","dot","dog","lot","log","cog"};
    string startWord = "hit";
    string endWord = "cog";


    bfs(WordList,startWord,endWord);

    return 0;
}
