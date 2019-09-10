#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#inc

class Queue
{
public:
     // б) Содайте конструктор, принимающий параметр max_size и инициадизирующий с
     //    помощью него поле типа Deque.

     explicit Queue(size_t max_size);
     // в) Создайте методы Push(value), Front(default_value) и Pop(), которые
     //    реализовывали бы основной функционал данной структуры данных.

     bool Push(int value);

     int Front(int default_value = 0) const {
       return data_.Front(default_value);
     }

     bool Pop() {
       return data_.PopFront();
     }


     // г) Создайте методе Size(), MaxSize(), IsEmpty() и IsFull(), аналогичные по
     //    поведению созданным методам для класса Deque.
     //
     // YOUR_CODE_HERE

     size_t Size() const {
       return data_.Size();
     }
     size_t MaxSize() const {
       return data_.MaxSize();
     }
     bool IsEmpty() const {
       return data_.IsEmpty();
     }
     bool IsFull() const {
       return data_.IsFull();
     }

    private:
     // a) Содайте поле типа Deque, в котором будут храниться значения.
     //
     // YOUR_CODE_HERE
     Deque data_;
   };

   // ----------------------------------------------------------------------------
   //
   //          Задание № 3: Класс Stack (стек, a.k.a. First-In-Last-Out).
   //
   class Stack {
    public:
     // б) Содайте конструктор, принимающий параметр max_size и инициадизирующий с
     //    помощью него поле типа Deque.
     //
     // YOUR_CODE_HERE

     explicit Stack(size_t max_size) : data_(max_size) {}

     // в) Создайте методы Push(value), Top(default_value) и Pop(), которые
     //    реализовывали бы основной функционал данной структуры данных.
     //
     // YOUR_CODE_HERE

     int Push(int value) {
       return data_.PushFront(value);
     }
     int Top(int default_value = 0) const {
       return data_.Front(default_value);
     }
     bool Pop() {
       return data_.PopFront();
     }

     // г) Создайте методе Size(), MaxSize(), IsEmpty() и IsFull(), аналогичные по
     //    поведению созданным методам для класса Deque.
     //
     // YOUR_CODE_HERE

     size_t Size() const {
       return data_.Size();
     }
     size_t MaxSize() const {
       return data_.MaxSize();
     }
     bool IsEmpty() const {
       return data_.IsEmpty();
     }
     bool IsFull() const {
       return data_.IsFull();
     }

    private:
     // a) Содайте поле типа Deque, в котором будут храниться значения.
     //
     // YOUR_CODE_HERE

     Deque data_;
};

#endif // QUEUE_H
