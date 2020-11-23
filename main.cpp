/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */
#include <iostream>
/*
 copied UDT 1:
 */
struct CentralProcessingUnit
{
    CentralProcessingUnit();
    ~CentralProcessingUnit();

    int numberOfCores {8};
    float clockSpeedInGHz {2.8};
    int l1CacheSize {8};
    int l2CacheSize {16};
    int l3CacheSize {32};
    int counter;
    int resetTimer;

    void communicateWithRAM();
    void communicateWithMotherboard();
    float processData();
};

CentralProcessingUnit::~CentralProcessingUnit()
{
    std::cout << "CentralProcessingUnit Destructor\n";
}

void CentralProcessingUnit::communicateWithRAM()
{
    std::cout << "Hi RAM\n";
}
void CentralProcessingUnit::communicateWithMotherboard()
{
    std::cout << "Hi Motherboard\n";
}
float CentralProcessingUnit::processData()
{
    float processedData = 1.0f;
    return processedData;
}

struct CPUCounter //For #1
{
    ~CPUCounter()
    {
        std::cout << "CPUCounter Destructor\n";
    }

    CentralProcessingUnit cpu1;
    int startCounter(int initVal , int maxVal);
};
int CPUCounter::startCounter(int initVal, int maxVal)
{
    for (int i = initVal ; i < maxVal+1 ; i++)
    {
        cpu1.counter = i; 
        std::cout<<cpu1.counter<<"\n";
        if (cpu1.counter == maxVal)
            return cpu1.counter;
    }
    return 0;
}   
/*
 copied UDT 2:
 */
struct CPUReset //While #1
{
    ~CPUReset()
    {
        std::cout << "CPUReset Destructor\n";
    }

    CentralProcessingUnit cpu1;
    std::string reset();
};

std::string CPUReset::reset()
{
    int i = 0;
    cpu1.resetTimer = 0;
    while (i < 10)
    {
        cpu1.resetTimer += 1;
        std::cout << "It has been " << cpu1.resetTimer << " second(s) since reset was initiated" << std::endl;
        if (cpu1.resetTimer == 10)
            return "The CPU has been reset";
    }
    return "Error while resetting";
}
/*
 copied UDT 3:
 */

struct Library
{
    Library()
    {
        librarianAge = 58;
        numEmployees = 5;
        numShelves = 50;
        numBooks = 3000;
        lateFees = 2.5f;
    }
    ~Library()
    {
        std::cout << "Library Destructor\n";
    }

    int librarianAge;
    int numEmployees;
    int numShelves;
    int numBooks;
    float lateFees;

    void checkOutBook();
    std::string returnBook();
    float chargeLateFee(float lateFee, int numDays);

    std::string buyNewBooks(int numNewBooks);
};

std::string Library::buyNewBooks (int numNewBooks) //While #2
{
    int i = 0;
    while (i < numNewBooks + 1)
    { 
        if (i == numNewBooks)
            return "We have bought " + std::to_string(numNewBooks) + " new books for our library\n" + "We now have " + std::to_string(numBooks) + " books in our library\n";
        numBooks++;
        i++;
    }
    return "We didn't buy enough books";
}

void Library::checkOutBook()
{
    std::cout << "Enjoy your book\n";
}

std::string Library::returnBook()
{
    return "Did you enjoy your book?";
}

float Library::chargeLateFee(float lateFee1, int numDays1)
{
    return lateFee1 * numDays1;
}
/*
 new UDT 4:
 with 2 member functions
 */
struct CPUTimer
{
    CPUTimer()
    {
        timer = 0;
        std::cout << "CPU Timer Constructor\n";
    }
    ~CPUTimer()
    {
        std::cout << "CPU Timer Destructor\n";
    }

    CentralProcessingUnit cpu1;
    int timer;
    std::string startTimer(int maxVal);
    void resetTimer();
};

std::string CPUTimer::startTimer(int maxVal)
{
    for(timer = 0; timer < maxVal+1; timer++)
    {
        std::cout << std::to_string(timer) << "\n";
        if (timer == maxVal)
        {
            return "The timer has reached its max value\n";
        }
    }
    return "";  
}

void CPUTimer::resetTimer()
{
    timer = 0;
}

/*
 new UDT 5:
 with 2 member functions
 */
struct University
{
    University()
    {
        std::cout << "University Constructor\n";
    }
    ~University()
    {
        std::cout << "University Destructor\n";
    }

    Library library1;
    void addNewShelves(int numNewShelves);
    void hireAdditionalStaff(int numStaff);
};

void University::addNewShelves(int numNewShelves)
{
    int booksPerShelf = 30;
    library1.numShelves += numNewShelves;
    library1.buyNewBooks(numNewShelves/booksPerShelf);
}

void University::hireAdditionalStaff(int numStaff)
{
    std::cout << "We have hired " << std::to_string(numStaff) << " additional people to help manage the library\n";
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    CPUTimer timer1;
    University university1;
    std::cout << "good to go!" << std::endl;
}
