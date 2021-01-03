#include <stdio.h>
void main() {
	int a[] = { 1,7,12,15 };
	int *p1 = a;
	int *p2 = p1++;
	int address0 = &p2 - &p1;
	printf("p2=%d\n", p2);
	*p1 += *p2++;//即*(p2++)，此时指针变量p2内部储存的地址值（而不是指针变量p2自身的地址值） 将自增一个int指针的量，即+4.
	//或者VS打断点看看
	int address = &p2 - &p1;
	printf("%d %d\n", address0,address);//[k1]这里检测出来的其实是指针变量p1,p2自身的地址值，所以他们的差值是不会变的。
	printf("p1指针指向的数组数据=%d，\np2指针指向的数组数据=%d\n", *p1, *p2);
	printf("p1指针中储存的地址=%d，\np2指针中储存的地址%d\n", p1, p2);
	printf("p1指针自身的地址=%d,\np2指针自身的地址=%d\n", &p1, &p2);
	//从这里可以看出p1与&p1的值虽然都是地址，但p1指的是指针变量p1内部储存的地址值(且与a[1]的地址相同)，而&p1指的是指针变量p1自身的地址值。
	printf("数组元素a[1]的地址=%d，a[1]=%d\n", &a[1],a[1]);
	int length = sizeof(int);
	printf("size of int=%d\n", length);//用于检测int占位多少。
	int address3 = &p2 - &p1;
	printf("%d\n", address3);//同上方的[k1]这里检测出来的其实是指针变量p1,p2自身的地址值，所以他们的差值是不会变的。
}
