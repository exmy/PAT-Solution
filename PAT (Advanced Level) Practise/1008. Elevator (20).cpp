# include <iostream>
using namespace std;

int main()
{
    int n;
    int a[1000];
    enum cost{ up = 6, down = 4, stay = 5 };

    cin >> n >> a[0];
    int total = a[0] * up + stay;
    for(int i = 1; i < n; ++i)
    {
        cin >> a[i];
        if(a[i] >= a[i - 1])
        {
            total += (a[i] - a[i - 1]) * up + stay;
        }
        else
        {
            total += (a[i - 1] - a[i]) * down + stay;
        }
    }
    cout << total << endl;
}
