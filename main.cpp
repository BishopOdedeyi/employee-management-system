#include <iostream>
#include <vector>

class Employee
{
protected:
    std::string FirstName;
    std::string LastName;
    std::string Email;
    std::string Role = "Ordinary Staff";
    int Salary;

public:
    virtual std::string displayRole()
    {
        return "\nRole - " + Role;
    }

    void displayInfo()
    {
        std::cout << "\nName - " << FirstName + " " + LastName << "\nEmail - " << Email << "\nSalary - " << Salary << std::endl;
    }

    virtual int increaseSalary()
    {
        Salary *= 1.05;
        std::cout << "\n" + FirstName + " " + LastName << " got a 5% raise in salary your salary is now " << Salary << std::endl;
        return Salary;
    }

    std::string getName()
    {
        return FirstName + " " + LastName;
    }

    std::string getEmail()
    {
        return Email;
    }

    Employee(std::string firstname, std::string lastname, std::string email, int salary)
    {
        FirstName = firstname;
        LastName = lastname;
        Email = email;
        Salary = salary;
    }
};

class Manager: public Employee
{
private:
    std::vector<Employee> Team;
    std::string Role = "Manager";
    int ManagerID;
public:
    Manager(std::string firstname, std::string lastname, std::string email, int salary)
    :Employee(firstname, lastname, email, salary)
    {
        ManagerID += 1;
    }

    int getID()
    {
        return ManagerID;
    }

    std::string displayRole()
    {
        return "\nRole - " + Role;
    }

    void addEmployee(Employee employee)
    {
        Team.push_back(employee);
        std::cout << "\n" << employee.getName() << " has been added to " << FirstName + "\'s"<< " team as an Employee" << std::endl;
    }

    void displayTeam()
    {
        for(int i = 0; i < Team.size(); i++)
        {
            std::cout << "\n" << "Name - " << Team[i].getName() << "\t||\t" << " Email - " << Team[i].getEmail() << std::endl;
        }
    }

    int increaseSalary()
    {
        Salary *= 1.10;
        std::cout << "\n" + FirstName + " " + LastName << " got a 10% raise in salary your salary is now " << Salary << std::endl;
        return Salary;
    }
};

class Company
{
public:
    std::string Name;
    std::vector<Employee> Employees;
    std::vector<Manager> Managers;
//public:
    std::string displayName()
    {
        return Name;
    }

    void addEmployee(Employee employee)
    {
        Employees.push_back(employee);
        std::cout << "\n" << employee.getName() << " has been added to the company " << Name << " as an Employee";
    }

    void addManager(Manager manager)
    {
        Managers.push_back(manager);
        std::cout << "\n" << manager.getName() << " has been added to " << Name << " company as a Manager" << std::endl;
    }

    void displayManagers()
    {
        std::cout << "\n\t\t\tManagers" << std::endl;
        for(int i = 0; i < Managers.size(); i++)
        {
            std::cout << "\n" << "ID - " << Managers[i].getID() << " Name - " << Managers[i].getName() << "\t||\t" << " Email - " << Managers[i].getEmail() << std::endl;
        }
    }

    void displayHireachy()
    {
        for(int i=0; i < Managers.size(); i++)
        {
            std::cout << Managers[i].getName() << Managers[i].displayRole() << std::endl;
            std::cout << "\t\t\t" << Managers[i].getName() << " Team" << std::endl;
            Managers[i].displayTeam();
        }
    }

    Company(std::string name)
    {
        Name = name;
    }
};


int main()
{
    std::string help = "\nWhat would you like to do: \n\n1. Add Managers\n2. Add employees to certain Managers\n3. Add staff directly to company\n4. Display all staffs\n5. Display all managers\n6. Increase Worker salary\n7. Print this help\n8. Exit\n";

    std::string companyName;
    std::cout << "\nPlease enter the name of your company : ";
    std::getline(std::cin, companyName);
    Company company = Company(companyName);
    std::cout << "\n\t\t\t" << company.displayName() << std::endl;

    std::cout << help << std::endl;
    bool running = true;
    company.displayManagers();

    while(true)
    {
        int choice;
        std::cout << "Please enter the id of what you would like to do : ";
        std::cin >> choice;

        if(choice == 1)
        {
            std::string firstName;
            std::string lastName;
            std::string email;
            int salary;
            std::cout << "Please enter the firstname of the manager : ";
            std::cin >> firstName;
            std::cout << "Please enter the lastname of the manager : ";
            std::cin >> lastName;
            std::cout << "Please enter the manager's email : ";
            std::cin >> email;
            std::cout << "Please enter the manager's pay : ";
            std::cin >> salary;
            Manager manager = Manager(firstName, lastName, email, salary);
            manager.displayInfo();
            company.addManager(manager);
        }

        else if(choice == 2)
            {
                std::string firstName;
                std::string lastName;
                std::string email;
                int managerID;
                int salary;
                std::cout << "Please enter the first name of the employee : ";
                std::cin >> firstName;
                std::cout << "Please enter the lastname of the employee : ";
                std::cin >> lastName;
                std::cout << "Please enter the employee's email : ";
                std::cin >> email;
                std::cout << "Please enter the employee's pay : ";
                std::cin >> salary;
                Employee employee = Employee(firstName, lastName, email, salary);
                company.displayManagers();
                std::cout << "Please enter the firstname of manager you want to assign this employee to : ";
                std::cin >> managerID;
                for(int i=0; i < company.Managers.size(); i++)
                {
                    /*
                    if(managerID != company.Managers[i])
                    {
                        continue;
                    }
                    else
                    {
                        company.Managers[i].addEmployee(employee);
                    }

                }
            }
    }


    // Company dropshiptv = Company("DropshipTV");
    // std::cout << "\n\t\t\t" << dropshiptv.displayName() << std::endl;

    // Manager man1 = Manager("Pope", "Bukola", "pope@bukola.com", 150000);

    // Manager man2 = Manager("Elizabeth", "Marty", "elizabeth@marty.com", 120000);

    // Manager man3 = Manager("Dorothy", "Lilian", "dorothy@lilian.com", 130000);

    // dropshiptv.addManager(man1);
    // dropshiptv.addManager(man2);
    // dropshiptv.addManager(man3);

    // Employee emp1 = Employee("Bishop", "Odedeyi", "bishop@odedeyi.com", 80000);
    // Employee emp2 = Employee("Tuna", "McButter", "tuna@mcbutter.com", 50000);
    // Employee emp3 = Employee("Phil", "Tunde", "phil@tunde.com", 60000);
    // Employee emp4 = Employee("Gregory", "Lucas", "gregorio@lucas.com", 40000);
    // Employee emp5 = Employee("Sarah", "Brooks", "sarah@brooks.com", 70000);
    // Employee emp6 = Employee("Babara", "Gordon", "babara@gordon.com", 45000);
    // Employee emp7 = Employee("Bruce", "Wayne", "bruce@wayne.com", 55000);
    // Employee emp8 = Employee("Gordon", "Ramsey", "gordon@ramsey.com", 65000);
    // Employee emp9 = Employee("Daemon", "Kusto", "daemon@kusto.com", 75000);
    // Employee emp10 = Employee("Nancy", "Susan", "nancy@susan.com", 48000);

    // man1.addEmployee(emp1);
    // man1.addEmployee(emp2);
    // man1.addEmployee(emp3);
    // man1.addEmployee(emp4);
    // man1.addEmployee(emp5);

    // man2.addEmployee(emp6);
    // man2.addEmployee(emp7);
    // man2.addEmployee(emp8);

    // man3.addEmployee(emp9);
    // man3.addEmployee(emp10);
}
