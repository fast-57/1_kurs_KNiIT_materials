# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <windows.h>
# include <locale.h>
using namespace std;
// функция для выбора случайного слова из списка
string random(const vector<string>& words){ 
    srand(time(0));
    return words[rand() % words.size()];
}
// функция для отображения текущего состояния угаданного слова
void ygadaika(string& word, vector<bool>& ygadai){
    for(int i = 0; i < word.length(); i++){
        if(ygadai[i] == true){
            cout << word[i] << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}
// функция для проверки, угадано ли всё слово
bool ygadal(vector<bool>& ygadai){
    for(bool ygadali : ygadai){
        if (!ygadali){
            return false;
        }
    }
    return true;
}
// функция для отображения доступных букв
void check_alphabet(vector<bool>& alphabetEng, const vector<string>& russian_bukvi, vector<bool>& alphabetRus){
    cout << "Английские буквы: ";
    for(char i = 'a'; i <= 'z'; i++){
        if(alphabetEng[i - 'a'] == true){
            cout << i << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;

    cout << "Русские буквы: ";
    for(int i = 0; i < russian_bukvi.size(); i++){
        if (alphabetRus[i] == true){
            cout << russian_bukvi[i] << " ";
        } else{
            cout << "_ ";
        }
    }
    cout << endl;
}



int main(){
    // setlocale(LC_ALL, "RUS");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    vector<string> words;
    cout << "Введите не менее 10 слов, каждое из которых состоит из 8-15 букв: " << endl;
    while (words.size() < 10){
        string word;
        cout << words.size() + 1 << " слово: ";
        cin >> word;
        if(word.length() < 8 || word.length() > 15){
            cout << "Неправильная длина слова" << endl;
            continue;
        }
        words.push_back(word);
    }
    string word = random(words);
    vector<bool> ygadali(word.length(), false);
    vector<bool> alphabetEng(26, true);
    vector<string> russian_bukvi = {"а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я"};
    vector<bool> alphabetRus(russian_bukvi.size(), true);
    int popitki = 6;

    while (popitki > 0 && !ygadal(ygadali)){
        cout << "Попыток осталось: " << popitki << endl;
        ygadaika(word, ygadali);
        for (int i = 0; i < 33; i++){
            cout << bool(alphabetRus[i]) << " ";
        }
        check_alphabet(alphabetEng, russian_bukvi, alphabetRus);

        cout << "Введите букву или слово целиком: ";
        string bukva_word;
        cin >> bukva_word;
        if (bukva_word.length() == 1){
            string bukva = bukva_word;
            int index;
            for(int i = 0; i < russian_bukvi.size(); i++){
                if (russian_bukvi[i] == bukva){
                    index = i;
                    if (alphabetRus[index] == true){
                        alphabetRus[index] = false;
                        bool found = false;
                        for(int i = 0; i < word.length(); i++){
                            if(word[i] == bukva[0]){
                                ygadali[i] = true;
                                found = true;
                            }
                        }
                        if (!found){
                            popitki--;
                            cout << "Буквы " << bukva << " нету в слове!" << endl;
                        }
                    } 
                    else{
                        cout << "Буква " << bukva << " уже использована!" << endl;
                    }
                
                }else{
                    cout << "Неправильный символ!" << endl;
                }
                break;
            }
        }else{
            if (bukva_word == word){
                cout << "Cлово целиком: " << word << " Точно! И перед нами победитель!!! ПО-БЕ-ДИ-ТЕЛЬ!!!" << endl;
            return 0;
            }
            else{
                cout << "Увы и ах! Неверное слово! Игра окончена." << endl;
            return 0;
            }
        }
    }
    if (ygadal(ygadali)){
        cout << "Cлово целиком: " << word << " Точно! И перед нами победитель!!! ПО-БЕ-ДИ-ТЕЛЬ!!!" << endl;
    }
    else{
        cout << "Увы и ах! Попытки закончились! Загаданное слово: " << word << endl;
    }
    char test;
    cin >> test;
    cout << "Вы ввели: " << test << endl;
    system("pause");
    return 0;
}
