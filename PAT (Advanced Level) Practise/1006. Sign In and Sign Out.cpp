# include <iostream>
# include <cstdio>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

struct sign{
    string id, signIn, signOut;
    int signInVal;
    int signOutVal;
    sign(string _id, string ot, string out):id(_id), signIn(ot), signOut(out)
    {
        int hour = (signIn[0] - '0') * 10 + (signIn[1] - '0');
        int minute = (signIn[3] - '0') * 10 + (signIn[4] - '0');
        int second = (signIn[6] - '0') * 10 + (signIn[7] - '0');

        signInVal = hour * 3600 + minute * 60 + second;

        int h = (signOut[0] - '0') * 10 + (signOut[1] - '0');
        int m = (signOut[3] - '0') * 10 + (signOut[4] - '0');
        int s = (signOut[6] - '0') * 10 + (signOut[7] - '0');

        signOutVal = h * 3600 + m * 60 + s;
    }
};

int cmpIn(const sign &a, const sign &b)
{
    return a.signInVal < b.signInVal;
}

int cmpOut(const sign &a, const sign &b)
{
    return a.signOutVal > b.signOutVal;
}

int main()
{
    int n;
    string id, signIn, signOut;
    vector<sign> vec;

    cin >> n;
    while(n--)
    {
        cin >> id >> signIn >> signOut;
        vec.push_back(sign(id, signIn, signOut));
    }
    
    sort(vec.begin(), vec.end(), cmpIn);
    cout << vec[0].id << " ";
    sort(vec.begin(), vec.end(), cmpOut);
    cout << vec[0].id << endl;
	return 0; 
}
