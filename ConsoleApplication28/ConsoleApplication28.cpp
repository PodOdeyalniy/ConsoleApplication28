#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Абстрактный класс устройства
class Device {
protected:

    int quantity;

    string color;
public:
    string manufacturer;
    string model;
    double price;
    virtual void printInfo() = 0; // Абстрактный метод печати информации об устройстве
    virtual ~Device() {} // Виртуальный деструктор
};

// Класс Мобильный телефон
class MobilePhone : public Device {
private:
    string operatingSystem;
    int memory;
public:
    MobilePhone(string manufacturer, string model, int quantity, double price, string color, string operatingSystem, int memory) {
        this->manufacturer = manufacturer;
        this->model = model;
        this->quantity = quantity;
        this->price = price;
        this->color = color;
        this->operatingSystem = operatingSystem;
        this->memory = memory;
    }
    void printInfo() {
        cout << "Мобильный телефон" << endl;
        cout << "Производитель: " << manufacturer << endl;
        cout << "Модель: " << model << endl;
        cout << "Количество: " << quantity << endl;
        cout << "Цена: " << price << endl;
        cout << "Цвет: " << color << endl;
        cout << "Операционная система: " << operatingSystem << endl;
        cout << "Память: " << memory << " Гб" << endl;
        cout << endl;
    }

};

// Класс Ноутбук
class Laptop : public Device {
private:
    string cpu;
    int ram;
public:
    Laptop(string manufacturer, string model, int quantity, double price, string color, string cpu, int ram) {
        this->manufacturer = manufacturer;
        this->model = model;
        this->quantity = quantity;
        this->price = price;
        this->color = color;
        this->cpu = cpu;
        this->ram = ram;
    }
    void printInfo() {
        cout << "Ноутбук" << endl;
        cout << "Производитель: " << manufacturer << endl;
        cout << "Модель: " << model << endl;
        cout << "Количество: " << quantity << endl;
        cout << "Цена: " << price << endl;
        cout << "Цвет: " << color << endl;
        cout << "Процессор: " << cpu << endl;
        cout << "Оперативная память: " << ram << " Гб" << endl;
        cout << endl;
    }
};

// Класс Планшет
class Tablet : public Device {
private:
    string os;
    bool hasCamera;
public:
    Tablet(string manufacturer, string model, int quantity, double price, string color, string os, bool hasCamera) {
        this->manufacturer = manufacturer;
        this->model = model;
        this->quantity = quantity;
        this->price = price;
        this->color = color;
        this->os = os;
        this->hasCamera = hasCamera;
    }
    void printInfo() {
        cout << "Планшет" << endl;
        cout << "Производитель: " << manufacturer << endl;
        cout << "Модель: " << model << endl;
        cout << "Количество: " << quantity << endl;
        cout << "Цена: " << price << endl;
        cout << "Цвет: " << color << endl;
        cout << "Операционная система: " << os << endl;
        if (hasCamera) {
            cout << "Камера: есть" << endl;
        }
        else {
            cout << "Камера: нет" << endl;
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Device*> devices; // Список устройств
    int choice = 0;
    while (choice != 5) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить устройство" << endl;
        cout << "2. Удалить устройство" << endl;
        cout << "3. Вывести список устройств" << endl;
        cout << "4. Найти устройство" << endl;
        cout << "5. Выйти" << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Выберите тип устройства:" << endl;
            cout << "1. Мобильный телефон" << endl;
            cout << "2. Ноутбук" << endl;
            cout << "3. Планшет" << endl;
            int typeChoice;
            cin >> typeChoice;
            cout << "Введите производителя:" << endl;
            string manufacturer;
            cin >> manufacturer;
            cout << "Введите модель:" << endl;
            string model;
            cin >> model;
            cout << "Введите количество:" << endl;
            int quantity;
            cin >> quantity;
            cout << "Введите цену:" << endl;
            double price;
            cin >> price;
            cout << "Введите цвет:" << endl;
            string color;
            cin >> color;
            if (typeChoice == 1) {
                cout << "Введите операционную систему:" << endl;
                string operatingSystem;
                cin >> operatingSystem;
                cout << "Введите память:" << endl;
                int memory;
                cin >> memory;
                devices.push_back(new MobilePhone(manufacturer, model, quantity, price, color, operatingSystem, memory));
            }
            else if (typeChoice == 2) {
                cout << "Введите процессор:" << endl;
                string cpu;
                cin >> cpu;
                cout << "Введите оперативную память:" << endl;
                int ram;
                cin >> ram;
                devices.push_back(new Laptop(manufacturer, model, quantity, price, color, cpu, ram));
            }
            else if (typeChoice == 3) {
                cout << "Введите операционную систему:" << endl;
                string os;
                cin >> os;
                cout << "Наличие камеры (1 - есть, 0 - нет):" << endl;
                bool hasCamera;
                cin >> hasCamera;
                devices.push_back(new Tablet(manufacturer, model, quantity, price, color, os, hasCamera));
            }
            else {
                cout << "Неверный выбор" << endl;
            }
            break;
        }
        case 2: {
            cout << "Выберите критерий удаления:" << endl;
            cout << "1. Производитель" << endl;
            cout << "2. Модель" << endl;
            cout << "3. Цена" << endl;
            
            int deleteChoice;
            cin >> deleteChoice;
            string deleteValue;
            cout << "Введите значение:" << endl;
            cin >> deleteValue;
            for (int i = devices.size() - 1; i >= 0; i--) {
                if (deleteChoice == 1 && devices[i]->manufacturer == deleteValue) {
                    devices.erase(devices.begin() + i);
                }
                else if (deleteChoice == 2 && devices[i]->model == deleteValue) {
                    devices.erase(devices.begin() + i);
                }
                else if (deleteChoice == 3 && devices[i]->price == stod(deleteValue)) {
                    devices.erase(devices.begin() + i);
                }
            }
            break;
        }
        case 3: {
            for (int i = 0; i < devices.size(); i++) {
                devices[i]->printInfo();
            }
            break;
        }
        case 4: {
            cout << "Выберите критерий поиска:" << endl;
            cout << "1. Производитель" << endl;
            cout << "2. Модель" << endl;
            cout << "3. Цена" << endl;
            int searchChoice;
            cin >> searchChoice;
            string searchValue;
            cout << "Введите значение:" << endl;
            cin >> searchValue;
            for (int i = 0; i < devices.size(); i++) {
                if (searchChoice == 1 && devices[i]->manufacturer == searchValue) {
                    devices[i]->printInfo();
                }
                else if (searchChoice == 2 && devices[i]->model == searchValue) {
                    devices[i]->printInfo();
                }
                else if (searchChoice == 3 && devices[i]->price == stod(searchValue)) {
                    devices[i]->printInfo();
                }
            }
            break;
        }
        case 5: {
            break;
        }
        default: {
            cout << "Неверный выбор" << endl;
            break;
        }
        }
    }
    return 0;
}