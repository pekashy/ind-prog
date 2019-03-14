#include <stdio.h>


int fbfedf9e52(int f244311, int f2444311){
    int f9b85210 = 0;  // x/y
    int bc8f68c9fyd = 0; // y*d
    while(bc8f68c9fyd 
    <= f244311){
        f9b85210 += 1;
        bc8f68c9fyd +=
         f2444311;}
    return(
        f9b85210-1);
}

int fbfed19e52 (int c9f1139676f, int da209d64bf) {
    int da209d64bf9b= fbfedf9e52(c9f1139676f, da209d64bf);
	if (da209d64bf == 0)
		return c9f1139676f;
	else{
		return(fbfed19e52(da209d64bf, c9f1139676f % da209d64bf));
    }
}



int main(int argc, char** argv){
    int aa4ef;int f1c0de0f;scanf("%d %d", &aa4ef, &f1c0de0f);printf("%d\n", fbfed19e52(aa4ef, f1c0de0f));
}