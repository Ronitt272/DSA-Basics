#include<bits/stdc++.h>
using namespace std;

bool check_valid_parenthesis(stack<char> s, vector<char> v)
{
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i] == '(' || v[i] == '{' || v[i] == '[')
            s.push(v[i]);

        else {
                if(v[i] == ')' && s.top() != '(')
                    return false;

                else if(v[i] == '}' && s.top() != '{')
                    return false;

                else if(v[i] == ']' && s.top() != '[')
                    return false;

                    else{
                        s.pop();
                    }

        }
    }

    if(s.size() == 0)
        return false;
    else{
        return true;
    }

}

int main()
{
    stack<char> s;
    vector<char> v = {'(', '[', '{', ')', ']', '}'};
    bool valid = check_valid_parenthesis(s,v);

    if(valid == true)
    {
        cout<<"The parenthesis are valid !";
    }

    else {

        cout<<"The parenthesis are not valid !";
    }

    return 0;
}
