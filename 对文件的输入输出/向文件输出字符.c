#include "stdio.h"
#include "stdlib.h"
#pragma warning(disable : 4996)//VS2019环境设置

int main() 
{
	FILE *targetFilePoint;//定义文件指针
	char fileName[]="本程序生成的.txt";
	char inputContent;
	targetFilePoint = fopen(fileName,"w");//使文件指针指向 本程序生成的.txt 文件
	printf("请输入准备储存到磁盘里的字符串，以#号结束");
	printf("\n");
	inputContent = getchar();
	while (inputContent!='#')
	{
		fputc(inputContent, targetFilePoint);//向磁盘文件输出一个字符
		putchar(inputContent);//将刚才输入的字符输出到电脑屏幕上
		inputContent = getchar();
	}
	fclose(targetFilePoint); //关闭文件
}
