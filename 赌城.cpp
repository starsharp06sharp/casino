#include <cstdio> 
#include <cstdlib> 
#include <conio.h>
#include <ctime> 
#include <windows.h> 

int cpucard[6][2],playcard[6][2],card[6][2],cpun,playn;
int have=1000,m,s;
int bank_have=0,bank_h=0;
char pai[9][8]={"ɢ��]  ","����]  ","����]  ","����]  ","˳��]  ","ͬ��]  ","��«]  ","��֧]  ","ͬ��˳]"} ;
char dian[21][4]={"   "," 8 "," 9 "," 10"," J "," Q "," K "," A "," 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 "," 10"," J "," Q "," K "};
char hua[5][3]={" ","\4","\5","\3","\6"};

/******************************************************************************/
int random(int n)
{    
    int nn;
    srand((unsigned)time(NULL)+rand());
    for(int i=(int)rand()%1000/100+10;i>=0;i--)
          nn=rand()%n;
     return nn;
}
/******************************************************************************/
void paixu()
{    int c,i,j,t;
     for(c=1;c<=5;c++)
     for(i=1;i<=5;i++)
     {for(j=i+1;j<=5;j++)
      {if(card[i][0]<card[j][0]){t=card[i][0];card[i][0]=card[j][0];card[j][0]=t;
                                 t=card[i][1];card[i][1]=card[j][1];card[j][1]=t;}
       if(card[i][0]==card[j][0]&&card[i][1]<card[j][1])
                                {t=card[i][0];card[i][0]=card[j][0];card[j][0]=t;
                                 t=card[i][1];card[i][1]=card[j][1];card[j][1]=t;}
             }
     }
}
int same(int f,int l)
{
    for(int i=f;i<=l-1;i++)
       if(card[i][0]!=card[i+1][0])return 0;
    return 1;
}
int tonghua() 
{
    for(int i=1;i<=4;i++)
       if(card[i][1]!=card[i+1][1])return 0;
    return 1;
}
int shunzi()
{
    for(int i=1;i<=4;i++)
       if(card[i][1]!=card[i+1][1]+1)return 0;
    return 1;
}
int panduan()
{
    if(tonghua()&&shunzi())return 800+card[1][0]*10+card[1][1]; //ͬ��˳
    else if(same(1,4)||same(2,5))return 700+card[1][0]*10+card[1][1]; //��֧
    else if(same(1,3)&&same(4,5)||same(3,5)&&same(1,2))return 600+card[1][0]*10+card[1][1]; //��«
    else if(tonghua())return 500+card[1][0]*10+card[1][1]; //ͬ��
    else if(shunzi())return 400+card[1][0]*10+card[1][1]; //˳��
    else if(same(1,3)||same(2,4)||same(3,5))return 300+card[1][0]*10+card[1][1]; //����
    else if(same(1,2)&&same(3,4)||same(2,3)&&same(4,5)||same(1,2)&&same(4,5))return 200+card[1][0]*10+card[1][1]; //����
    else if(same(1,2)||same(2,3)||same(3,4)||same(4,5))return 100+card[1][0]*10+card[1][1]; //����
    else return card[1][0]*10+card[1][1]; //ɢ��
}
/******************************************************************************/
void print(int f,int l,int ll)
{
    printf("�������������������������������������������϶�ע�� %7d������\n",m);
    printf("��ׯ�����ϵ����ǣ�                                            ��\n");
    printf("��");for(int i=1;i<=l;i++)printf("������������");for(int i=l+1;i<=5;i++)printf("            ");printf("��\n");
    printf("��");for(int i=1;i<f;i++)printf("������������");for(int i=f;i<=l;i++)printf("��%s%s    ��",hua[cpucard[i][1]],dian[cpucard[i][0]]);for(int i=l+1;i<=5;i++)printf("            ");printf("��\n");
    for(int j=1;j<=4;j++){printf("��");for(int i=1;i<f;i++)printf("������������");for(int i=f;i<=l;i++)printf("��        ��");for(int i=l+1;i<=5;i++)printf("            ");printf("��\n");}
    printf("��");for(int i=1;i<f;i++)printf("������������");for(int i=f;i<=l;i++)printf("��    %s%s��",hua[cpucard[i][1]],dian[cpucard[i][0]]);for(int i=l+1;i<=5;i++)printf("            ");printf("��\n");
    printf("��");for(int i=1;i<=l;i++)printf("������������");for(int i=l+1;i<=5;i++)printf("            ");printf("��\n");
    printf("�������ϵ����ǣ�                                              ��\n");
    printf("��");for(int i=1;i<=ll;i++)printf("������������");for(int i=ll+1;i<=5;i++)printf("            ");printf("��\n");
    printf("��");for(int i=1;i<=ll;i++)printf("��%s%s    ��",hua[playcard[i][1]],dian[playcard[i][0]]);for(int i=ll+1;i<=5;i++)printf("            ");printf("��\n");
    for(int j=1;j<=4;j++){printf("��");for(int i=1;i<=ll;i++)printf("��        ��");for(int i=ll+1;i<=5;i++)printf("            ");printf("��\n");}
    printf("��");for(int i=1;i<=ll;i++)printf("��    %s%s��",hua[playcard[i][1]],dian[playcard[i][0]]);for(int i=ll+1;i<=5;i++)printf("            ");printf("��\n");
    printf("��");for(int i=1;i<=ll;i++)printf("������������");for(int i=ll+1;i<=5;i++)printf("            ");printf("��\n");
}
/******************************************************************************/
void game21end(int p,int c)
{
     system ("cls");
    system("title �ĳ�-21�� ZDC����");
     print(1,cpun,playn);
     printf("�t����Ƶ���ǣ�%2d����������������������ׯ�ҵ��Ƶ���ǣ�%2d�����s\n",p,c);
     if(p>c&&p<=21){printf("��ϲ���ʤ��!��Ӯ��%dԪ\n",m);have+=m;getch();return;}
     if(p<c&&c<=21){printf("�����ˣ�ׯ�һ�ʤ��!������%dԪ\n",m);have-=m;getch();return;}
     if(p<=21&&c>21){printf("ׯ�ұ��ˣ�����ʤ�ˣ���Ӯ��%dԪ\n",m);have+=m;getch();return;}
     if(p>21&&c<=21){printf("�����ˣ�ׯ�һ�ʤ�ˣ�������%dԪ\n",m);have-=m;getch();return;} 
     if(p>21&&c>21) {printf("��Ҷ����ˣ�ƽ�֣�\n",m);getch();return;} 
     if(p<=21&&c<=21&&p==c) {printf("��Ҷ�һ����ƽ�֣�\n",m);getch();return;} 
}

/******************************************************************************/
void game21()
{
     
     system("mode con: cols=65 lines=23");
    system("title �ĳ�-21�� ZDC����");
     int cpuand,playand,ss;
     m=0;s=0;
     while(1){
     system ("cls");m=0;
     print(1,0,0);
     printf("�t�������������������������������������������������������������s\n");
     printf("�������ע(1~%d)��",have);scanf("%d",&m);
     if(m>0&&m<=have)break;
     printf("���벻�Ϸ���");Sleep(1000);
     }
     for(int i=1;i<=5;i++){cpucard[i][0]=random(13)+7;cpucard[i][1]=random(4)+1;}
     for(int i=1;i<=5;i++){playcard[i][0]=random(13)+7;playcard[i][1]=random(4)+1;}
     playn=cpun=1;
     while(1){
              playand=cpuand=0;
              system ("cls");
              for(int i=1;i<=playn;i++)
              {if(playcard[i][0]-7<10)playand+=playcard[i][0]-6;else playand+=10;}
              for(int i=2;i<=cpun;i++)
              {if(cpucard[i][0]-7<10)cpuand+=cpucard[i][0]-6;else cpuand+=10;}
              print(2,cpun,playn);
              printf("�t����Ƶ���ǣ�%2d����������������������ׯ�ҵ��Ƶ���ǣ�%2d�����s\n",playand,cpuand);
              if(playand>21){printf("��������21,�Զ����ƣ�\n");Sleep(1200);ss=0;}
              else {printf("���Ƿ����Ҫ�ƣ�(1/0)");scanf("%d",&ss);}
              if(ss==1&&playn==5){
                                 printf("\n�Բ������Ѿ�Ҫ���������ˣ�");
                                 ss=0;
                                 Sleep(2000); 
                                 }
              if(ss==1)playn++;
              if(cpucard[1][0]-7>10)cpuand+=cpucard[1][0]-7;else cpuand+=10;
              if(cpuand<16&&cpun<=5)cpun++;
              else if(cpuand<=playand-playcard[0][0]&&cpun<=5)cpun++;
              else if(ss==0){game21end(playand,cpuand);return;}
              }
}
/******************************************************************************/
void gameshend()
{    system ("cls");
     system("mode con: cols=65 lines=24");
     system("title �ĳ�-��� ZDC����");
     print(1,5,5);
     printf("��ׯ�����ϵ������ǣ�[%s                                  ��\n",pai[cpun/100]);
     printf("�������ϵ������ǣ�[%s                                    ��\n",pai[playn/100]);
     printf("�t�������������������������������������������������������������s\n");
     if(playn>cpun){printf("��ϲ���ʤ��!��Ӯ��%dԪ\n",m);have+=m;system("pause");return;}
     if(playn<cpun){printf("�����ˣ�ׯ�һ�ʤ��!������%dԪ\n",m);have-=m;system("pause");return;}
     if(playn==cpun) {printf("��Ҷ�һ����ƽ�֣�\n",m);system("pause");return;} 
}
/******************************************************************************/
void gamesh()
{
     system("mode con: cols=65 lines=24");
     system("title �ĳ�-��� ZDC����");
     m=0;s=0;
     int c; 
     for(int i=1;i<=5;i++){cpucard[i][0]=random(7)+1;cpucard[i][1]=random(4)+1;}
     for(int i=1;i<=5;i++){playcard[i][0]=random(7)+1;playcard[i][1]=random(4)+1;}
     for(int i=1;i<=5;i++){card[i][0]=playcard[i][0];card[i][1]=playcard[i][1];}
     paixu();playn=panduan();
     for(int i=1;i<=5;i++){card[i][0]=cpucard[i][0];card[i][1]=cpucard[i][1];}
     paixu();cpun=panduan();
     while(1){
     system ("cls");
     print(1,0,0);
     printf("�t�������������������������������������������������������������s\n");
     printf("�������ʼ��ע(1~%d)��",have);scanf("%d",&s);
     if(s<0||s>have-m){printf("���벻�Ϸ���");Sleep(1000);continue;}
     m=s;break;
     }
     while(1)
             {       
                     system ("cls");
                     print(2,5,5);
                     printf("�t�������������������������������������������������������������s\n");
                     printf("�Ƿ��ע(1/0)��");scanf("%d",&c);
                     if(c==0){printf("��û�м�ע�ˣ�\n");break;}
                     printf("�����ע���ע(1~%d)��",have-m);scanf("%d",&s);
                     if(s<1||s>have-m){printf("���벻�Ϸ���");Sleep(1000);continue;}
                     m+=s;
                     if(random(2)){printf("ׯ��û�м�ע�ˣ�\n");break;}
                     printf("ׯ�Ҹ�ע�ˣ�\n");
                     m+=s;
                     system("pause");
             } 
     system("pause");
     gameshend();
}
/******************************************************************************/
void laohu()
{
    system("mode con: cols=34 lines=13");
    system("title �ĳ�-�ϻ��� ZDC����");
    int c;
    clock_t t_time;
    double beginning_time,finish_time; 
    int a[6],n=0;
    for(int i=0;i<6;i++)a[i]=random(5)+3;
    char t[8][3]={"��","��","��","�I","��","��","��","��"};
    system ("cls");
    printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("         �����ϻ�������\n");
    printf("  1000000��%s%s%s%s%s��1000000\n",t[(a[1]-2)%8],t[(a[2]-2)%8],t[(a[3]-2)%8],t[(a[4]-2)%8],t[(a[5]-2)%8]);
    printf("  2000000��%s%s%s%s%s��2000000\n",t[(a[1]-1)%8],t[(a[2]-1)%8],t[(a[3]-1)%8],t[(a[4]-1)%8],t[(a[5]-1)%8]);
    printf("  5000000��%s%s%s%s%s��5000000\n",t[(a[1])%8],t[(a[2])%8],t[(a[3])%8],t[(a[4])%8],t[(a[5])%8]);
    printf("  2000000��%s%s%s%s%s��2000000\n",t[(a[1]+1)%8],t[(a[2]+1)%8],t[(a[3]+1)%8],t[(a[4]+1)%8],t[(a[5]+1)%8]);
    printf("  1000000��%s%s%s%s%s��1000000\n",t[(a[1]+2)%8],t[(a[2]+2)%8],t[(a[3]+2)%8],t[(a[4]+2)%8],t[(a[5]+2)%8]);
    printf("         ��������������\n");
    printf("�^�T�T�T�T ���ո�ֹͣ �T�T�T�T�a\n");
    printf("Ҫ��ʼ�ϻ���ô(�軨��100Ԫ)\n�㻹������%d�Σ�(1/0)",have/100);scanf("%d",&c);
    if(c==0)return;
    if(have<100){printf("���㣡");system("pause");return;}
    have-=100;
    while(1){
             system("cls");
             printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
             printf("         �����ϻ�������\n");
             printf("  1000000��%s%s%s%s%s��1000000\n",t[(a[1]-2)%8],t[(a[2]-2)%8],t[(a[3]-2)%8],t[(a[4]-2)%8],t[(a[5]-2)%8]);
             printf("  2000000��%s%s%s%s%s��2000000\n",t[(a[1]-1)%8],t[(a[2]-1)%8],t[(a[3]-1)%8],t[(a[4]-1)%8],t[(a[5]-1)%8]);
             printf("  5000000��%s%s%s%s%s��5000000\n",t[(a[1])%8],t[(a[2])%8],t[(a[3])%8],t[(a[4])%8],t[(a[5])%8]);
             printf("  2000000��%s%s%s%s%s��2000000\n",t[(a[1]+1)%8],t[(a[2]+1)%8],t[(a[3]+1)%8],t[(a[4]+1)%8],t[(a[5]+1)%8]);
             printf("  1000000��%s%s%s%s%s��1000000\n",t[(a[1]+2)%8],t[(a[2]+2)%8],t[(a[3]+2)%8],t[(a[4]+2)%8],t[(a[5]+2)%8]);
             printf("         ��������������\n");
             printf("�^�T�T�T�T ���ո�ֹͣ �T�T�T�T�a\n");
             if(n==5)break;
             t_time=clock(); 
             beginning_time=(double)t_time/(double)CLOCKS_PER_SEC;
             do{
                 if(GetAsyncKeyState(VK_SPACE)){n++;break;}
             t_time=clock(); 
             finish_time=(double)t_time/(double)CLOCKS_PER_SEC;
             }
             while(finish_time-beginning_time<0.01);
             Sleep(99); 
             for(int i=n;i<6;i++)a[i]+=+1;
             }
    if((a[1]-2)%8==(a[2]-1)%8&&(a[2]-1)%8==a[3]%8&&a[3]%8==(a[4]+1)%8&&(a[4]+1)%8==(a[5]+2)%8){have+=10000;printf("��ϲ������100000Ԫ\n");}
    else if((a[1]-1)%8==(a[2]-1)%8&&(a[2]-1)%8==a[3]%8&&a[3]%8==(a[4]+1)%8&&(a[4]+1)%8==(a[5]+1)%8){have+=20000;printf("��ϲ������200000Ԫ\n");}
    else if(a[1]%8==a[2]%8&&a[2]%8==a[3]%8&&a[3]%8==a[4]%8&&a[4]%8==a[5]%8){have+=50000;printf("��ϲ������500000Ԫ\n");}
    else if((a[5]-1)%8==(a[4]-1)%8&&(a[4]-1)%8==a[3]%8&&a[3]%8==(a[2]+1)%8&&(a[2]+1)%8==(a[1]+1)%8){have+=20000;printf("��ϲ������200000Ԫ\n");}
    else if((a[5]-2)%8==(a[4]-1)%8&&(a[4]-1)%8==a[3]%8&&a[3]%8==(a[2]+1)%8&&(a[2]+1)%8==(a[1]+2)%8){have+=10000;printf("��ϲ������100000Ԫ\n");}
    else printf("ʧ�ܣ�\n");
    for(char cc;cc==' ';)
    cc=getch(); 
    system("pause");
}
/******************************************************************************/
int zhucaidan()
{system("mode con: cols=57 lines=20");
char cc;//bug fixed by ZL
while(1){
system("cls");
system("title �ĳ� ZDC����");
printf("                    |>>>          �㻹���ʱ���%9d \n",have);
printf("                    |                                 \n");
printf("      |>>>      _  _|_  _         |>>>                \n");
printf("      |        |;| |;| |;|        |     �X�������������[\n");
printf("  _  _|_  _    \\\\.    .  /    _  _|_  _ ��Ҽ  �����  ��\n");
printf(" |;|_|;|_|;|    \\\\: +   /    |;|_|;|_|;|����  ��21��  ��\n");
printf(" \\\\..      /    ||:+++. |    \\\\.    .  /����  ���ϻ�����\n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\:  .  / ����  ��Ϸ������\n");
printf("   ||:+  |_   _ ||_ . _ | _   _||:+  |  ����  ȥ����  ��\n");
printf("   ||+++.|||_|;|_|;|_|;|_|;|_|;||+++ |  ��½  ����    ��\n");
printf("   ||+++ ||.    .     .      . ||+++.|  ����  ������é�\n");
printf("   ||:   ||:  ,     +       .  ||: , |  ����  �뿪��Ϸ��\n");
printf("   ||:   ||:.     +++++      . ||:   |  �^�������������a\n");
printf("   ||:   ||.     +++++++  .    ||: . |                  \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                  \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                  \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("��ѡ��(1/2/3/4/5/6/7/8)��");
while (1) {//bug fixed by ZL
cc=getch();//bug fixed by ZL
//scanf("%c",&cc);
if(cc<='8'&&cc>='0') return cc-'0';//bug fixed by ZL
}
}
}
/******************************************************************************/
int help()
{
system("cls");
system("title �ĳ�-���� ZDC����");
system("mode con: cols=57 lines=47");
printf("~~~~�������~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("  ���һ��ò�˥�Ķĳ���Ϸ����8������ȡ��8~A�⼸���ƣ�\n");
printf("��ׯ�Һ���ս�߸������������������Ƶ����ʹ�С��ʤ����    \n");
printf("                                                        \n");
printf("  ���ʹ�С˳��Ϊ                                        \n");
printf("  ͬ��˳����֧����«��ͬ����˳�ӣ����������ԣ����ӣ�ɢ��\n");
printf("                                                        \n");
printf("  ������ʹ�Сһ���ͱȵ�һ���ƵĴ�С��ɫ���绹һ������ƽ\n");
printf("�֣�                                                    \n");
printf("  �������ͣ�                                            \n");
printf("    ͬ��˳��A,A+1,A+2,A+3,A+4 �һ�ɫһ��                \n");
printf("    ��֧��AAAAB          ��«��AAABB                    \n");
printf("    ͬ������ɫһ��       ˳�ӣ�A,A+1,A+2,A+3,A+4        \n");
printf("    ������AAABC          ���ԣ�AABBC                    \n");
printf("    ���ӣ�AABCD          ɢ�ƣ�ABCDE                    \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
printf("~~~~21����Ϸ����~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
printf("  21��Ҳ��һ��ʮ������˼����Ϸ����Һ�ׯ��ÿ���������ơ�\n"); 
printf("��˭�������Ƶ���ӽ�21�㵫������21�㡣                \n"); 
printf("                                                        \n"); 
printf("  ���������                                            \n"); 
printf("    A��1��                                              \n"); 
printf("    2~10����������ĵ���                                \n"); 
printf("    J~K����10��                                         \n"); 
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
printf("~~~~�ϻ�������~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
printf("  ʮ�ּ򵥰��ո������ϻ���ͣת���������ر�ķ��ż��ɻ��\n"); 
printf("�߶����                                              \n"); 
printf("                                                        \n"); 
printf("  ������ţ�                                            \n"); 
printf("     -----      ----- -----        *---- ----*          \n"); 
printf("     -----      *---- ----*        -*--- ---*-          \n"); 
printf("     *****      -***- -***-        --*-- --*--          \n"); 
printf("     -----      ----* *----        ---*- -*---          \n"); 
printf("     -----      ----- -----        ----* *----          \n"); 
printf("    5000000       2000000            1000000            \n"); 
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
printf("~~~~����ϵͳ����~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
printf("  û��ʲô��˵�ı�˵�����������ᣡ������������ö�\n"); 
printf("û����һ�غϾͻ�����1�����öȣ����öȴ���100ʱ���޷�����\n"); 
printf("  ������Ϣ��һ�غ���Ϣ10%   ������Ŷ ^o^                \n"); 
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
system("pause");
}
/******************************************************************************/
void fengg()
{
int c; 
system("cls");
system("mode con: cols=57 lines=20");
system("title �ĳ�-��� ZDC����");
printf("                    |>>>          �㻹���ʱ���%9d \n",have);
printf("                    |                                 \n");
printf("      |>>>      _  _|_  _         |>>>                \n");
printf("      |        |;| |;| |;|        |     �X�������������[\n");
printf("  _  _|_  _    \\\\.    .  /    _  _|_  _ ��Ҽ  ��׼    ��\n");
printf(" |;|_|;|_|;|    \\\\: +   /    |;|_|;|_|;|����  ѩ��    ��\n");
printf(" \\\\..      /    ||:+++. |    \\\\.    .  /����  �ݵ�    ��\n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\:  .  / ����  ���    ��\n");
printf("   ||:+  |_   _ ||_ . _ | _   _||:+  |  ����  �ƽ��  ��\n");
printf("   ||+++.|||_|;|_|;|_|;|_|;|_|;||+++ |  ��½  ����    ��\n");
printf("   ||+++ ||.    .     .      . ||+++.|  ����  ���±�  ��\n");
printf("   ||:   ||:  ,     +       .  ||: , |  �^�������������a\n");
printf("   ||:   ||:.     +++++      . ||:   |                  \n");
printf("   ||:   ||.     +++++++  .    ||: . |                  \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                  \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                  \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("��ѡ��(1/2/3/4/5)........."); 
scanf("%d",&c);
if(c==1)system("color 07");
if(c==2)system("color f7");
if(c==3)system("color a2");
if(c==4)system("color 9f");
if(c==5)system("color e6");
if(c==6)system("color c4");
if(c==7)system("color f0");
}
/******************************************************************************/
void about()
{system("cls");
system("mode con: cols=55 lines=18");
system("title �ĳ�-���� ZDC����");
printf("                    |>>>                              \n");
printf("                    |                                 \n");
printf("      |>>>      _  _|_  _       �ĳ���Ϸ              \n");
printf("      |        |;| |;| |;|      �汾��V4.001          \n");
printf("  _  _|_  _    \\\\.    .  /    _ ������ı�д�ߣ�ZDC   \n");
printf(" |;|_|;|_|;|    \\\\+     /    |;|ͼ������Ч����ZDC     \n");
printf(" \\\\..      /    ||:+++. |    \\\\.    .  /              \n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\��Ϸ�е������21�㣬  \n");
printf("   ||:+  |_   _ ||_ . _ | _   _|�ϻ���������Ȩ���鱾��\n");
printf("   ||+++.|||_|;|_|;|_|;|_|;|_|;|���г��Ա��˸Ų�����\n");
printf("   ||+++ ||.    .     .      . ||+++.|                \n");
printf("   ||:   ||:  ,     +       .  ||: , |     2008��8��  \n");
printf("   ||:   ||:.     +++++      . ||:   |                \n");
printf("   ||:   ||.     +++++++  .    ||: . |  ��Ȩ���У�    \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |       ����ؾ� \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
system("pause");
}
/******************************************************************************/
void end()
{system("cls");
system("mode con: cols=55 lines=18");
system("title �ĳ�-���� ZDC����");
printf("                    |>>>                              \n");
printf("                    |                                 \n");
printf("      |>>>     ������Ϸ����       |>>>                \n");
printf("      |  ���Ʋ�����Ϸ �ܾ�������Ϸ                    \n");
printf("  _  _|_ ע�����ұ��� ������ƭ�ϵ� _  _               \n");
printf(" |;|_|;| �ʶ���Ϸ���� ������Ϸ���� |_|;|              \n");
printf(" \\\\..    ������ʱ�� ���ܽ�������  .  /              \n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\:  .  /               \n");
printf("   ||:+  |_   _ ||_ . �Ĳ��к����Ľ���                \n");
printf("   ||+++.|||_|;|_|;|_|�벻Ҫǧ����ʵ�Ķĳ�������ȥ�޻�\n");
printf("   ||+++ ||.    .     .      . ||+++.|                \n");
printf("   ||:   ||:  ,     +       .  ||: , |��Ϸ��д�ߣ�    \n");
printf("   ||:   ||:.     +++++      . ||:   |          ZDC   \n");
printf("   ||:   ||.     +++++++  .    ||: . |                \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
system("pause");
}
/******************************************************************************/
void bank(int ccc)
{
int cc;
system("cls");system("mode con: cols=55 lines=21");
if(ccc==1){system("mode con: cols=55 lines=22");printf("��ûǮ�ˣ�����\n");}
system("title �ĳ�-���� ZDC����");
printf("                    |>>>        �㻹���ʱ���%9d \n",have);
printf("                    |           ��Ƿ���У�  %9d \n",bank_have);
printf("      |>>>      _  _|_  _       ������öȣ�      %3d \n",bank_h);
printf("      |        |;| |;| |;|        |     �X�����������[\n");
printf("  _  _|_  _    \\\\.    .  /    _  _|_  _ ��Ҽ  ����  ��\n");
printf(" |;|_|;|_|;|    \\\\: +   /    |;|_|;|_|;|����  ����  ��\n");
printf(" \\\\..      /    ||:+++. |    \\\\.    .  /����  �뿪  ��\n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\:  .  / �^�����������a\n");
printf("   ||:+  |_   _ ||_ . _ | _   _||:+  |                \n");
printf("   ||+++.|||_|;|_|;|_|;|_|;|_|;||+++ |                \n");
printf("   ||+++ ||.    .     .      . ||+++.|                \n");
printf("   ||:   ||:  ,     +       .  ||: , |                \n");
printf("   ||:   ||:.     +++++      . ||:   |                \n");
printf("   ||:   ||.     +++++++  .    ||: . |                \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("��ѡ��(1/2/3)��");scanf("%d",&cc);
if(cc==1){if(bank_h>=100){printf("����������öȻ����������ȥ��");system("pause");return;}
          printf("����������");scanf("%d",&cc);
          if(cc>0){bank_have+=cc;have+=cc;printf("�ɹ�����%dԪ��\n",cc);system("pause");return;} 
         } 
if(cc==2){printf("�����뻹���");scanf("%d",&cc);
          if(cc>0){bank_have-=cc;have-=cc;printf("�ɹ�����%dԪ��\n",cc);system("pause");return;}
         } 
if(cc==3){return;
         } 
}
/******************************************************************************/
void over()
{system("cls");
system("mode con: cols=79 lines=7");
system("title �ĳ�-���� ZDC����");
printf("*******  *******  *       *  *******      *******  *       *  *******  ******\n");
printf("*        *     *  **     **  *            *     *   *     *   *        *     *\n");
printf("*  ****  *******  * *   * *  *******      *     *    *   *    *******  ******\n");
printf("*     *  *     *  *  * *  *  *            *     *     * *     *        *  *\n");
printf("*******  *     *  *   *   *  *******      *******      *      *******  *    *\n");
printf("������˼ҵף����Ÿ�ծ�����Ų�����¼�������˳������Ժ�û��������������\n");
system("pause"); 
}
/******************************************************************************/
main()
{
      int cc;
      while(1)
      {if(bank_h>100&&have<=0){over();end();return 1;} 
       while(have<=0){bank(1);}
       cc=zhucaidan();
       if(cc==1)gamesh();
       if(cc==2)game21();
       if(cc==3)laohu();
       if(cc==4)help();
       if(cc==5)bank(0);
       if(cc==6)about();
       if(cc==7)fengg();
       if(cc==8){end();return 1;}
       if(bank_have>0){bank_have*=1.1;bank_h+=1;}
      }
}
