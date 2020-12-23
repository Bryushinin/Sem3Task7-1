#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Comp(string a, string b)
{
    if(a>b)
        return 1;
    return 0;
}



int main()
{
    ifstream src("input.txt");

    map<string, vector<string> > M;
    vector<string> A;
    int i,n,f=0,f1;
    string s,d;
    vector<string>::iterator ai;
    src>>n;
    for(i=0;i<n;++i)
    {
        src>>s;
        //out<<s<<endl;
        src>>d;
        //out<<d<<endl;
        while(d=="-" || f)
        {
            f=0;
            src>>d;
            if(d[d.size()-1]==',')
            {
                d=d.substr(0,d.size() -1);
                f=1;
            }
            if(d!="-")
            {
                M[d].push_back(s);
                f1=1;

                for(ai=A.begin();ai!=A.end();++ai)
                    if(*ai==d)
                        f1=0;
                if(f1)
                    A.push_back(d);
            }
            //out<<d<<endl;
        }
    }
    sort(A.begin(),A.end());
    ofstream out("output.txt");
    for(ai=A.begin();ai!=A.end();++ai)
    {
        vector<string>::iterator it;
        out<<*ai<<" - ";
        for(it=M[*ai].begin();it!=M[*ai].end();++it)
            {
                out<<*it;
                if((it+1)!=M[*ai].end())
                    out<<", ";
            }
        out<<endl;
    }
    src.close();
    out.close();
    ////////////////// vivod


    return 0;
}
