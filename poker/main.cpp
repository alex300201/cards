//
//  main.cpp
//  poker
//
//  Created by alex on 01.09.2020.
//  Copyright © 2020 alex. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
template<typename t>
void swap(t a,t b){
    t c=a;
    a=b;
    b=c;
}
template<short size>
class deck{
    short curent_card=0;
    short *cards_deck=new short[size];
    void shuffle(){
        for(int i=0;i<100;++i){
            swap<int>(std::rand()%size,std::rand()%size);
        }
    }
    std::string (*convertor)(int);
public:
    deck(std::string convertor(int)){
        for(short i=0;i<size;++i){
            cards_deck=i;
        }
        this->shuffle();
        this->convertor=convertor;
    }
    std::string draw_card(){
        if(curent_card<size){
            return convertor(curent_card++);
        }
        else{
            shuffle();
            curent_card=0;
            return convertor(curent_card++);
        }
    }
    int  draw_card_seed(){
        if(curent_card<size){
                   return curent_card++;
               }
               else{
                   shuffle();
                   curent_card=0;
                   return curent_card++;
               }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
