#include <iostream>
#include <vector>
using namespace std;
vector<int> add(vector<int> A, vector<int> B)
{
    int m = A.size();
    int n = B.size();
    int size = max(m, n);
    vector<int> sum(size);
    for(int i = 0; i<size; i++)
    {
        sum[i] = 0;
    }
    for (int i = 0; i<m; i++)
        sum[i] = A[i];
    for (int i=0; i<n; i++)
        sum[i] += B[i];
    return sum;
}
vector<int> multiply(vector<int> A, vector<int> B)
{
    int m = A.size(), n=B.size();
    vector<int> prod(m+n-1);
    for (int i = 0; i<m+n-1; i++)
        prod[i] = 0;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            prod[i+j] += A[i]*B[j];
    }
    return prod;
}
void printPoly(vector<int> poly)
{
    int n = poly.size();
    for (int i=0; i<poly.size(); i++)
    {
        cout << poly[i];
        if (i != 0)
            cout << "x^" << i ;
        if (i != n-1)
            cout << " + ";
    }
}
int main()
{
    int m,n;
    cout<<"Enter the degree of first polynomial: ";
    cin>>m;
    m++;
    vector<int> A(m);
    cout<<"Enter the coefficients in increasing order of degree ( starting from 0): ";
    for(int i = 0; i<m; i++)
    {
        cin>>A[i];
    }
    cout<<"Enter the degree of second polynomial: ";
    cin>>n;
    n++;
    vector<int> B(n);
    cout<<"Enter the coefficients in increasing order of degree ( starting from 0): ";
    for(int i = 0; i<n; i++)
    {
        cin>>B[i];
    }
    cout << "First polynomial is \n";
    printPoly(A);
    cout << "\nSecond polynomial is \n";
    printPoly(B);
    vector<int> sum = add(A, B);
    vector<int> prod = multiply(A,B);
    cout << "\nAddition of polynomials is \n";
    printPoly(sum);
    cout<<"\nMultiplication of polynomials is \n";
    printPoly(prod);
    return 0;
}
