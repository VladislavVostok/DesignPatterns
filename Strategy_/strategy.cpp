#include <string_view>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * Интерфейс Стратегии объявляет операции, общие для всех поддерживаемых версий
 * некоторого алгоритма.
 *
 * Контекст использует этот интерфейс для вызова алгоритма, определённого
 * Конкретными Стратегиями.
 */


class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual string doAlgorithm(string_view data) const = 0;
};

/**
 * Контекст определяет интерфейс, представляющий интерес для клиентов.
 */

class Context
{
    /**
     * @var Strategy Контекст хранит ссылку на один из объектов Стратегии.
     * Контекст не знает конкретного класса стратегии. Он должен работать со
     * всеми стратегиями через интерфейс Стратегии.
     */
private:
    unique_ptr<Strategy> strategy_;
    /**
     * Обычно Контекст принимает стратегию через конструктор, а также
     * предоставляет сеттер для её изменения во время выполнения.
     */
public:
    explicit Context(unique_ptr<Strategy>&& strategy = {}) : strategy_(move(strategy))
    {
    }
    /**
     * Обычно Контекст позволяет заменить объект Стратегии во время выполнения.
     */
    void set_strategy(unique_ptr<Strategy>&& strategy)
    {
        strategy_ = move(strategy);
    }
    /**
     * Вместо того, чтобы самостоятельно реализовывать множественные версии
     * алгоритма, Контекст делегирует некоторую работу объекту Стратегии.
     */
    void doSomeBusinessLogic() const
    {
        if (strategy_) {
            cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
            string result = strategy_->doAlgorithm("aecbd");
            cout << result << "\n";
        }
        else {
            cout << "Context: Strategy isn't set\n";
        }
    }
};

/**
 * Конкретные Стратегии реализуют алгоритм, следуя базовому интерфейсу
 * Стратегии. Этот интерфейс делает их взаимозаменяемыми в Контексте.
 */
class ConcreteStrategyA : public Strategy
{
public:
    string doAlgorithm(string_view data) const override
    {
        string result(data);
        sort(begin(result), end(result));

        return result;
    }
};
class ConcreteStrategyB : public Strategy
{
    string doAlgorithm(string_view data) const override
    {
        string result(data);
        sort(begin(result), end(result), greater<>());

        return result;
    }
};
/**
 * Клиентский код выбирает конкретную стратегию и передаёт её в контекст. Клиент
 * должен знать о различиях между стратегиями, чтобы сделать правильный выбор.
 */

void clientCode()
{
    Context context(make_unique<ConcreteStrategyA>());
    cout << "Client: Strategy is set to normal sorting.\n";
    context.doSomeBusinessLogic();
    cout << "\n";
    cout << "Client: Strategy is set to reverse sorting.\n";
    context.set_strategy(make_unique<ConcreteStrategyB>());
    context.doSomeBusinessLogic();
}

int main()
{
    clientCode();
    return 0;
}