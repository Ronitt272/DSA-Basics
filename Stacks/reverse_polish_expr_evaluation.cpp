#include<bits/stdc++.h>
using namespace std;

int evaluate_expression(stack<int> s, vector<string> v)
{

    int expr = 0;

    for(int i=0;i<v.size();i++)
    {
        if(v[i]!="+" && v[i]!="-" && v[i]!="*" && v[i]!="/")
            {
            s.push(atoi(v[i].c_str()));
            }
        else{
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();

                if(v[i]=="+")
                {
                    s.push(n1+n2);
                }

                if(v[i]=="-")
                {
                    s.push(n1-n2);
                }

                if(v[i]=="*")
                {
                    s.push(n1*n2);
                }

                if(v[i]=="/")
                {
                    s.push(n1/n2);
                }

        }
    }

    return s.top();

}

int main()
{
    stack<int> s;
    vector<string> v = {"4", "13", "5", "/", "+"};

    int expr = evaluate_expression(s,v);

    cout<<"The reverse polish evaluation is: "<<expr<<endl;

    return 0;
}
