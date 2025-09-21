#include <cstdint>
#include <atomic>
#include <mutex>

constexpr uint32_t OPERATION_OK = 0;
constexpr uint32_t OPERATION_CREATE_FAILURE = 1;
constexpr uint32_t OPERATION_OBJECT_ALREADY_EXIST = 2;

class Singleton {
public:
    static Singleton& GetInstance();
    void Write(int v);
    int Read() const;
private:
    Singleton() = default;
    ~Singleton() = default;

    // forbid copy and assignment
    Singleton(const Singleton &) = delete;
    Singleton& operator=(const Singleton &) = delete;

    std::atomic<int> val;
};

Singleton& Singleton::GetInstance()
{
    static Singleton object;
    return object;
}

int Singleton::Read() const {
    return val.load(std::memory_order_relaxed);
}

void Singleton::Write(int v) {
    val.store(v, std::memory_order_relaxed);
}