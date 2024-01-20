#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <limits>

class Customer {
protected:
    std::string name;
    int age;
public:
    Customer(std::string name, int age) : name(name), age(age) {}
        
    std::string getName() const {
        return name;
    }

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    virtual void displayDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

class Member : public Customer {
private:
    int membershipNumber;
public:
    Member(std::string name, int age, int membershipNumber) : Customer(name, age), membershipNumber(membershipNumber) {}

    void displayDetails() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Membership Number: " << membershipNumber << std::endl;
    }
};

class Guest : public Customer {
private:
    std::string contactNumber;
public:
    Guest(std::string name, int age, std::string contactNumber) : Customer(name, age), contactNumber(contactNumber) {}

    void displayDetails() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Contact Number: " << contactNumber << std::endl;
    }
};

class VIP : public Customer {
private:
    std::string email;
public:
    VIP(std::string name, int age, std::string email) : Customer(name, age), email(email) {}

    void displayDetails() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Email: " << email << std::endl;
    }
};

class CustomerManager {
private:
    std::vector<Customer*> customers;
    std::string historyFile = "registration_history.txt";

    void saveRegistrationHistory(const std::string& details) {
        std::ofstream outFile(historyFile, std::ios::app);
        if (outFile.is_open()) {
            outFile << details << std::endl;
            outFile.close();
        } else {
            std::cout << "Failed to save registration history." << std::endl;
        }
    }

public:
    ~CustomerManager() {
        for (const auto& customer : customers) {
            delete customer;
        }
    }

    void loadCustomersFromFile() {
        std::ifstream inFile(historyFile);
        if (inFile.is_open()) {
            std::string line;
            while (std::getline(inFile, line)) {
                std::cout << line << std::endl;
            }
            inFile.close();
        } else {
            std::cout << "Failed to open registration history file." << std::endl;
        }
    }

    void addCustomer(Customer* customer) {
        customers.push_back(customer);
        std::string details = "Name: " + customer->getName();
        saveRegistrationHistory(details);
    }

    void displayCustomers() {
        std::cout << "Customer List:" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << std::setw(5) << "Index" << std::setw(20) << "Name" << std::endl;
        std::cout << "---------------------------------------" << std::endl;

        int index = 1;
        for (const auto& customer : customers) {
            std::cout << std::setw(5) << index << std::setw(20) << customer->getName() << std::endl;
            index++;
        }
        
        std::cout << "---------------------------------------" << std::endl;
    }

    void displayCustomerDetails(int customerIndex) {
        if (customerIndex > 0 && customerIndex <= customers.size()) {
            std::cout << "Customer Details:" << std::endl;
            std::cout << "---------------------------------------" << std::endl;
            customers[customerIndex - 1]->displayDetails();
            std::cout << "---------------------------------------" << std::endl;
        } else {
            std::cout << "Invalid customer index!" << std::endl;
        }
    }


    void editCustomerDetails(int customerIndex) {
        if (customerIndex > 0 && customerIndex <= customers.size()) {
            Customer* customer = customers[customerIndex - 1];
            std::cout << "Edit Customer Details" << std::endl;
            std::cout << "---------------------------------------" << std::endl;
            std::cout << "Name: " << customer->getName() << std::endl;
            std::cout << "Age: " << customer->getAge() << std::endl;
            std::cout << "1. Edit Name" << std::endl;
            std::cout << "2. Edit Age" << std::endl;
            std::cout << "Enter option: ";
            int option;
            std::cin >> option;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (option) {
                case 1: {
                    std::cout << "Enter new name: ";
                    std::string newName;
                    std::getline(std::cin, newName);
                    customer->setName(newName);
                    std::cout << "Name updated successfully." << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "Enter new age: ";
                    int newAge;
                    std::cin >> newAge;
                    customer->setAge(newAge);
                    std::cout << "Age updated successfully." << std::endl;
                    break;
                }
                default:
                    std::cout << "Invalid option." << std::endl;
                    break;
            }
        } else {
            std::cout << "Invalid customer index!" << std::endl;
        }
    }

    void deleteCustomer(int customerIndex) {
        if (customerIndex > 0 && customerIndex <= customers.size()) {
            Customer* customer = customers[customerIndex - 1];
            std::string details = "Deleted customer: " + customer->getName();
            saveRegistrationHistory(details);
            delete customer;
            customers.erase(customers.begin() + (customerIndex - 1));
            std::cout << "Customer deleted successfully." << std::endl;
        } else {
            std::cout << "Invalid customer index!" << std::endl;
        }
    }

    void displayMenu() {
        std::cout << "Menu:" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "1. Display Customers" << std::endl;
        std::cout << "2. Display Customer Details" << std::endl;
        std::cout << "3. Add Customer" << std::endl;
        std::cout << "4. Edit Customer Details" << std::endl;
        std::cout << "5. Delete Customer" << std::endl;
        std::cout << "6. Load Customers from File" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter option: ";
    }

    void runMenu() {
        int option = 0;
        while (option != 7) {
            displayMenu();
            std::cin >> option;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (option) {
                case 1:
                    displayCustomers();
                    break;
                case 2: {
                    int customerIndex;
                    std::cout << "Enter customer index: ";
                    std::cin >> customerIndex;
                    displayCustomerDetails(customerIndex);
                    break;
                }
                case 3: {
                    std::string name;
                    int age;
                    std::cout << "Enter customer name: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter customer age: ";
                    std::cin >> age;
                    addCustomer(new Customer(name, age));
                    std::cout << "Customer added successfully." << std::endl;
                    break;
                }
                case 4: {
                    int customerIndex;
                    std::cout << "Enter customer index: ";
                    std::cin >> customerIndex;
                    editCustomerDetails(customerIndex);
                    break;
                }
                case 5: {
                    int customerIndex;
                    std::cout << "Enter customer index: ";
                    std::cin >> customerIndex;
                    deleteCustomer(customerIndex);
                    break;
                }
                case 6:
                    loadCustomersFromFile();
                    break;
                case 7:
                    std::cout << "Exiting..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid option." << std::endl;
                    break;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    CustomerManager customerManager;

    customerManager.addCustomer(new Member("John Doe", 30, 1234));
    customerManager.addCustomer(new Guest("Jane Smith", 25, "987654321"));
    customerManager.addCustomer(new VIP("Alice Johnson", 40, "alice@example.com"));

    customerManager.runMenu();

    return 0;
}