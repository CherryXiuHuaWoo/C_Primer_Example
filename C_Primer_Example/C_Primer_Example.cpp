// C_Primer_Example.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>


#define STUDENT_NUM		5	// 统计总人数
#define SCORE_NUM		3	// 科目总数

/* score 为各科成绩分数.
 *		score[0] 为语文成绩,
 *		score[1] 为数学成绩,
 *		score[2] 为英文成绩.
 * grade 为各科成绩的分数等级
 *		grade[0] 为语文成绩等级,
 *		grade[1] 为数学成绩等级,
 *		grade[2] 为英文成绩等级.
 * name 为 student name
 */
struct student
{
	int score[SCORE_NUM];
	char grade[SCORE_NUM];
	char name[20];
};

student s_array[STUDENT_NUM];	// 声明学生数组

void input_message(void);
void printf_grade(student *stu_pc);

/*
* Function: 键入每个学生的信息，包括：姓名、语文成绩、数学成绩和英语成绩
* Note:
*		先键入学生名称，再键入语文成绩，再键入数学成绩，最后键入英语成绩
*		信息键入需要注意空格！
*/
void input_message(void)
{
	// 依据输入的信息，输出每个学生的成绩等级
	for (int i = 0; i < STUDENT_NUM; i++)
	{
		printf("Enter the num %d student's message:\r\n", i);
		scanf("%s %d %d %d", &s_array[i].name, &s_array[i].score[0], &s_array[i].score[1], &s_array[i].score[2]);

		printf_grade(&s_array[i]);
	}
}

/*
 * Function: 将单个学生的各科的成绩结果划分等级, 输出各科的成绩等级
 * Note: 
 *		[0 , 60) 为 D
 *		[60, 75) 为 C
 *		[75, 85) 为 B
 *		[85, 100] 为 A
 *		其余输入值会被认为是错误值，显示 E
 */
void printf_grade(student *stu_pc)
{
	for (int i = 0; i < SCORE_NUM; i++)
	{
		if ((0 <= stu_pc->score[i]) && (60 > stu_pc->score[i]))
		{
			stu_pc->grade[i] = 'D';
		}
		else if ((60 <= stu_pc->score[i]) && (75 > stu_pc->score[i]))
		{
			stu_pc->grade[i] = 'C';
		}
		else if ((75 <= stu_pc->score[i]) && (85 > stu_pc->score[i]))
		{
			stu_pc->grade[i] = 'B';
		}
		else if ((85 <= stu_pc->score[i]) && (100 >= stu_pc->score[i]))
		{
			stu_pc->grade[i] = 'A';
		}
		else
		{
			stu_pc->grade[i] = 'E';	// Error
		}

		printf("%c ", stu_pc->grade[i]);
	}

	printf("\r\n");
}

/*
* Function: 使用冒泡法，对单科成绩进行排名
* Note:
*		
*/
void bubble_method(int *score_buf, char *stuname_buf)
{
	int score_temp;
	char *stuname_temp;

	for (int i = 0; i < STUDENT_NUM - 1; i++)
	{
		for (int j = 0; j < STUDENT_NUM - i - 1; j++)
		{
			score_temp = score_buf[j];
			stuname_temp = &stuname_buf[j];
			if (score_buf[j] > score_buf[j + 1])
			{
				score_buf[j] = score_buf[j + 1];
				stuname_buf[j] = stuname_buf[j + 1];

				score_buf[j + 1] = score_temp;
				stuname_buf[j + 1] = *stuname_temp;
			}
		}
	}
}

/*
* Function: main 
*			循环键入 5 个学生的 student name，语文、数学和英语成绩。
*			输出每个学生的各科成绩等级。
*			输出各科成绩的排名。
*/ 
int main(void)
{
	
	int score_temp[STUDENT_NUM];	// 声明临时成绩数组，用于成绩排序
	char *studentname_temp[STUDENT_NUM];	// 声明临时学生姓名数组，用于跟踪成绩排序结果
	int i, k;

	input_message();

	// 输出各科成绩排名结果
	for (k = 0; k < SCORE_NUM; k++)
	{
		// 暂存学生姓名和单科成绩
		for (i = 0; i < STUDENT_NUM; i++)
		{
			score_temp[i] = s_array[i].score[k];
			studentname_temp[i] = s_array[i].name;
		}

		// 采用冒泡法对各科成绩进行排序
		bubble_method(&score_temp[0], studentname_temp[0]);

		// 输出各科成绩信息
		switch (k)
		{
			case 0:
				printf("Chinese Ranking:\r\n");
				break;
			case 1:
				printf("Math Ranking:\r\n");
				break;
			case 2:
				printf("English Ranking:\r\n");
				break;
			default:
				printf("Error\r\n");
		}

		for (i = STUDENT_NUM - 1; i >= 0; i--)
		{
			printf("Num %d is %s, score = %d\r\n", STUDENT_NUM - i, studentname_temp[i], score_temp[i]);
		}
	}
	return 0;
}

