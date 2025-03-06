//
//  main.cpp
//  Twelw Balls
//
//  Created by Fev1L on 06.03.2025.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int l = rand() % 11;
int h = rand() % 11;

class twelwBalls{
private:
    int x,y,z,x1,y1,z1;
    
    int lChoise, hChoise;
    
    bool win = false;
public:
    void endGame(){
        cout<<"Chose light ball (you can chose randomly if you dont know): "<<endl;
        cin>>lChoise;
        cout<<"Chose heavy ball (you can chose randomly if you dont know): "<<endl;
        cin>>hChoise;
        
        if(lChoise == l && hChoise == h){
            cout<<"You are win";
            exit(0);
        }else if(lChoise == l && hChoise != h){
            cout<<"light ball is correct"<<endl;
            exit(0);
        }else if(lChoise != l && hChoise == h){
            cout<<"heavy ball is correct"<<endl;
            exit(0);
        }else{
            cout<<"Nice try"<<endl;
            exit(0);
        }
    }
    void balls(int arr[12]){
        cout<<"Please chose 1 to 3 balls for first side (cannot be similar) [From 1 - 12]: "<<endl;
        cout<<"Chose how many balls you want to weight: "<<endl;
        cin>>x;
        if(x < 1 || x > 3){
            do{
                cout<<"Chose from 1 - 3 balls"<<endl;
                cin>>x;
            }while(x < 1 || x > 3);
        }
        cout<<"Chose balls: "<<endl;
        for(int i = 0;i<x;i++){
            cin>>y;
            z += arr[y];
        }
        
        cout<<"Please chose 1 to 3 balls for second side (cannot be similar) [From 1 - 12]: "<<endl;
        cout<<"Chose how many balls you want to weight: "<<endl;
        cin>>x1;
        if(x1 < 1 || x1 > 3){
            do{
                cout<<"Chose from 1 - 3 balls"<<endl;
                cin>>x1;
            }while(x1 < 1 || x1 > 3);
        }
        cout<<"Chose balls: "<<endl;
        for(int i = 0;i<x1;i++){
            cin>>y1;
            z1 += arr[y1];
        }
        if(z > z1){
            cout<<"First side is heavier"<<endl;
        }else if(z < z1){
            cout<<"Second side is heavier"<<endl;
        }else{
            cout<<"Both sides are simiilar"<<endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    bool end = false;
    int atemps = 0;
    string answear;
    srand(time_t(0));
    int arr[12] = {2,2,2,2,2,2,2,2,2,2,2,2};
    if(h == l){
        do{
            h = rand() & 11;
        }while(h != l);
    }
    
    for(int i = 0;i<12;i++){
        if(i == l){
            arr[i] = 1;
        }
        if(i == h){
            arr[i] = 3;
        }
    }
    twelwBalls obj;
    do{
        cout<<"Chose comands[stop,balls,chose]: "<<endl;
        cin>>answear;
        if(answear == "stop"){
            end = true;
            exit(0);
        }else if(atemps == 3){
            cout<<"Atemps is over, lets over the game!"<<endl;
        }else if(answear == "chose"){
            obj.endGame();
        }else if(answear == "balls" && atemps < 3){
            obj.balls(arr);
            atemps += 1;
        }
    }while(end == false);
    return 0;
}
