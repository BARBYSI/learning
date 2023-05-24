#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

int gcd(int m, int n)
{
    int r;
    while((r=m%n)) m=n,n=r;
    return n;
}

int main(int argc, char* argv[])
{
    int x,y,g;
    cout<<"\nProgram gcd using C++\n";
    if (argc != 3)
    {
        cout << "Wrong amount of arguments!" << endl;
        return 1;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    while(fin >> x >> y)
    {
        assert(x*y!=0);
        cout<<"\nGCD("<<x<< ", "<<y<<") = "<<(g=gcd(x,y))<<endl;
        fout << g << endl;
        assert(x%g==0&&y%g==0);

    }

    string test;
    cin >> test;
}