#include <iostream>
#include <string>
#include <vector>
#include <cctype> 
#include "draw.h"
#include "func_with_word.h"


void hangman_game()
{
    std::vector<char> unknown_word;  //пустой вектор  для отображения неизвестного слова 
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int size = alphabet.size();
    int win = 0;
    int fail = 0;
    std::string word;
    std::string l; //буква слова 
    std::vector<int> index;// массив индеквов, где находится в исходном слове введеная буква
    
   
    std::cout<<"Enter a word: ";
    word = Is_it_a_word();
    word = Tolower_be(word);
    system("clear");
    
    
    
    std::cout<< word.size() << " letter word: ";
    for (int i=0; i < word.size();i++) { // вывод позвотелю слова в виде - ????
        unknown_word.__emplace_back('?');
        std::cout << unknown_word[i];        
    }
        
    std::cout<<"\n";    
     
    while (fail< 7){                    // попытки отгадать слово
        std::cout<<"Choose the letter from the alphabet \n";  
        ///////вывод алфавита и секретного слова
        for(int i = 0; i < size; i++)
            std::cout << alphabet[i]<< " ";
        std::cout<<"\n"; 
        
        for(int i = 0; i < unknown_word.size(); i++)   
        std::cout << unknown_word[i];
        std::cout<<"\n";
        
        
        l = Is_it_a_word();
        l = Tolower_be(l);
        
        int where_was_find = -1; // index где нашли букву
        int pos = 0;            // позиция с которой искать
        int find = -1;
        while ((where_was_find = word.find(l, pos)) != std::string::npos){  
            index.__emplace_back(where_was_find);
            pos = where_was_find+1;
            find=1;
        } //  есть ли буква в слове или нет
        if (find == 1){
           
           std::cout<<"letter in the word\n";
           Draw(fail);
           Change_alphaber(alphabet,l,size);
           
           
           for (int i=0;i<index.size();i++){
               unknown_word[index[i]] = word[index[i]];
               win+=1;
           }
           index.clear();
           if (win == word.size()){
               std::cout<<"You are winner!!!\n";
               
               break;
               
           }
           
       }
       else{
           std::cout<<"letter is not in the word\n";
           fail+=1;
           
           Draw(fail);
           
           Change_alphaber(alphabet,l,size);
           
           
       }
       
        l.erase(0); // удаляет из строки S  с символа с индексом pos и до конца строки.
        

    } 
    std::cout<< "The word was: "<< word<<"\n"; 
    
}

