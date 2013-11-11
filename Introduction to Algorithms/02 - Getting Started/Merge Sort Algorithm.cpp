#include <iostream>
#include <limits>
#define INF numeric_limits<T>::min()
using namespace std;

template <typename T>
void merge(T *A, int p, int q, int r, int (*compar)(T,T)) {
    int n1 = q - p + 1;
    int n2 = r - q;
    T L[n1+1], R[n2+1];
    for(int i=1; i<=n1; i++)
        L[i] = A[p+i-1];
    for(int j=1; j<=n2; j++)
        R[j] = A[q+j];
    L[n1+1] = INF;
    R[n2+1] = INF;
    int i = 1;
    int j = 1;
    for(int k=p; k<=r; k++)
        if(compar(L[i],R[j]) <= 0) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
}

template <typename T>
void msort(T *A, int p, int r, int (*compar)(T,T)) {
    if(p < r) {
        int q = (p+r) / 2;
        msort(A,p,q, compar);
        msort(A,q+1,r, compar);
        merge(A,p,q,r, compar);
    }
}

int int_compare(int a, int b) {
  return (a-b);
}

int c_compare(char a, char b) {
    return (b-a);
}

int main(void)
{
    // Demonstrate integer msort
    int i_values[] = {5,2,4,7,1,3,2,6};
    int i_len = sizeof(i_values) / sizeof(int);
    msort(i_values, 0, i_len-1, int_compare);
    cout << "Ascending: ";
    for(int i=0; i<i_len; i++)
        cout << i_values[i] << ends;
    cout << endl;

    // Demonstrate string msort
    char c_values[] = {'f', 'a', 'k', 'b', 'h'};
    int c_len = sizeof(c_values) / sizeof(char);
    msort(c_values, 0, c_len, c_compare);
    cout << "Descending: ";
    for(int i=0; i<c_len; i++)
        cout << c_values[i] << ends;
    cout << endl;
    return(0);
}
