#include "stdio.h"
#include "stdlib.h"
#pragma warning(disable : 4996)//VS2019环境设置，防止fopen报错

/*
* 编辑时间：2020-11-24 14:54 周二 小雨
* 事迹：今天研发部门里楠姐被老板气走啦，怀念一下，貌似是2020-4-21来的，比我早5个月，昨天她做了最后的任务，把部门之前的报销全清了。
* 参考书籍：《C程序设计》第五版 谭浩强 P345~P348 例10.4
* 函数说明：
	fread(buffer,size,count,fp);
		其中,
		buffer:为数据源的地址。	此处即为一个结构体变量组成的数组里 各结构体变量的地址，即 &Hampback_LabTeam[数组成员编号] 或 Hampback_LabTeam+数组成员编号。
		size:为要读写的字数。	此处为结构体Human_info的结构体长度，使用sizeof(struct Human_info)来测量Human_info结构体的长度。
		count:为要读写的数据项，每个数据项长度为size。	此处设置为 1 ，即每次读或写 1 个Human_info结构体的 大小。
		fp:FILE类型的指针。	此处fp指针指向“座头鲸研发部人员清单.dat”文件。
		总结：即 将要传输的数据视为“包(cell)”，则每个包对应一个 Human_info结构体，数据源为 Hampback_LabTeam[]数组，该数据源由 Human_info结构体 定义。
	fwrite(buffer,size,count,fp);同上。
	fopen("文件名","使用文件的方式");其中wb为建立二进制文件；rb为读取一个二进制文件。
	scanf("格式控制"，各种地址);其中&为取地址符。
----------------------------------------------------------------------------------------------------------------------------------------------------
* 修改时间：2020-12-11 10:06 周五 阴
* 事迹：今天左侧的巨工正式离职啦(昨天下午跑的，貌似是2020-6-1来的)，反正老板是个文科的，不懂音箱工程师硬件的泪，另外采购部门跑得就剩一个人了，电源线都买不到更别说线的认证了，音箱的3C认证也弄不下来；
* 	右边的倪工因为加薪失败也请假散心去了。
* 修改内容：新增#define date_since_20201211_member 17-1-1
*/
#define date_since_20201124_member 17-1
#define date_since_20201211_member 17-1-1
//#define test 2 //最初测试这个demo时候用的

#define exit_mode 0 //这三个模式用于在主循环中 使用 对应的模式
#define write_mode 1
#define read_mode 2

#define data_count 1//对应fwrite(buffer,size,count,fp)中的count

#define date date_since_20201211_member //以后每次只需要修改此处的宏定义中 date_since_xxxx 选项即可
struct Human_info {
	char name[15];
	//int birthday_year;
	//int birthday_month;
	//int birthday_day;
	char sex[2];//中文输入在VS2019中 一个汉字 占据 2个数组位
	int worked_year;//其实工作年月 也可以定义成char的数组形式的
	int worked_month;
};

struct Human_info Hampback_LabTeam[date];//定义一个向文件写入的数据结构体变量，用于储存想要写入或者读取的文件数据对象。

void save_Hampback_LabTeam() {
	FILE* filePoint;
	if ((filePoint = fopen("座头鲸研发部人员清单.dat", "wb")) == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for (int i = 0; i < date; i++) {
		//fwrite()和fread()都是有返回值的，即若执行成功，则返回它们的第三个参数count的值。
		if (fwrite(&Hampback_LabTeam[i], sizeof(struct Human_info), data_count, filePoint) != data_count)
		{
			printf("file write error\n");
		}
	}
	fclose(filePoint);
}

void read_Hampback_LabTeam() {
	FILE* filePoint;
	if ((filePoint = fopen("座头鲸研发部人员清单.dat", "rb")) == NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	for (int i = 0; i < date; i++) {
		fread(&Hampback_LabTeam[i], sizeof(struct Human_info), data_count, filePoint);
		//fread(Hampback_LabTeam+i, sizeof(struct Human_info), data_count, filePoint);这一行效果是和上一行是一样的。
		printf("[%2d] %-10s %-4s %4d %4d \n", i+1,Hampback_LabTeam[i].name, Hampback_LabTeam[i].sex, Hampback_LabTeam[i].worked_year, Hampback_LabTeam[i].worked_month);
	}
	fclose(filePoint);
}

int main()
{
	int mode_input;
	do {
		printf("请输入对应的编号，进入相应的模式（0.退出 1.输入模式 2.读取模式）\n");
		scanf("%d", &mode_input);//注意scanf的第一个参数里不要添加"\n"之类的东西，第二个参数为地址。
		if (mode_input == write_mode) {
			printf("请输入姓名 性别 工作年数 工作月数\n");
			for (int i = 0; i < date; i++)
			{
				scanf("%s%s%d%d", Hampback_LabTeam[i].name, Hampback_LabTeam[i].sex, &Hampback_LabTeam[i].worked_year, &Hampback_LabTeam[i].worked_month);
			}
			save_Hampback_LabTeam();
		}
		else if (mode_input == read_mode) {
			read_Hampback_LabTeam();
		}
		else if (mode_input == exit_mode) {
			printf("已退出\n");
		}
	} while (mode_input != exit_mode);
	return 0;
}
