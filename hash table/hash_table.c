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
void add(struct htable * bs,char * str)
{
    while(bs->next!=NULL)
    {
        bs=bs->next;
        if(strcmp(bs->str,str)==0)
        {
            return;
        }
    }
    bs->next=(struct htable *)malloc(sizeof(struct htable));
    bs=bs->next;
    bs->str=(char *)malloc(sizeof(char)*(strlen(str)+1));
    strcpy(bs->str,str);
    bs->next=NULL;
}
void make_hash(struct htable * arr)
{
 initialize(arr);
 int n;
 scanf("%d",&n);
 char str[1000];
 while(n--)
 {
     scanf("%s",str);
     int hsh=rethsh(str);
     add(arr+hsh,str);
 }
}
void print(struct htable * arr)
{
    for(int x=0;x<101;x++)
    {
       struct htable * ptr=arr+x;
       while(ptr->next!=NULL)
       {
            ptr=ptr->next;
           printf("%s\n",ptr->str);
       }
    }
}
int main()
{
    struct htable arr[101];
    make_hash(arr);
    print(arr);
    return 0;
}
