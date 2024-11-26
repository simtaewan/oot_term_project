#include <iostream>
using namespace std;

//컴퓨터 추상 클래스
class AbstractComputer {
public:
    virtual string getComputerOption() = 0;
    virtual int getPrice() = 0;
};

//컴퓨터 클래스
class Computer : public AbstractComputer {
public:
    string getComputerOption() { return ""; }
    int getPrice() { return 500000; }
};

//데코레이터 클래스
class Decorator : public AbstractComputer {
protected:
    AbstractComputer* computer;
public:
    Decorator(AbstractComputer* computer) : computer(computer) {}
    ~Decorator() { delete computer; }
};

//RAM 클래스
class RAM : public Decorator {
    public:
    RAM(AbstractComputer* computer) : Decorator(computer) {}
    string getComputerOption() {
        return computer->getComputerOption() + "RAM";
    }
    int getPrice() {
        return 50000 + computer->getPrice();
    }
};

//SSD 클래스
class SSD : public Decorator {
public:
    SSD(AbstractComputer* computer) : Decorator(computer) {}
    string getComputerOption() { 
        return computer->getComputerOption() + "SSD";
    }
    int getPrice() {
        return 80000 + computer->getPrice();
    }
};

//GPU 클래스
class GPU : public Decorator {
public:
    GPU(AbstractComputer* computer) : Decorator(computer) {}
    string getComputerOption() {
        return computer->getComputerOption() + "GPU";
    }
    int getPrice() {
        return 200000 + computer->getPrice();
    }
};

//결과 출력
void print(AbstractComputer* computer) {
    cout << computer->getComputerOption() << "Computer, " << computer->getPrice();
}

int main() {
    char ans;
    AbstractComputer* computer = new Computer();
    // RAM 추가
    cout << "Add RAM? (y/n): ";
    cin >> ans;
    if (ans == 'y') { computer = new RAM(computer); }
    // SSD 추가
    cout << "Add SSD? (y/n): ";
    cin >> ans;
    if (ans == 'y') { computer = new SSD(computer); }
    //GPU 추가
    cout << "Add GPU? (y/n): ";
    cin >> ans;
    if (ans == 'y') { computer = new GPU(computer); }

    print(computer);
    delete computer;
    return 0;
}
