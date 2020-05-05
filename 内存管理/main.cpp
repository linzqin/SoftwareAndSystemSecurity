#include<stdio.h>
#include<malloc.h>
#include<string>
#include <windows.h>
using namespace std;
#include<iostream>
//int main()
//{
//	int i = 0,anum;
//	char *p;
//
//	p = (char *)malloc(100);
//	if (p)
//		printf("Memory Allocated at: %x/n", p);
//	else
//		printf("Not Enough Memory!/n");
//	for (i = 0; i<4096; i++)
//	{
//		p[i] = 'a';
//	}
//	anum = i;
//	//printf("共写入%d字节/n", anum);
//	//cout << "共写入" << anum << "字节" << endl;
//	for (i = 0; i<4096; i++)
//	{
//		if (p[i] != 'a')
//		{
//			anum--;
//		}
//	}
//	//printf("共%d字节读取正确/n", anum);
//	
//	free(p);
//	return 0;
//}

void main()
{
	BOOL flag;
	//分配内存，标记为提交、可读可写 
	LPVOID lpvBase = VirtualAlloc(
		NULL,                 // system selects address
		4096,     // size of allocation
		MEM_COMMIT,   // allocate reserved pages
		PAGE_READWRITE
	);       // protection = no access   
	if (lpvBase == NULL )   
		return;
	//向该内存里面写些东西
	unsigned char *ustr = (unsigned char *)lpvBase;
	ustr[0] = 'a';
	//printf("写入的数据：%d/n", ustr[0]);
	
	//修改为“只读”属性，验证是否能写入
	DWORD dw;
	char c;
	VirtualProtect(lpvBase, 4096, PAGE_READONLY, &dw);
	c = ustr[0];  //可以读取
	//ustr[0]=0x44; //失败

	// virtualfree
	flag = VirtualFree(lpvBase,4096, MEM_DECOMMIT);
	if (flag == TRUE)
	{
		cout << "释放成功"<<endl;
	}
	else
	{
		cout << "释放失败" << endl;
	}
	//c = ustr[0];  //不可读取
	ustr[0] = 0x44; //失败

}