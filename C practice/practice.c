//设置密码，确认是否正确

#include <stdio.h>
#include <string.h>
int main()
{
    char password[20];
    printf("请输入密码：\n");
    scanf("%s", password);
    int ch=0;
    while((ch=getchar())!='\n' && ch!=EOF)//这句作用是吸收回车，防止回车被下一次输入读取到
    {;}
    printf("确认密码：%s\n",password);
int ret=getchar();
if('Y'==ret)
{
    printf("yes\n");
}
else
{
    printf("no\n");
}
return 0;
}

