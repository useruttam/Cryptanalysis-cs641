#include<bits/stdc++.h>
using namespace std;
void DECRYPT_OCT(unsigned char *packed,unsigned char *binary)
{unsigned int var1, var2, var3;
for (var1=0; var1<8; var1++) {var3 = *packed++;for (var2=0; var2<8;var2++) *binary++ = (var3>>(7-var2)) &01 ;}
}

void CRYPT_OCT(unsigned char *packed,unsigned char *binary)
{unsigned int var1, var2, var3;
  for (var1=0; var1<8; var1++) {
    var3 = 0;
    for (var2=0; var2<8;var2++) var3  = (var3<<1)+ *binary++;
    *packed++ = var3;
  }
}
unsigned int S[8][64]=
{
  14, 4, 13, 1, 2, 15, 11, 8, 3 , 10, 6, 12, 5, 9, 0, 7,0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,4, 1 , 14, 8, 13, 6, 2, 11, 15, 12, 9, 7,3, 10, 5, 0,15, 12, 8,2,4, 9, 1,7 , 5, 11, 3, 14, 10, 0, 6, 13 ,
  15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0,5, 10,3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,0, 14, 7, 11, 10, 4, 13, 1, 5, 8,12, 6, 9, 3, 2, 15,13, 8, 10, 1, 3, 15, 4, 2,11,6, 7, 12, 0,5, 14, 9,
  10, 0, 9,14,6,3,15,5, 1, 13, 12, 7, 11, 4,2,8,13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12,5, 10, 14, 7,1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,
  7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,10, 6, 9, 0, 12, 11, 7, 13, 15, 1 , 3, 14, 5, 2, 8, 4,3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,
  2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,14, 11,2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3,
  12, 1, 10, 15, 9, 2, 6,8, 0, 13, 3, 4, 14, 7, 5, 11,10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,9, 14, 15, 5, 2,8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13,
  4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,
  13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12,7,1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 };



unsigned int PRE_COM1[] = {
  57, 49, 41, 33, 25, 17, 9,1, 58, 50, 42, 34, 26, 18,10,  2, 59, 51, 43, 35, 27,19, 11,  3, 60, 52, 44, 36,63, 55, 47, 39, 31, 23, 15,7, 62, 54, 46, 38, 30, 22,14,  6, 61, 53, 45, 37, 29,21, 13,  5, 28, 20, 12,  4
};

unsigned short _SHUF[] = {
1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

unsigned int PRE_COM[] = {
  14, 17, 11, 24,  1, 5,3, 28 ,15,  6, 21, 10,23, 19, 12,  4, 26, 8,16,  7, 27, 20, 13, 2,41, 52, 31, 37, 47, 55,30, 40, 51, 45, 33, 48,44, 49, 39, 56, 34, 53,46, 42, 50, 36, 29, 32
};


unsigned char KEY_SF[16][48];


void KEY_INIT(int var_Main_,unsigned char *CRYPT_DEC,int _res)

{
    unsigned int var1, var2, var3, temp_1, temp_2;
  int var_z;
 

  for ( var1=0; var1<_res; var1++) { 
    for (var2 =0; var2 <_SHUF[var1]; var2++) {
      temp_1 = CRYPT_DEC[0];
      temp_2 = CRYPT_DEC[28];
      for ( var3=0; var3<27; var3++) {
	CRYPT_DEC[var3] = CRYPT_DEC[var3+1];
	CRYPT_DEC[var3+28] = CRYPT_DEC[var3+29];
      }
      CRYPT_DEC[27] = temp_1;
      CRYPT_DEC[55] = temp_2;
    }
  
    var2 = var_Main_ ? _res-1-var1 :var1 ;  


    for (var3=0; var3< 48 ; var3++)  KEY_SF[var2][var3] = CRYPT_DEC[PRE_COM[var3] -1];

  }

  return;

}

unsigned int S_PI[] = {
  58,50,42, 34,26,18,10,2,60,52,44,36,28,20,12,4,62,54, 46, 38, 30, 22, 14,6,64, 56, 48, 40,32,24, 16, 8,57, 49, 41, 33,25,17, 9,1,59, 51,43,35,27,19,11,3,61,53,45,37,29,21,13, 5,63,55, 47,39,31,23,15,7
};



unsigned int _PermFR[] = {
  8,40,16,48,24,56,32,64,7, 39,15,47,23,55,31,63,6,38,14,46,22,54,30,62,5,37,13,45, 21,53,29,61,4,36,12,44,20,52,28,60,3, 35, 11,43,19,51,27,59,2, 34, 10, 42,18, 50,26,58,1,33,9,41, 17, 49, 25,57,
};
unsigned int _Enc[] = {
  32, 1, 2, 3, 4, 5,4, 5,6, 7, 8, 9,8, 9, 10, 11, 12, 13,12, 13, 14, 15, 16, 17,16, 17, 18, 19, 20, 21,20, 21, 22, 23, 24, 25,24, 25, 26, 27, 28, 29,28, 29, 30, 31, 32, 1
};
unsigned int _Perm_[] = {
  16, 7, 20, 21,29, 12, 28, 17,1, 15, 23, 26,5, 18, 31,10,2, 8, 24, 14,32, 27, 3, 9,19, 13, 30, 6,22, 11, 4, 25,
};
unsigned int INV_P[] = {
	9, 17, 23, 31,13, 28, 2, 18,24, 16, 30, 6,26, 20, 10, 1,8, 14, 25, 3,4, 29, 11, 19,32, 12, 22, 7,5, 27, 15, 21,
};
void ALGO_DES(unsigned char *in,unsigned char *out,unsigned int _res,char _FLag)

{
    unsigned int var1, var2, var3, var_temp_;
  static unsigned char block[64];
  static unsigned char RIGHT_LEFT[64], f[32], preS[48];

int var_z;
  DECRYPT_OCT(in, block);
  
       for (var2 =0; var2<64 ; var2++)
        {
                RIGHT_LEFT[var2] = block[S_PI[var2] -1];    
        }

        

        for (var1=0; var1<_res; var1++) { 
	  for( var2=0; var2<48; var2++) {
	    preS[var2] = RIGHT_LEFT[_Enc[var2] +31]^KEY_SF[var1][var2];
	  }
	  for (var2=0; var2<8; var2++) {
 var3= 6*var2;
	    var_temp_= preS[var3];
	    var_temp_ = (var_temp_<<1) | preS[var3+5];
	    var_temp_ = (var_temp_<<1)| preS[var3+1];
	    var_temp_ = (var_temp_<<1)| preS[var3+2];
	    var_temp_ = (var_temp_<<1)| preS[var3+3];
	    var_temp_ = (var_temp_<<1)| preS[var3+4];
	    var_temp_ = S[var2][var_temp_];
	    var3= 4*var2;
	    f[var3] = (var_temp_>>3)&1;
	    f[var3+1] = (var_temp_ >> 2) & 1;
	    f[var3+2] = (var_temp_ >> 1) & 1;
	    f[var3+3] = var_temp_ &1;
	  }


	  for (var2=0; var2 <32; var2++) {
	    var_temp_ = RIGHT_LEFT[var2+32];
		if (_FLag == 'N')
	    	RIGHT_LEFT[var2+32] = RIGHT_LEFT[var2]^f[_Perm_[var2] -1];
		else
	    	RIGHT_LEFT[var2+32] = RIGHT_LEFT[var2]^f[INV_P[var2] -1];
	
	    RIGHT_LEFT[var2] =var_temp_;
	  }
        }

        for (var2=0; var2 < 64; var2++) block [var2] = RIGHT_LEFT[_PermFR[var2]-1];
    CRYPT_OCT(out, block);
	  out[9] = '\0';
}
int main()
{
    int var_Main_;int var_to_h=0;unsigned char key[56],key2[56];int _res;unsigned char cipher2[9];char _FLag;int var1;string var_str;ifstream input_file_;input_file_.open("key_possible.txt");
    while( getline(input_file_,var_str))
    {
        for(var1=0;var1<56;var1++)
            key[var1]=var_str[var1]-48;
       for(var1=0;var1<56;var1++)
            key2[var1]=key[var1];
    var_Main_=0;
    _res=6;
    unsigned char get_p_c[9]={0,0,0,0,0,0,0,0,'\0'};
    unsigned char Text_cipher[9]={220, 234, 91, 186, 90, 99, 158, 195,'\0'};
    _FLag='N';
    var_to_h=0;
    KEY_INIT(var_Main_,key,_res);
    ALGO_DES(get_p_c,cipher2,_res,_FLag);
    for(var1=0;var1<8&&var_to_h==0;var1++){if(int(Text_cipher[var1])!=int(cipher2[var1])) var_to_h=1;}
    if(var_to_h==0)
    {
        for(var1=0;var1<56;var1++)
        {    cout<<int(key2[var1]);
        }}}
    input_file_.close();
    return 0;
}


