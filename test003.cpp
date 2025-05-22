#include<iostream>

int checkbalance(double balance);
double deposit();
double withdraw(double balance);
double balance=0;
int main(){
    
    int choice=0;
    do{
        
        std::cout<<"enter your choice:\n";
        std::cout<<"1:check balance \n";
        std::cout<<"2:to deposit \n";
        std::cout<<"3:to withdraw mony\n ";
        std::cout<<"4:exit";
        std::cin>>choice;
        std::cin.clear();
        
        switch (choice){
            case 1:checkbalance(balance);
                    break;
            case 2:balance+=deposit();
                    
                    checkbalance(balance);
                    break;
            case 3:balance-=(withdraw(balance));
                    checkbalance(balance);
                    break;
            case 4:std::cout<<"Thanks for coming.\n";
                    break;
            default:std::cout<<"Invalid choice\n";
                    break;


        }
    }while( choice !=4);
    
}
int checkbalance(double balance){
    std::cout<<"Current balance:"<<balance<<"\n";
    return 0;
}
double deposit(){
    double amu=0;
    std::cout<<"\nEnter the amout:";
    std::cin>>amu;
    amu;

    return amu;
}
double withdraw(double balance){
    double amu=0;
    std::cout<<"\nenter the amount :";
    std::cin>>amu;
    if(amu > 0 ){
        if(amu<balance){
            return amu;
        }
        else{
            std::cout<<"insuficient balance\n";
        }
    }
    else{
        std::cout<<"invalade\n ";
    }
        
    
}































/*int main (){
    std::cout<<"it works";
    return 0;
}*/