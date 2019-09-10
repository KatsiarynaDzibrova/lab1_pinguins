#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>


class Deque {
     public:
      // в) Добавьте конструктор, который бы в качестве единственного аргумента
      //    принимал число - максимально возможное количство элементов, одновременно
      //    находящихся в деке. Гарантируется, что max_size > 0.

      explicit Deque(size_t max_size);

      // г) Добавьте методы Size() и MaxSize(), которые бы возвращали текущее и
      //    максимально возможное количество элементов в контейнере соответственно.
      //
      // YOUR_CODE_HERE

      size_t Size() const;
      size_t MaxSize() const;
      // д) Добавьте методы IsEmpty() и IsFull(), которые будут возращать значения
      //    типа bool - "пуст ли контейнер?" и "полностью ли заполнен контейнер?".
      //    Используйте вызовы функций из предыдущего пункта для получения размера.
      //
      // YOUR_CODE_HERE

      bool IsEmpty() const;
      bool IsFull() const;

      // е) Добавьте метод PushBack(int), который бы добавлял элемент в конец дэка
      //    и возвращал true, если это удалось сделать или false, если контейнер
      //    полностью заполнен.
      //
      // YOUR_CODE_HERE

      bool PushBack(int element);
      // ж) Добавьте метод Back(int default_value), который бы возвращал последний
      //    элемент из дэка. Если контейнер пустой, то должно возвращаться
      //    значение 'default_value', если и оно не указано - 0.
      //
      // YOUR_CODE_HERE

      int Back(int default_value = 0) const {
        if (size_ == 0) {
          return default_value;
        } else {
          return data_[(tail_ + MaxSize() - 1) % MaxSize()];
        }
      }
      // е) Добавьте метод PopBack(), который бы удалял последний элемент из дэка
      //    и возвращал true, если это удалось сделать или false, если
      //    контейнер пуст.
      //
      // YOUR_CODE_HERE

      bool PopBack() {
        if (IsEmpty()) {
          return false;
        } else {
          tail_ = (tail_ + MaxSize() - 1) % MaxSize();
          size_--;
          return true;
        }
      }
      //  ж) Добавьте методы PushFront(int), Front(int) и PopFront(), аналогичные
      //     методам выше, но оперирующие с первыми элементами контейнера.
      //
      // YOUR_CODE_HERE
      bool PushFront(int element) {
        if (IsFull()) {
          return false;
        } else {
          head_ = (head_ + MaxSize() - 1) % MaxSize();
          data_[head_] = element;
          size_++;
          return true;
        }
      }

      int Front(int default_value = 0) const {
        if (size_ == 0) return default_value;
        else
          return data_[head_];
      }

      bool PopFront() {
        if (size_ == 0) {
          return false;
        } else {
          head_ = (head_ + 1) % MaxSize();
          size_--;
          return true;
        }
      }

     private:
      // а) Добавьте поле "data_", которое будет хранить элементы.
      //
      //    ВАЖНО! Изменять размер поля "data_" за пределами конструктора
      //           запрещается.
      //
      // YOUR_CODE_HERE

      vector<int> data_;

      // б) Добавьте поля "head_" и "tail_", которое будут хранить позиции в
      //    "data_", соответствующие первому и последнему элементам, а также поле
      //    "size_" - количество элементов.
      //
      // YOUR_CODE_HERE

      size_t head_;
      size_t tail_;
      size_t size_;
    };
}


#endif // DEQUE_H
