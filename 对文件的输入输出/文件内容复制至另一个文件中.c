#include "stdio.h"
#include "stdlib.h"
#pragma warning(disable : 4996)//VS2019环境设置，防止fopen报错

int main() 
{
	FILE * readInFilePoint, * writeOutFilePoint;
	char naka, inFileName[30], outFileName[30];
	printf("输入读入文件的名字\n");
	scanf("%s",inFileName);
	printf("输入输出文件的名字\n");
	scanf("%s",outFileName);
	if ((readInFilePoint = fopen(inFileName, "r")) == NULL)
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
	while (!feof(readInFilePoint))
	{
		fputc(naka, writeOutFilePoint);
		putchar(naka);
		naka = fgetc(readInFilePoint);
	}
	fclose(readInFilePoint);
	fclose(writeOutFilePoint);
}
