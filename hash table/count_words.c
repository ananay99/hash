#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct htable{
char *str;
struct htable * next;
};
void initialize(struct htable * arr)
{
    for(int x=0;x<101;x++)
    {
        arr[x].str=NULL;
        arr[x].next=NULL;
    }
}
int rethsh(char * str)
{
    int sm=0;
    for(int y=0;str[y]!='\0';y++)
    {
        sm+=str[y];
    }
    return(sm%101);
}
int add(struct htable * bs,char * str,int count)
{
    while(bs->next!=NULL)
    {
        bs=bs->next;
        if(strcmp(bs->str,str)==0)
        {
            return count;
        }
    }
    bs->next=(struct htable *)malloc(sizeof(struct htable));
    bs=bs->next;
    bs->str=(char *)malloc(sizeof(char)*(strlen(str)+1));
    strcpy(bs->str,str);
    bs->next=NULL;
    count++;
    return count;
}
void make_hash(struct htable * arr)
{
 initialize(arr);
 int n;
 char str[1000];
 int count=0;
 while(( scanf("%s",str))!=EOF)
 {
     int hsh=rethsh(str);
     count=add(arr+hsh,str,count);
 }
 printf("%d\n",count);
}
int main()
{
    struct htable arr[101];
    make_hash(arr);
    return 0;
}
