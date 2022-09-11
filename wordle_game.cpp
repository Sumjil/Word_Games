#include <iostream>
#include <string>
#include <vector>
#include <cctype> 
#include <stdlib.h>
#include "func_with_word.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <time.h>

void wordle_game(){
    int time_to_win[6] ={0,0,0,0,0,0}; // массив из пяти чисел
    int result = 0;
    



    int how_many_times_wordle = 0;
    int win_wordle = 0;

    how_many_times_wordle++;
    std::string word ; //= "today";//, try_unlock = "batty";
    std::vector<std::string> words;
    std::ifstream file("/Users/yulia/Downloads/game/input.txt");
    while (!file.eof()) {
        std::string word;
        file >> word;
        words.push_back(word);
    }
    word = words[GetRandomNumber(0,5756)];

    std::string try_unlock;
    std::vector<char> used;
    std::vector<int> green;
    std::vector<int> yellow;
    std::vector<std::string> draw;
    for (int i=0; i < 6;i++) { 
       for (int j=0;j<5;j++){
                std::cout<< std::setw(5)<<"?";
            }
        std::cout<<"\n";
        draw.push_back("? ? ? ? ?\n");    
    }
    int where_was_find; 
    std::vector<int>::iterator it;
    std::vector<int>::iterator iter;
    int fail=0;
    int num = 0;



    std::cout<<"\n"; 

    while (fail< 6){ // имеется 6 попыток
        
        try_unlock = Is_it_a_word_for_wordle();      // enter word
        try_unlock = Tolower_be(try_unlock); // tower
        
        draw[num] = try_unlock; // изменяет табличку добавляем слово
        num++;   
        std::cout<<"\n";

       for (int k=0; k < num;k++){
           try_unlock = draw[k];
           green.clear();
           yellow.clear();
           used.clear();
           for (int i=0; i < try_unlock.size();i++){ 
                int pos = 0;
                /////////////////////////////////////////////////////////////////////
                

                while ((where_was_find = word.find(try_unlock[i], pos)) != std::string::npos)
                    {            
                        if (where_was_find == i){ // если индексы в предлож слове и загад совпад - зел
                            green.push_back(i);
                        }
                        else{
                            yellow.push_back(i);
                        }
                        pos = where_was_find+1;
                    }
                    
                    
           }
            int prev_colour = 0; 

            for (int i=0; i<try_unlock.size();i++){     // вывод букв

                it = find (green.begin(), green.end(), i);
                iter = find (yellow.begin(), yellow.end(), i);
                if (it != green.end()){
                    std::cout << "\033[1;32m "<< std::setw(4-prev_colour) << try_unlock[i] <<" \033[0m";
                    prev_colour = 1;
                }
                else if (iter != yellow.end() ) {
                    std::cout << "\033[1;33m "<< std::setw(4-prev_colour)<< try_unlock[i] <<" \033[0m";
                    prev_colour = 1;
                }
                else {
                    std::cout<< std::setw(5-prev_colour)<<try_unlock[i];
                    prev_colour = 0;
                }
                
            } 
        std::cout<<"\n";
        }
        for(int i = num; i < draw.size();i++){
            for (int j=0;j<5;j++){
                std::cout<< std::setw(5)<<"?";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
            
        if (try_unlock==word){
            std::cout<<"You are winner\n";
            time_to_win[fail]++;
            win_wordle++;
            fail = 6;
        }
        else{
            fail+=1;
            
               
        }    
    }
    std::cout<<"The word was: " << word<<"\n" ;
    std::cout<<"\n";  


    std::cout<<"\n";
    std::cout <<("+---------------------+-------------+-------+\n");
    std::cout << "В игре wordle следующая статистика: \n";
    std::cout<<"\n";
    std::cout <<"Всего сыграно игр: "<<how_many_times_wordle<<"\n";
    std::cout<<"Кол-во раз отгаданий с первой попытки: "<<time_to_win[0]<<"\n";
    std::cout<<"Кол-во раз отгаданий со второй попытки: "<<time_to_win[1]<<"\n";
    std::cout<<"Кол-во раз отгаданий с третий попытки: "<<time_to_win[2]<<"\n";
    std::cout<<"Кол-во раз отгаданий с четвертой попытки: "<<time_to_win[3]<<"\n";
    std::cout<<"Кол-во раз отгаданий с пятой попытки: "<<time_to_win[4]<<"\n";
    std::cout<<"Кол-во раз отгаданий с шестой попытки: "<<time_to_win[5]<<"\n";
    std::cout<<"\n";

    std::cout<<"Кол-во проигрышей: "<<how_many_times_wordle-win_wordle<<"\n";
                       
}
