#include <iostream>
#include <list>
#include <deque>
#include <vector>

// Если я правильно понял задание, ну если что, отправьте на доработку, будем переделывать
// Подскажите еще пару вопросов:
// 1. Правильно ли вообще я понял и реализовал
// 2. Как реализовать подобное для std::array, так и не придумал как его передать
// 3. Как можно сделать так, чтобы при итерации можно было добавлять элементы в структуру
// Сейчас если у меня создался объект моих классов, то все если  ядобавляю то итерируюсь по старому, т.к.
// передаю записываю в объект копию. Или такое поведение правильное?

template <class T>
class IIterator {
public:
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual bool hasNext() = 0;
    virtual bool hasPrev() = 0;
    virtual T getCurrentIt() = 0;
    virtual ~IIterator(){};
};

template <class T>
class vectorIterator: public IIterator<T> {
public:
    typedef typename std::vector<T>::iterator iter_type;
    vectorIterator(std::vector<T> &v): data(v), it(data.begin()){}

    void next() override {
        if(hasNext())
            ++it;
        else
            std::cout << "No next. This is end position." << std::endl;
    }
    void prev() override {
        if(hasPrev())
            --it;
        else
            std::cout << "No prev. This is begin position." << std::endl;
    }

    T getCurrentIt() override {
        return *it;
    }

    bool hasNext() override {
        iter_type temp = it;
        if (++temp != data.end()) {
            return true;
        }
        return false;
    }
    bool hasPrev() override {
        return (it) != data.begin();
    }
private:
    std::vector<T> data;
    iter_type it;
};


template <class T>
class listIterator: public IIterator<T> {
public:
    typedef typename std::list<T>::iterator iter_type;
    listIterator(std::list<T> &v): data(v), it(data.begin()){}

    void next() override {
        if(hasNext())
            ++it;
        else
            std::cout << "No next. This is end position." << std::endl;
    }
    void prev() override {
        if(hasPrev())
            --it;
        else
            std::cout << "No prev. This is begin position." << std::endl;
    }

    T getCurrentIt() override {
        return *it;
    }

    bool hasNext() override {
        iter_type temp = it;
        if (++temp != data.end()) {
            return true;
        }
        return false;
    }
    bool hasPrev() override {
        return it != data.begin();
    }
private:
    std::list<T> data;
    iter_type it;
};


template <class T>
class dequeIterator: public IIterator<T> {
public:
    typedef typename std::deque<T>::iterator iter_type;
    dequeIterator(std::deque<T> &v): data(v), it(data.begin()){}

    void next() override {
        if(hasNext())
            ++it;
        else
            std::cout << "No next. This is end position." << std::endl;
    }
    void prev() override {
        if(hasPrev())
            --it;
        else
            std::cout << "No prev. This is begin position." << std::endl;
    }

    T getCurrentIt() override {
        return *it;
    }

    bool hasNext() override {
        iter_type temp = it;
        if (++temp != data.end()) {
            return true;
        }
        return false;
    }
    bool hasPrev() override {
        return (it) != data.begin();
    }
private:
    std::deque<T> data;
    iter_type it;
};

template <class T>
class arrayIterator: public IIterator<T> {
public:
    arrayIterator(T* &v, size_t s): _data(v), _size(s), it(_data){}

    void next() override {
        if(hasNext())
            ++it;
        else
            std::cout << "No next. This is end position." << std::endl;
    }
    void prev() override {
        if(hasPrev())
            --it;
        else
            std::cout << "No prev. This is begin position." << std::endl;
    }

    T getCurrentIt() override {
        return *it;
    }

    bool hasNext() override {
        return it != _data + _size - 1;
    }
    bool hasPrev() override {
        return it != _data;
    }
private:
    T* _data;
    size_t _size;
    T* it;
};

template <class T>
class IContainer {
    virtual IIterator<T>* createIterator() = 0;
};

template <class T>
class myVec : public IContainer<T> {
    std::vector<T> _data;
public:
    myVec(std::vector<T> &v) : _data(v){}

    IIterator<T>* createIterator() override {
        return new vectorIterator(_data);
    }
};

template <class T>
class myList : public IContainer<T> {
    std::list<T> _data;
public:
    myList(std::list<T> v) : _data(v){}

    IIterator<T>* createIterator() override {
        return new listIterator(_data);
    }
};

template <class T>
class myDeque : public IContainer<T> {
    std::deque<T> _data;
public:
    myDeque(std::deque<T> v) : _data(v){}

    IIterator<T>* createIterator() override {
        return new dequeIterator(_data);
    }
};

template <class T>
class myArray : public IContainer<T> {
    T* _data;
    size_t _size;
public:
    myArray(T* &v, size_t s): _data(v), _size(s){}

    IIterator<T>* createIterator() override {
        return new arrayIterator<T>(_data, _size);
    }
};




int main() {


    std::vector<int> test;
    test.push_back(3);
    test.push_back(1);
    test.push_back(2);

    myVec v(test);
    IIterator<int>* vi = v.createIterator();
    vi->next();
    std::cout << vi->getCurrentIt() << std::endl;
    vi->next();
    std::cout << vi->getCurrentIt() << std::endl;
    vi->next();
    std::cout << vi->getCurrentIt() << std::endl;
    vi->next();
    std::cout << vi->getCurrentIt() << std::endl;

    std::cout << "************************************" << std::endl;

    size_t length = 5;
    int *array = new int[5] { 99, 77, 55, 33, 11 };

    myArray va(array, length);
    IIterator<int>* vai = va.createIterator();
    vai->next();
    std::cout << vai->getCurrentIt() << std::endl;
    vai->next();
    std::cout << vai->getCurrentIt() << std::endl;
    vai->next();
    std::cout << vai->getCurrentIt() << std::endl;
    vai->prev();
    std::cout << vai->getCurrentIt() << std::endl;



    delete vai;
    delete vi;
    return 0;
}
