#include <iostream>
#include <vector>
#include <string>
using namespace std;
class pru
{
    int length;
    int width;
public:
    pru()
    {
         int length=0;
         int width=0;
    }
    void set(int l, int w)
    {
        length=l;
        width=w;
    }
    pru(int l, int w)
    {
        length=l;
        width=w;
    }
    int getArea() const
    {
        return length*width;
    }
    void print() const
    {
        cout<<"length:"<<length<<" width:"<<width<<endl;

    }
    void print2() const
    {
        cout<<"length:"<<length<<" width:"<<width<<" square:"<<getArea()<<endl;

    }
};
int main()
{
    int n;
    cout<<"n=";
    cin>>n;
    int l;
    int w;
    int S;
    pru *ppru;
	ppru=new pru[n];
	vector<pru> vecpru(n);
	for(int i=0; i<n; i++)
	{
	cout<<"Rectangle N="<<(i+1)<<":\n"<<"length:";
	cin.ignore();
	cin>>l;
	cout<<"Rectangle N="<<(i+1)<<":\n"<<"width:";
	cin.ignore();
	cin>>w;
	ppru[i].set(l, w);
	vecpru[i].set(l, w);
	}
	for(int i=0; i<n; i++) ppru[i].print();
	int c;
	cout<<"Number: ";
	cin>>c;
	for(int i=0; i<n; i++)
    {
        S=ppru[i].getArea();
        if (S>c)
        {

            cout<<(i+1)<<") ";
            for(;;)
            {
                ppru[i].print2();
                break;
            }
        }

    }
    return 0;
}
