#include <stdio.h>
#include<stdlib.h>




//FUNCTION DECLARATION

void main_menu();
void name();
void round1();
void r2_selection();
void round2();
void help();
void file();
void reset();
void high_score();

//STRUCTURES
struct player{

 char name[20];  //First round and second round same name
 int score;
 int price;
 }r1,r2;

//GLOBAL VARIABLES

int choice;
int h_choice;
int r2_choice;
int r_choice;


int main(){

main_menu();  //This line declare the 'main' function, which is the entry point of the program

return 0;
}

void main_menu(){
   printf("\n\t\t****************************************\n");
   printf("\n\t\t        WELCOME TO QUIZ GAME 2   \n") ;
   printf("\n\t\t****************************************");
   printf("\n\t\t________________________________________\n");
   printf("\n\t\t > Press 1 to start the game");
   printf("\n\t\t > Press 2 to view the highest score  ");
   printf("\n\t\t > Press 3 to reset score");
   printf("\n\t\t > press 4 for help            ");
   printf("\n\t\t > press 5 to exit             ");
   printf("\n\t\t________________________________________\n\n");

   printf("ENTER YOUR CHOICE : "); //getting choice by user
   scanf("%d",&choice);

   switch(choice){      //checking the option
       case 1:
           round1();
           break;

       case 2:
           high_score();
           break;

       case 3:
           reset();
           break;

       case 4:
           help();
           break;

       case 5:
           printf("\n\tTHANK YOU FOR PARTICIPATING...\n\n");
           break;
       default:
           printf("\n\t\t\tInvalid Section\n\n\n");
           main_menu();

}
}

//Player Name
void name(){

   printf("\n\tENTER YOUR FIRST NAME : ");  //getting a name
   scanf("%s",&r1.name);
   r1.price=0;
   r1.score=0;
   r2.price=0;
   r2.score=0;

}


//Game Round 1
void round1(){

    name();

    printf("\n\n\t*********************************************************\n");
    printf("\n\t\t\t  WELCOME TO 1ST ROUND   \n") ;

   char questions[][100]={"A.What is the commercial capital of Sri Lanka?",
                          "B.What is the name of King Kasyapa's Fortress?",
                          "C.Name the first Executive President of Sri Lanka?",
                          "D.Cricket is the most popular sport in Sri Lanka.Whom did they beat in 1996 to win the World Cup?",
                          "E.Which is the forth planet of our solar system?"};

   char options[][100]={"1.Colombo","2.Ratnapura","3.Jaffna","4.Galle fort",
                        "1.Taj Mahal","2.Lion rock","3.Adam's peak","4.Sithulpawwa",
                        "1.Mahinda rajapaksha","2.Ranasinghe Premadasa","3.D.S. Senanayake","4.J.R. Jayawardhana",
                        "1.Sri lanka","2.England","3.Australia","4.India",
                        "1.Venus","2.Mars","3.Jupiter","4.Earth"};

   int answers[5]={1,2,4,3,2};


   int numberofquestions= sizeof(questions)/sizeof(questions[0]);  //Get the number of items stored in the array


   for(int i=0; i<numberofquestions; i++){    //i = questions
        printf("\n\t*********************************************************\n\n");
        printf("\t%s \n\n",questions[i]);

    for(int j=(4*i); j<(4*i)+4; j++){      //j = options
        printf("\t\t%s\n",options[j]);

    }
    printf("\n\tENTER YOUR CHOICE : ");
    scanf("%d",&choice);                 //assigning user input to choice
    printf("\n");
    if(answers[i] == choice){
        printf("\t\t|YOUR ANSWER IS CORRECT|\n\t\t|YOU WON 100$| \n\n");
        r1.score = r1.score+1;         //adding score
        r1.price = r1.price+100;       //adding price
    }
    else{
        printf("\t\t|YOUR ANSWER IS WRONG|\n\n");
    }
}

   printf("\n\t****************** First round is over ******************\n\n");

   printf("\tPlayer name is = %s\n",r1.name);             //Display player name
   printf("\tFirst round Score = %d\n",r1.score);         //Display player Round 1 score
   printf("\tFirst round cash price = %d$\n",r1.price);   //Display player Round 1 price

   if(r1.score >= 3){
        r2_selection();   //Calling Function r2_selection
   }
  else{
    file();   //Calling Function file
    printf("\n\t------------------------------------------------\n");
    printf("\tYou did not selected for second round\n");
    printf("\t------------------------------------------------\n\n");

    mainmenu:
    printf("\tENTER 6 TO GO MAIN MENU");
    scanf("%d",&choice);
    if(choice==6){
            main_menu();
    }
    else{
        goto mainmenu;
    }
}
}

//Round 2 selection
void r2_selection(){

    int select1;
    printf("\n\t------------------------------------------------\n");
    printf("\tCongratulations You qualified for the next round\n");
    printf("\t------------------------------------------------\n");
    printf("\n\n\tDO YOU LIKE TO PLAY SECOND ROUND?");
    printf("\n\tIF YES PRESS 7\n\tRETURN TO THE MAIN MENU PRESS 6");
    printf("\n\n\tENTER YOUR SELECTION : ");
    scanf("%d",&select1);
    printf("\n");

   retun_selection:
   switch(select1){

       case 6:
           printf("\n\tTHANK YOU FOR PLAYING !\n\n");
           main_menu();
           break;

       case 7:
           round2();
           break;

       default:
          printf("\tENTER VALID SELECTION : ");
          scanf("%d",&select1);
          goto retun_selection;
}
}


//Game Round 2
void round2(){

    printf("\n\t*********************************************************\n");
    printf("\n\t\t\t  WELCOME TO 2ND ROUND   \n") ;

    char questions[][100] ={"A.What is the national game of Bangladesh?",
                            "B.Which one is the longest river in the world?",
                            "C.Which city will host Olympic 2024?",
                            "D.Who was invented World Wide Web (WWW)?",
                            "E.What is the largest island in the world?" };

    char options[][100] = {"1.Cricket","2.Kabaddi","3.Food ball","4.Shooting",
                           "1.Nile","2.Amazon","3.Yangtze","4.Ganga",
                           "1.New York","2.Sydney","3.Beijing","4.Paris",
                           "1.Tim Berners-Lee","2.Bob Kahn","3.Steve Jobs","3.Bill Gates",
                           "1.Iceland","2.Greenland","3.Sri Lanka","4.New Zealand" };


    int answers[5]={2,1,4,1,2};

    int numberofquestions = sizeof(questions)/sizeof(questions[0]);

    for(int i=0; i<numberofquestions; i++){
            printf("\n\t*********************************************************\n\n");
            printf("\t%s \n\n",questions[i]);

           for(int j=(i*4); j<(i*4)+4; j++){
                printf("\t\t%s\n",options[j]);

           }
               printf("\n\tENTER YOUR CHOICE :");
               scanf("%d",&choice);
               printf("\n");
               if(answers[i] == choice){
                    printf("\t\t|YOUR ANSWER IS CORRECT|\n\t\t|YOU WON 100$| \n\n");
                    r2.score = r2.score+1;
                    r2.price = r2.price+100;
                    }
              else{
                    printf("\t\t|YOUR ANSWER IS WRONG|\n\n");
              }
}

    printf("\n\t****************** Second round is over ******************\n\n");

    printf("\tPlayer name is = %s\n",r1.name);
    printf("\tSecond round Score = %d\n",r2.score);
    printf("\tSecond round cash price = %d$\n\n",r2.price);
    printf("\n\t------------------------------------------------\n\n");
    printf("\tCongratulations You have won %d$ in total price\n",r1.price+r2.price);
    if(0<r2.score){
     file();
    }
    printf("\n\t------------------------------------------------\n");
    printf("\n\tENTER 6 TO GO MAIN MENU:");
    return_choice:
    scanf("%d",&r2_choice);
        if(r2_choice == 6){
               main_menu();
        }
        else{
                printf("\tENTER VALID SELECTION : ");
                goto return_choice;
        }

}


//Write data to file
void file() {
    FILE *fp;                         //creating and Write file
    FILE *ph;
    fp=fopen("score.txt", "a");//high score
    ph=fopen("user_details.txt", "a");//save data
    fprintf(fp, " %d \n", r1.score+r2.score);
    fprintf(ph, "%s  %d \n", r1.name, r1.score+r2.score);
    fclose(fp);
    fclose(ph);
}


//High Score
void high_score(){

    FILE *fp;
    int num;
    int max=0;
    fp = fopen("score.txt", "r");

    // Read integers from the file line by line
    while (fscanf(fp, "%d", &num) == 1) {
        // Process the integer here
       if(num>max){
        max=num;
       }

    }
    printf("\n\tHIGHST SCORE ->: %d",max);
    fclose(fp);

    printf("\n\n\tENTER 6 TO GO MAIN MENU\n");
    printf("\n\tENTER YOUR SELECTION : ");
    scanf("%d",&h_choice);

    retun_score:
    switch(h_choice){

       case 6:
           main_menu();
           break;

      default:
          printf("\tENTER VALID SELECTION : ");
          scanf("%d",&h_choice);
          goto retun_score;

}
}


//Reset Score
void reset() {

    printf("\n\tSUCCESSFULLY RESET\n\n");
    FILE *fp;
    FILE *ph;
    fp=fopen("score.txt", "w");    //open file write mode
    ph=fopen("user_details.txt", "w");
    fclose(fp);

    printf("\tENTER 6 TO GO MAIN MENU\n");
    printf("\n\tENTER YOUR SELECTION : ");
    scanf("%d",&r_choice);

    retun_reset:
    switch(r_choice){

       case 6:
           main_menu();
           break;

      default:
          printf("\tENTER VALID SELECTION : ");
          scanf("%d",&r_choice);
          goto retun_reset;
    }
}


//Help
void help(){

     printf("\n\n\t\t ************************* QUIZ GAME HELP *************************\n");
     printf("\n\t\t > There are 2 rounds in this Quiz Game");
     printf("\n\t\t > Player must score 3 or more than 3 to qualified for the second round");
     printf("\n\t\t > You will be given 4 options and you have to press 1, 2 ,3 or 4 for the");
     printf("\n\t\t   right option");
     printf("\n\t\t > Each correct Questions awarded $100 cash price");
     printf("\n\t\t > You will be asked questions continuously.");
     printf("\n\t\t > There is no negative marking for wrong answer");
     printf("\n\n\t\t ************************* ALL THE BEST ***************************\n\n");
     printf("\n\tENTER 1 TO START GAME\n");
     printf("\tENTER 6 TO GO MAIN MENU\n");
     printf("\n\tENTER YOUR SELECTION : ");
     scanf("%d",&h_choice);

     retun_Help:
     switch(h_choice){

       case 1:
           round1();
           break;

       case 6:
           main_menu();
           break;

      default:
          printf("\tENTER VALID SELECTION : ");
          scanf("%d",&h_choice);
          goto retun_Help;
}
}
