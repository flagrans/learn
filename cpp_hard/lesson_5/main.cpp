#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <list>
#include <unordered_set>
#include <map>

#include <algorithm>

// Task 1
template <typename T>
void uniqWords(T begin, T end) {
    std::set<std::string> temp;
    copy(begin, end, inserter(temp, temp.end()));
    copy(temp.begin(), temp.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main() {
// Task 1
    {
        std::cout << "********** Task 1 **********" << std::endl;

        std::vector<std::string> vec = {"the", "write", "operation", "is", "performed", "when", "the", "iterator", "whether", "dereferenced", "or", "not", "is", "assigned", "to", "incrementing", "the", "std::ostream_iterator", "is", "a", "no-op"};
        std::list<std::string> lis = {"the", "write", "operation", "is", "performed", "when", "the", "iterator", "whether", "dereferenced", "or", "not", "is", "assigned", "to", "incrementing", "the", "std::ostream_iterator", "is", "a", "no-op"};
        std::unordered_multiset<std::string> ums = {"the", "write", "operation", "is", "performed", "when", "the", "iterator", "whether", "dereferenced", "or", "not", "is", "assigned", "to", "incrementing", "the", "std::ostream_iterator", "is", "a", "no-op"};

        uniqWords(vec.begin(), vec.end());
        std::cout << std::endl << std::endl;

        uniqWords(lis.begin(), lis.end());
        std::cout << std::endl << std::endl;

        uniqWords(ums.begin(), ums.end());

        std::cout << "****************************" << std::endl;
        std::cout << std::endl << std::endl;
    }
// Task 2
    {
        std::cout << "********** Task 2 **********" << std::endl;
        std::string temp_p="";
        std::string temp="";
        std::multimap<int, std::string> mySet;
        std::cin >> temp;
        while(temp != "endend") { //Здесь для окончания ввода необходимо ввести строку "endend"
            temp_p += temp + " ";
            if(temp.back() == '.' || temp.back() == '!' || temp.back() == '?') { // Признак окончания предложения знаки препинания ".", "?" и "!"
                mySet.insert(std::make_pair(temp_p.size(), temp_p));
                temp_p="";
            }
            std::cin >> temp;
        }
        std::cout << "*** List ***" << std::endl;
        std::for_each(mySet.begin(), mySet.end(), [](std::pair<int, std::string> p){std::cout << p.second << std::endl;});

        std::cout << "****************************" << std::endl;
        std::cout << std::endl << std::endl;
    }
    return 0;
}
