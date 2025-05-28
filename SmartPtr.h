#ifndef SMARTPTR_H
#define SMARTPTR_H

#include <utility>  // Для std::exchange

// Шаблон умного указателя, реализующий простое управление ресурсами
// Поддерживает копирование и перемещение (в отличие от std::unique_ptr)
template <class T>
class smart_ptr {
    T* obj;  // Указатель на управляемый объект

public:
    // Конструктор по умолчанию или с передачей указателя
    explicit smart_ptr(T* p = nullptr) : obj(p) {}

    // Копирующий конструктор: создает новый объект копированием
    smart_ptr(const smart_ptr& other)
        : obj(other.obj ? new T(*other.obj) : nullptr) {}

    // Перемещающий конструктор: переносит владение
    smart_ptr(smart_ptr&& other) noexcept
        : obj(std::exchange(other.obj, nullptr)) {}

    // Деструктор: освобождает память
    ~smart_ptr() {
        delete obj;
    }

    // Копирующее присваивание
    smart_ptr& operator=(const smart_ptr& other) {
        if (this != &other) {
            reset(other.obj ? new T(*other.obj) : nullptr);
        }
        return *this;
    }

    // Перемещающее присваивание
    smart_ptr& operator=(smart_ptr&& other) noexcept {
        if (this != &other) {
            reset(std::exchange(other.obj, nullptr));
        }
        return *this;
    }

    // Доступ к объекту
    T* operator->() const { return obj; }
    T& operator*() const { return *obj; }

    // Проверка на наличие объекта
    explicit operator bool() const { return obj != nullptr; }

    // Получить "сырой" указатель
    T* get() const { return obj; }

    // Передать владение наружу
    T* release() {
        T* temp = obj;
        obj = nullptr;
        return temp;
    }

    // Заменить управляемый объект
    void reset(T* p = nullptr) {
        if (obj != p) {
            delete obj;
            obj = p;
        }
    }

    // Обмен содержимым с другим умным указателем
    void swap(smart_ptr& other) noexcept {
        std::swap(obj, other.obj);
    }
};

#endif // SMARTPTR_H
