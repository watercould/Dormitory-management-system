#define FLOOR_NUM 6//每一栋楼的楼层数
#define NUMBER 4 //每个宿舍的最大人数
#define MAX 200//待定名单最大人数
#define DORMITORY_MAX 10 //每层楼的最大宿舍数
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>
#pragma once
typedef struct {//每个成员的个人信息
	wchar_t name[50];//姓名
	wchar_t id[15];//学号
	wchar_t native_place[50];//籍贯
	wchar_t hobby[50];//兴趣爱好
	wchar_t nation[50];//民族
	wchar_t religion[50];//宗教
	wchar_t abroad;//是否是境外生，是为1，否为0
	int check;//是否报到
}member_meg,*m_meg;
typedef struct dormitory{//每个宿舍信息
	m_meg member[NUMBER];//成员组成
	int dormitory_num;//宿舍人数
	int dormitory_id;//宿舍号
	struct dormitory* next;
}dormitory,* dormitory_p;

typedef struct{//每栋楼的信息
	dormitory_p floor[FLOOR_NUM];//每层楼的信息，该数组元素指向每层楼第一个宿舍
}Building,*building;

typedef struct{//待定名单
	int member_num;//待定名单人数
	m_meg unscheduled_member[MAX];//待定名单成员信息
}pendingList,*pend;