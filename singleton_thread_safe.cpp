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
    static Singleton* object;
    Singleton() = default;
    ~Singleton() = default;

    // forbid copy and assignment
    static std::mutex mtx; // the mutex is for creation lock
    Singleton(const Singleton &) = delete;
    Singleton operator=(const Singleton &) = delete;

    class GarbageCollector {
    public:
        ~GarbageCollector() {
            if (Singleton::object != nullptr) {
                delete Singleton::object;
                Singleton::object = nullptr;
            }
        }
    };
    static GarbageCollector gc;

    std::atomic<int> val;
};

Singleton* Singleton::object = nullptr;
Singleton::GarbageCollector Singleton::gc;

Singleton& Singleton::GetInstance()
{
    if (Singleton::object == nullptr) {
        std::lock_guard lock(Singleton::mtx);
        if (Singleton::object == nullptr) {
            object = new Singleton();
        }
    }
    return *object;
}

int Singleton::Read() const {
    return val;
}

void Singleton::Write(int v) {
    val = v;
}