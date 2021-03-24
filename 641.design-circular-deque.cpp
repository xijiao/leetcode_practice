/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
class MyCircularDeque {
    vector<int> _data;
    int _start;
    int _count;
    int _size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        _start = 0;
        _count = 0;
        _size = k;
        _data.resize(k);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (_count >= _size) return false;
        _start = (_start + _size - 1) % _size;
        _count++;
        _data[_start] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (_count >= _size) return false;
        _data[(_start + _count) % _size] = value;
        _count++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (_count == 0) return false;
        _start = (_start + 1) % _size;
        _count--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (_count == 0) return false;
        _count--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (_count == 0) return -1; 
        return _data[_start];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (_count == 0) return -1; 
        return _data[(_start + _count - 1) % _size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return _count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return _count == _size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

