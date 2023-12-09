/*
#include"struct.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILE_IN "student_msg.txt"
#define FILE_OUT "domitory.txt"

int main()
{
	FILE* in, * out;
	errno_t err_in = fopen_s(&in, FILE_IN, "r");
	errno_t err_out = fopen_s(&out, FILE_OUT, "w");

	char c;
	int i, ja = 1, count_a = 1;
	if (err_in != 0) {
		printf("无法打开文件\n");
		return -1;
	}
	if (err_out != 0) {
		printf("无法打开文件\n");
		return -1;
	}
	c = fgetc(in);
	printf("%c", c);
	fprintf(&out, "%c", c);

	printf("欢迎使用宿舍床位分配系统！\n");
	printf("\n================================\n");
	printf("请输入报道学生的信息：\n(依次输入学生姓名，学号，籍贯，兴趣爱好，民族，宗教，是否为境外生（1为境外生,0为境内生）)\n");
	fclose(in);
	fclose(out);
	return 0;
}*/


