#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
char number[9]={'1','2','3','4','5','6','7','8','9'};
void  print_pattern(char);
int play_game_computer();
int play_game_player();
int play_game_evil();
int evil_move();
int check_win();
void rand_number();
void computer_move();
void main()
{
    char ch;
    int result;
    char replay;
    r:
        system("cls");
    printf("\n enter your choice -> ");
    printf("\n1. Want to play with smart computer ");
    printf("\n2. Want to play with Evil computer ");
    printf("\n3. Want to play with player ");
    printf("\n4. Exit\n");
    fflush(stdin);
    ch=getch();
   system("cls");
    switch(ch)
    {
    case '1':
        print_pattern(ch);
        result=play_game_computer();
        if(result==1)
            printf("\n PLAYER 1 WON");
        else if(result==2)
            printf("\n COMPUTER WON ");
        else
                printf("\n TIE BETWEEN TWO PLAYERS .......");
        break;
    case '2':
         print_pattern(ch);
         result=play_game_evil();
         if(result==1)
            printf("\n PLAYER 1 WON");
        else if(result==2)
            printf("\n COMPUTER WON ");
        else
                printf("\n TIE BETWEEN TWO PLAYERS .......");
        break;
    case '3':
        print_pattern(ch);
        result=play_game_player();
        if(result==1)
            printf("\n PLAYER 1 WON");
        else if(result==2)
            printf("\n PLAYER 2 WON");
        else
                printf("\n TIE BETWEEN TWO PLAYERS .......");
        break;
    case '4':
        exit(0);
        break;
    default:
        printf("\n invalid choice ");
    }
    printf("\n if you want to play game again then enter \'y\'  other wise press any key :  ");
    fflush(stdin);
    replay=getch();
    if(replay=='y' || replay=='Y') // if player want to play game again then refresh array and position
    {
        number[0]='1';
        number[1]='2';
        number[2]='3';
        number[3]='4';
        number[4]='5';
        number[5]='6';
        number[6]='7';
        number[7]='8';
        number[8]='9';
        goto r;
    }
    else
        exit(0);
}
void print_pattern(char c) // for printing pattern
{
    printf("\n\t##################   Tic-Tac-Toe   #######################\n\n");
    if(c=='3') // for two players
    {
        printf("\n\tFIRST PLAYER  x");
        printf("\n\tSECOND PLAYER  0");
    }
    else{  // for player and computer
         printf("\n\tYOU ARE FIRST PLAYER  x");
        printf("\n\tCOMPUTER IS SECOND PLAYER  0");
    }

    //printing pattern like tic-tac-toe
    printf("\n");
    printf("\n\t       |       |      ");
    printf("\n\t   %c   |   %c   |   %c  ",number[0],number[1],number[2]);
    printf("\n\t_______|_______|_______");
    printf("\n\t       |       |      ");
    printf("\n\t   %c   |   %c   |   %c  ",number[3],number[4],number[5]);
    printf("\n\t_______|_______|_______");
    printf("\n\t       |       |      ");
    printf("\n\t   %c   |   %c   |   %c  ",number[6],number[7],number[8]);
    printf("\n\t_______|_______|_______");
    printf("\n\t");
    printf("\n\n\t");
    printf("###########################################################\n\n");
}
int play_game_player()
{
    char player='x';
    int  j=0;
    int ch;
    int result=0;
    while(1)
    {

        if(j%2==0)
        {
             printf("\n player 1, enter marking place -> ");
             scanf("%d",&ch);
             while(number[ch-1]=='x' || number[ch-1]=='0')
            {
                system("cls");
                print_pattern('3');
                printf("\n player 1, enter marking place -> ");
                scanf("%d",&ch);
            }
            system("cls");
            number[ch-1]='x';
            print_pattern('3');
        }

        else{
             printf("\n player 2, enter marking place -> ");
             scanf("%d",&ch);
            while(number[ch-1]=='x' || number[ch-1]=='0')
            {
                system("cls");
                print_pattern('3');
                printf("\n player 2, enter marking place -> ");
                scanf("%d",&ch);
            }
            system("cls");
            number[ch-1]='0';
            print_pattern('3');
        }

        if(j>=4)
        {
            result=check_win();
                if(result!=0)
                      return result;
        }
        if(j==8)
        {
             if(result==0)
                return -1;

        }

         j++;
    }
    return 0;
}
int play_game_computer()
{
     int result=0;
    int j=0,ch;
    int pre=0,current=0;
     int see=1;
    while(1)
    {
        if(j%2==0)  //  this is for player 1 which is user
        {
            printf("\n player 1, enter marking place -> ");
             scanf("%d",&ch);
             pre=current;
             current=ch;
             while(number[ch-1]=='x' || number[ch-1]=='0')
            {
                system("cls");
                print_pattern('1');
                printf("\n player 1, enter marking place -> ");
                scanf("%d",&ch);
            }
            system("cls");
            number[ch-1]='x';
            print_pattern('1');
        }
        else{   // for computer

                   if(j==1)
                   {
                        if(ch==3 || ch==6 || ch==9)
                            number[ch-2]='0';
                         else
                             number[ch]='0';
                         system("cls");
                         print_pattern('1');
                   }
                   else{
                         computer_move();
                         system("cls");
                         print_pattern('1');
                   }
        }
        if(j>=4)   // after 4 moves evey time it check condition
        {
            result=check_win();
                      if(result!=0)
                      {
                          return result;
                      }
        }
        if(number[0]!='1' && number[1]!='2' && number[2]!='3' && number[3]!='4' && number[4]!='5' && number[5]!='6' && number[6]!='6' && number[7]!='8' && number[8]!='9')
            return -1;

       /* if(j==8) // check tie between two players
        {
            if(result==0)
                 return -1;
        } */
        j++;
    }
    return 0;
}
void computer_move()
{
       if(number[0]==number[3]  || number[2]==number[4] || number[7]==number[8])
    {
        if(number[6]!='0' && number[6]!='x')
        {
            number[6]='0';
            return ;
        }
    }

    if(number[1]==number[4] || number[6]==number[8])
    {
        if(number[7]!='0' && number[7]!='x')
        {
             number[7]='0';
             return ;
        }

    }

    if(number[2]==number[5] || number[0]==number[4]|| number[6]==number[7])
    {
         if(number[8]!='0' && number[8]!='x')
         {
              number[8]='0';
              return ;
         }

    }

    if(number[6]==number[3] || number[8]==number[4] || number[1]==number[2])
       {
           if(number[0]!='0' && number[0]!='x')
           {
                number[0]='0';
                return ;
           }

       }

    if(number[7]==number[4]|| number[0]==number[2])
        {
            if(number[1]!='0' && number[1]!='x')
            {
                number[1]='0';
                return ;
            }

        }

    if(number[8]==number[5]|| number[0]==number[1] || number[6]==number[4])
    {
        if(number[2]!='0' && number[2]!='x')
        {
             number[2]='0';
             return ;
        }
    }

    if(number[0]==number[6] || number[5]==number[4])
    {
        if(number[3]!='0' && number[3]!='x')
        {
             number[3]='0';
             return ;
        }

    }

    if(number[1]==number[7] || number[0]==number[8]|| number[2]==number[6] || number[3]==number[5])
    {
        if(number[4]!='0' && number[4]!='x')
        {
            number[4]='0';
            return ;
        }
    }

    if(number[2]==number[8] || number[3]==number[4])
    {
        if(number[5]!='0' && number[5]!='x')
        {
             number[5]='0';
             return ;
        }
    }
    if(1)
    {
        rand_number();
    }
}
void rand_number(void)
{
   srand(time(NULL));
    int n;
    do{
        n=rand()%9;
    }while(number[n]=='0' || number[n]=='x');
    number[n]='0';
}
int play_game_evil()
{

     int result=0;
    int j=0,ch;
     int see=1;
     int rem=0;
    while(1)
    {
        if(j%2==0)  //  this is for player 1 which is user
        {
            printf("\n player 1, enter marking place -> ");
             scanf("%d",&ch);
             while(number[ch-1]=='x' || number[ch-1]=='0')
            {
                system("cls");
                print_pattern('1');
                printf("\n player 1, enter marking place -> ");
                scanf("%d",&ch);
            }
            system("cls");
            number[ch-1]='x';
            print_pattern('1');
             result=check_win();
                       if(result!=0)
                                 return result;
        }
        else{   // for computer

                   if(j==1) // for first case for computer
                   {
                        if(ch==3 || ch==6 || ch==9)
                            number[ch-2]='0';
                         else
                             number[ch]='0';
                         system("cls");
                         print_pattern('1');
                   }
                   else{
                        if(number[4]=='x')
                                  rem=evil_move();
                        if(rem!=1)
                                 computer_move();
                        system("cls");
                        print_pattern('1');// print pattern
                        result=check_win(); //check winning condition
                       if(result!=0)
                                 return result;
                   }
        }
        j++;
    }
    return 0;
}
int evil_move(void)
{
    // where position 5 have 'x' then it put '0' in two or three position
         int flag=0;
        if(number[0]=='x' && number[3]=='x')
        {
            if(number[5]=='6')
            {
                flag=1;
                 number[5]='0';
            }

            if(number[6]=='7')
            {
                flag=1;
                 number[6]='0';
            }

            if(number[8]=='9')
            {
                flag=1;
                number[8]='0';
            }

            return flag;
        }
         if(number[2]=='x' && number[5]=='x')
        {
            if(number[3]=='4')
            {
                flag=1;
                number[3]='0';
            }

            if(number[6]=='7')
            {
                flag=1;
                number[6]='0';
            }

            if(number[8]=='9')
            {
                flag=1;
                number[8]='0';
            }

           return flag;
        }
        if(number[6]=='x' && number[3]=='x')
        {
            if(number[0]=='1')
            {
                flag=1;
                 number[0]='0';
            }

            if(number[2]=='3')
            {
                flag=1;
                number[2]='0';
            }

            if(number[5]=='6')
            {
                flag=1;
                number[5]='0';
            }

            return flag;
        }
    if(number[8]=='x' && number[5]=='x')
        {
            if(number[0]=='1')
            {
                flag=1;
                number[0]='0';
            }

            if(number[2]=='3')
            {
                flag=1;
                 number[2]='0';
            }

            if(number[3]=='6')
            {
                 flag=1;
                 number[3]='0';
            }
            return flag;
        }
       if(number[0]=='x' && number[1]=='x')
        {
             if(number[2]=='3')
             {
                 flag=1;
                 number[2]='0';
             }

            if(number[7]=='8')
            {
                flag=1;
                number[7]='0';
            }

            if(number[8]=='9')
            {
                flag=1;
                 number[8]='0';
            }
            return flag;
        }
    if(number[1]=='x' && number[2]=='x')
        {
             if(number[0]=='1')
             {
                 flag=1;
                  number[0]='0';
             }

            if(number[6]=='7')
            {
                flag=1;
                number[6]='0';
            }

            if(number[7]=='8')
            {
                flag=1;
                number[7]='0';
            }
            return flag;
        }
    if(number[6]=='x' && number[7]=='x')
        {
             if(number[1]=='2')
             {
                 flag=1;
                 number[1]='0';
             }

            if(number[2]=='3')
            {
                flag=1;
                number[2]='0';
            }

            if(number[8]=='9')
            {
                flag=1;
                number[8]='0';
            }
            return flag;
        }
    if(number[7]=='x' &&number[8]=='x')
        {
             if(number[0]=='1')
             {
                 flag=1;
                 number[0]='0';
             }

            if(number[1]=='2')
            {
                flag=1;
                 number[1]='0';
            }

            if(number[6]=='7')
            {
                flag=1;
                number[6]='0';
            }
            return flag;
        }
    if(number[3]=='x' && number[7]=='x')
        {
            if(number[1]=='2')
            {
                flag=1;
                number[1]='0';
            }

            if(number[5]=='6')
            {
                flag=1;
                number[5]='0';
            }
            return flag;
        }
       if(number[7]=='x' && number[5]=='x')
        {
            if(number[1]=='2')
            {
                flag=1;
                number[1]='0';
            }

            if(number[3]=='4')
            {
                flag=1;
                number[3]='0';
            }
          return flag;
        }
     if(number[3]=='x' &&number[1]=='x')
        {
           if(number[5]=='6')
           {
               flag=1;
                number[5]='0';
           }

           if(number[7]=='8')
           {
               flag=1;
               number[7]='0';
           }
           return flag;
        }
      if(number[1]=='x' &&number[5]=='x')
        {
           if(number[3]=='4')
           {
               flag=1;
               number[3]='0';
           }

           if(number[7]=='8')
           {
               flag=1;
               number[7]='0';
           }
           return flag;
        }
       if(number[0]=='x' &&number[6]=='x')
        {
             if(number[2]=='3')
             {
                 flag=1;
                 number[2]='0';
             }
             if(number[3]=='4')
             {
                 flag=1;
                 number[3]='0';
             }
             if(number[8]=='9')
             {
                 flag=1;
                 number[8]='0';
             }
             return flag;
        }
     if(number[2]=='x' &&number[8]=='x')
        {
            if(number[0]=='1')
            {
                 flag=1;
                 number[0]='0';
            }
            if(number[5]=='6')
            {
                flag=1;
                number[5]='0';
            }
            if(number[6]=='7')
            {
                flag=1;
                number[6]='0';
            }
           return flag;

        }
         if(number[6]=='x' && number[8]=='x')
        {
            if(number[0]=='1')
            {
                flag=1;
                number[0]='0';
            }
            if(number[2]=='3')
            {
                flag=1;
                number[2]='0';
            }
            if(number[7]=='8')
            {
                flag=1;
                number[7]='0';
            }
            return flag;
        }
      if(number[0]=='x' && number[2]=='x')
        {
            if(number[1]=='2')
            {
                flag=1;
                number[1]='0';

            }
            if(number[6]=='7')
            {
                flag=1;
                number[6]='0';
            }
            if(number[8]=='9')
            {
                flag=1;
                number[8]='0';
            }
            return flag;
        }
        else
            return 0;
}
int check_win(void)
{
    // for check winning condition
    //if player 1 win then return 1
    //if player 2 win then return 2
    //special case for evil computer where tie return 3
    //tie return 0
    if((number[0]==number[1] && number[1]==number[2]) || (number[0]==number[3] && number[3]==number[6]) || (number[0]==number[4] && number[0]==number[8]))
    {
        if(number[0]=='x')
            return 1;
        else
            return 2;
    }
    else if((number[1]==number[4] && number[1]==number[7]) || (number[3]==number[4] && number[3]==number[5]) || (number[2]==number[4] && number[2]==number[6]))
    {
        if(number[4]=='x')
               return 1;
        else
            return 2;

    }
    else if((number[2]==number[5] && number[2]==number[8]) || (number[6]==number[7] && number[6]==number[8]))
    {
        if(number[8]=='x')
            return 1;
        else
            return 2;
    }
    else if(number[0]!='1' && number[1]!='2' && number[2]!='3' && number[3]!='4' && number[4]!='5' && number[5]!='6' && number[6]!='7' && number[7]!='8' && number[8]!='9')
        return 3;
    else
        return 0;
}

