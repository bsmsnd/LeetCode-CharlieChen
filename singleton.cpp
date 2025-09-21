#include <cstdint>
using namespace std;

constexpr uint32_t OPERATION_OK = 0;
constexpr uint32_t OPERATION_CREATE_FAILURE = 1;
constexpr uint32_t OPERATION_OBJECT_ALREADY_EXIST = 2;

class Singleton {
public:
    static Singleton& GetInstance();
private:
    static Singleton* object;
    Singleton() = default;
    ~Singleton() = default;

    // forbid copy and assignment
    Singleton(const Singleton &) = delete;
    Singleton operator=(const Singleton &) = delete;
    uint32_t Create();

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
};

Singleton* Singleton::object = nullptr;
Singleton::GarbageCollector Singleton::gc;

Singleton& Singleton::GetInstance()
{
    Create();
    return *object;
}

uint32_t Singleton::Create()
{
    if (object != nullptr) {
        return OPERATION_OBJECT_ALREADY_EXIST;
    }
    object = new Singleton();
    return OPERATION_OK;
}
