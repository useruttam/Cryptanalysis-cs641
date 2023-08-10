#include<bits/stdc++.h>
using namespace std;
int main()
{

    int VAR3,VAR1,VAR2,VAR4;
    ifstream _input_file_0,_input_file_1;
    ofstream _ouput_file_0,_ouput_file_1,_ouput_file_2;
    int _arr[8][8],_brr[8][8],_crr[8][8],_drr[8][8],_Extra1[8][8],_Extra2[8][4],_Extra3,m,n,o;
    int invrfp[8][8]= {57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7,58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8};
int ex[8][6] = {
  32, 1, 2, 3, 4, 5,4, 5,6, 7, 8, 9,8, 9, 10, 11, 12, 13,12, 13, 14, 15, 16, 17,16, 17, 18, 19, 20, 21,20, 21, 22, 23, 24, 25,24, 25, 26, 27, 28, 29,28, 29, 30, 31, 32, 1
};
int invp[8][4] = {
    9, 17, 23, 31,13, 28, 2, 18,24, 16, 30, 6,26, 20, 10, 1,8, 14, 25, 3,4, 29, 11, 19,32, 12, 22, 7,5, 27, 15, 21,};

    _input_file_1.open("outputs.txt");
    _ouput_file_0.open("betaxor.txt");
    _ouput_file_1.open("gammaxor.txt");
    _ouput_file_2.open("final_rev_perm.txt");
    string str1,str2;
    while ( getline (_input_file_1,str1) )
    {
        getline (_input_file_1,str2);
        VAR3=0;
    for(VAR1=0;VAR1<8;VAR1++)
        for(VAR2=0;VAR2<8;VAR2++)
    {
        _arr[VAR1][VAR2]=str1[VAR3]-48;
        VAR3++;

    }

    VAR3=0;
    for(VAR1=0;VAR1<8;VAR1++)
        for(VAR2=0;VAR2<8;VAR2++)
    {
        _brr[VAR1][VAR2]=str2[VAR3]-48;
        VAR3++;
    }

   for(VAR1=0;VAR1<8;VAR1++)
        for(VAR2=0;VAR2<8;VAR2++)
        {
            VAR3=(invrfp[VAR1][VAR2]-1)/8;
            VAR4=(invrfp[VAR1][VAR2]-1)%8;
            _crr[VAR1][VAR2]=_arr[VAR3][VAR4];
            _ouput_file_2<<_crr[VAR1][VAR2];
        }
        _ouput_file_2<<'\n';
    for(VAR1=0;VAR1<8;VAR1++)
        for(VAR2=0;VAR2<8;VAR2++)
        {
            VAR3=(invrfp[VAR1][VAR2]-1)/8;
            VAR4=(invrfp[VAR1][VAR2]-1)%8;
            _drr[VAR1][VAR2]=_brr[VAR3][VAR4];
            _ouput_file_2<<_drr[VAR1][VAR2];
        }
        _ouput_file_2<<'\n';
for(VAR1=0;VAR1<8;VAR1++)
    for(VAR2=0;VAR2<8;VAR2++)
    {
        _Extra1[VAR1][VAR2]=_crr[VAR1][VAR2]^_drr[VAR1][VAR2];
    }
     for(VAR1=0;VAR1<8;VAR1++)
  {
    for(VAR2=0;VAR2<6;VAR2++)
    {
        VAR3=(ex[VAR1][VAR2]-1)/8;
        VAR4=(ex[VAR1][VAR2]-1)%8;
        _Extra3=_Extra1[VAR3][VAR4];
        _ouput_file_0<<_Extra3;
    }
  }
_Extra1[4][5]=_Extra1[4][5]^1;
        _ouput_file_0<<'\n';
    for(VAR1=0;VAR1<8;VAR1++)
        for(VAR2=0;VAR2<4;VAR2++)
        {
            VAR3=(invp[VAR1][VAR2]-1)/8;
            VAR4=(invp[VAR1][VAR2]-1)%8;
            _Extra2[VAR1][VAR2]=_Extra1[VAR3+4][VAR4];
            _ouput_file_1<<_Extra2[VAR1][VAR2];
        }
        _ouput_file_1<<'\n';
    }
    _input_file_0.close();
    _input_file_1.close();
    _ouput_file_0.close();
    _ouput_file_1.close();
    _ouput_file_2.close();
    return 0;
    }
