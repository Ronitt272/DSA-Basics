#include<bits/stdc++.h>
using namespace std;

void remove_duplicates(vector<string> v)
{
    stack<string> s;
    for(int i=0;i<v.size();i++)
    {
        if(s.size()==0)
        {
            s.push(v[i]);
        }

        else{

            if(s.top()==v[i])
            {
                s.pop();
            }

            else{
                s.push(v[i]);
            }
        }
    }


    vector<string> ans;

    while(s.size()!=0)
    {
        ans.push_back(s.top());
        s.pop();
    }

    for(int i=(ans.size()-1);i>=0;i--)
    {
        cout<<ans[i];
    }

}

int main()
{
    vector<string> v = {"a", "a", "b", "c", "c", "d", "d", "d", "e", "f", "f"};

    remove_duplicates(v);

    return 0;
}
