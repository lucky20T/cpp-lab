#include<iostream>
#include<ctime>
char getuserchoice();
char botchoice();
void showchoice(char choice);
void checkwinner(char player,char bot);
int main(){
    char player;
    char bot;
    player=getuserchoice();
    std::cout<<"your choice";
    showchoice(player);
    bot=botchoice();
    std::cout<<"bot choice";
    showchoice(bot);
    checkwinner(player,bot);

    return 0;
}
char getuserchoice(){
    char player;
    std::cout<<"Rock-Paper-Scissors Game!\n";
    do{
    std::cout<<"r-Rock\n";
    std::cout<<"p-Paper\n";
    std::cout<<"s-Scissors \n";
    std::cout<<"enter your choice\n";
    std::cin>>player;
    }while(player!='r' && player!='p' && player!='s');
    
    return player;
}
char botchoice(){
    srand(time(0));
    int n=rand()%3;
    switch (n)
    {
    case 0:return 'r';
    case 1:return 'p';
    case 2:return 's';
    };
    
};
void showchoice(char choice){
    switch(choice){
        case 'r':std::cout<<"Rock\n";
                break;
        case 'p':std::cout<<"Paper\n";
                break;
        case 's':std::cout<<"Scissors\n";
                break;
    }

}
void checkwinner(char player,char bot){
    switch (player)
    {
    case 'r':if(bot=='p'){
                std::cout<<"You lose!\n";
                }
            else if(bot=='s'){
                std::cout<<"You win!\n";
                }
            else{
                std::cout<<"It's a tie!\n";
                }
        break;
    case 's':if(bot=='r'){
                std::cout<<"You lose!\n";
                }
            else if(bot=='p'){
                std::cout<<"You win!\n";
                }
            else{
                std::cout<<"It's a tie!\n";
                }
        break;
    case 'p':if(bot=='s'){
                std::cout<<"You lose!\n";
                }
            else if(bot=='r'){
                std::cout<<"You win!\n";
                }
            else{
                std::cout<<"It's a tie!\n";
                }
        break;
    
    default:
        break;
    }
}