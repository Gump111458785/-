#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

// 信号处理函数，防止 Ctrl+C 终止程序
void sigint_handler(int sig) {
    // 移动光标到行首，清空当前行内容，然后重新输出提示信息
    printf("\b\b  \b\b");  // 删除 ^C
    fflush(stdout);
}

int main() {
    int dividend, divisor;
    char input[10];

    // 捕获 SIGINT 信号，防止 Ctrl+C 终止进程
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("输入被除数\n");
        scanf("%s", input);

        // 判断是否为 "exit" 命令
        if (strcmp(input, "exit") == 0) {
            printf("程序退出。\n");
            break;
        }

        // 将输入的被除数转换为整数
        dividend = atoi(input);

        printf("输入除数\n");
        scanf("%s", input);

        // 判断是否为 "exit" 命令
        if (strcmp(input, "exit") == 0) {
            printf("程序退出。\n");
            break;
        }

        // 将输入的被除数转换为整数
        divisor = atoi(input);

        // 检查除数是否为0
        if (divisor == 0) {
            printf("Divide by zero!\n");
        } else {
            printf("%d / %d = %d\n", dividend, divisor, dividend / divisor);
        }
    }

    return 0;
}
