#include <bits/stdc++.h>
using namespace std;

int main()
{
    FILE *inputfile, *outputfile;
    inputfile = fopen("output_pairs.txt", "r+");
    outputfile = fopen("outputs.txt", "w+");
    long long i = 0;
    char temp[65];
    char s1[17];
    while (i < 200000){
        fscanf(inputfile, "%s", s1);
        for (int j = 0; j < 16; j++){
            int x;
            x=(int)s1[j]-102;
            for(int k = 0; k < 4; k++){
                temp[4*j+3-k]=(char)(x%2+48);
                x/=2;
            }
        }
        temp[64] = '\0';
        i++;
        fprintf(outputfile, "%s\n", temp);
    }
}