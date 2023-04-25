#include <iostream>

template <typename T>
T swap(T& a, T& b) {
    int temp = a;
    a = b;
    b = temp;
    return a;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    swap(a, b);
    std::cout << a << " " << b;
}
