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
		printf("�޷����ļ�\n");
		return -1;
	}
	if (err_out != 0) {
		printf("�޷����ļ�\n");
		return -1;
	}
	c = fgetc(in);
	printf("%c", c);
	fprintf(&out, "%c", c);

	printf("��ӭʹ�����ᴲλ����ϵͳ��\n");
	printf("\n================================\n");
	printf("�����뱨��ѧ������Ϣ��\n(��������ѧ��������ѧ�ţ����ᣬ��Ȥ���ã����壬�ڽ̣��Ƿ�Ϊ��������1Ϊ������,0Ϊ��������)\n");
	fclose(in);
	fclose(out);
	return 0;
}*/


