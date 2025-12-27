#include<iostream>
#include<ctime>
void drawboard(char * speces);
void playermove(char * speces,char player);
void computermove(char * speces, char computer);
bool checkwinner(char * speces, char player ,char computer);
bool checktie(char * speces);
int main(){
    char speces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer='O';
    bool running = true;
    drawboard(speces);
    while(running){
        playermove(speces,player);
        drawboard(speces);
        if(checkwinner(speces,player,computer)){
            running=false;
            break;
            }
        else if (checktie(speces)){
            running=false;
            break;
        }
        
        computermove(speces,computer);
        drawboard(speces);
        if(checkwinner(speces,player,computer)){
            running=false;
            break;
            }
        else if (checktie(speces)){
            running=false;
            break;
        }
        
    }
    return 0;
}
void drawboard(char * speces){
    std::cout<<"\n";
    std ::cout <<speces[0]<<"  | "<<speces[1]<<" | "<<speces[2]<<'\n';
    std ::cout <<"-----------"<<'\n';
    std ::cout <<speces[3]<<"  | "<<speces[4]<<" | "<<speces[5]<<'\n';
    std ::cout <<"-----------"<<'\n';
    std ::cout <<speces[6]<<"  | "<<speces[7]<<" | "<<speces[8]<<'\n';
    std::cout<<"\n";
}
void playermove(char * speces,char player){
    int num;
    do{
    std :: cout<<"\n Enter where you like to play(1-9): ";
    std::cin>>num;
    num--;
    if(speces[num]==' '){
        speces[num]=player;
        break;
        } 
    else{
        std::cout<<"\n sport have bin taken :";
    }
    }while(!num>0 || !num < 8);
}
void computermove(char * speces, char computer){
    int num;
    srand(time(0));
    num=(rand()%9 )+1;
    do{
    
    num--;
    if(speces[num]==' '){
        speces[num]=computer;
        break;
        } 
    else{
        num=(rand()%9 )+1;
    }
    }while(!num>0 || !num < 8);

}
bool checkwinner(char * speces, char player ,char computer){
    if (speces[0]!=' ' && speces[0]==speces[1] && speces[1]==speces[2])
    player==speces[0] ? std::cout<<"you won \n" : std::cout<<"you lose\n";
    else if (speces[3]!=' ' && speces[3]==speces[4] && speces[4]==speces[5])
    player==speces[3] ? std::cout<<"you won \n" : std::cout<<"you lose\n";
    else if (speces[6]!=' ' && speces[6]==speces[7] && speces[7]==speces[8])
    player==speces[6] ? std::cout<<"you won \n" : std::cout<<"you lose\n";
    else if (speces[0]!=' ' && speces[0]==speces[3] && speces[3]==speces[7])
    player==speces[0] ? std::cout<<"you won \n" : std::cout<<"you lose\n";
    else if (speces[1]!=' ' && speces[1]==speces[4] && speces[4]==speces[8])
    player==speces[1] ? std::cout<<"you won \n" : std::cout<<"you lose\n";
    else if (speces[2]!=' ' && speces[2]==speces[5] && speces[5]==speces[8])
    player==speces[2] ? std::cout<<"you won \n" : std::cout<<"you lose\n";
    else if (speces[0]!=' ' && speces[0]==speces[4] && speces[4]==speces[8])
    player==speces[0] ? std::cout<<"you won \n" : std::cout<<"you lose\n";
    else if (speces[2]!=' ' && speces[2]==speces[4] && speces[4]==speces[6])
    player==speces[2] ? std::cout<<"you won \n" : std::cout<<"you lose\n";
    else {
        return false;
    }
    return true;    
}
bool checktie(char * speces){
    for(int i=0;i<9;i++){
        if (speces[i]==' '){
            return false;
            break;
        }
    }
    std::cout<<"its a tie";
    return true;
}