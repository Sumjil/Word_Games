#include <iostream>
#include <string>
#include <vector>
#include <cctype> 
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

std::string Is_it_a_word_for_wordle( ){
    int i=1;
    std::string word; 
    while(i > 0){
        
        std::getline (std::cin,word);
        i = 0;
        for (int j=0; j < word.size();j++){
            if (word.size()!=5){
                std::cout << "Слово не из 5 букв, введите пятибуквенное слово\n";
                std::cout << "Enter again: "; 
                i++;
                word.erase(0);
                break;
            }
            
            if(isalpha(word[j])==0) {
                std::cout << "String contains a number or other invalid character\n";
                std::cout << "Enter again: "; 
                i++;
                word.erase(0);
            }
            
        }
        
    }
    
    return (word);
   
}


int GetRandomNumber(int min, int max)
{
  // Установить генератор случайных чисел
  srand(time(NULL));

  // Получить случайное число - формула
  int num = min + rand() % (max - min + 1);

  return num;
}


std::string Tolower_be(std::string first_word){
    std::string word; 
    int ix = 0;                               // индекс символов строки
    char character;
    while (first_word[ix])                    // пока не конец строки
    {
    character = first_word[ix];
    word += (char)tolower(character);  // преобразовать текущий символ строки в строчный
    ix++;                                   // инкремент индекса символов в строке
   }
   return word;
    
    
}

void Change_alphaber(std::string &alphabet, std::string &s, int size){
    for (int i=0; i < size;i++) { 
        if (alphabet[i] == s[0] ){
            alphabet[i] = '_';
            i=25;
        }
    }
}

std::string Is_it_a_word( ){
    int i=1;
    std::string word; 
    while(i > 0){
        
        std::getline (std::cin,word);
        i = 0;
        for (int j=0; j < word.size();j++){
            if( isalpha(word[j])==0) {
                std::cout << "String contains a number or other invalid character\n";
                std::cout << "Enter again: "; 
                i++;
                word.erase(0);
            }
            
        }
        
    }
    
    return (word);   
}

