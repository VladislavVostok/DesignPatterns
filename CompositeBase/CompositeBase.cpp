// Паттерн Composite (Компоновщик)
#include <iostream>
#include <list>
using namespace std;

class Composite;

// Реализация структуры
class Component
{
protected:

public:
    // Конструктор
    Component()
    { }

    // чисто виртуальная функция
    virtual void Operation() = 0;

    // Метод, добавляющий элемент – не нужно ничего делать
    virtual void Add(Component* _comp) = 0;

    // Удаляет элемент из дерева – это только интерфейс
    virtual void Remove(Component* _comp) = 0;

    // вернуть номер потомка (начиная с 0) - для класса Сomposite
    virtual Component* GetChild(int _child) = 0;

    // Определяет, есть ли компонент составным (Component)
    virtual Composite* GetComposite()
    {
        return nullptr;
    }
};

// Класс Composite - может иметь потомков
class Composite :public Component
{
private:
    // Список потомков
    list<Component*> L;

public:
    // Конструктор - не сохраняет данные
    Composite() : Component()
    {
        L.clear();
    }

    // Здесь необязательная операция
    void Operation() override
    {
        cout << "Composite::Operation()" << endl;
    }

    // Добавить компонент в список
    void Add(Component* _comp) override
    {
        L.push_back(_comp);
    }

    // Удаление компонента
    void Remove(Component* _comp)
    {
        // Объявить итератор на список L
        list<Component*>::iterator it = L.begin();

        // Поиск элемента _comp
        while (it != L.end())
        {
            if (*it == _comp)
                break;
            it++;
        }

        // Удалить элемент, если он есть
        if (it != L.end())
        {
            L.erase(it);
        }
    }

    // Возвращает текущий компонент
    Composite* GetComposite() override
    {
        return this;
    }

    // Отобразить список потомков
    void PrintChild()
    {
        list<Component*>::iterator it = L.begin();
        while (it != L.end())
        {
            (*it)->Operation();
            it++;
        }
    }

    // Повернуть компонент по его номеру в узле,
    // номер начинается с 0
    Component* GetChild(int _child) override
    {
        list<Component*>::iterator it = L.begin();
        int i = 0;
        while ((i < _child) && (it != L.end()))
        {
            i++;
            it++;
        }
        return *it;
    }
};

// Класс Лист - нету потомков
class Leaf : public Component
{
private:
    // Данные класса Leaf
    string data;

public:
    // Конструктор
    Leaf(string _data) : data(_data) { }

    void Operation() override
    {
        cout << "Leaf.data = " << data << endl;
    }

private:
    // Скрыть методы Add(), Remove()
    // здесь не нужно ничего делать
    void Add(Component* _comp) override
    { };

    // здесь также не нужно ничего делать
    void Remove(Component* _comp) override
    { };

    // здесь не обязательно что то делать
    Component* GetChild(int _child) override
    {
        return nullptr;
    }
};

void main()
{
    /*
    Создать дерево
    Composite1 -----> Leaf1
                 |
                 |--> Composite2 --> Leaf2
                 |               |
                 |              --> Leaf3
                 |
                 ---> Leaf4
    */

    // Клиент
    Component* client = nullptr;

    // Создать верхний узел
    Component* composite1 = new Composite;

    // Создать листки Leaf1, Leaf2, Leaf3, Leaf4
    Leaf* leaf1 = new Leaf("Leaf1");
    Leaf* leaf2 = new Leaf("Leaf2");
    Leaf* leaf3 = new Leaf("Leaf3");
    Leaf* leaf4 = new Leaf("Leaf4");

    // Создать промежуточный узел
    Composite* composite2 = new Composite;

    // Добавить верхнюю ветвь
    composite1->Add(leaf1);

    // Создать среднюю ветвь
    composite2->Add(leaf2);
    composite2->Add(leaf3);

    // Добавить среднюю ветвь
    composite1->Add(composite2);

    // Добавить нижнюю ветвь
    composite1->Add(leaf4);

    // Установить клиента на composite1
    client = composite1;

    // Отобразить уровень composite1
    ((Composite*)client)->PrintChild();

    // Отобразить уровень composite2
    cout << "------------------" << endl;
    ((Composite*)composite2)->PrintChild();

    // Удалить ветви leaf2 и leaf4 и опять отобразить дерево
    composite1->Remove(leaf4);
    composite2->Remove(leaf2);

    cout << "-------------------------" << endl;
    cout << "-------------------------" << endl;

    ((Composite*)composite1)->PrintChild();
    cout << "-------------------------" << endl;
    composite2->PrintChild();

    // --------------------------------------
    // Исследование метода GetComposite()
    Component* resComposite = leaf1->GetComposite();

    if (resComposite != nullptr)
        cout << "leaf1 => Composite" << endl;
    else
        cout << "leaf1 => Leaf" << endl;

    resComposite = composite2->GetComposite();
    if (resComposite)
        cout << "composite1 => Composite" << endl;
    else
        cout << "composite1 => Leaf" << endl;

    // ----------------------------------------
    // Освободить память под все компоненты
    if (leaf1) delete leaf1;
    if (leaf2) delete leaf2;
    if (leaf3) delete leaf3;
    if (leaf4) delete leaf4;

    if (composite1) delete composite1;
    if (composite2) delete composite2;
}