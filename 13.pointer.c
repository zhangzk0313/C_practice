/*************************************************************************
	> File Name: 13.pointer.c
	> Author: zhang zk
	> Mail: 815028387@qq.com 
	> Created Time: 2019年12月14日 星期六 16时45分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define offset(T, a) (long long)(&(((T *)(NULL))->a))
#define pchar char * //简单替换、傻瓜替换。
typedef char * ppchar;//给他一个别名。

struct Data {
	int a;
	double b;
	char c;
};

void output_arg(int argc, char *argv[], char *env[]){
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	for (int i = 0; env[i]; i++) {
		printf("env[%d] = %s\n", i, env[i]);
		if (strncmp(env[i], "USER=", 5) == 0) {
			if (strcmp(env[i] + 5, "huguang")) {
				printf("you don't have authority");
				exit(0);
			}
		}
	}
	return;
}

int main(int argc, char *argv[], char *env[]) {
	int num1 = 0x61626364;
	int num2 = 0x616263;
	pchar p1, p2;
	ppchar p3, p4;
	printf("%s\n", (char *)(&num2));//cba
	printf("%s\n", (char *)(&num1));//输出cbadcba 1.与栈区存储数据方式有关，2.因为末尾才遇到‘\0’
	printf("%s\n", (char *)(&num1 + 1));//输出cba 等同14行
	printf("sizeof(p1) = %lu sizeof(p2) = %lu\n", sizeof(p1), sizeof(p2));
	printf("sizeof(p3) = %lu sizeof(p4) = %lu\n", sizeof(p3), sizeof(p4));
	output_arg(argc, argv, env);
 	return 0;
}
