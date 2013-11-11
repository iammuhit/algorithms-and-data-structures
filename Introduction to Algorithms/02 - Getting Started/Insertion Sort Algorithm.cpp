#include <iostream>
using namespace std;

template <typename T>
void isort(T *A, size_t size, int (*compar)(T,T)) {
    for(int j=1; j<size; j++) {
        T key = A[j];
        int i = j - 1;
        while(i>=0 && compar(A[i],key) >= 0) {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

int int_compare(int a, int b) {
  return (a-b);
}

int str_compare(string a, string b) {
  return b.compare(a);
}


int main(void)
{
    // Demonstrate integer isort
    int i_values[] = {9, 5, 2, 0, 1};
    int i_len = sizeof(i_values) / sizeof(int);
    isort(i_values, i_len, int_compare);
    cout << "Ascending: ";
    for(int i=0; i<i_len; i++)
        cout << i_values[i] << ends;
    cout << endl;

    // Demonstrate string isort
    string s_values[] = {"Muhit", "Moslu", "Raju", "Yanis", "Belal"};
    int s_len = sizeof(s_values) / sizeof(string);
    isort(s_values, s_len, str_compare);
    cout << "Descending: ";
    for(int i=0; i<s_len; i++)
        cout << s_values[i] << ends;
    cout << endl;

    return(0);
}
