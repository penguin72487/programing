#include <iostream>
#include <queue>
#include <vector>

class Class {
public:
    int a, b, c;
    Class(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

int main() {
    auto comp = [](const Class& lhs, const Class& rhs) {
        if (lhs.b != rhs.b) return lhs.b > rhs.b;  // 按b的升序排序
        if (lhs.a != rhs.a) return lhs.a > rhs.a;  // 如果b相同，則按a的升序排序
        return lhs.c > rhs.c;                      // 如果a和b都相同，則按c的升序排序
    };

    std::priority_queue<Class, std::vector<Class>, decltype(comp)> pq(comp);

    // 添加元素到priority_queue
    pq.push(Class(1, 2, 3));
    pq.push(Class(1, 2, 2));
    pq.push(Class(1, 1, 3));

    // 打印元素
    while (!pq.empty()) {
        Class obj = pq.top();
        pq.pop();
        std::cout << "a: " << obj.a << ", b: " << obj.b << ", c: " << obj.c << std::endl;
    }

    return 0;
}
