#include <stdio.h>
int func_days(int input){
    int tmp = 0;

    tmp = input / 1440;

    return tmp;
}

int func_hour(int input){
    int tmp = 0;

    tmp = input / 60;

    return tmp % 24;
}

int func_minute(int input){
    return input % 60;
}

int main(){
    int input;

    printf("분을 입력하세요.\n");
    scanf("%d", &input);

    printf("%d분은 %d일 %d시간 %d분입니다.", input, func_days(input), func_hour(input), func_minute(input));

    return 0;
}