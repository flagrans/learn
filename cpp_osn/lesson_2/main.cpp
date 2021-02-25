#include <iostream>

/***************************** Первое задание **************************************/

static int si1;
extern int ei1; // Почему мы не можем инициализировать в main(){}? Выдает ошибку - "..... ошибка: undefined reference to `ei1'"
// Т.е. если мы объявили переменную как extern мы не можем ее использовать в этом файле? только во внешнем?

typedef enum transport {car = 5, moto, aqua, avia} trans;

struct student {
    std::string name; // Почему когда я подключаю - #include <string>, то объявление string name - выдает ошибку неизвестный тип? или в библиотеке string храняться только методы для работы со строками?
    int age;
    char group;
};
// Почему структура объявляется вне тела main()? А отсальные переменные мы объявляем преимущественно в теле main()?


/***************************** Четвертое задание **************************************/

    struct pole {
        int sizeX;
        int sizeY;
    };
    // Как я понял из задания необходимо создать структуру поля - поле у нас может обладать двумя свойствами размерность по X и размерность по Y

/***************************** Пятое задание **************************************/

    union test {
        int ti1;
        float ti2;
        bool ti3;
        char ti4;
    };
    // К вопросу почему мы структуры определяем вне main () - Нам здесь пришлось определить union до структуры, чтобы структура знала о его существовании. Можно как-нибудь по другому поступит ьв данной ситуации?
    struct Prime {
        union test u_test;
        int is_int: 1;
        int is_float: 1;
        int is_bool: 1;
        int is_char: 1;
    };

int main(){

/***************************** Первое задание **************************************/

    int i1;
    char c1;
    long l1;
    long long ll1;

    float f1;
    double d1;

    bool b1 = true;

    char c2 = 'F';

    // Можно немного поподробнее об этих типах
    unsigned int ui1 = 223;

    i1 = 1;
    c1 = 68;
    l1 = 21342143234235;
    ll1 = 2757568679573462354;

    f1 = 12.3;
    d1 = 5434134234234.3334234234234;

    // Можно немного поподробнее об этих типах
    int8_t i8 = 65;
    int16_t i16 = 2;
    int32_t i32 = 2;
    int64_t i64 = 2;

    si1 = 2;

    const int ci1 = 3;
    volatile int vi1 = 6;

    std::cout << "Int i1 = " << i1 << "  size = " <<  sizeof(i1) << std::endl;
    std::cout << "Char c1 = " << c1 << "  size = " <<  sizeof(c1) << std::endl;
    std::cout << "Long l1 = " << l1 << "  size = " <<  sizeof(l1) << std::endl;
    std::cout << "Long long ll1 = " << ll1 << "  size = " <<  sizeof(ll1) << std::endl;
    std::cout << "Float f1 = " << f1 << "  size = " <<  sizeof(f1) << std::endl;
    std::cout << "Double d1 = " << d1 << "  size = " <<  sizeof(d1) << std::endl;
    std::cout << "Bool b1 = " << b1 << "  size = " <<  sizeof(b1) << std::endl;
    std::cout << "Char c2 = " << c2 << "  size = " <<  sizeof(c2) << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "Unsigned int ui1 = " << ui1 << "  size = " <<  sizeof(ui1) << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "int8_t i8 = " << i8 << "  size = " <<  sizeof(i8) << std::endl; // Здесь выводит 'A' - т.е. это аналог char?
    std::cout << "int16_t i16 = " << i16 << "  size = " <<  sizeof(i16) << std::endl;
    std::cout << "int32_t i32 = " << i32 << "  size = " <<  sizeof(i32) << std::endl;
    std::cout << "int64_t i64 = " << i64 << "  size = " <<  sizeof(i64) << std::endl;
    std::cout << "******************************************" << std::endl;


    trans t1;
    t1 = avia;
    std::cout << "enum t1 = " << t1 << std::endl;
    std::cout << "******************************************" << std::endl;

    student st1;
    st1.name = "Alex";
    st1.age = 23;
    st1.group = 'F';

    student s2 {"Fedor", 29, 'A'};
    // student s3 {44, "Maks", 'B'}; - выдает ошибку. Т.е. при создании экземпляра структуры совместно с ее инициализацией значения полей необходимо указывать в том порядке, в котором поля идут в объявлении структуры

    int arr[20];
    arr[0] = 1;
    arr[3] = 33;

    int arr2[] = {1, 2, 3};

    char arr3[2][2];
    arr3[0][0] = 'A';
    arr3[1][1] = 'B';


    union temp {
        int s1;
        float s2;
        bool s3;
        char s4;
    };
    union temp tmp;
    tmp.s1 = 23;
    std::cout << "temp(int) = " << tmp.s1 << std::endl;
    tmp.s2 = 1.22;
    std::cout << "temp(float) = " << tmp.s2 << std::endl;
    tmp.s3 = false;
    std::cout << "temp(bool) = " << tmp.s3 << std::endl;
    tmp.s4 = 'D';
    std::cout << "temp(char) = " << tmp.s4 << std::endl;
    std::cout << "******************************************" << std::endl;



/***************************** Второе задание **************************************/

    enum variables {p, x, o}; // p - признак пустого поля, x - крестик, o - нолик

/***************************** Третье задание **************************************/

    enum variables mass[] = {p, x, o}; // Не совсем понятно зачем нам массив из данного перечисления везь мы могли сразу инициализироват массив 0, 1 и 2

/***************************** Пятое задание **************************************/

    struct Prime ex_Prime;
    ex_Prime.u_test.ti2 = 21.23;
    ex_Prime.is_float = 1;

    std::cout << "Test Prime " << ex_Prime.u_test.ti2 << std::endl;

    return 0;
}
