#include <stdio.h>
#include <ctype.h>

void jerseyPrompt(int i){
    printf("Enter player %d's jersey number:\n", i);
}
void ratingPrompt(int i){
    printf("Enter player %d's rating:\n", i);
}
void printRoster(int jerseyNums[], int ratingNums[]){
    printf("ROSTER\n");
        for(int i = 0; i < 5; i++){
            printf("Player %d -- Jersey number: %d, Rating: %d\n", (i+1), jerseyNums[i], ratingNums[i]);
        }
}
char menu(){
    printf("\nMENU\n");
    printf("u - Update player rating\n");
    printf("r - Replace player\n");
    printf("o - Output roster\n");
    printf("q - Quit\n");
    printf("Choose an option:\n");
    char option;
    scanf(" %c",&option);
    return option;
}
int find_jerseyNums(int jerseyNums[],int number){
    for(int i=0;i<5;i++)
        if(jerseyNums[i]==number)
            return i;
    return -1;
}
void input(int *jerseyNums,int *ratingNums){
    for(int i=0;i<5;i++){
        jerseyPrompt(i+1);
        scanf("%d",&jerseyNums[i]);
            while(jerseyNums[i]<1||jerseyNums[i]>99){
                printf("Invalid jersey number. ");
                jerseyPrompt(i+1);
                scanf("%d",&jerseyNums[i]);
            }
                ratingPrompt(i+1);
                scanf("%d",&ratingNums[i]);
            while(ratingNums[i]<1||ratingNums[i]>10){
                printf("Invalid player rating. ");
                ratingPrompt(i+1);
                scanf("%d",&ratingNums[i]);
            }
    printf("\n");
    }
}
int jerseyInput(int jerseyNums[],int check){
    int number,i;
    if(check==0){
        printf("\nEnter jersey number for rating update:\n");
    }
    else{
        printf("\nEnter jersey number to replace:\n");
    }
    scanf("%d",&number);

    i=find_jerseyNums(jerseyNums,number);

    while(i==-1){
        printf("Invalid jersey number. Enter valid jersey number:\n");
        scanf("%d",&number);
        i=find_jerseyNums(jerseyNums,number);
    }
    return i;
}
void update(int *jerseyNums,int *ratingNums){
    int number,rate,i;
    i=jerseyInput(jerseyNums,0);

    printf("Found jersey number. Enter new rating for player:\n");
    scanf("%d",&rate);

    while(rate<1||rate>10){
        printf("Invalid player rating. Enter valid rating:\n");
        scanf("%d",&rate);
    }

    ratingNums[i]=rate;
}
void replace(int *jerseyNums,int *ratingNums){
    int number,rate,jersey,i;
    i=jerseyInput(jerseyNums,1);

    printf("Found jersey number. Enter new jersey number:\n");
    scanf("%d",&jersey);

    while(jersey<1||jersey>99){
        printf("Invalid jersey number. Enter valid jersey number:\n");
        scanf("%d",&jersey);
    }

    printf("Enter player rating:\n");
    scanf("%d",&rate);

    while(rate<1||rate>10){
        printf("Invalid player rating. Enter valid rating:\n");
        scanf("%d",&rate);
    }

    jerseyNums[i]=jersey;
    ratingNums[i]=rate;
}

const int NUM_PLAYERS = 5;

int main()
{

    int jerseyNums[5];
    int ratingNums[5];
    input(jerseyNums,ratingNums);
    printRoster(jerseyNums,ratingNums);
    char option;

    do{
        option=menu();
        switch(option){
    case 'u':
        update(jerseyNums,ratingNums);
        break;
    case 'r':
        replace(jerseyNums,ratingNums);
        break;
    case 'o':
        printRoster(jerseyNums,ratingNums);
        break;
    case 'q':
        break;
    default:
        printf("Invalid option\n");
        break;
    }
    }while(option!='q');
    return 0;
    }
