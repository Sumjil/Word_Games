#include <iostream>
#include "draw.h"
#include "func_with_word.h"
#include "hangman_game.h"
#include "wordle_game.h"



void print_menu() {
    system("clear"); // очищаем экран
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Играть в Hangman" << std::endl;
    std::cout << "2. Играть в wordle" << std::endl;
    std::cout << "3. Посмотреть статистику" << std::endl;
    std::cout << "4. Сбросить статистику" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << ">";
}

int get_variant(int count) {
    int variant;
    std::string s; // строка для считывания введённых данных
    getline(std::cin, s); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        std::cout << "Incorrect input. Try again: "; // выводим сообщение об ошибке
        getline(std::cin, s); // считываем строку повторно
    }

    return variant;
}



int main() {
    int variant; // выбранный пункт меню
    int how_many_times_hangman = 0;
    int win_hangman = 0;
    int fail_hangman = 0;


    int time_to_win[6] = {0,0,0,0,0,0}; 
       
        int result = 0;
    



    int how_many_times_wordle = 0;
    int win_wordle = 0;
    
    


    do {
        print_menu(); // выводим меню на экран

        variant = get_variant(5); // получаем номер выбранного пункта меню

        switch (variant) {
            case 1:{
                    
                    hangman_game();


            }
                
                break;

            case 2:{
                   
                    wordle_game();
                   
            }
                
                break;

            case 3:
                system("clear");
                std::cout <<("+---------------------+-------------+-------+\n");
                std::cout << "В игре hangman следующая статистика: \n";
                std::cout<<"\n";
                std::cout <<"Всего сыграно игр: "<<how_many_times_hangman<<"\n";
                std::cout <<"Выиграшных партий: "<< win_hangman <<" Проигрышных партий :"<< fail_hangman<<"\n";
                
             
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
                



                break;

            case 4:
                how_many_times_hangman = 0;
                win_hangman = 0;
                fail_hangman = 0;


                how_many_times_wordle = 0;
                
                time_to_win[0] = 0; 
                time_to_win[1] = 0;
                time_to_win[2] = 0;
                time_to_win[3] = 0;
                time_to_win[4] = 0;
                time_to_win[5] = 0;
                win_wordle=0;
                
                std::cout<<"Cтатистика обновлена\n";
                
                
                break;
        }

        if (variant != 5)
            system( "read -n 1 -s -p \"Press any key to continue...\"" ); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 5);

    return 0;
}

