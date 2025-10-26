#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ai( int *p,int z)
{
    srand(time(0));
    int i,j,t1,t2,k=0,stop=0,s=0,s1=0,s2=0;
    int rand1[4]= {1,3,7,9};
    int rand2[2];
    int randindx=rand()%4;
    int randnum=rand1[randindx];
    for (t1=1,t2=0; t2<2 ; t1--,t2++)
    {
        for (i=0; i<7; i+=3)
        {
            if (*(p+i)+*(p+i+1)+*(p+i+2)==(z*2+2)*t1+(4-z*2)*t2)
            {
                stop=0;
                for (j=0; j<3; j++)
                {
                    if (*(p+i+j)==0)
                    {
                      stop++;
                      s1=i;
                      s2=j;
                    }

                }
                if (stop==1)
                return s1+s2+1;
            }
        }
        for (i=0; i<3; i++)
        {
            if (*(p+i)+*(p+i+3)+*(p+i+6)==(z*2+2)*t1+(4-z*2)*t2)
            {
                stop=0;
                for (j=0; j<7; j+=3)
                {
                    if (*(p+i+j)==0)
                    {
                     stop++;
                     s1=i;
                     s2=j;
                    }

                }
                if (stop==1)
                return s1+s2+1;
            }
        }
        if (*p+*(p+4)+*(p+8)==(z*2+2)*t1+(4-z*2)*t2)
        {
            stop=0;
            for (i=0; i<9; i+=4)
            {
                if (*(p+i)==0)
                {
                 stop++;
                 s=i;
                }

            }
            if(stop==1)
            return s+1;
        }
        if (*(p+2)+*(p+4)+*(p+6)==(z*2+2)*t1+(4-z*2)*t2)
        {
            for (i=0 ; i<5; i+=2)
            {
                if (*(p+i+2)==0)
                {
                 stop++;
                 s=i;
                }

            }
            if(stop==1)
            return s+3 ;
        }
    }
    if (*(p+4)==0)
        return 5;
    else
    {
        if (*p+*(p+2)+*(p+6)+*(p+8)==0)
            return randnum;
        else if (*p+*(p+2)+*(p+6)+*(p+8)==2-z)
        {
            if (*p)
                return 9;
            if (*(p+2))
                return 7;
            if (*(p+6))
                return 3;
            if (*(p+8))
                return 1;
        }
        else if(*p+*(p+2)+*(p+6)+*(p+8)>=2)
        {
            if (*p==0)
            {
                rand2[k]=1;
                k++;
            }
            if (*(p+2)==0)
            {
                rand2[k]=3;
                k++;
            }
            if (*(p+6)==0)
            {
                rand2[k]=7;
                k++;
            }
            if (*(p+8)==0)
            {
                rand2[k]=9;
                k++;
            }
            if (k==2)
            {
            randindx=rand()%2;
            randnum=rand2[randindx];
            return randnum;
            }
        }
        else
        {
            if (*(p+1)==0)
            {
                rand2[k]=2;
                k++;
            }
            if (*(p+3)==0)
            {
                rand2[k]=4;
                k++;
            }
            if (*(p+5)==0)
            {
                rand2[k]=6;
                k++;
            }
            if (*(p+7)==0)
            {
                rand2[k]=8;
                k++;
            }
            randindx=rand()%2;
            randnum=rand2[randindx];
            return randnum;
        }
    }
    for (i=0;i<9;i++)
    if (*(p+i)==0)
    return i+1;
    return 0;
}

int main()
{
    while(1)
    {
        int i,j,k,x,y,z,f,n,a=1,w=0,s=0,t=1,num=0,again=0,where[9]={0},whowin[3][3]={0};
        int i1[9]={0,0,0,3,3,3,7,7,7};
        int i2[9]={3,3,3,7,7,7,11,11,11};
        int j1[9]={0,5,11,0,5,11,0,5,11};
        int j2[9]={5,11,17,5,11,17,5,11,17};
        printf("choose 'x'==>1 or 'o'==>0\n");
        scanf("%i",&z);
        k=z;
        while (num<10)
        {
            t=1;
            for (i=0; i<11; i++)
            {
                y=0;
                for (j=0; j<17; j++)
                {
                    if (t==4)
                    {
                        if (j%2==0)
                            printf(".");
                        else
                            printf(" ");

                    }
                    else
                    {
                        if (y==5)
                        {
                            printf(".");
                            y-=5;
                        }
                        else
                        {
                            if (where[0] || where[x])
                            {
                                for (x=0; x<9; x++)
                                {
                                    if (where[x]==0)
                                        break;
                                    s=where[x];
                                    if ( i2[s-1]>=i && i>=i1[s-1] && j2[s-1]>=j && j>=j1[s-1] )
                                    {
                                        if ((x+z)%2==1 && num!=0)
                                        {
                                            if (i%2==0)
                                            {
                                                if (j%2==0)
                                                    printf(" ");
                                                else
                                                    printf("*");
                                            }
                                            else
                                            {
                                                if (j==2 || j==8 || j==14)
                                                    printf("*");
                                                else
                                                    printf(" ");
                                            }
                                        }
                                        else if ((x+z)%2==0 && num!=0)
                                        {
                                            if (i%2==0)
                                            {
                                                if (j==0 || j==4 || j==6 || j==10 || j==12 || j==16)
                                                {
                                                    printf(" ");
                                                }
                                                else
                                                    printf("*");
                                            }
                                            else
                                            {
                                                if (j%2==0)
                                                    printf(" ");
                                                else
                                                    printf("*");
                                            }
                                        }
                                        y++;
                                        break;
                                    }
                                }
                            }
                            if (where[x]==0)
                            {
                                if (i==1 && j==2)
                                    printf("1");
                                else if (i==1 && j==8)
                                    printf("2");
                                else if (i==1 && j==14)
                                    printf("3");
                                else if (i==5 && j==2)
                                    printf("4");
                                else if (i==5 && j==8)
                                    printf("5");
                                else if (i==5 && j==14)
                                    printf("6");
                                else if (i==9 && j==2)
                                    printf("7");
                                else if (i==9 && j==8)
                                    printf("8");
                                else if (i==9 && j==14)
                                    printf("9");
                                else
                                    printf(" ");
                                y++;
                            }
                        }
                    }
                }
                if (t==4)
                    t=0;
                t++;
                printf("\n");
            }
            if (num>=5)
            {
                for (i=0; i<3; i++)
                {
                    if (whowin[0][i]==whowin[1][i] &&  whowin[1][i]==whowin[2][i])
                        w=whowin[0][i];
                    if (whowin[i][0]==whowin[i][1] &&  whowin[i][1]==whowin[i][2])
                        w=whowin[i][0];
                }
                if (whowin[0][0]==whowin[1][1] && whowin[1][1]==whowin[2][2] )
                    w=whowin[0][0];
                if (whowin[0][2]==whowin[1][1] && whowin[1][1]==whowin[2][0] )
                    w=whowin[0][2];
            }
            if (w!=0)
                break;
            if (num==9)
                break;
            if (a)
            {
                printf("\nwhere you want\n");
                scanf("%i",&where[num]);
                a--;
            }
            else
            {
                printf("bot choosed\n");
                where[num]=ai(&whowin[0][0],z);
                printf("%i\n",where[num]);
                a++;
            }
            n=1,f=0;
            if (k)
            {
                for (i=0; i<3; i++)
                {
                    for (j=0; j<3; j++)
                    {
                        if (where[num]==n)
                        {
                            whowin[i][j]=1;
                            f++;
                            k--;
                            break;
                        }
                        n++;
                    }
                    if (f>0)
                        break;
                }
            }
            else
            {
                for (i=0; i<3; i++)
                {
                    for (j=0; j<3; j++)
                    {
                        if (where[num]==n)
                        {
                            whowin[i][j]=2;
                            f++;
                            k++;
                            break;
                        }
                        n++;
                    }
                    if (f>0)
                        break;
                }
            }
            num++;
        }
        if (w==1)
        {
            printf("x is Winner");
            break;
        }
        else if (w==2)
        {
            printf("o is winner");
            break;
        }
        else
        {
            printf("draw\n");
            printf("do you want again?\n");
            printf("yes==>1 no==>0\n");
            scanf("%i",&again);
            if (again)
                printf("let's begin\n");
            else
                break;
        }
    }
    return 0;
}
