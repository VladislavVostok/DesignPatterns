#include <string_view>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * ��������� ��������� ��������� ��������, ����� ��� ���� �������������� ������
 * ���������� ���������.
 *
 * �������� ���������� ���� ��������� ��� ������ ���������, ������������
 * ����������� �����������.
 */


class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual string doAlgorithm(string_view data) const = 0;
};

/**
 * �������� ���������� ���������, �������������� ������� ��� ��������.
 */

class Context
{
    /**
     * @var Strategy �������� ������ ������ �� ���� �� �������� ���������.
     * �������� �� ����� ����������� ������ ���������. �� ������ �������� ��
     * ����� ����������� ����� ��������� ���������.
     */
private:
    unique_ptr<Strategy> strategy_;
    /**
     * ������ �������� ��������� ��������� ����� �����������, � �����
     * ������������� ������ ��� � ��������� �� ����� ����������.
     */
public:
    explicit Context(unique_ptr<Strategy>&& strategy = {}) : strategy_(move(strategy))
    {
    }
    /**
     * ������ �������� ��������� �������� ������ ��������� �� ����� ����������.
     */
    void set_strategy(unique_ptr<Strategy>&& strategy)
    {
        strategy_ = move(strategy);
    }
    /**
     * ������ ����, ����� �������������� ������������� ������������� ������
     * ���������, �������� ���������� ��������� ������ ������� ���������.
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
 * ���������� ��������� ��������� ��������, ������ �������� ����������
 * ���������. ���� ��������� ������ �� ����������������� � ���������.
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
 * ���������� ��� �������� ���������� ��������� � ������� � � ��������. ������
 * ������ ����� � ��������� ����� �����������, ����� ������� ���������� �����.
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