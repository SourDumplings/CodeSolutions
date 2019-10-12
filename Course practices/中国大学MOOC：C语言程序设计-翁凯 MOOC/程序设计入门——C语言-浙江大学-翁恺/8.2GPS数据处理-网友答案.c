#include <stdio.h>
#include <string.h>
//#include <math.h>
//#include<stdlib.h>
#define GPS_ARRAY_SIZE 1000
void gps(char str[], int times[]);
int main(int argc, const char * argv[]) {
    // insert code here...
    // TODO Auto-generated method stub
    char word[GPS_ARRAY_SIZE];
    int times[3]={0};
    char end[]="END";
    do
    {
    scanf("%s",word);
        gps(word,times);
    }while(strcmp(word,end)!=0);
    printf("%02d:%02d:%02d\n",times[0],times[1],times[2]);
    return 0;
}
/*GPS数据处理
 str[]是一行GPS数据，times[]长度为3，存储验证通过的时间的时分秒数
 */
void gps(char str[], int times[]){
    int i;
    if(str[0]=='$'&&str[1]=='G'&&str[2]=='P'&&str[3]=='R'&&str[4]=='M'&&str[5]=='C'&&str[6]!='\0'){

        //处理$和*之间所有字符异或
        int sum = 0; //异或值
        for(i=1; str[i]!='*'; i++){
            sum = sum ^ str[i];
        }

        //处理*后的字符
        char c1=str[i+1], c2=str[i+2];

        //int1,int2存储校验字符的整型值，mask存储int1,int2转换为10进制
        int int1, int2, mask;
        if(c1 >='A' && c1<='F'){
            int1 = 10+(c1-'A');
        }else{
            int1 = c1 - '0';
        }
        if(c2 >='A' && c2<='F'){
            int2 = 10+(c2-'A');
        }else{
            int2 = c2 - '0';
        }
        mask = int1*16 + int2; //16进制转10进制

        //找出状态值
        for(i=7; str[i]!='*'; i++){ //从第一个逗号后面开始遍历
            if(str[i]==',')break;
        }
        if(str[i+1]=='A'&&mask==sum){
            int hour = 10*(str[7]-'0') + (str[8]-'0'); //小时
            hour = (hour + 8) % 24;
            times[0] = hour;
            times[1] = 10 * (str[9] - '0') + (str[10] - '0'); //分钟
            times[2] = 10 * (str[11] - '0') + (str[12] - '0'); //秒
        }
    }
}
