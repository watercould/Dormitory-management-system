#define FLOOR_NUM 6//ÿһ��¥��¥����
#define NUMBER 4 //ÿ��������������
#define MAX 200//���������������
#define DORMITORY_MAX 10 //ÿ��¥�����������
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>
#pragma once
typedef struct {//ÿ����Ա�ĸ�����Ϣ
	wchar_t name[50];//����
	wchar_t id[15];//ѧ��
	wchar_t native_place[50];//����
	wchar_t hobby[50];//��Ȥ����
	wchar_t nation[50];//����
	wchar_t religion[50];//�ڽ�
	wchar_t abroad;//�Ƿ��Ǿ���������Ϊ1����Ϊ0
	int check;//�Ƿ񱨵�
}member_meg,*m_meg;
typedef struct dormitory{//ÿ��������Ϣ
	m_meg member[NUMBER];//��Ա���
	int dormitory_num;//��������
	int dormitory_id;//�����
	struct dormitory* next;
}dormitory,* dormitory_p;

typedef struct{//ÿ��¥����Ϣ
	dormitory_p floor[FLOOR_NUM];//ÿ��¥����Ϣ��������Ԫ��ָ��ÿ��¥��һ������
}Building,*building;

typedef struct{//��������
	int member_num;//������������
	m_meg unscheduled_member[MAX];//����������Ա��Ϣ
}pendingList,*pend;