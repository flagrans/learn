#ifndef ARRAY_H
#define ARRAY_H
#include <cassert> // для assert()
#include <iostream>
#include <algorithm>

class ArrayInt {
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr) { }
    ArrayInt(int length): m_length(length) {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    ~ArrayInt() {
        delete[] m_data;
    }
    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }
    int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    friend std::ostream& operator<< (std::ostream &out, const ArrayInt &a);
    void resize(int newLength) {
        if (newLength == m_length)
            return;
        if (newLength <= 0) {
            erase();
            return;
        }
        int *data = new int[newLength];
        if (m_length > 0) {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }
    void insertBefore(int value, int index) {
        assert(index >= 0 && index <= m_length);
        int *data = new int[m_length+1];
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];
        data [index] = value;
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void push_back(int value) { insertBefore(value, m_length); }

    int pop_back() {
        if (m_length == 0)
            return 0;
        int *data = new int[m_length-1];
        int temp = m_data[m_length - 1];
        for (int i=0; i < m_length - 1; ++i)
            data[i] = m_data[i];
        delete[] m_data;
        m_data = data;
        --m_length;
        return temp;
    }
    int pop_front() {
        if (m_length == 0)
            return 0;
        int *data = new int[m_length - 1];
        int temp = m_data[0];
        for (int i = 1; i < m_length; ++i)
            data[i - 1] = m_data[i];
        delete[] m_data;
        m_data = data;
        --m_length;
        return temp;
    }

    void sort() {
        std::sort(m_data, m_data + m_length);
    }
    void print() {
        std::cout << *this << std::endl;
    }
};

std::ostream& operator<< (std::ostream &out, const ArrayInt &a){
    out << "{ ";
    for (int i = 0; i < a.m_length; i++) {
        if ((i + 1) == a.m_length) {
            out << a.m_data[i];
        } else {
            out << a.m_data[i] << ", ";
        }
    }
    out << " }";
    return out;
}


#endif // ARRAY_H
