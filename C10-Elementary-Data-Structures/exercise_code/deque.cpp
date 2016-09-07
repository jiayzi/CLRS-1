#include<cassert>
#include<iostream>
#include<vector>

using namespace std;

class Deque {
    
private:
    vector<int> data_;
    int size_;
    int head_;
    int tail_;
    int capacity_;
    
public:
    
    Deque(int size) : size_(0), head_(0), tail_(size-1), capacity_(size), data_(size, 0) {}
    
    void push_front(int v) {
        assert(head_ <= tail_);
        data_[head_++] = v;
        size_++;
    }
    
    void push_back(int v) {
        assert(head_ <= tail_);
        data_[tail_--] = v;
        size_++;
    }
    
    void pop_front() {
        assert(head_ > 0);
        head_--;
        size_--;
    }
    
    void pop_back() {
        assert(tail_ < capacity_);
        tail_++;
        size_--;
    }
    
    int front() const { 
        assert(head_ > 0);
        return data_[head_-1];
    }
    
    int back() const {
        assert(tail_ < capacity_-1);
        return data_[tail_+1];
    }
    
    int size() const { return size_; }
    
    int empty() const { return size_ == 0; }
    
    
    ~Deque() {}
};

int main() {
    Deque mydeque(3);
    mydeque.push_front(1);
    mydeque.push_back(3);
    cout << mydeque.front() << " " << mydeque.back() << endl;
    cout << mydeque.size();
}
