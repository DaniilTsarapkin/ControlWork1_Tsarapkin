#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Contact {
    std::string name;
    std::string phone;
};

typedef void (*ContactFunc)(std::vector<Contact>&);

void add(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Введите имя: ";
    std::cin >> newContact.name;
    std::cout << "Введите номер телефона: ";
    std::cin >> newContact.phone;
    contacts.push_back(newContact);
    std::cout << "Контакт успешно добавлен.\n";
}

void del(std::vector<Contact>& contacts) {
    std::string nametodel;
    std::cout << "Введите имя контакта для удаления: ";
    std::cin >> nametodel;

    auto it = std::remove_if(contacts.begin(), contacts.end(),
        [nametodel](const Contact& contact) { return contact.name == nametodel; });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        std::cout << "Контакт успешно удален.\n";
    } else {
        std::cout << "Контакт не найден.\n";
    }
}

void update(std::vector<Contact>& contacts) {
    std::string nametoup;
    std::cout << "Введите имя контакта для обновления: ";
    std::cin >> nametoup;

    auto it = std::find_if(contacts.begin(), contacts.end(),
        [nametoup](const Contact& contact) { return contact.name == nametoup; });

    if (it != contacts.end()) {
        std::cout << "Введите новый номер телефона: ";
        std::cin >> it->phone;
        std::cout << "Информация о контакте успешно обновлена.\n";
    } else {
        std::cout << "Контакт не найден.\n";
    }
}

void show(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "Список контактов пуст.\n";
    } else {
        std::cout << "Список контактов:\n";
        for (const auto& contact : contacts) {
            std::cout << "Имя: " << contact.name << ", Номер телефона: " << contact.phone << "\n";
        }
    }
}

int main() {
    std::vector<Contact> contacts;
    ContactFunc contactFunc;

    while (true) {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Добавить контакт\n";
        std::cout << "2. Удалить контакт\n";
        std::cout << "3. Обновить контакт\n";
        std::cout << "4. Вывести все контакты\n";
        std::cout << "5. Выход\n";

        int choice;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                contactFunc = add;
                break;
            case 2:
                contactFunc = del;
                break;
            case 3:
                contactFunc = update;
                break;
            case 4:
                contactFunc = show;
                break;
            case 5:
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                continue;
        }

        contactFunc(contacts);
    }

    return 0;
}
