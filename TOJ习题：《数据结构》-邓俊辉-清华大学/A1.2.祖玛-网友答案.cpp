#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

using namespace std;

const int SZ = 1<<20;  //快速io
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

char s[20001];
char temp[20001];
int len = 0, po;

int del(int p){
    int first = p,second = p;
    char elem = s[p];
    while(s[first] == elem && first) first--;
    if(first || s[first] != elem) first++;
    while(s[second] == elem && second < len) second++;
    if(second - first > 2)
    {
        strcpy(temp,s + second);
        strcpy(s + first, temp);
        len = len + first - second;
        po = first;
        return 1;
    }
    else
        return 0;
}


int main(){
    gets(s);
    while(s[len] >= 'A' && s[len] <= 'Z') len++;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i ++) {
        char c;
        scanf("%d %c",&po,&c);
        strcpy(temp, s + po);
        strcpy(s + po + 1, temp);
        s[po] = c;
        len ++;
        while(del(po) && len);
        if(len)
            puts(s);
        else
            puts("-");

    }
    return 0;
}
