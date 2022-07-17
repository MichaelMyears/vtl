#pragma once

#include<iosfwd>

namespace vtl
{

    template<typename T>
    class vector
    {
    public:
        vector()
        {
            arr_ = new T[1];
            capacity_ = 1;
        }

        vector(const vector& other)
        {
            if (this != &other)
            {
                delete[] arr_;
                arr_ = new T[other.capacity_];
                for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
                size_ = other.size_;
                capacity_  =other.capacity_;
            }
        }

        vector(vector&& other) noexcept
        {
            if (this != &other)
            {
                delete[] arr_;
                arr_ = other.arr_;
                size_ = other.arr_;
                capacity_ = other.capacity_;
                other.arr_ = nullptr;
                other.size_ = other.capacity_ = 0;
            }
        }

        ~vector()
        {
            delete[] arr_;
        }

        [[nodiscard]] bool isEmpty() const
        {
            return size_ == 0;
        }

        [[nodiscard]] size_t size() const
        {
            return size_;
        }

        [[nodiscard]] size_t capacity() const
        {
            return capacity_;
        }

        void addMemory()
        {
            capacity_ *= 2;
            T* tmp = arr_;
            arr_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
            delete[] tmp;
        }

        void push_back(const T& value)
        {
            if (size_ >= capacity_) addMemory();
            arr_[size_++] = value;
        }

        void erase(size_t index)
        {
            for (size_t i = index + 1; i < size_; ++i) {
                arr_[i - 1] = arr_[i];
            }
            --size_;
        }

        constexpr T* begin() noexcept
        {
            return &arr_[0];
        }

        constexpr const T* begin() const noexcept
        {
            return &arr_[0];
        }

        constexpr T* end()
        {
            return &arr_[size_];
        }

        constexpr const T* end() const noexcept
        {
            return &arr_[size_];
        }

        constexpr T& operator[](size_t index)
        {
            return arr_[index];
        }

        constexpr const T& operator[](size_t index) const
        {
            return arr_[index];
        }

        vector& operator=(vector& other)
        {
            if (this != &other)
            {
                delete[] arr_;
                arr_ = new T[other.capacity_];
                for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
                size_ = other.size_;
                capacity_ = other.capacity_;
            }

            return *this;
        }

        vector& operator=(vector&& other) noexcept
        {
            if (this != &other)
            {
                delete[] arr_;
                arr_ = other.arr_;
                size_ = other.arr_;
                capacity_ = other.capacity_;
                other.arr_ = nullptr;
                other.size_ = other.capacity_ = 0;
            }

            return *this;
        }

    private:
    T* arr_;
    size_t size_{};
    size_t capacity_{};

    };
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const vtl::vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i) os << vec[i] << ' ';
    return os;
}

