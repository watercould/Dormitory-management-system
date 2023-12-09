
#include"struct.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>
#define FILE_IN "student_msg.txt"
#define FILE_OUT "dormitory.txt"
//初始化宿舍
dormitory_p init_dormitory() {
	dormitory_p head, p, q;
	head = q=(dormitory_p)malloc(sizeof(dormitory));
	if (head == NULL)return NULL;
	head->next = NULL;
	q = head;
	for (int i = 1; i <= 10; i++) {
		p = (dormitory_p)malloc(sizeof(dormitory));
		if (p == NULL) return NULL;
		p->dormitory_id = i;
		p->dormitory_num = 0;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	return head;
}
//初始化楼栋
building init_building(building building_2) {
	dormitory_p dor = (dormitory_p)malloc(sizeof(dormitory));
	for (int i = 0; i < FLOOR_NUM; i++) {
		dor = init_dormitory();
		building_2->floor[i] = dor;
	}
	return building_2;
}
//初始化待选名单
pend init_pendingList() {
	pend pending = (pend)malloc(sizeof(pendingList));
	if (pending == NULL) return NULL;
	pending->member_num = 0;
	return pending;
}
//分宿舍 
void insert_dormitory(m_meg  member, building building_1) {
	dormitory_p p=(dormitory_p)malloc(sizeof(dormitory_p));
	

	int floor_num = 0;//从第一层开始遍历
	int  k = 0, j, flag = 0, flag_native = 0;//flag判断是否入住,0为新开房间,1为入住,flag_native判断籍贯是否相同，0为不同，1为相同
	while ((floor_num <  FLOOR_NUM ) && (flag != 1)) {
		p = building_1->floor[floor_num]->next;//p指向每一层楼的首个房间
		while ((p != NULL) && (flag != 1)) {
			if ((p->dormitory_num <  NUMBER) && (flag != 1)) {//宿舍尚未满人
				flag = 0;
				if (p->dormitory_num == 0) {//宿舍一开始没人
					p->member[0] = member;//直接拎包入住
					
					p->dormitory_num++;//人数+1
					flag = 1;
				}
				else {//宿舍有人了
					flag_native = 0;
					for (j = 1; j <= p->dormitory_num; j++) {//判断籍贯是否相同
						if (wcscmp(p->member[j-1]->native_place, member->native_place) == 0) {//同一籍贯
							flag_native = 1;
							break;
						}

					}
					if (flag_native == 0) {//籍贯不同
						for (j = 1; j <= p->dormitory_num; j++) {
							if (wcscmp(p->member[j-1]->hobby, member->hobby) == 0) {//同一个兴趣爱好
								flag = 1;//标志入住
								break;
							}
						}

					}
					if (flag) {//入住
						/*wprintf(L"%ls\n", p->member[p->dormitory_num]->name);
						wprintf(L"%ls\n", member->id);*/
						p->member[p->dormitory_num++] = member;
						
					}
				}

			}
			
			p = p->next;
		}
		floor_num++;
	}

}
//输出
void print(building building_temp) {
	int floor_num = 0;
	dormitory_p p = (dormitory_p)malloc(sizeof(dormitory));
	int flag = 0;//判断是否是空宿舍，如果是空宿舍则提前退出循环
	int j = 0;
	while (floor_num < FLOOR_NUM) {
		p = building_temp->floor[floor_num]->next;
		if ((building_temp->floor[0]->next->dormitory_num == 0) || (building_temp->floor[0]->next == NULL)) {
			printf("该楼栋无人居住!\n");
			return;
		}
		printf("%d楼：\n", floor_num + 1);
		floor_num++;
		while (p != NULL) {
			if (p->dormitory_num > 0) {

				printf("%d\t", p->dormitory_id);
				for (j = 0; j < p->dormitory_num; j++) {
					//if (p->member[j]->check == 1) {//报道的才输出
						wprintf(L"%ls\t", p->member[j]->name);
					//}
					

				}
				printf("\t共%d人\n", p->dormitory_num);
			}
			else {
				flag = 1;
				break;
			}
			p = p->next;
		}
		if (flag) break;
		p = building_temp->floor[floor_num];
	}
}
//修改
void modify(wchar_t *temp_id, building building_temp) {
	int floor_num = 0;
	dormitory_p p = (dormitory_p)malloc(sizeof(dormitory));
	int flag = 0;//判断是否是空宿舍，如果是空宿舍则提前退出循环
	int j = 0;
	while (floor_num < FLOOR_NUM) {
		p = building_temp->floor[floor_num]->next;
		if ((building_temp->floor[0]->next->dormitory_num == 0) || (building_temp->floor[0]->next == NULL)) {
			printf("输入错误！该楼栋无人居住！\n");
			return;
		}
		floor_num++;
		while (p != NULL) {
			if (p->dormitory_num > 0) {
				for (j = 0; j < p->dormitory_num; j++) {
					if (wcscmp(temp_id, p->member[j]->id) == 0) {
						p->member[j]->check = 1;
						printf("报道成功，欢迎来到华侨大学！您的宿舍是%d楼，%d号房,请尽快入住！\n",floor_num,p->dormitory_id);
					}
				}
			}
			else {
				
				flag = 1;
				break;
			}
			p = p->next;
		}
		if (flag) break;
		p = building_temp->floor[floor_num];
	}
	
}
//最后输出
void print_last(building building_temp) {
	int floor_num = 0;
	dormitory_p p = (dormitory_p)malloc(sizeof(dormitory));
	int flag = 0;//判断是否是空宿舍，如果是空宿舍则提前退出循环
	int j = 0;
	int mem_num;
	while (floor_num < FLOOR_NUM) {
		p = building_temp->floor[floor_num]->next;
		mem_num = p->dormitory_num;
		if ((building_temp->floor[0]->next->dormitory_num == 0) || (building_temp->floor[0]->next == NULL)) {
			printf("该楼栋无人居住!\n");
			return;
		}
		printf("%d楼：\n", floor_num + 1);
		floor_num++;
		while (p != NULL) {
			if (p->dormitory_num > 0) {

				printf("%d\t", p->dormitory_id);
				for (j = 0; j < p->dormitory_num; j++) {
					if (p->member[j]->check == 1) {//报道的才输出
					wprintf(L"%ls\t", p->member[j]->name);
					}
					else {
						mem_num--;
					}

				}
				printf("\t共%d人\n", mem_num);
			}
			else {
				flag = 1;
				break;
			}
			p = p->next;
		}
		if (flag) break;
		p = building_temp->floor[floor_num];
	}
}
int main()
{
	setlocale(LC_ALL, "");
	FILE* in;
	//FILE* out;
	errno_t err_in = fopen_s(&in, FILE_IN, "r,ccs=UTF-8");
	//errno_t err_out = fopen_s(&out, FILE_OUT, "w");
	building building_A = (building)malloc(sizeof(Building));
	building building_B = (building)malloc(sizeof(Building));
	building building_C = (building)malloc(sizeof(Building));
	building building_D = (building)malloc(sizeof(Building));
	building_A = init_building(building_A);
	building_B = init_building(building_B);
	building_C = init_building(building_C);
	building_D = init_building(building_D);
	int ja=1,count_a=1;
	if (err_in != 0) {
		printf("无法打开文件\n");
		return -1;
	}
	/*if (err_out != 0) {
		printf("无法打开文件\n");
		return -1;
	}*/
	wchar_t wc_no[] = L"无";
	wchar_t line[100]={'\0'};
	//printf("学生信息为：\n");
	fgetws(line, 100, in);
	while (fgetws(line,100,in)!=NULL) {//读取文件信息
		//wprintf(L"%ls", line);
		wchar_t* context = (wchar_t*)malloc(sizeof(wchar_t));
		wchar_t* token = wcstok_s(line, L" ", &context);
		int j = 0;
		//wprintf(L"%ls", token);
		m_meg member = (m_meg)malloc(sizeof(member_meg));
		member->check = 0;
		//信息录入
			wcscpy_s(member->name,sizeof(member->name-1),token);
		//if (err == 0) printf("1");
		token = wcstok_s(NULL, L" ", &context);
		wcscpy_s(member->id, sizeof(member->id-1),token );
		//if (err == 0) printf("1");
		token = wcstok_s(NULL, L" ", &context);
		wcscpy_s(member->native_place, sizeof(member->native_place-1), token);
		token = wcstok_s(NULL, L" ", &context);
		wcscpy_s(member->hobby, sizeof(member->hobby-1), token);
		token = wcstok_s(NULL, L" ", &context);
		wcscpy_s(member->nation, sizeof(member->nation-1),token);
		token = wcstok_s(NULL, L" ", &context);
		wcscpy_s(member->religion, sizeof(member->religion-1),token );
		token = wcstok_s(NULL, L" ", &context);
		member->abroad = *token;
			
			//wprintf(L"%ls\n", member->id);
			//wprintf(L"%ls %ls %ls %ls %ls %ls %lc %d\n", member->name,member->id,  member->native_place, member->hobby, member->nation, member->religion, member->abroad, member->check);
			//分宿舍
			//有宗教境外生 A
			if (wcscmp(member->religion, wc_no) != 0 && member->abroad == '1') {
				insert_dormitory(member, building_A);
			}
			//有宗教境内生 B
			else if (wcscmp(member->religion, wc_no) != 0 && member->abroad == '0') {
				insert_dormitory(member, building_B);
			}
			//无宗教境外生 C
			else if (wcscmp(member->religion, wc_no) == 0 && member->abroad == '1') {
				insert_dormitory(member, building_C);
			}
			//无宗教境内生 D
			else if (wcscmp(member->religion , wc_no) == 0 && member->abroad == '0') {
				insert_dormitory(member, building_D);
			
		}
		
		
	}
	
	printf("\n欢迎使用华侨大学宿舍床位分配系统！\n");
	//第一次输出
	int i=0;
	dormitory_p p = (dormitory_p)malloc(sizeof(dormitory));
	int flag = 0;//判断是否是空宿舍，如果是空宿舍则提前退出循环
	int j = 0;
	printf("\n================================================================\n");
	printf("23级大数据的新生安排宿舍安排如下:\n");
	printf("\n-----------------------------------\n");
	printf("楼栋号：A(有宗教的境外生)\n");
	print(building_A);
	printf("\n-----------------------------------\n");
	printf("楼栋号：B(有宗教的境内生)\n");
	print(building_B);
	printf("\n-----------------------------------\n");
	printf("楼栋号：C(无宗教的境外生)\n");
	print(building_C);
	printf("\n-----------------------------------\n");
	printf("楼栋号：D(无宗教的境内生)\n");
	print(building_D);
	//输入
	wchar_t temp_name[50];
	wchar_t temp_id[50];
	wchar_t wc_stop[] = L"#";
	printf("\n==============================================================\n");
	printf("请输入A栋报道学生的信息(依次输入学生姓名，学号,以#结束)：\n");
	while (1) {
		wscanf_s(L"%ls", temp_name, (unsigned)_countof(temp_id));
		if (wcscmp(temp_name, wc_stop) == 0) break;
		else {
			wscanf_s(L"%ls", temp_id, (unsigned)_countof(temp_id));
			modify(temp_id, building_A);
			
			//wprintf(L"%ls", temp_id);*/

		}
		
	}
	printf("\n==============================================================\n");
	printf("请输入B栋报道学生的信息(依次输入学生姓名，学号,以#结束)：\n");
	while (1) {
		wscanf_s(L"%ls", temp_name, (unsigned)_countof(temp_id));
		if (wcscmp(temp_name, wc_stop) == 0) break;
		else {
			wscanf_s(L"%ls", temp_id, (unsigned)_countof(temp_id));
			modify(temp_id, building_B);

			//wprintf(L"%ls", temp_id);*/

		}

	}

	printf("\n==============================================================\n");
	printf("请输入C栋报道学生的信息(依次输入学生姓名，学号,以#结束)：\n");
	while (1) {
		wscanf_s(L"%ls", temp_name, (unsigned)_countof(temp_id));
		if (wcscmp(temp_name, wc_stop) == 0) break;
		else {
			wscanf_s(L"%ls", temp_id, (unsigned)_countof(temp_id));
			modify(temp_id, building_C);

			//wprintf(L"%ls", temp_id);*/

		}

	}

	printf("\n==============================================================\n");
	printf("请输入D栋报道学生的信息(依次输入学生姓名，学号,以#结束)：\n");
	while (1) {
		wscanf_s(L"%ls", temp_name, (unsigned)_countof(temp_id));
		if (wcscmp(temp_name, wc_stop) == 0) break;
		else {
			wscanf_s(L"%ls", temp_id, (unsigned)_countof(temp_id));
			modify(temp_id, building_D);

			//wprintf(L"%ls", temp_id);*/

		}

	}

	//最终输出
	printf("\n==============================================================\n");
	printf("23级大数据的最终的新生安排宿舍安排如下:\n");
	printf("\n-----------------------------------\n");
	printf("楼栋号：A(有宗教的境外生)\n");
	print_last(building_A);
	printf("\n-----------------------------------\n");
	printf("楼栋号：B(有宗教的境内生)\n");
	print_last(building_B);
	printf("\n-----------------------------------\n");
	printf("楼栋号：C(无宗教的境外生)\n");
	print_last(building_C);
	printf("\n-----------------------------------\n");
	printf("楼栋号：D(无宗教的境内生)\n");
	print_last(building_D);

	printf("\n==============================================================\n");
	printf("您已成功退出，欢迎再次使用华侨大学宿舍床位分配系统！\n");

	fclose(in);
	//fclose(out);
	return 0;
}


