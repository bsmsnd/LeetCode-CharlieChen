/* 基于 pull model 实现观察者模式 */
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
class ISubject;

class IObserver {
public:
    virtual ~IObserver() = default; // 为多态基类添加虚析构函数
    virtual void Update(ISubject& subject) = 0;
};

class ISubject {
public:
    virtual ~ISubject() = default; // 为多态基类添加虚析构函数
    virtual size_t Attach(std::shared_ptr<IObserver> observer) = 0;
    virtual size_t Detach(std::shared_ptr<IObserver> observer) = 0;
    virtual void Notify() = 0;
    virtual int GetState() = 0;
};

class NewsAgency : public ISubject {
public:
    size_t Attach(std::shared_ptr<IObserver> observer) override;
    size_t Detach(std::shared_ptr<IObserver> observer) override;
    void Notify() override;
    int GetState() override;
private:
    std::vector<std::weak_ptr<IObserver>> subscribers;
};

class ActiveSubscriber : public IObserver {
public:
    void Update(ISubject& subject) override
    {
        std::cout << "ActiveSubscriber updated! " << std::endl;
        std::cout << subject.GetState() << std::endl;
    }
};

class LazySubscriber : public IObserver {
public:
    void Update(ISubject& subject) override
    {
        std::cout << "LazySubscriber updated! " << std::endl;
        std::cout << subject.GetState() << std::endl;
    }
};

size_t NewsAgency::Attach(std::shared_ptr<IObserver> observer)
{
    if (observer.get() != nullptr) {
        subscribers.emplace_back(observer);
    }
    return subscribers.size();
}

size_t NewsAgency::Detach(std::shared_ptr<IObserver> observer) {
    if (observer.get() != nullptr) {
        subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(),
            [&observer](const std::weak_ptr<IObserver> item) {
                    // Remove the observer if it matches, or if it has expired.
                    return item.expired() || item.lock() == observer;
                }
            ), subscribers.end());
    }
    return subscribers.size();
}

void NewsAgency::Notify()
{
    for (auto &item : subscribers) {
        if (!item.expired()) {
            std::shared_ptr shared_observer = item.lock();
            if (shared_observer != nullptr) {
                shared_observer->Update(*this);
            }
        }
    }
}

int NewsAgency::GetState() { return 0; }
