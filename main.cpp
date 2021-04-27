/*调研、选择一个典型仓库材料信息管理案例，实现材料库存、领用信息信息管理。每种材料的记录信息，
包括：编号、名称、单价、入库数量、库存数量、出库数量、保管人、进货时间、出货时间和备注等。*/
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
typedef struct person                               //定义结构体  
{  
     char num[10];   //编号  
    char name[20]; //名称  
    float money;    //单价
    int ruku;      //入库数量  
    int  kucun;      //库存数量
    int  chuku;      //出库数量
    char name1[20];		//保管人
	int timein1,timein2,timein3;			//进货时间
	int timeout1,timeout2,timeout3;		//出货时间
	char a[1000];		//备注
}person;  
person p[200]={2};  //定义100  
char filename[20];                                      //定义全局变量  

/*void menu_filename()  
   {  
      system("cls");  
      printf("请输入你要操作的文件名:");  
      scanf("\t%s",filename);  
    }  */
    //*********************************************************************//  
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  


int menu_select()                              //菜单选择系统函数  
{  
     char c;  
      do{  
        printf("\t\t ╭══════════■□■□══════════╮\n");  
        printf("\t\t│      仓库材料信息管理系统    │\n");  
        printf("\t\t╰ ══════════■□■□═══════════╯\n");  
        printf("\t\t   ┌────────────────────────────┐\n");  
        printf("\t\t   │ 1. 添加记录    2. 显示记录 │\n");  
        printf("\t\t   │                            │\n");  
        printf("\t\t   │ 3. 信息查询    0. 退出     │\n");  
        printf("\t\t   │                            │\n");  
     //   printf("\t\t   │ 0. 退出                    │\n");  
        printf("\t\t   └────────────────────────────┘\n");  
        printf("\t\t请您选择(0-3):\n");  
        c=getchar();  
     }while(c<'0'||c>'3');  
        return (c-'0');                                      //字符减去'0'得到的是数字整型//  
}  
void add()                                      //信息的录入与添加函数  
  {  
    FILE *fp;  
    int i=0,n=0;  
    char sign='y';                              //首先定义sing='y'  
    system("cls"); 
	                             //清屏函数  系统中调用  
    while(sign!='n'&&sign!='N')                    //其实只有当输入N或n时才跳出循环  
      {  
        printf("             ----添加----\n");  
        printf("名称：\n");  
        scanf("%s",p[i].name);
		getchar();
        printf("编号:\n");  
        scanf("%s",p[i].num);  
		getchar();
        printf("单价：\n"); 
        scanf("%f",&p[i].money);  
        printf("入库数量：\n");  
        scanf("%d",&p[i].ruku);  
        printf("库存数量：\n");  
        scanf("%d",&p[i].kucun);
        printf("出库数量：\n");  
        scanf("%d",&p[i].chuku);  
        printf("保管人：\n");  
        scanf("%s",p[i].name1); 
		printf("进货时间：\n");
		scanf("%d %d %d",&p[i].timein1,&p[i].timein2,&p[i].timein3);
		printf("出货时间：\n");
		scanf("%d %d %d",&p[i].timeout1,&p[i].timeout2,&p[i].timeout3);
        printf("是否继续添加?(y/n)");
		getchar();
        scanf("%c",&sign);  
        i++;  
        n=n+1;  
        system( "cls ");  
   }system("pause");    
	
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	//等待命令  

	if((fp=fopen("studata.txt","a"))==NULL)                    //以2进制形式进行文件尾追加//  
      {  
         printf("cannot open the files\n");  
         system("pause");  
         return;                                         //如果文件出现错误 就返回  2
       }  
        for(i=0;i<n;i++)  
        {
            fprintf(fp,"%s %s %f %d %d %d %s %d %d %d %d %d %d\n",p[i].name,p[i].num,p[i].money,p[i].ruku,p[i].kucun,p[i].chuku,p[i].name1,p[i].timein1,p[i].timein2,p[i].timein3,p[i].timeout1,p[i].timeout2,p[i].timeout3);    //以2进制形式写入文件中//一次写入一个数组//  
        
        }
       // printf("file write error\n");  
        fclose(fp);                                       //关闭文件  
        system("pause");  
  }  

	 void scan()                        //显示记录  进行全面信息浏览  
   {  
    char sign='y';  
    FILE *fp;  
    int n;  
    system("cls");  
      if((fp=fopen("studata.txt","r"))==NULL)             //以2进制方式读取文件信息//  
      {  
         printf("cannot open the files\n");  
         system("pause");  
         return;  
       }  
     //printf("%d",n=0);
    int i=0;
    while(fscanf(fp,"%s%s%f%d%d%d%s%d%d%d%d%d%d\n",p[i].name,p[i].num,&p[i].money,&p[i].ruku,&p[i].kucun,&p[i].chuku,p[i].name1,&p[i].timein1,&p[i].timein2,&p[i].timein3,&p[i].timeout1,&p[i].timeout2,&p[i].timeout3)!=EOF)
    { 
     //printf("");
    // printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
     printf("名称   编号      单价     入库数量  库存数量  出库数量  保管人  进货时间  出货时间\n");  
     //printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"); 
     printf("%s      %s        %f    %d	       %d        %d         %s      %d %d %d    %d %d %d\n",p[i].name,p[i].num,p[i].money,p[i].ruku,p[i].kucun,p[i].chuku,p[i].name1,p[i].timein1,p[i].timein2,p[i].timein3,p[i].timeout1,p[i].timeout2,p[i].timeout3);  
     printf("\n"); 
         i++;
    }   
     system("pause");  
     system("cls");  
  
  }  
  
     //*********************************************************************//  
     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
   void query()                     //信息的不同方式查询  
   {      
        system("cls");
        person p[200];
        FILE *fp1;  
        int i=0;
        int n=0;  
        int m;   
        printf("\t\n请选择查询方式:\n");  
        printf("\t┌────────────┐\n");    
        printf("\t│1------名称 │\n");  
        printf("\t│2------编号 │\n");  
        printf("\t│3------返回 │\n");  
        printf("\t└────────────┘\n");  
        printf("请输入你要查询的方式\n");  
        scanf("%d",&m);  
        while(m!=1&&m!=2&&m!=3)  
            {  
                printf("输入错误请重新查询\n");  
                scanf("%d",&m);  
            }  
          if((fp1=fopen("studata.txt","r"))==NULL)                 //以2进制方式读取文件信息//  
          {  
             printf("cannot open the files\n");  
           }    
    
        while(fscanf(fp1,"%s %s %f %d %d %d %s %d %d %d %d %d %d\n",p[i].name,p[i].num,&p[i].money,&p[i].ruku,&p[i].kucun,&p[i].chuku,p[i].name1,&p[i].timein1,&p[i].timein2,&p[i].timein3,&p[i].timeout1,&p[i].timeout2,&p[i].timeout3)!=EOF)
        {    
             i++;
             n=n+1;
        }  
    
              
        
      
  
    if(m==1)                                            //名称查询  
       {  
        char s[20];  
        int j=0;  
        printf("\t请输入想查询的名称:");  
        scanf("\t%s",s);  
        while(strcmp(p[j].name,s)!=0&&j<n) j++;            //比较p[i].name与所输入名称是否相同//  
        if(j==n)
        {
            printf("无");
        }
                printf("\t编号: %s\n",p[j].num);  
                printf("\t名称: %s\n",p[j].name);  
                printf("\t单价: %f\n",p[j].money);  
                printf("\t入库数量: %d\n",p[j].ruku);  
                printf("\t库存数量: %d\n",p[j].kucun);
                printf("\t出库数量: %d\n",p[j].chuku);  
                printf("\t保管人: %s\n",p[j].name1); 
				printf("\t进货时间: %d %d %d\n",p[j].timein1,p[j].timein2,p[j].timein3); 
				printf("\t出货时间: %d %d %d\n",p[j].timeout1,p[j].timeout2,p[j].timeout3); 
            
      }   
    if(m==2)                                                            //编号查询  
        {  
          char s[15];  
          int i=0;  
          printf("请输入想查询的编号：");  
          scanf("\t%s",s);  
          
          while(strcmp(p[i].num,s)!=0&&i<n)                                //比较p[i].name与所输入编号是否相同//
         i++;                         
            if(i==n)  
            {  
                printf("\t未找到目标!\n");  
                system("pause");  
                return;  
            }  
                printf("\t编号: %s\n",p[i].num);  
                printf("\t名称: %s\n",p[i].name);  
                printf("\t单价: %f\n",p[i].money);  
                printf("\t入库数量: %d\n",p[i].ruku);  
                printf("\t库存数量: %d\n",p[i].kucun);
                printf("\t出库数量: %d\n",p[i].chuku);  
                printf("\t保管人: %s\n",p[i].name1); 
				printf("\t进货时间: %d %d %d\n",p[i].timein1,p[i].timein2,p[i].timein3); 
				printf("\t出货时间: %d %d %d\n",p[i].timeout1,p[i].timeout2,p[i].timeout3); 
            
          }  
          fclose(fp1); 
          system("pause"); 
  }  
   
     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
  /* void delet()                                                  //删除
  {  
  
    person p[200];
    FILE *fp;  
    char s[10];  
    int i=0,n=0;  
      if((fp=fopen("studata.txt","r"))==NULL)                  //以2进制方式读取文件信息//  
      {  
         printf("cannot open the files\n");  
         system("pause");  
         return;  
       }  
  
        while(fscanf(fp,"%s %s %f %d %d %d %s %d %d %d %d %d %d\n",p[i].name,p[i].num,&p[i].money,&p[i].ruku,&p[i].kucun,&p[i].chuku,p[i].name1,&p[i].timein1,&p[i].timein2,&p[i].timein3,&p[i].timeout1,&p[i].timeout2,&p[i].timeout3)!=EOF)
        {    
             i++;
             n=n+1;
        } 
 
    fclose(fp); 
      
    printf("材料编号：");  
    scanf("%s",s);  
    i=0;
    while(strcmp(p[i].num,s)!=0&&i<n)
    {
         i++;
     }                           //进行比较 找到所需要的信息  
        if(i==n)  
         {  
            printf("\t未找到目标!\n");  
            return;  
         }  
    else{  
    FILE *fin,*ftp;
    fin=fopen("studata.txt","r");//读打开原文件123.txt
    ftp=fopen("tmp.txt","w");//写打开临时文件tmp.txt
    if(fin==NULL || ftp==NULL){
        printf("Open the file failure...\n");
        exit(0);
    }
    int kk=0;
    while(kk<n) //从原文件读取一行
    {
        if(strcmp(p[kk].num,s)!=0)//检验是要删除的行吗?
        {
            fprintf(ftp,"%s %s %f %d %d %d %s %d %d %d %d %d %d\n",p[i].name,p[i].num,p[i].money,p[i].ruku,p[i].kucun,p[i].chuku,p[i].name1,p[i].timein1,p[i].timein2,p[i].timein3,p[i].timeout1,p[i].timeout2,p[i].timeout3);//不是则将这一行写入临时文件tmp.txt
        }
 
       kk++;    
    }
        
 
    fclose(fin);
    fclose(ftp);
    remove("studata.txt");//删除原文件
    rename("tmp.txt","studata.txt");//将临时文件名改为原文件名
    printf("删除成功！") ; 
} 
   }*/
													 //运用switch语句进行菜单选择// 
    int main()  
  {  
 
 
  
      int n=0;    
      //menu_filename();                                         //引用全局变量文件名  
      for(;;)                                                 //循环使用主界面直到遇到结束命令  
      {   
          switch(menu_select())                               // 函数的调用//  
          {  
          case 1: 
              printf("\t\t *=_=*添加记录 *=_=*\n");  
              add();  
              break;  
          case 2:  
              printf("\t\t *=_=*材料信息浏览 *=_=*\n");  
              scan();  
              break;  
          case 3:  
              printf("\t\t *=_=*材料信息查询 *=_=*\n");  
              query();  
              break;  
          /*case 4:  
              printf("\t\t *=_=*删除信息 *=_=*\n");  
              delet();  
              break;  */
          case 0:  
                printf("\n\t\t后会无期!\n");  
                printf("\n\t\t");  
                system("pause");  
                exit(0);  
          }  
      }  
      
 
        system("pause");  
        
 
          //system("pause");  */
          return 0;
  } 
