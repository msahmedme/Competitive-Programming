#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    for(int i=0; i<t; ++i){
        char name[101];
        scanf("%s", name);

        int len = strlen(name);

        if (len<=10) 
            printf("%s\n", name);
        else
            printf("%c%d%c\n", name[0], len-2, name[len-1]);
    }
    
    return 0;

}

