class FizzBuzz {
private:
    int n;
    mutex gLock;
    int count;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (count <= n) {
            if (count % 3 == 0 && count % 5 != 0 && count <= n) {
                printFizz();
                gLock.lock();
                ++count;
                gLock.unlock();
            }
            
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (count <= n) {
            if (count % 3 != 0 && count % 5 == 0 && count <= n) {
                printBuzz();
                gLock.lock();
                ++count;
                gLock.unlock();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (count <= n) {
            if (count % 3 == 0 && count % 5 == 0 && count <= n) {
                printFizzBuzz();
                gLock.lock();
                ++count;
                gLock.unlock();
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (count <= n) {
            if (count % 3 != 0 && count % 5 != 0 && count <= n) {
                printNumber(count);
                gLock.lock();
                ++count;
                gLock.unlock();
            }
        }
    }
};