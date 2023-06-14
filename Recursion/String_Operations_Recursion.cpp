#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void print(char ch[], int i)
{
    if(ch[i]=='\0')
        return;

    cout<<ch[i];
    print(ch,i+1);
}

void reverseprint(char ch[], int i)
{
    if(ch[i]=='\0')
        return;

    reverseprint(ch,i+1);
    cout<<ch[i];
}

int length(char ch[])
{
    if(ch[0]=='\0')
        return 0;


    return 1+length(ch+1);
}

void replacechar(char ch[], char a, char b)
{
    if(ch[0]=='\0')
        return;

    if(ch[0]==a)
        ch[0]=b;

    replacechar(ch+1,a,b);

}

void removec(char ch[], char x)
{
    if(ch[0]=='\0')
        return;

    if(ch[0]==x)
    {
        for(int i=0;ch[i]!='\0';i++)
            ch[i]=ch[i+1];

        removec(ch,x);

    }else{

        removec(ch+1,x);

    }

}

void removeduplicates(char ch[])
{
    if(ch[0]=='\0')
    {
            return;
    }

    if(ch[0]==ch[1])
       {
           for(int i=0;ch[i]!='\0';i++)
                ch[i]=ch[i+1];

           removeduplicates(ch);
       }

       else{

        removeduplicates(ch+1);

       }


}

int main()
{
    char c[20];
    cin>>c;

    print(c,0);

    cout<<endl;

    reverseprint(c,0);

    cout<<endl;

    cout<<"The length of this string is: "<<length(c);

    cout<<endl;
   // char a='t', b='x';

   // replacechar(c,a,b);
    //cout<<c;
    //char x;
    //cin>>x;

    //removec(c,x);

    removeduplicates(c);

    cout<<"The new string is: "<<c;
    return 0;
}
