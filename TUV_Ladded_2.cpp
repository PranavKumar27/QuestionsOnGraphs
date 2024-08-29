#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<string> VecOfStr;

void findIfConversionPossibleAtLevel(VecOfStr AllStrings,string AtNowWord,VecOfStr& ToBeWords)
{
    int sz = AtNowWord.size();

    for(int Index=0;Index<sz;++Index)
    {
        // check at index i
        cout << "At index i=" << Index << endl;
        string newWord = AtNowWord;
        for(char value = 'a';value<='z';value++)
        {
            newWord[Index] = value;
            auto itr = find(AllStrings.begin(),AllStrings.end(),newWord);
            if(itr!=AllStrings.end() && newWord!=AtNowWord)
            {
                // Found a Match
                cout << "Found a Match =" << newWord << endl;
                ToBeWords.push_back(newWord);
                //return true;
            }

        }
    }
    //return false;
}
void DeleteInStrList(VecOfStr& AllStrings,string ToBeDeleted)
{
    auto itr = find(AllStrings.begin(),AllStrings.end(),ToBeDeleted);
    cout << "Size before Delete =" << AllStrings.size() << endl;
    if(itr != AllStrings.end())
    {
        AllStrings.erase(itr);
        cout << "Deleted Str =" << ToBeDeleted << endl;
    }
    cout << "Size After Delete =" << AllStrings.size() << endl;

}
void print_v(VecOfStr AllStrings)
{
    for(auto str:AllStrings)
    {
        cout << str << "\t";
    }
    cout << endl;
}
void findAllShortestPaths(VecOfStr AllStrings,string startWord,string endWord,vector<VecOfStr>& AllShortestPaths)
{
    queue<pair<VecOfStr,int>> q;
    int level = 1;
    VecOfStr ArrayOfStr;
    ArrayOfStr.push_back(startWord);
    q.push({ArrayOfStr,level});
    int prev_level=0;
    string prevStr = startWord;
    int shortestLen = 1;
    while(!q.empty())
    {
        VecOfStr strList = q.front().first;
        int old_level = q.front().second;
        q.pop();
        cout << "Item Popped Details: Level=" << old_level << " Path=" ;
        print_v(strList);
        cout << endl;

        if(old_level == prev_level+1) // Once complete Level is done
        {
            //if(q.size()>=1)
            {
                int upcoming_level = q.front().second;
                cout << "upcoming level = " << upcoming_level << endl;
                //if(upcoming_level!=old_level)
                {
                    // We need to delete prevStr
                    cout << "Calling Delete" << endl;
                    DeleteInStrList(AllStrings,prevStr);
                }


            }
        }
        int new_level = old_level + 1;

        int sz = strList.size();
        string lastStr = strList[sz-1];
        cout << "laststr = " << lastStr << endl;
        if(lastStr == endWord)
        {
            cout << "Found The destination Word " << endl;
            // Reached the destination Word
            AllShortestPaths.push_back(strList);
            shortestLen = sz;
        }
        VecOfStr AllWords;
        findIfConversionPossibleAtLevel(AllStrings,lastStr,AllWords);
        string currentStr = "";
        int list_size = AllWords.size();
        cout << list_size << endl;
        if(list_size>0)
        {
            for(auto str:AllWords)
            {
                cout << "str=" << str << endl;

                VecOfStr tempStrList(strList);
                currentStr = str;
                tempStrList.push_back(currentStr);
                cout << "Pushing currentStr =" << currentStr << " into the List " << endl;
                cout << "old_level =" << old_level << endl;
                cout << "new level =" << new_level << endl;
                print_v(tempStrList);
                q.push({tempStrList,new_level});

            }

            prev_level = old_level;
            prevStr = currentStr;
        }
    }
}

int main()
{
    VecOfStr AllStrings = {"bat","bot","pat","pot","poz","coz"};
    string startWord = "bat";
    string endWord = "coz";

    vector<VecOfStr> AllShortestPaths;

    findAllShortestPaths(AllStrings,startWord,endWord,AllShortestPaths);

    cout << "All Possible Shortest Strings" << endl;
    for(auto vectorOfStrings:AllShortestPaths)
    {
        for(auto Strings:vectorOfStrings)
        {
            cout << Strings << " ,\t";
        }
        cout << endl;
    }

    return 0;
}
