#include <iostream>
#include <fstream>
#include <algorithm>

/****************** Задание №2 **********************/
int connectFile(std::string file1, std::string file2, std::string file3) {
    std::ifstream fs1 (file1);
    std::ifstream fs2 (file2);
    std::ofstream fs3 (file3);
    char* fmem1 = (char*)calloc(123, sizeof(char));
    char* fmem2 = (char*)calloc(108, sizeof(char));
    if (fmem1 == nullptr || fmem2 == nullptr) {
        return 1;
    }
    int i = 0;
    char temp;
    while ((temp = fs1.get()) != EOF) { // Почему то когда я использую в while(!fs1.eof()) - в результирующий файл попадает мусор. в конце строки. "с кодами 255, 225"
        fmem1[i] = temp;                // А при таком использовании while - все норм. Можно пояснить этот момент?
        i++;
    }
    fs3 << fmem1;
    free(fmem1);
    fs1.close();
    i = 0;
    while ((temp = fs2.get()) != EOF) {
        fmem2[i] = temp;
        i++;
    }
    fs3 << fmem2;
    free(fmem2);
    fs2.close();
    fs3.close();
    return 0;
}
/****************** Задание №3 **********************/
bool checkWord(std::string st, std::string fl) {
    std::transform(st.begin(), st.end(), st.begin(), tolower); // Приводим к нижнему регистру
    std::ifstream fs (fl);
    std::string temp = "";
    while(!fs.eof()){
        fs >> temp;
        temp = temp.substr(0, temp.find('.', temp.size() - 1) ); // Убираем точку в конце слова
        temp = temp.substr(0, temp.find(',', temp.size() - 1) ); // Убираем запятую, здесь наверное было бы логично воспользоваться регулярными выражениями...
        std::transform(temp.begin(), temp.end(), temp.begin(), tolower); // Приводим к нижнему регистру
        if (temp == st) {
            fs.close();
            return true;
        }
    }
    fs.close();
    return false;
}

int main(int argc, char *argv[]) {
/****************** Задание №1 **********************/
    std::string text1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    std::string text2 = " Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
    std::ofstream fs1 ("file1.txt");
    fs1 << text1;
    fs1.close();
    fs1.open("file2.txt");
    fs1 << text2;
    fs1.close();
/****************** Задание №2 **********************/
    std::string  file1 = "file1.txt";
    std::string  file2 = "file2.txt";
    std::string  file3 = "result.txt";
    connectFile(file1, file2, file3);
/****************** Задание №3 **********************/
    // Здесь примем за условие, что у анс все-таки осмысленный текст а не набор символов, т.к. если у нас набор символов,
    // то необходимо будет в одной большой строке искать вхождение типа использовать find - но в таком случае можно целиком
    // или построчно считывать в переменную и искать вхождение с помощью метода find

    if (argc != 3) {
        std::cout << "Wrong number of parameters!" << std::endl;
        return 1;
    }
    if (checkWord(argv[1], argv[2])) {
        std::cout << "String " << argv[1] << " found in " << argv[2] << std::endl;
    } else{
        std::cout << "String " << argv[1] << " NOT found in " << argv[2] << std::endl;
    }

    return 0;
}
