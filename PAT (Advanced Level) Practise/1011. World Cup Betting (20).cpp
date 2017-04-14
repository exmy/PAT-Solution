# include <iostream>
# include <iomanip>
using namespace std;

double odds[9];
char   type[] = {'W', 'T', 'L'};

double findMax(int first, int last)
{
    double maxn = 0;
    int    index = 0;
    for(int it = first; it <= last; ++it)
        if(maxn < odds[it])
        {
            maxn = odds[it];
            index = it;
        }
    cout << type[index % 3] << " ";
    return odds[index];
}

int main()
{
    for(int i = 0; i < 9; ++i)
            cin >> odds[i];

    double first  = findMax(0, 2);
    double second = findMax(3, 5);
    double third  = findMax(6, 8);

    cout << setprecision(4)  << (first * second * third * 0.65 - 1) * 2 << endl;
}
