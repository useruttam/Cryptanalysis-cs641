#include <bits/stdc++.h>
int main()
{
	FILE *outputfile;
	outputfile=fopen("key_possible.txt","w+");
	int maxv=(int) pow(2,14);
	for(int i = 0; i < maxv; i++)
	{
		fprintf(outputfile,"%d11%d%d1%d%d01011%d100%d%d11%d11100%d1100101%d00101000%d01%d0111%d001\n", (i/8192)%2, (i/4096)%2, (i/2048)%2, (i/1024)%2, (i/512)%2, (i/256)%2, ((i/128))%2, ((i/64))%2, (i/32)%2, (i/16)%2, (i/8)%2, (i/4)%2, (i/2)%2, i%2);
	}              
	return 0;
}

