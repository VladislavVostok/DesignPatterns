#include <iostream>
/**
    Интерфейс Subject объявляет общие операции как для реального субъекта, так и для прокси. 
    Пока клиент работает с RealSubject, используя этот интерфейс, вы сможете передавать ему прокси вместо реального субъекта.
 */
class Subject {
public:
    virtual void Request() const = 0;
};
/**
    Реальный объект содержит некоторую основную бизнес-логику. 
    Обычно RealSubjects способны выполнять некоторую полезную работу, 
    которая также может быть очень медленной или чувствительной - например, 
    исправлять входные данные. Прокси-сервер может решить эти проблемы без 
    каких-либо изменений в коде RealSubject.
 */
class RealSubject : public Subject {
public:
    void Request() const override {
        std::cout << "RealSubject: Handling request.\n";
    }
};
/**
    Прокси имеет интерфейс, идентичный реальному субъекту.
 */
class Proxy : public Subject {
    /**
     * @var RealSubject
     */
private:
    RealSubject* real_subject_;

    bool CheckAccess() const {
        // Здесь должны быть какие-то реальные проверки.
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }
    void LogAccess() const {
        std::cout << "Proxy: Logging the time of request.\n";
    }

    /**
        Прокси поддерживает ссылку на объект класса RealSubject. 
        Он может быть либо загружен с задержкой, либо передан прокси-серверу клиентом.
     */
public:
    Proxy(RealSubject* real_subject) : real_subject_(new RealSubject(*real_subject)) {
    }

    ~Proxy() {
        delete real_subject_;
    }
    /**
        Наиболее распространенными приложениями шаблона прокси-сервера являются отложенная загрузка, 
        кэширование, управление доступом, ведение журнала и т.д. Прокси может выполнить одно из этих действий, 
        а затем, в зависимости от результата, передать выполнение тому же методу в связанном объекте RealSubject.
     */
    void Request() const override {
        if (this->CheckAccess()) {
            this->real_subject_->Request();
            this->LogAccess();
        }
    }
};
/**
    Предполагается, что клиентский код работает со всеми объектами (как субъектами, так и прокси) через интерфейс Subject, 
    чтобы поддерживать как реальные субъекты, так и прокси-серверы.
    Однако в реальной жизни клиенты в основном работают со своими реальными объектами напрямую. 
    В этом случае, чтобы упростить реализацию шаблона, вы можете расширить свой прокси из класса реального субъекта.
 */
void ClientCode(const Subject& subject) {
    // ...
    subject.Request();
    // ...
}

int main() {
    std::cout << "Клиент: Выполнение клиентского кода с реальным субъектом:\n";
    RealSubject* real_subject = new RealSubject;
    ClientCode(*real_subject);
    std::cout << "\n";
    std::cout << "Клиент: Выполнение того же клиентского кода с помощью прокси-сервера:\n";
    Proxy* proxy = new Proxy(real_subject);
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;
    return 0;
}