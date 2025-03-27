//
//  main.cpp
//  Twelw Balls
//
//  Created by Fev1L on 06.03.2025.
//

#include <iostream>
#include <cstdlib>
using namespace std;



class twelwBalls{
private:
    int x,y,z = 0,x1,y1,z1 = 0;
    
    int lChoise, hChoise;
    
    bool win = false;
public:
    void endGame(int h,int l){
        cout<<"Chose first ball: "<<endl;
        cin>>lChoise;
        cout<<"Chose second ball: "<<endl;
        cin>>hChoise;
        
        if(lChoise == l && hChoise == h){
            cout<<"You are win";
            exit(0);
        }else if(lChoise == l || hChoise == l){
            cout<<"light ball is correct"<<endl;
            exit(0);
        }else if(lChoise == l || hChoise == l){
            cout<<"heavy ball is correct"<<endl;
            exit(0);
        }else{
            cout<<"Nice try"<<endl;
            exit(0);
        }
    }
    void balls(int arr[12]){
        cout<<"Please chose 1 to 4 balls for first side (cannot be similar) [From 0 - 11]: "<<endl;
        cout<<"Chose how many balls you want to weight: "<<endl;
        cin>>x;
        cout<<"Chose balls: "<<endl;
        for(int i = 0;i<x;i++){
            cin>>y;
            z += arr[y];
        }
        
        cout<<"Please chose 1 to 4 balls for second side (cannot be similar) [From 0 - 11]: "<<endl;
        cout<<"Chose balls: "<<endl;
        for(int i = 0;i<x;i++){
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
    srand(time(0));
    int arr[12] = {2,2,2,2,2,2,2,2,2,2,2,2};
    
    int l = rand() % 11;
    int h = rand() % 11;
    
    if(h == l){
        do{
            h = rand() % 11;
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
    obj.balls(arr);
    obj.balls(arr);
    obj.endGame(h,l);
    
    return 0;
}
