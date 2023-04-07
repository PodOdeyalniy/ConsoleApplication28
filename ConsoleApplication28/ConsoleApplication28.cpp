#include<iostream>
#include<vector>
#include<string>

using namespace std;

// ����������� ����� ����������
class Device {
protected:

    int quantity;

    string color;
public:
    string manufacturer;
    string model;
    double price;
    virtual void printInfo() = 0; // ����������� ����� ������ ���������� �� ����������
    virtual ~Device() {} // ����������� ����������
};

// ����� ��������� �������
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
        cout << "��������� �������" << endl;
        cout << "�������������: " << manufacturer << endl;
        cout << "������: " << model << endl;
        cout << "����������: " << quantity << endl;
        cout << "����: " << price << endl;
        cout << "����: " << color << endl;
        cout << "������������ �������: " << operatingSystem << endl;
        cout << "������: " << memory << " ��" << endl;
        cout << endl;
    }

};

// ����� �������
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
        cout << "�������" << endl;
        cout << "�������������: " << manufacturer << endl;
        cout << "������: " << model << endl;
        cout << "����������: " << quantity << endl;
        cout << "����: " << price << endl;
        cout << "����: " << color << endl;
        cout << "���������: " << cpu << endl;
        cout << "����������� ������: " << ram << " ��" << endl;
        cout << endl;
    }
};

// ����� �������
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
        cout << "�������" << endl;
        cout << "�������������: " << manufacturer << endl;
        cout << "������: " << model << endl;
        cout << "����������: " << quantity << endl;
        cout << "����: " << price << endl;
        cout << "����: " << color << endl;
        cout << "������������ �������: " << os << endl;
        if (hasCamera) {
            cout << "������: ����" << endl;
        }
        else {
            cout << "������: ���" << endl;
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Device*> devices; // ������ ���������
    int choice = 0;
    while (choice != 5) {
        cout << "�������� ��������:" << endl;
        cout << "1. �������� ����������" << endl;
        cout << "2. ������� ����������" << endl;
        cout << "3. ������� ������ ���������" << endl;
        cout << "4. ����� ����������" << endl;
        cout << "5. �����" << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "�������� ��� ����������:" << endl;
            cout << "1. ��������� �������" << endl;
            cout << "2. �������" << endl;
            cout << "3. �������" << endl;
            int typeChoice;
            cin >> typeChoice;
            cout << "������� �������������:" << endl;
            string manufacturer;
            cin >> manufacturer;
            cout << "������� ������:" << endl;
            string model;
            cin >> model;
            cout << "������� ����������:" << endl;
            int quantity;
            cin >> quantity;
            cout << "������� ����:" << endl;
            double price;
            cin >> price;
            cout << "������� ����:" << endl;
            string color;
            cin >> color;
            if (typeChoice == 1) {
                cout << "������� ������������ �������:" << endl;
                string operatingSystem;
                cin >> operatingSystem;
                cout << "������� ������:" << endl;
                int memory;
                cin >> memory;
                devices.push_back(new MobilePhone(manufacturer, model, quantity, price, color, operatingSystem, memory));
            }
            else if (typeChoice == 2) {
                cout << "������� ���������:" << endl;
                string cpu;
                cin >> cpu;
                cout << "������� ����������� ������:" << endl;
                int ram;
                cin >> ram;
                devices.push_back(new Laptop(manufacturer, model, quantity, price, color, cpu, ram));
            }
            else if (typeChoice == 3) {
                cout << "������� ������������ �������:" << endl;
                string os;
                cin >> os;
                cout << "������� ������ (1 - ����, 0 - ���):" << endl;
                bool hasCamera;
                cin >> hasCamera;
                devices.push_back(new Tablet(manufacturer, model, quantity, price, color, os, hasCamera));
            }
            else {
                cout << "�������� �����" << endl;
            }
            break;
        }
        case 2: {
            cout << "�������� �������� ��������:" << endl;
            cout << "1. �������������" << endl;
            cout << "2. ������" << endl;
            cout << "3. ����" << endl;
            
            int deleteChoice;
            cin >> deleteChoice;
            string deleteValue;
            cout << "������� ��������:" << endl;
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
            cout << "�������� �������� ������:" << endl;
            cout << "1. �������������" << endl;
            cout << "2. ������" << endl;
            cout << "3. ����" << endl;
            int searchChoice;
            cin >> searchChoice;
            string searchValue;
            cout << "������� ��������:" << endl;
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
            cout << "�������� �����" << endl;
            break;
        }
        }
    }
    return 0;
}