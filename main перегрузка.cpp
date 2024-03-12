#include <iostream>
#include <fstream>
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
         length = 0;
         width = 0;
    }

    void set(int l, int w)
    {
        length = l;
        width = w;
    }

    pru(int l, int w)
    {
        length = l;
        width = w;
    }
    int getLength() const
{
    return length;
}

int getWidth() const
{
    return width;
}


    int getArea() const
    {
        return length * width;
    }

    void print() const
    {
        cout << "length: " << length << " width: " << width << endl;
    }

    void print2() const
    {
        cout << "length: " << length << " width: " << width << " square: " << getArea() << endl;
    }

    friend ostream& operator<<(ostream& out, const pru& p)
    {
        out << "length: " << p.length << ", width: " << p.width << ", area: " << p.getArea();
        return out;
    }

    friend istream& operator>>(istream& in, pru& p)
    {
        in >> p.length >> p.width;
        return in;
    }
};

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int n;
    inputFile >> n;
    int c;
    inputFile >> c;
    int l, w, S;

    pru* ppru = new pru[n];
    vector<pru> vecpru(n);

    for (int i = 0; i < n; i++)
    {
        inputFile >> l >> w;
        ppru[i].set(l, w);
        vecpru[i].set(l, w);
    }

    for (int i = 0; i < n; i++)
    {
        outputFile << "Rectangle " << i + 1 << ": " << vecpru[i] << endl;
    }

    for (int i = 0; i < n; i++)
    {
        S = ppru[i].getArea();
        if (S > c)
        {
           outputFile << (i + 1) << ") " << "length: " << ppru[i].getLength() << ", width: " << ppru[i].getWidth() << ", square: " << S << endl;

        }
    }

    delete[] ppru;

    inputFile.close();
    outputFile.close();

    return 0;
}



