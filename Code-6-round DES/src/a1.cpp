#include<bits/stdc++.h>
using namespace std;
int main(){
ifstream inputfile;
ofstream outputfile;
inputfile.open("final_rev_perm.txt");
outputfile.open("alpha1.txt");
int Encryption[] = {32, 1, 2, 3, 4, 5,4, 5,6, 7, 8, 9,8, 9, 10, 11, 12, 13,12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29,28, 29, 30, 31, 32, 1};
string mapi,inpstr;
while(getline(inputfile,mapi)){getline (inputfile,inpstr);for (int i=0;i<48;i++)outputfile<<mapi[Encryption[i]-1];outputfile<<'\n';}
return 0;
}
