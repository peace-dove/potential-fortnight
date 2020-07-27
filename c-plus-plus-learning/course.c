#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lesson
{
    char classnum[6];
    char name[20];
    int score;
    char teacher[12];
    int maxstu;
    int chosenstu;
} lesson[20];

struct chooselesson
{
    char stunum[10];
    char classnum[6];
} chooselesson[20];

int cnt=0;
int choosecnt=0;

FILE *fp;
char filename[20];
void create()
{
    printf("\nfile name:\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"w+"))==NULL)
    {
        printf("create error!");
        exit(0);
    }
    printf("File created success.\n");
}
void read()
{
    printf("\nfile name:\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"a+"))==NULL)
    {
        printf("read error!");
        exit(0);
    }
    for(int i=0; i<cnt; i++)
    {
        fread(&lesson[i],sizeof(struct lesson),1,fp);
    }
    fclose(fp);
    printf("File loaded success.\n\n");
}
void save()
{
    FILE *fp;
    printf("\nFile name:");
    scanf("%s",filename);
    if((fp=fopen(filename,"wb"))==NULL)
    {
        printf("open error\n");
        return;
    }
    for(int i=0; i<cnt; i++)
        if(fwrite(&lesson[i],sizeof(struct lesson),1,fp)!=1)
            printf("save error\n");
    fclose(fp);
    printf("You have saved the file.\n");
}
void Add()
{
    printf("the number of the lesson:");
    scanf("%s",lesson[cnt].classnum);
    printf("the name of the lesson:");
    scanf("%s",lesson[cnt].name);
    printf("the score of the lesson:");
    scanf("%d",&lesson[cnt].score);
    printf("the teacher of the lesson:");
    scanf("%s",lesson[cnt].teacher);
    printf("the coloum of the lesson:");
    scanf("%d",&lesson[cnt].maxstu);
    printf("the current students of the lesson:");
    scanf("%d",&lesson[cnt].chosenstu);
    cnt++;
    printf("The lesson has been added.\n");
}
void Delete()
{
    char lessonnumber[6];
    printf("Input the class number to be deleted:");
    scanf("%s",lessonnumber);

    for(int i=0; i<cnt; i++)
    {
        if(strcmp(lesson[i].classnum,lessonnumber)==0)
        {
            strcpy(lesson[i].classnum,lesson[cnt-1].classnum);
            strcpy(lesson[i].name,lesson[cnt-1].name);
            lesson[i].score=lesson[cnt-1].score;
            strcpy(lesson[i].teacher,lesson[cnt-1].teacher);
            lesson[i].maxstu=lesson[cnt-1].maxstu;
            lesson[i].chosenstu=lesson[cnt-1].chosenstu;

            cnt--;
            printf("The lesson has been deleted.\n");
            return;
        }
    }
    printf("Sorry! No this lesson.\n");
    return;
}
void inquirecan()
{
    int total=0;
    printf("number\t\tname\t\thas chosen/max volume\n");
    for(int i=0; i<cnt; i++)
    {
        if(lesson[i].maxstu>lesson[i].chosenstu)
        {
            printf("%s\t\t%s\t\t%d/%d\n",lesson[i].classnum,lesson[i].name,lesson[i].chosenstu,lesson[i].maxstu);
            total++;
        }
    }
    printf("You can choose %d lessons.\n",total);
}
void inquirehas()
{
    char snum[10];
    char cnum[6];
    int total=0;
    printf("Input your student number:");
    scanf("%s",snum);

    printf("number\tname\t\n");
    for(int i=0; i<choosecnt; i++)
    {
        if(strcmp(snum,chooselesson[i].stunum)==0)
        {
            strcpy(cnum,chooselesson[i].classnum);
            for(int j=0; j<cnt; j++)
            {
                if(strcmp(cnum,lesson[j].classnum)==0)
                {
                    printf("%s %s\n",lesson[j].classnum,lesson[j].name);
                    total+=lesson[j].score;
                }
            }
        }
    }
    printf("Total score is %d.\n",total);
}
void select()
{

    printf("Input student number:");
    scanf("%s",chooselesson[choosecnt].stunum);
    printf("Input lesson number:");
    scanf("%s",chooselesson[choosecnt].classnum);

    for(int i=0; i<cnt; i++)
        if(strcmp(chooselesson[choosecnt].classnum,lesson[i].classnum)==0)
        {
            lesson[i].chosenstu++;
            break;
        }

    choosecnt++;
    printf("You have chosen the lesson.\n");
}
void drop()
{
    char snum[10],cnum[6];
    printf("Input student number:");
    scanf("%s",snum);
    printf("Input lesson number:");
    scanf("%s",cnum);

    for(int i=0; i<choosecnt; i++)
    {
        if(strcmp(snum,chooselesson[i].stunum)==0&&strcmp(cnum,chooselesson[i].classnum)==0)
        {
            for(int j=0; j<cnt; j++)
            {
                if(strcmp(cnum,lesson[j].classnum)==0)
                {
                    lesson[j].chosenstu--;
                    break;
                }
            }
            strcpy(chooselesson[i].stunum,chooselesson[choosecnt-1].stunum);
            strcpy(chooselesson[i].classnum,chooselesson[choosecnt-1].classnum);
            choosecnt--;
            printf("You have dropped the lesson.\n");
            return;
        }
    }
    printf("Sorry Input Error! Or you don't choose this lesson.\n");
}
int main()
{
    printf("\n");
    while(1)
    {
        printf("\tCourse Select System\n");
        printf("\tPlease press number to operate:\n");

        printf("\t\t1:create file\t\n");
        printf("\t\t2:open a file\t\n");
        printf("\t\t3:add lesson\t\n");
        printf("\t\t4:delete lesson\t\n");
        printf("\t\t5:inquire lessons can be chosen\t\n");
        printf("\t\t6:inquire lessons you have chosen\t\n");
        printf("\t\t7:select lesson\t\n");
        printf("\t\t8:drop lesson\t\n");
        printf("\t\t9:save file\t\n");
        printf("\tpress 10 to exit it\t\n");

        int order;
        scanf("%d",&order);
        switch(order)
        {
        case 1:
            create();
            break;
        case 2:
            read();
            break;
        case 3:
            Add();
            break;
        case 4:
            Delete();
            break;
        case 5:
            inquirecan();
            break;
        case 6:
            inquirehas();
            break;
        case 7:
            select();
            break;
        case 8:
            drop();
            break;
        case 9:
            save();
            break;
        default:
            printf("Bye!");
            return 0;
        }
    }
    return 0;
}
