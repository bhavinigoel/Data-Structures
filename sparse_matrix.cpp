#include<iostream>
using namespace std;
int main()
{
    int a[3][3];
    cout << "ENTER THE ELEMENTS OF THE MATRIX" << endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> a[i][j];
        }

    }
for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << a[i][j] << "\t";
        }
            cout << endl;
    }

    int count_zero=0 ,not_zero=0;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]==0)
            {
                count_zero++;
            }
            else
            {
                not_zero++;
            }
        }

    }

    if(not_zero > count_zero)
    {
        cout << "NOT A SPARSE MATRIX" << endl;
    }
    int s[not_zero][3],k=0;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!=0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }
cout << endl;
cout << endl;
cout << endl;
cout << "SPARSE MATRIX :" << endl;

    for(int i=0;i<not_zero;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << s[i][j] << "\t";
        }
        cout << endl;
    }
int t[3][not_zero];

cout << endl;
    cout << "TRANSPOSE OF THE SPARSE MATRIX :" << endl;
       for(int i=0;i<3;i++)
    {
        for(int j=0;j<not_zero;j++)
        {
            t[i][j] = s[j][i];
        }
        cout << endl;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<not_zero;j++)
        {
            cout << t[i][j] << "\t";
        }
        cout << endl;
    }

return 0;
}



