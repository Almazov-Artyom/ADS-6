// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size = 0>
class TPQueue {
 private:
    T arr[size] = {0};
    int left, right, count;

 public:
    TPQueue(): left(0), right(0), count(0) {}
    void push(const T& sm) {
        if (count == 0) {
            arr[0] = sm;
            ++right;
            ++count;
        } else {
            for (int i = right; i > left; --i) {
                if (arr[(i - 1) % size].prior >= sm.prior) {
                    arr[i % size] = sm;
                    break;
                } else {
                    arr[i % size] = arr[(i - 1) % size];
                    arr[(i - 1)%size] = sm;
                }
            }
            ++right;
        }
    }
    const T& pop() {
        return arr[(left++ % size)];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
