/*
需求：
	1、菜单：
		1、创建文件（名称宏定义） 2、追加写入文件内容 3、输出文件内容 0、退出程序
*/
#include <stdio.h>
#include <string.h>
#define true 1
#define IF_WRITE_ONE_LINE 1
#define PATH "./file1"
void print_menu();
int get_menu_item();
void create_file();
void append_write();
void output_file();
void mfflush(){
	char c;
	while(1){
		c = getchar();
		if(c == '\n')
			break;
	}
}
int main(){
	int menu_item = 0;
	while(true){
		print_menu();
		menu_item = get_menu_item();
		if(!menu_item){
			break;
		}
		switch(menu_item){
			case 1:		//create file
				create_file();			
				break;
			case 2:		//append write
				append_write();
				break;
			case 3:		//read file
				output_file();
				break;
			default:
				break;
		}
	}

	printf("main exit.\n");
	return 0;
}
void print_menu(){
	printf("\t1.create or truncate file\n\t2.append write\n\t3.output file\n->");
}
int get_menu_item(){
	int ret = 0;
	scanf("%d",&ret);
	mfflush();
	return ret;
}
void create_file(){
	printf("create file\n");
	FILE * fp = fopen(PATH,"w+");
	fclose(fp);
}
void append_write(){
	printf("append write\n");
	char buf[20] = {'\0'};
	scanf("%s",buf);
	FILE * fp = fopen(PATH,"a");
	fwrite(buf,sizeof(char),strlen(buf),fp);
	if(IF_WRITE_ONE_LINE){
		//在写指针所在位置写入一个换行符，使每次输入独占一行
		fwrite("\n",1,1,fp);
	}
	fclose(fp);
}
void output_file(){
	printf("output file\n");
	char buf[20] = {'\0'};
	FILE * fp = fopen(PATH,"r");
	while((fread(buf,sizeof(char),20,fp)) != 0){
		printf("%s",buf);
		memset(buf,0,strlen(buf));
	}
	printf("output end\n");
	fclose(fp);
}




