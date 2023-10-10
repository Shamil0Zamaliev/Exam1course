// Exam2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>



std::string replace(const std::string &line) {
    std::string res;

    for (char c : line) {
        if (std::isdigit(c)) {
            switch (c) {
                case '0':
                    res += "zero";
                    break;
                case '1':
                    res += "one";
                    break;
                case '2':
                    res += "two";
                    break;
                case '3':
                    res += "three";
                    break;
                case '4':
                    res += "four";
                    break;
                case '5':
                    res += "five";
                    break;
                case '6':
                    res += "six";
                    break;
                case '7':
                    res += "seven";
                    break;
                case '8':
                    res += "eight";
                    break;
                case '9':
                    res += "nine";
                    break;
                default:
                    res += c;
                    break;
            }
        }
        else
            res += c;
    }

    return res;
}

void Print(const std::string &text) {
    bool newSentence = false;

    for (char c : text) {
        std::cout << c;
        if (c == '.' || c == '!' || c == '?') {
            newSentence = true;
        }
        if (newSentence && c != ' ' && c != '\n') {
            newSentence = false;
            std::cout << std::endl;
        }
    }
}

void filter(const std::string& filename) {
    std::ifstream fin(filename);

    if (!fin) {
        std::cout << "Failed to open file: " << filename << '\n';
        return;
    }
    std::string line;
    std::string text;

    while (std::getline(fin, line)) {
        text += replace(line) + '\n';
    }
    fin.close();

    Print(text);
}



int main()
{
    setlocale(LC_ALL, "Russian");
    std::string path = "test.txt.txt";

    filter(path);
}
