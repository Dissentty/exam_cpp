#include <fstream>
#include <iostream>
#include <string>
#include <locale>
using namespace std;

void input_to_base(void);
void search_in_file(void);
void delete_line_from_file(void);

int main() {
    locale::global(locale("ru_RU.UTF-8"));
    int part;
    cout << "Выберите пункт:\n1. Внесение ученика в базу\n2. Поиск ученика по ФИО\n";
    cin >> part;
    if (part == 1) {
        input_to_base();
    }
    if (part == 2) {
        search_in_file();
    }
}

void input_to_base(void) {
    string name;
    float avg_point;
    ofstream outFile("/Users/dissentty/Documents/cpp/learn_cpp/output.txt", ios::app);
    if (!outFile) {
        cerr << "Ошибка при открытии файла!\n";
    }
    
    cin.ignore();
    cout << "Введите ФИО ученика\n";
    getline(cin, name);
    cout << "Введите средний балл ученика\n";
    cin >> avg_point;
    outFile << name << endl << "avg: " << avg_point << endl << endl;
    outFile.close();
}

void search_in_file(void) {
    string search_str;
    bool flag = true;
    bool flag_success_search = false;
    cout << "Введите ФИО ученика\n";
    cin >> search_str;
    ifstream inFile("/Users/dissentty/Documents/cpp/learn_cpp/output.txt");
    if (!inFile) {
        cerr << "Ошибка при открытии файла!" << endl;
    }
    string line;
    while (getline(inFile, line)) {
        if (flag_success_search == true) {
            int choice;
            cout << line << endl;
            cout << "Хотите удалить запись о ученике? 1 - да 2 - нет";
            cin >> choice;
            if (choice == 1) {
                
            }
            break;
        }
        if (line.find(search_str) != string::npos) {
            flag = true;
            flag_success_search = true;
            cout << "Ученик найден в базе\n";
            continue;
        }
    }
    if (flag == false) {
        cout << "Ученик не найден в базе\n";
    }
}

void delete_line_from_file(void) {
    ifstream inFile("/Users/dissentty/Documents/cpp/learn_cpp/output.txt");
    if (!inFile) {
        
    }
}

