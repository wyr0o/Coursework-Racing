#include <iostream>
#include "Transport.h"
#include "Race.h"
#include "TransportFactory.h"

void showRaceTypeMenu();
void showTransportMenu(const Race& race);
void registerTransport(Race& race);

int main() {
    setlocale(LC_ALL, "Russian");

    while (true) {
        showRaceTypeMenu();
        int raceType;
        std::cin >> raceType;

        if (raceType < 1 || raceType > 3) {
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            continue;
        }

        double distance;
        do {
            std::cout << "Укажите длину дистанции (должна быть положительна): ";
            std::cin >> distance;
            if (distance <= 0) {
                std::cout << "Дистанция должна быть положительной!\n";
            }
        } while (distance <= 0);

        Race race(distance, raceType != 2, raceType != 1);

        while (true) {
            std::cout << "\n1. Зарегистрировать транспорт\n";
            if (race.getTransportCount() >= 2) {
                std::cout << "2. Начать гонку\n";
            }
            std::cout << "Выберите действие: ";

            int action;
            std::cin >> action;

            if (action == 1) {
                registerTransport(race);
            }
            else if (action == 2 && race.getTransportCount() >= 2) {
                race.runRace();
                break;
            }
            else {
                std::cout << "Некорректный выбор или недостаточно транспортных средств.\n";
            }
        }

        std::cout << "\n1. Провести ещё одну гонку\n2. Выйти\nВыберите действие: ";
        int choice;
        std::cin >> choice;
        if (choice == 2) break;
    }

    return 0;
}

void showRaceTypeMenu() {
    std::cout << "Добро пожаловать в гоночный симулятор!\n";
    std::cout << "1. Гонка для наземного транспорта\n";
    std::cout << "2. Гонка для воздушного транспорта\n";
    std::cout << "3. Гонка для наземного и воздушного транспорта\n";
    std::cout << "Выберите тип гонки: ";
}

void registerTransport(Race& race) {
    while (true) {
        showTransportMenu(race);

        int choice;
        std::cin >> choice;

        if (choice == 0 || choice == 8) break;

        Transport* transport = TransportFactory::createTransport(choice);
        if (!transport) {
            std::cout << "Некорректный выбор транспорта.\n";
            continue;
        }

        if (!race.canAddTransport(transport)) {
            bool alreadyRegistered = false;
            for (int i = 0; i < race.getTransportCount(); ++i) {
                if (race.getTransport(i)->getName() == transport->getName()) {
                    alreadyRegistered = true;
                    break;
                }
            }

            if (alreadyRegistered) {
                std::cout << transport->getName() << " уже зарегистрирован!\n";
            }
            else {
                std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
            }
            delete transport;
            continue;
        }

        race.addTransport(transport);
        std::cout << transport->getName() << " успешно зарегистрирован!\n";
    }
}

void showTransportMenu(const Race& race) {
    std::cout << "\nГонка для ";
    if (race.isGroundRace() && race.isAirRace()) {
        std::cout << "наземного и воздушного транспорта";
    }
    else if (race.isGroundRace()) {
        std::cout << "наземного транспорта";
    }
    else {
        std::cout << "воздушного транспорта";
    }
    std::cout << ". Расстояние: " << race.getDistance() << "\n";

    if (race.getTransportCount() > 0) {
        std::cout << "Зарегистрированные транспортные средства: ";
        for (int i = 0; i < race.getTransportCount(); ++i) {
            if (i != 0) std::cout << ", ";
            std::cout << race.getTransport(i)->getName();
        }
        std::cout << "\n";
    }

    std::cout << "1. Ботинки-вездеходы\n";
    std::cout << "2. Метла\n";
    std::cout << "3. Верблюд\n";
    std::cout << "4. Кентавр\n";
    std::cout << "5. Орёл\n";
    std::cout << "6. Верблюд-быстроход\n";
    std::cout << "7. Ковёр-самолёт\n";
    std::cout << "8. Закончить регистрацию\n";
    std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
}