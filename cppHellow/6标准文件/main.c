//
//  main.c
//  6标准文件
//
//  Created by codew on 8/7/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
typedef struct Stu
{
    char name[50];
    int id;
}Stu;

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);

void test6(void);
void test7(void);
void test8(void);
void test9(void);

void test10(void);
void test11(void);
void test12(void);
void test13(void);

void test14(void);
void test15(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    test13();

    
    return 0;
}


void test1()
{
//    FILE * file = fopen("/Users/codew/Desktop/T/list.m", "r");
    
    FILE * file = fopen("./list.mp4", "r");
    
    printf("%hd \n", file->_flags);
    
    
    // 获取当前目录
    char *buffer;
    if((buffer = getcwd(NULL,0))==NULL){
        perror("getcwd error");
    }
    else{
        printf("%s\n",buffer);
        
    }
    
    
    fclose(file);
}

void test2(void)
{
       FILE *fp = NULL;

        // "\\"这样的路径形式，只能在windows使用
        // "/"这样的路径形式，windows和linux平台下都可用，建议使用这种
        // 路径可以是相对路径，也可是绝对路径
    //    fp = fopen("./tesfdgst", "w");
        //fp = fopen("..\\test", "w");

        if (fp == NULL) //返回空，说明打开失败
        {
            //perror()是标准出错打印函数，能打印调用库函数出错原因
            perror("open");
//            return -1;
        }
        
}

/**
 按照字符-写文件
 */
void test3(void)
{

    // w没有文件的话, 就创建
    FILE * myFile = fopen("/Users/codew/Desktop/cpp/codePath/myfile.txt", "w");;
    
    char buf[] = "this is a code for xy";
    int i = 0;
    int n = strlen(buf);
    for (i = 0; i < n; i++)
    {
        //往文件fp写入字符buf[i]
        int ch = fputc(buf[i], myFile);
        printf("ch = %c\n", ch);
    }
    
    
    fclose(myFile);
}

/**
 按照字符-读文件
 */
void test4(void)
{
    // w没有文件的话, 就创建
    FILE * myFile = fopen("/Users/codew/Desktop/cpp/codePath/myfile.c", "r");;
    
    
    char ch;
    #if 0
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");
    #endif

    while (!feof(myFile)) //文件没有结束，则执行循环
    {
        ch = fgetc(myFile);
        printf("%c", ch);
    }
    printf("\n");
    
    fclose(myFile);
}

/**
 按照行-写文件
 */
void test5(void)
{
    FILE * myFile = fopen("/Users/codew/Desktop/cpp/codePath/fputs2.c", "w");
    
    //char *buf[] = {"hahah\n","lalalw\n","koao\n"};
    
    char *buf[] = {"hi","baby","come"};
    for (int i =0; i < 3; i++) {
        
        int len = fputs(buf[i], myFile);
        printf("len = %d\n");
    }
    
    fclose(myFile);
    
}

/**
按照行-读文件
*/
void test6(void)
{
    FILE * myFile = fopen("/Users/codew/Desktop/cpp/codePath/fputs.c", "r");
    
    char buf[100];
    
    while ( !feof(myFile) ) {
        
        memset(buf, 0, sizeof(buf) );
        
        char *p = fgets(buf, sizeof(buf), myFile);
        if (p != NULL) {
            
            printf("buf = %s", buf);
        }
    }
    
}


/**
 按照格式化文件-写文件
 */
void test7(void)
{
    FILE * myFile = fopen("/Users/codew/Desktop/cpp/codePath/fprintf.c", "w");
    
    // 这玩意会覆盖老文件
//    fprintf(myFile, "吃点啥好呢? %s %s","煮面?", "火锅?");
    
    fprintf(myFile, "%d %d %d\n", 1, 2, 3);
    
    fclose(myFile);
}

/**
按照格式化文件-读文件
*/
void test8(void)
{
    FILE * myFile = fopen("/Users/codew/Desktop/cpp/codePath/fputs.c", "r");
    
    
    if (myFile == NULL) {
        
        printf("没有这个文件打印个毛线!");
        
        return;
    }
    
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    fscanf(myFile, "%d %d %d\n", &a, &b, &c);
//    printf("a = %d, b = %d, c = %d\n", a, b, c);
//
    
    //
    
    char str1[100];
    char str2[100];
    char str3[100];
    fscanf(myFile, "%s %s %s\n", str1, str2, str3);
    printf("str1 = %s, str2 = %s, str3 = %s\n", str1, str2, str3);
    
    
    fclose(myFile);
}

/**
 按照块-写文件
 这个就是序列化
 */
void test9(void)
{
    FILE * myFile = fopen("/Users/codew/Desktop/cpp/codePath/fwrite.c", "w");

    Stu s[3];
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        sprintf(s[i].name, "stu%d%d%d", i, i, i);
        s[i].id = i + 1;
    }

    int ret = fwrite(s, sizeof(Stu), 3, myFile);
    printf("ret = %d\n", ret);
    
    fclose(myFile);
}

/**
按照块-读文件
 反序列化
*/
void test10(void)
{
    FILE * myFile = fopen("/Users/codew/Desktop/cpp/codePath/fwrite.c", "r");
    Stu s[3];
    int ret = fread(s, sizeof(Stu), 3, myFile);
    printf("ret = %d\n", ret);

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("s = %s, %d\n", s[i].name, s[i].id);
    }

    fclose(myFile);
}

/**
 文件的随机读写
 随机读文件
 */
void test11(void)
{
    FILE * myFile = fopen("/Users/codew/Desktop/cpp/codePath/fwrite.c", "r");
    
    //假如已经往文件写入3个结构体
    //fwrite(s, sizeof(Stu), 3, fp);

    Stu s[3];
    Stu tmp;
    int ret = 0;

    //文件光标读写位置从开头往右移动2个结构体的位置
    fseek(myFile, 2 * sizeof(Stu), SEEK_SET);

    //读第3个结构体
    ret = fread(&tmp, sizeof(Stu), 1, myFile);
    if (ret == 1)
    {
        printf("[tmp]%s, %d\n", tmp.name, tmp.id);
    }

    //把文件光标移动到文件开头
    //fseek(fp, 0, SEEK_SET);
    rewind(myFile);

    ret = fread(s, sizeof(Stu), 3, myFile);
    printf("ret = %d\n", ret);

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("s === %s, %d\n", s[i].name, s[i].id);
    }
    
    fclose(myFile);
}

/**
 
 判断文件是 linux还是Windows格式
 */
void test12(void)
{
    

    FILE *p = fopen("/Users/codew/Desktop/cpp/codePath/fputs2.c", "r");
    if (!p){
        
        printf("文件不存在!");
        return;
    }
        

    char a[1024] = { 0 };
    fgets(a, sizeof(a), p);

    int len = 0;
    while (a[len])
    {
        if (a[len] == '\n')
        {
            if (a[len - 1] == '\r')
            {
                printf("windows file\n");
            }
            else
            {
                printf("linux file\n");
            }
        }
        len++;
    }

    fclose(p);
}

void test13(void)
{
//    #include <sys/types.h>
//    #include <sys/stat.h>
    struct stat st = { 0 };

    stat("/Users/codew/Desktop/cpp/codePath/fputs2.c", &st);
    
    // 获取文件字节数
    int size = st.st_size;//得到结构体中的成员变量
    
    // 这个是timestamp
    long stCtime = st.st_ctime;
    printf("%d\n", size);
    
    printf("%ld\n", stCtime);
}

void test14(void)
{
    
}
void test15(void)
{
    
}
