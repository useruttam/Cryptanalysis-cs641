#include<bits/stdc++.h>
using namespace std;

vector <int> shifts = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
vector <int> permut_container = {  14, 17, 11, 24, 1, 5,3, 28 ,15,  6, 21, 10,23, 19, 12,  4, 26, 8,  16,  7, 27, 20, 13, 2,  41, 52, 31, 37, 47, 55,  30, 40, 51, 45, 33, 48,  44, 49, 39, 56, 34, 53,  46, 42, 50, 36, 29, 32};

vector<vector<int> > keyshift(16,vector<int>(48));

int main()
{
    ofstream outputfile;
    outputfile.open("permuted_key.txt");
    int  var_temp1, var_temp2,z;
    vector<int> comp_done = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56};

    int sw1=0,r=6;
    for (int i=0; i<r; i++) { 
      for (int j =0; j <shifts[i]; j++) {
        var_temp1 = comp_done[0];
        var_temp2 = comp_done[28];
        for (int k=0; k<27; k++) {
          comp_done[k] = comp_done[k+1];
          comp_done[k+28] = comp_done[k+29];
        }
        comp_done[27] = var_temp1;
        comp_done[55] = var_temp2;
      }
      int j = sw1 ? r-1-i :i ;   
      for (int k=0; k< 48 ; k++)  keyshift[j][k] = comp_done[permut_container[k] -1];
    }
    vector <int> a(48);  
    for(z=0;z<48;z++) a[z]=keyshift[5][z];
    char key[48],exp_key[56];
    for (int i=0;i<48;i++) cin>>key[i];
    for (int i=0;i<56;i++) exp_key[i]='X';
    for (int i=0;i<48;i++) 
        exp_key[a[i]-1]=key[i];
    for (int i=0;i<56;i++) outputfile<<exp_key[i];
    return 0;
}


