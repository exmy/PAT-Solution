#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string Upper(string src)
{
    for(size_t i = 0; i < src.length(); ++i)
    {
        src[i] = toupper(src[i]);
    }
    return src;
}

int main()
{
    string src, dec;
    string ans;

    getline(cin, src);
    getline(cin, dec);
    src = Upper(src), dec = Upper(dec);

    size_t i = 0, j = 0;
    while(i < src.length() && j < dec.length())
    {
        if(src[i] != dec[j])
        {
            if(ans.find(src[i]) == string::npos)
                ans.push_back(src[i]);
            i++;
        }
        else { i++, j++; }
    }
    cout << ans << endl;
}
