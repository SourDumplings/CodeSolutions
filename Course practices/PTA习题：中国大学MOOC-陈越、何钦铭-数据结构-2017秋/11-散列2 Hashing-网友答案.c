#include <stdio.h>
int nextPrime(int n){
    if(n==1)    return 2;
    int p = (n%2==1) ? n+2 : n+1;
    while (1) {
        int i;
        for(i=3; i*i<=p; i+=2){
            if(p%i == 0)    break;
        }
        if(i*i > p) break;
        else    p += 2;
    }
    return p;
}

int getPos(int hashTable[], int data, int tableSize){
    int oldKey = data%tableSize, newKey = oldKey;
    int step = 1;
    while (1) {
        if(hashTable[newKey] == -1){
            hashTable[newKey] = data;
            return newKey;
        }else{
            newKey = (oldKey+step*step)%tableSize;
        }
        step++;
        if(step > tableSize)   return -1;
    }

}

int main(int argc, const char * argv[]) {
    int M, N, tmp;
    int pos;
    scanf("%d%d", &M, &N);
    int tableSize = nextPrime(M);
    int hashTable[tableSize];
    for(int i=0; i<tableSize; i++){
        hashTable[i] = -1;
    }
    for(int i=0; i<N; i++){
        scanf("%d", &tmp);
        pos = getPos(hashTable, tmp, tableSize);
        if(pos == -1)   printf("-");
        else            printf("%d", pos);
        if(i != N-1)    printf(" ");
        else            printf("\n");
    }
    return 0;
}
