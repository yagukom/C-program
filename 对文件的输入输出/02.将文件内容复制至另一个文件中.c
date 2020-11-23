#include "stdio.h"
#include "stdlib.h"
#pragma warning(disable : 4996)//VS2019环境设置，防止fopen报错
/*
* 编辑时间：2020-11-23 14:37
* 参考内容：C程序设计（第五版）谭浩强 P341 例10.2
* fgetc(fp) 	从fp指向的文件读入一个字符，输出失败则返回文件结束标志EOF(即-1)。
* fputc(ch,fp) 	把字符ch写到文件指针变量fp所指向的文件中，输出失败则返回文件结束标志EOF(即-1)。
* feof(fp)	可以检测文件尾标志是否被读取过。
* 注意：可以先创建一个文件，里面写一些东西再执行本程序。
* 其他：当使用二进制文件时，只需将"r"和"w"更改为"rb"和"wb"即可。
*/
int main() 
{
	FILE * readInFilePoint, * writeOutFilePoint;
	char naka, inFileName[30], outFileName[30];
	printf("输入读入文件的名字\n");
	scanf("%s",inFileName);
	printf("输入输出文件的名字\n");
	scanf("%s",outFileName);
	if ((readInFilePoint = fopen(inFileName, "r")) == NULL)//读的对象要为"r"才行
	{
		printf("无法打开此文件\n");
		exit(0);
	}
	if ((writeOutFilePoint = fopen(outFileName, "w")) == NULL)
	{
		printf("无法打开此文件\n");
		exit(0);
	}
	naka = fgetc(readInFilePoint);
	while (!feof(readInFilePoint))//可以将此处改为 while(naka!=-1) 或 while(naka!=EOF)
	{
		fputc(naka, writeOutFilePoint);
		putchar(naka);
		naka = fgetc(readInFilePoint);
	}
	fclose(readInFilePoint);
	fclose(writeOutFilePoint);
}
