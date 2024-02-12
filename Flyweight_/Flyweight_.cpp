/**
 *  Flyweight Design Pattern
    Назначение: Позволяет вместить больше объектов в доступный объем оперативной 
    памяти за счет совместного использования общих частей состояния между 
    несколькими объектами вместо сохранения всех данных в каждом объекте.
 */

#include <iostream>
#include <map>
#include<unordered_map>

using namespace std;

struct SharedState
{
    string brand_;
    string model_;
    string color_;

    SharedState(const string& brand, const string& model, const string& color)
        : brand_(brand), model_(model), color_(color)
    {
    }

    friend ostream& operator<<(ostream& os, const SharedState& ss)
    {
        return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
    }
};

struct UniqueState
{
    string owner_;
    string plates_;

    UniqueState(const string& owner, const string& plates)
        : owner_(owner), plates_(plates)
    {
    }

    friend ostream& operator<<(ostream& os, const UniqueState& us)
    {
        return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
    }
};

/**
  Преспособленец хранит общую часть состояния (также называемую внутренним состоянием), 
  которая принадлежит нескольким реальным бизнес-объектам. Промежуточный вес принимает остальную часть 
  состояния (внешнее состояние, уникальное для каждого объекта) через параметры своего метода.
 */
class Flyweight
{
private:
    SharedState* shared_state_;

public:
    Flyweight(const SharedState* shared_state) : shared_state_(new SharedState(*shared_state))
    {
    }
    Flyweight(const Flyweight& other) : shared_state_(new SharedState(*other.shared_state_))
    {
    }
    ~Flyweight()
    {
        delete shared_state_;
    }
    SharedState* shared_state() const
    {
        return shared_state_;
    }
    void Operation(const UniqueState& unique_state) const
    {
        cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state << ") state.\n";
    }
};
/**
    FlyweightFactory создает объекты Flyweight и управляет ими. 
    Это гарантирует корректное распределение flyweight. 
    Когда клиент запрашивает flyweight, фабрика либо возвращает 
    существующий экземпляр, либо создает новый, если он еще не существует.
 */

class FlyweightFactory
{
    /**
     * @var Flyweight[]
     */
private:
    unordered_map<string, Flyweight> flyweights_;
    /**
     * Возвращает хэш строки Flyweights для данного состояния.
     */
    string GetKey(const SharedState& ss) const
    {
        return ss.brand_ + "_" + ss.model_ + "_" + ss.color_;
    }

public:
    FlyweightFactory(initializer_list<SharedState> share_states)
    {
        for (const SharedState& ss : share_states)
        {
            this->flyweights_.insert(make_pair<string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
        }
    }

    /**
     * Возвращает существующий балансир с заданным состоянием или создает новый.
     */
    Flyweight GetFlyweight(const SharedState& shared_state)
    {
        string key = this->GetKey(shared_state);
        if (this->flyweights_.find(key) == this->flyweights_.end())
        {
            cout << "FlyweightFactory: Не удается найти flyweight, создаю новый.\n";
            this->flyweights_.insert(make_pair(key, Flyweight(&shared_state)));
        }
        else
        {
            cout << "FlyweightFactory: Повторное использование существующего FlyweightFactory.\n";
        }
        return this->flyweights_.at(key);
    }
    void ListFlyweights() const
    {
        size_t count = this->flyweights_.size();
        cout << "\nFlyweightFactory: У меня есть " << count << " flyweights:\n";
        for (pair<string, Flyweight> pair : this->flyweights_)
        {
            cout << pair.first << "\n";
        }
    }
};

// ...
void AddCarToPoliceDatabase(
    FlyweightFactory& ff, const string& plates, const string& owner,
    const string& brand, const string& model, const string& color)
{
    cout << "\nClient: Adding a car to database.\n";
    const Flyweight& flyweight = ff.GetFlyweight({ brand, model, color });
    // Клиентский код либо сохраняет, либо вычисляет внешнее состояние и передает его методам flyweights.
    flyweight.Operation({ owner, plates });
}

/**
 * Клиентский код обычно создает набор предварительно заполненных 
   промежуточных значений на этапе инициализации приложения.
 */

int main()
{
    FlyweightFactory* factory = new FlyweightFactory({ 

            {"Chevrolet", "Camaro2018", "pink"}, 
            {"Mercedes Benz", "C300", "black"}, 
            {"Mercedes Benz", "C500", "red"}, 
            {"BMW", "M5", "red"}, 
            {"BMW", "X6", "white"} 

        });
    factory->ListFlyweights();

    AddCarToPoliceDatabase(*factory,
        "CL234IR",
        "James Doe",
        "BMW",
        "M5",
        "red");

    AddCarToPoliceDatabase(*factory,
        "CL234IR",
        "James Doe",
        "BMW",
        "X1",
        "red");
    factory->ListFlyweights();
    delete factory;

    return 0;
}