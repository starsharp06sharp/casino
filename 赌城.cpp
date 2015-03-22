#include <cstdio> 
#include <cstdlib> 
#include <conio.h>
#include <ctime> 
#include <windows.h> 

int cpucard[6][2],playcard[6][2],card[6][2],cpun,playn;
int have=1000,m,s;
int bank_have=0,bank_h=0;
char pai[9][8]={"散牌]  ","对子]  ","二对]  ","三条]  ","顺子]  ","同花]  ","葫芦]  ","铁支]  ","同花顺]"} ;
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
    if(tonghua()&&shunzi())return 800+card[1][0]*10+card[1][1]; //同花顺
    else if(same(1,4)||same(2,5))return 700+card[1][0]*10+card[1][1]; //铁支
    else if(same(1,3)&&same(4,5)||same(3,5)&&same(1,2))return 600+card[1][0]*10+card[1][1]; //葫芦
    else if(tonghua())return 500+card[1][0]*10+card[1][1]; //同花
    else if(shunzi())return 400+card[1][0]*10+card[1][1]; //顺子
    else if(same(1,3)||same(2,4)||same(3,5))return 300+card[1][0]*10+card[1][1]; //三条
    else if(same(1,2)&&same(3,4)||same(2,3)&&same(4,5)||same(1,2)&&same(4,5))return 200+card[1][0]*10+card[1][1]; //二对
    else if(same(1,2)||same(2,3)||same(3,4)||same(4,5))return 100+card[1][0]*10+card[1][1]; //对子
    else return card[1][0]*10+card[1][1]; //散牌
}
/******************************************************************************/
void print(int f,int l,int ll)
{
    printf("┏───────────────────桌上赌注： %7d──┓\n",m);
    printf("┃庄家手上的牌是：                                            ┃\n");
    printf("┃");for(int i=1;i<=l;i++)printf("┏━━━━┓");for(int i=l+1;i<=5;i++)printf("            ");printf("┃\n");
    printf("┃");for(int i=1;i<f;i++)printf("┃※※※※┃");for(int i=f;i<=l;i++)printf("┃%s%s    ┃",hua[cpucard[i][1]],dian[cpucard[i][0]]);for(int i=l+1;i<=5;i++)printf("            ");printf("┃\n");
    for(int j=1;j<=4;j++){printf("┃");for(int i=1;i<f;i++)printf("┃※※※※┃");for(int i=f;i<=l;i++)printf("┃        ┃");for(int i=l+1;i<=5;i++)printf("            ");printf("┃\n");}
    printf("┃");for(int i=1;i<f;i++)printf("┃※※※※┃");for(int i=f;i<=l;i++)printf("┃    %s%s┃",hua[cpucard[i][1]],dian[cpucard[i][0]]);for(int i=l+1;i<=5;i++)printf("            ");printf("┃\n");
    printf("┃");for(int i=1;i<=l;i++)printf("┗━━━━┛");for(int i=l+1;i<=5;i++)printf("            ");printf("┃\n");
    printf("┃你手上的牌是：                                              ┃\n");
    printf("┃");for(int i=1;i<=ll;i++)printf("┏━━━━┓");for(int i=ll+1;i<=5;i++)printf("            ");printf("┃\n");
    printf("┃");for(int i=1;i<=ll;i++)printf("┃%s%s    ┃",hua[playcard[i][1]],dian[playcard[i][0]]);for(int i=ll+1;i<=5;i++)printf("            ");printf("┃\n");
    for(int j=1;j<=4;j++){printf("┃");for(int i=1;i<=ll;i++)printf("┃        ┃");for(int i=ll+1;i<=5;i++)printf("            ");printf("┃\n");}
    printf("┃");for(int i=1;i<=ll;i++)printf("┃    %s%s┃",hua[playcard[i][1]],dian[playcard[i][0]]);for(int i=ll+1;i<=5;i++)printf("            ");printf("┃\n");
    printf("┃");for(int i=1;i<=ll;i++)printf("┗━━━━┛");for(int i=ll+1;i<=5;i++)printf("            ");printf("┃\n");
}
/******************************************************************************/
void game21end(int p,int c)
{
     system ("cls");
    system("title 赌城-21点 ZDC制作");
     print(1,cpun,playn);
     printf("╰你的牌点和是：%2d───────────庄家的牌点和是：%2d──╯\n",p,c);
     if(p>c&&p<=21){printf("恭喜你获胜了!你赢了%d元\n",m);have+=m;getch();return;}
     if(p<c&&c<=21){printf("你输了，庄家获胜了!你输了%d元\n",m);have-=m;getch();return;}
     if(p<=21&&c>21){printf("庄家爆了，您获胜了！你赢了%d元\n",m);have+=m;getch();return;}
     if(p>21&&c<=21){printf("您爆了，庄家获胜了！你输了%d元\n",m);have-=m;getch();return;} 
     if(p>21&&c>21) {printf("大家都爆了，平局！\n",m);getch();return;} 
     if(p<=21&&c<=21&&p==c) {printf("大家都一样，平局！\n",m);getch();return;} 
}

/******************************************************************************/
void game21()
{
     
     system("mode con: cols=65 lines=23");
    system("title 赌城-21点 ZDC制作");
     int cpuand,playand,ss;
     m=0;s=0;
     while(1){
     system ("cls");m=0;
     print(1,0,0);
     printf("╰──────────────────────────────╯\n");
     printf("请输入赌注(1~%d)：",have);scanf("%d",&m);
     if(m>0&&m<=have)break;
     printf("输入不合法！");Sleep(1000);
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
              printf("╰你的牌点和是：%2d───────────庄家的牌点和是：%2d──╯\n",playand,cpuand);
              if(playand>21){printf("点数超过21,自动弃牌！\n");Sleep(1200);ss=0;}
              else {printf("您是否继续要牌？(1/0)");scanf("%d",&ss);}
              if(ss==1&&playn==5){
                                 printf("\n对不起，您已经要了五张牌了！");
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
     system("title 赌城-梭哈 ZDC制作");
     print(1,5,5);
     printf("┃庄家手上的牌型是：[%s                                  ┃\n",pai[cpun/100]);
     printf("┃你手上的牌型是：[%s                                    ┃\n",pai[playn/100]);
     printf("╰──────────────────────────────╯\n");
     if(playn>cpun){printf("恭喜你获胜了!你赢了%d元\n",m);have+=m;system("pause");return;}
     if(playn<cpun){printf("你输了，庄家获胜了!你输了%d元\n",m);have-=m;system("pause");return;}
     if(playn==cpun) {printf("大家都一样，平局！\n",m);system("pause");return;} 
}
/******************************************************************************/
void gamesh()
{
     system("mode con: cols=65 lines=24");
     system("title 赌城-梭哈 ZDC制作");
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
     printf("╰──────────────────────────────╯\n");
     printf("请输入初始赌注(1~%d)：",have);scanf("%d",&s);
     if(s<0||s>have-m){printf("输入不合法！");Sleep(1000);continue;}
     m=s;break;
     }
     while(1)
             {       
                     system ("cls");
                     print(2,5,5);
                     printf("╰──────────────────────────────╯\n");
                     printf("是否加注(1/0)？");scanf("%d",&c);
                     if(c==0){printf("你没有加注了！\n");break;}
                     printf("请输加注金额注(1~%d)：",have-m);scanf("%d",&s);
                     if(s<1||s>have-m){printf("输入不合法！");Sleep(1000);continue;}
                     m+=s;
                     if(random(2)){printf("庄家没有加注了！\n");break;}
                     printf("庄家跟注了！\n");
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
    system("title 赌城-老虎机 ZDC制作");
    int c;
    clock_t t_time;
    double beginning_time,finish_time; 
    int a[6],n=0;
    for(int i=0;i<6;i++)a[i]=random(5)+3;
    char t[8][3]={"ワ","⊙","◎","㊣","★","☆","◇","◆"};
    system ("cls");
    printf("╔══════════════╗\n");
    printf("         ┏━老虎机━┓\n");
    printf("  1000000┃%s%s%s%s%s┃1000000\n",t[(a[1]-2)%8],t[(a[2]-2)%8],t[(a[3]-2)%8],t[(a[4]-2)%8],t[(a[5]-2)%8]);
    printf("  2000000┃%s%s%s%s%s┃2000000\n",t[(a[1]-1)%8],t[(a[2]-1)%8],t[(a[3]-1)%8],t[(a[4]-1)%8],t[(a[5]-1)%8]);
    printf("  5000000┃%s%s%s%s%s┃5000000\n",t[(a[1])%8],t[(a[2])%8],t[(a[3])%8],t[(a[4])%8],t[(a[5])%8]);
    printf("  2000000┃%s%s%s%s%s┃2000000\n",t[(a[1]+1)%8],t[(a[2]+1)%8],t[(a[3]+1)%8],t[(a[4]+1)%8],t[(a[5]+1)%8]);
    printf("  1000000┃%s%s%s%s%s┃1000000\n",t[(a[1]+2)%8],t[(a[2]+2)%8],t[(a[3]+2)%8],t[(a[4]+2)%8],t[(a[5]+2)%8]);
    printf("         ┗━━━━━┛\n");
    printf("╚════ 按空格停止 ════╝\n");
    printf("要开始老虎机么(需花费100元)\n你还可以玩%d次？(1/0)",have/100);scanf("%d",&c);
    if(c==0)return;
    if(have<100){printf("余额不足！");system("pause");return;}
    have-=100;
    while(1){
             system("cls");
             printf("╔══════════════╗\n");
             printf("         ┏━老虎机━┓\n");
             printf("  1000000┃%s%s%s%s%s┃1000000\n",t[(a[1]-2)%8],t[(a[2]-2)%8],t[(a[3]-2)%8],t[(a[4]-2)%8],t[(a[5]-2)%8]);
             printf("  2000000┃%s%s%s%s%s┃2000000\n",t[(a[1]-1)%8],t[(a[2]-1)%8],t[(a[3]-1)%8],t[(a[4]-1)%8],t[(a[5]-1)%8]);
             printf("  5000000┃%s%s%s%s%s┃5000000\n",t[(a[1])%8],t[(a[2])%8],t[(a[3])%8],t[(a[4])%8],t[(a[5])%8]);
             printf("  2000000┃%s%s%s%s%s┃2000000\n",t[(a[1]+1)%8],t[(a[2]+1)%8],t[(a[3]+1)%8],t[(a[4]+1)%8],t[(a[5]+1)%8]);
             printf("  1000000┃%s%s%s%s%s┃1000000\n",t[(a[1]+2)%8],t[(a[2]+2)%8],t[(a[3]+2)%8],t[(a[4]+2)%8],t[(a[5]+2)%8]);
             printf("         ┗━━━━━┛\n");
             printf("╚════ 按空格停止 ════╝\n");
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
    if((a[1]-2)%8==(a[2]-1)%8&&(a[2]-1)%8==a[3]%8&&a[3]%8==(a[4]+1)%8&&(a[4]+1)%8==(a[5]+2)%8){have+=10000;printf("恭喜你获得了100000元\n");}
    else if((a[1]-1)%8==(a[2]-1)%8&&(a[2]-1)%8==a[3]%8&&a[3]%8==(a[4]+1)%8&&(a[4]+1)%8==(a[5]+1)%8){have+=20000;printf("恭喜你获得了200000元\n");}
    else if(a[1]%8==a[2]%8&&a[2]%8==a[3]%8&&a[3]%8==a[4]%8&&a[4]%8==a[5]%8){have+=50000;printf("恭喜你获得了500000元\n");}
    else if((a[5]-1)%8==(a[4]-1)%8&&(a[4]-1)%8==a[3]%8&&a[3]%8==(a[2]+1)%8&&(a[2]+1)%8==(a[1]+1)%8){have+=20000;printf("恭喜你获得了200000元\n");}
    else if((a[5]-2)%8==(a[4]-1)%8&&(a[4]-1)%8==a[3]%8&&a[3]%8==(a[2]+1)%8&&(a[2]+1)%8==(a[1]+2)%8){have+=10000;printf("恭喜你获得了100000元\n");}
    else printf("失败！\n");
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
system("title 赌城 ZDC制作");
printf("                    |>>>          你还有资本：%9d \n",have);
printf("                    |                                 \n");
printf("      |>>>      _  _|_  _         |>>>                \n");
printf("      |        |;| |;| |;|        |     ╔━━━━━━╗\n");
printf("  _  _|_  _    \\\\.    .  /    _  _|_  _ ┃壹  玩梭哈  ┃\n");
printf(" |;|_|;|_|;|    \\\\: +   /    |;|_|;|_|;|┃贰  玩21点  ┃\n");
printf(" \\\\..      /    ||:+++. |    \\\\.    .  /┃叁  玩老虎机┃\n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\:  .  / ┃肆  游戏帮助┃\n");
printf("   ||:+  |_   _ ||_ . _ | _   _||:+  |  ┃伍  去银行  ┃\n");
printf("   ||+++.|||_|;|_|;|_|;|_|;|_|;||+++ |  ┃陆  关于    ┃\n");
printf("   ||+++ ||.    .     .      . ||+++.|  ┃柒  风格设置┃\n");
printf("   ||:   ||:  ,     +       .  ||: , |  ┃捌  离开游戏┃\n");
printf("   ||:   ||:.     +++++      . ||:   |  ╚━━━━━━╝\n");
printf("   ||:   ||.     +++++++  .    ||: . |                  \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                  \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                  \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("请选择(1/2/3/4/5/6/7/8)？");
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
system("title 赌城-帮助 ZDC制作");
system("mode con: cols=57 lines=47");
printf("~~~~梭哈帮助~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("  梭哈一款经久不衰的赌场游戏，从8副牌中取出8~A这几张牌，\n");
printf("给庄家和挑战者各发五张牌由着五张牌的牌型大小决胜负。    \n");
printf("                                                        \n");
printf("  牌型大小顺序为                                        \n");
printf("  同花顺＞铁支＞葫芦＞同花＞顺子＞三条＞二对＞对子＞散牌\n");
printf("                                                        \n");
printf("  如果牌型大小一样就比第一张牌的大小花色，如还一样就是平\n");
printf("局！                                                    \n");
printf("  具体牌型：                                            \n");
printf("    同花顺：A,A+1,A+2,A+3,A+4 且花色一样                \n");
printf("    铁支：AAAAB          葫芦：AAABB                    \n");
printf("    同花：花色一样       顺子：A,A+1,A+2,A+3,A+4        \n");
printf("    三条：AAABC          二对：AABBC                    \n");
printf("    对子：AABCD          散牌：ABCDE                    \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
printf("~~~~21点游戏帮助~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
printf("  21点也是一款十分有意思的游戏，玩家和庄家每人轮流叫牌。\n"); 
printf("看谁的最后的牌点最接近21点但不高于21点。                \n"); 
printf("                                                        \n"); 
printf("  具体点数：                                            \n"); 
printf("    A算1点                                              \n"); 
printf("    2~10算他们自身的点数                                \n"); 
printf("    J~K都算10点                                         \n"); 
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
printf("~~~~老虎机帮助~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
printf("  十分简单按空格是让老虎机停转，当出现特别的符号即可获得\n"); 
printf("高额奖励！                                              \n"); 
printf("                                                        \n"); 
printf("  具体符号：                                            \n"); 
printf("     -----      ----- -----        *---- ----*          \n"); 
printf("     -----      *---- ----*        -*--- ---*-          \n"); 
printf("     *****      -***- -***-        --*-- --*--          \n"); 
printf("     -----      ----* *----        ---*- -*---          \n"); 
printf("     -----      ----- -----        ----* *----          \n"); 
printf("    5000000       2000000            1000000            \n"); 
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
printf("~~~~银行系统帮助~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
printf("  没有什么好说的别说你连贷款还款都不会！在这解释下信用度\n"); 
printf("没贷款一回合就会增加1点信用度，信用度大于100时将无法贷款\n"); 
printf("  还有利息是一回合利息10%   利滚利哦 ^o^                \n"); 
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
system("pause");
}
/******************************************************************************/
void fengg()
{
int c; 
system("cls");
system("mode con: cols=57 lines=20");
system("title 赌城-风格 ZDC制作");
printf("                    |>>>          你还有资本：%9d \n",have);
printf("                    |                                 \n");
printf("      |>>>      _  _|_  _         |>>>                \n");
printf("      |        |;| |;| |;|        |     ╔━━━━━━╗\n");
printf("  _  _|_  _    \\\\.    .  /    _  _|_  _ ┃壹  标准    ┃\n");
printf(" |;|_|;|_|;|    \\\\: +   /    |;|_|;|_|;|┃贰  雪地    ┃\n");
printf(" \\\\..      /    ||:+++. |    \\\\.    .  /┃叁  草地    ┃\n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\:  .  / ┃肆  天空    ┃\n");
printf("   ||:+  |_   _ ||_ . _ | _   _||:+  |  ┃伍  黄金城  ┃\n");
printf("   ||+++.|||_|;|_|;|_|;|_|;|_|;||+++ |  ┃陆  赤日    ┃\n");
printf("   ||+++ ||.    .     .      . ||+++.|  ┃柒  记事本  ┃\n");
printf("   ||:   ||:  ,     +       .  ||: , |  ╚━━━━━━╝\n");
printf("   ||:   ||:.     +++++      . ||:   |                  \n");
printf("   ||:   ||.     +++++++  .    ||: . |                  \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                  \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                  \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("请选择(1/2/3/4/5)........."); 
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
system("title 赌城-关于 ZDC制作");
printf("                    |>>>                              \n");
printf("                    |                                 \n");
printf("      |>>>      _  _|_  _       赌城游戏              \n");
printf("      |        |;| |;| |;|      版本号V4.001          \n");
printf("  _  _|_  _    \\\\.    .  /    _ 程序核心编写者：ZDC   \n");
printf(" |;|_|;|_|;|    \\\\+     /    |;|图像美化效果：ZDC     \n");
printf(" \\\\..      /    ||:+++. |    \\\\.    .  /              \n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\游戏中的梭哈，21点，  \n");
printf("   ||:+  |_   _ ||_ . _ | _   _|老虎机，发明权不归本人\n");
printf("   ||+++.|||_|;|_|;|_|;|_|;|_|;|如有沉迷本人概不负责！\n");
printf("   ||+++ ||.    .     .      . ||+++.|                \n");
printf("   ||:   ||:  ,     +       .  ||: , |     2008年8月  \n");
printf("   ||:   ||:.     +++++      . ||:   |                \n");
printf("   ||:   ||.     +++++++  .    ||: . |  版权所有，    \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |       翻版必揪 \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
system("pause");
}
/******************************************************************************/
void end()
{system("cls");
system("mode con: cols=55 lines=18");
system("title 赌城-结束 ZDC制作");
printf("                    |>>>                              \n");
printf("                    |                                 \n");
printf("      |>>>     健康游戏公告       |>>>                \n");
printf("      |  抵制不良游戏 拒绝盗版游戏                    \n");
printf("  _  _|_ 注意自我保护 谨防受骗上当 _  _               \n");
printf(" |;|_|;| 适度游戏益脑 沉迷游戏伤身 |_|;|              \n");
printf(" \\\\..    合理安排时间 享受健康生活  .  /              \n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\:  .  /               \n");
printf("   ||:+  |_   _ ||_ . 赌博有害身心健康                \n");
printf("   ||+++.|||_|;|_|;|_|请不要千万真实的赌场否则有去无回\n");
printf("   ||+++ ||.    .     .      . ||+++.|                \n");
printf("   ||:   ||:  ,     +       .  ||: , |游戏编写者：    \n");
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
if(ccc==1){system("mode con: cols=55 lines=22");printf("你没钱了！请贷款！\n");}
system("title 赌城-银行 ZDC制作");
printf("                    |>>>        你还有资本：%9d \n",have);
printf("                    |           你欠银行：  %9d \n",bank_have);
printf("      |>>>      _  _|_  _       你的信用度：      %3d \n",bank_h);
printf("      |        |;| |;| |;|        |     ╔━━━━━╗\n");
printf("  _  _|_  _    \\\\.    .  /    _  _|_  _ ┃壹  贷款  ┃\n");
printf(" |;|_|;|_|;|    \\\\: +   /    |;|_|;|_|;|┃贰  还款  ┃\n");
printf(" \\\\..      /    ||:+++. |    \\\\.    .  /┃叁  离开  ┃\n");
printf("  \\\\.  ,  /     ||:+++  |     \\\\:  .  / ╚━━━━━╝\n");
printf("   ||:+  |_   _ ||_ . _ | _   _||:+  |                \n");
printf("   ||+++.|||_|;|_|;|_|;|_|;|_|;||+++ |                \n");
printf("   ||+++ ||.    .     .      . ||+++.|                \n");
printf("   ||:   ||:  ,     +       .  ||: , |                \n");
printf("   ||:   ||:.     +++++      . ||:   |                \n");
printf("   ||:   ||.     +++++++  .    ||: . |                \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                \n");
printf("   ||: . ||: ,   +++++++ .  .  ||:   |                \n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("请选择(1/2/3)？");scanf("%d",&cc);
if(cc==1){if(bank_h>=100){printf("就你这个信用度还来贷款？滚出去！");system("pause");return;}
          printf("请输入贷款金额：");scanf("%d",&cc);
          if(cc>0){bank_have+=cc;have+=cc;printf("成功贷款%d元！\n",cc);system("pause");return;} 
         } 
if(cc==2){printf("请输入还款金额：");scanf("%d",&cc);
          if(cc>0){bank_have-=cc;have-=cc;printf("成功还款%d元！\n",cc);system("pause");return;}
         } 
if(cc==3){return;
         } 
}
/******************************************************************************/
void over()
{system("cls");
system("mode con: cols=79 lines=7");
system("title 赌城-结束 ZDC制作");
printf("*******  *******  *       *  *******      *******  *       *  *******  ******\n");
printf("*        *     *  **     **  *            *     *   *     *   *        *     *\n");
printf("*  ****  *******  * *   * *  *******      *     *    *   *    *******  ******\n");
printf("*     *  *     *  *  * *  *  *            *     *     * *     *        *  *\n");
printf("*******  *     *  *   *   *  *******      *******      *      *******  *    *\n");
printf("您输光了家底，背着负债，扛着不良记录，被赶了出来！以后没运气别来！！！\n");
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
