# include <iostream>
# include <string>
# include <sstream>
using namespace std;

string format(string &num)
{
    if(num[0] == '-' && num.size() - 1 < 4)
        return num;

    int len = num.size();
    int k = 1, t = 0;
    if(num[0] == '-'){
        for(int j = 1; j + 3 < len; j += 3){
            //num.insert(num.begin() + j + 3 + k++, ',');
            num.insert(num.end() - 3 * k++ - t++, ',');
        }
    }
    else{
        for(int j = 0; j + 3 < len; j += 3)
            //num.insert(num.begin() + j + 3 + k++, ',');
            num.insert(num.end() - 3 * k++ - t++, ',');
    }

    return num;
}

int main()
{
    int a, b;

    while(cin >> a >> b){
        //cin >> a >> b;
        stringstream stream;
        string str;
        int sum = a + b;
        stream << sum;
        stream >> str;

        //cout << str << endl;
        cout << format(str) << endl;
    }
}
