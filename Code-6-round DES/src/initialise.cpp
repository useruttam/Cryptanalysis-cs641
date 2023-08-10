#include <bits/stdc++.h>
using namespace std;
int main()
{long long int _var;
    FILE *file_Ptr;
    char arr[64];
    file_Ptr = fopen("inputs.txt", "w+");
    for (int n=0 ; n < 100000; n++){for (int i = 0; i < 64; i++){_var = rand() % 2;_var += 48; arr[i] = _var;}for (int i = 0; i < 64; i++)fprintf(file_Ptr, "%c", arr[i]);fprintf(file_Ptr, "\n");}
}