/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
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
    float clockSpeedInGHz {2.8f};
    int l1CacheSize {8};
    int l2CacheSize {16};
    int l3CacheSize {32};
    int counter;
    int resetTimer;

    std::string ramMessage = "Hi RAM\n";
    std::string motherboardMessage = "Hi Motherboard\n";

    void communicateWithRAM();
    void communicateWithMotherboard();
    float processData();

    void motherboardCommunication() {std::cout << this-> motherboardMessage;}
    void ramCommunication() {std::cout << this-> ramMessage;}
};

CentralProcessingUnit::CentralProcessingUnit()
{
    //std::cout << "CentralProcessingUnit Constructor\n";
}

CentralProcessingUnit::~CentralProcessingUnit()
{
    //std::cout << "CentralProcessingUnit Destructor\n";
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
    CPUCounter();
    ~CPUCounter();

    CentralProcessingUnit cpu1;
    int counter;
    int startCounter(int initVal , int maxVal);
    void returnCounterValue() { std::cout << "cnt.counter: " << this->cpu1.counter << std::endl;}
};
CPUCounter::CPUCounter()
{
    //std::cout << "CPUCounter Constructor\n";
}

CPUCounter::~CPUCounter()
{
   //std::cout << "CPUCounter Destructor\n";
}

int CPUCounter::startCounter(int initVal, int maxVal)
{
    for (int i = initVal ; i < maxVal+1 ; i++)
    {
        this->cpu1.counter = i; 
        //std::cout << this->cpu1.counter << "\n";
        if (cpu1.counter == maxVal)
            //std::cout << "CPU Counter Max Value: " << this->cpu1.counter << "\n";
            return this->cpu1.counter;
    }
    return this->cpu1.counter;
}   
/*
 copied UDT 2:
 */
struct CPUReset //While #1
{
    CPUReset();
    ~CPUReset();

    CentralProcessingUnit cpu1;
    std::string reset();
    void printResetMessage() {std::cout << "The CPU has been reset, it has been " + std::to_string(this->cpu1.resetTimer) + " seconds\n";}
};

CPUReset::CPUReset()
{
    //std::cout << "CPUReset Constructor\n";
}

CPUReset::~CPUReset()
{
    //std::cout << "CPUReset Destructor\n";
}
std::string CPUReset::reset()
{
    int i = 0;
    cpu1.resetTimer = 0;
    while (i < 10)
    {
        cpu1.resetTimer += 1;
        //std::cout << "It has been " << this->cpu1.resetTimer << " second(s) since reset was initiated" << std::endl;
        if (cpu1.resetTimer == 10)
            return "The CPU has been reset, it has been " + std::to_string(this->cpu1.resetTimer) + " seconds";
    }
    return "Error while resetting";
}
/*
 copied UDT 3:
 */

struct Library
{
    Library();
    ~Library();

    int librarianAge;
    int numEmployees;
    int numShelves;
    int numBooks;
    float lateFees;
    std::string checkoutMessage;

    std::string checkOutBook();
    std::string returnBook();
    float chargeLateFee(float lateFee, int numDays);

    int buyNewBooks(int numNewBooks);
    void printCheckoutMessage() {std::cout << this->checkoutMessage << "\n";}
    void boughtNewBooks() {std::cout << "We now have " << this->numBooks << " books in our library\n";}
};

Library::Library()
{
    librarianAge = 58;
    numEmployees = 5;
    numShelves = 50;
    numBooks = 3000;
    lateFees = 2.5f;
    checkoutMessage = "Enjoy your book\n";
}

Library::~Library()
{
    //std::cout << "Library Destructor\n";
}

int Library::buyNewBooks (int numNewBooks) //While #2
{
    int i = 0;
    while (i < numNewBooks + 1)
    { 
        if (i == numNewBooks)
            return numBooks;
        this->numBooks++;
        i++;
    }
    //this->numBooks += numNewBooks;
    return numBooks;
}

std::string Library::checkOutBook()
{
    return this->checkoutMessage;
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
    CPUTimer();
    ~CPUTimer();

    CentralProcessingUnit cpu1;
    int timer;
    int startTimer(int maxVal);
    void resetTimer();
};

CPUTimer::CPUTimer()
{
    timer = 0;
    //std::cout << "CPU Timer Constructor\n";
}

CPUTimer::~CPUTimer()
{
    //std::cout << "CPU Timer Destructor\n";
}

int CPUTimer::startTimer(int maxVal)
{
    for(timer = 0; timer < maxVal+1; timer++)
    {
        //std::cout << std::to_string(this->timer) << "\n";
        if (timer == maxVal)
        {
            //std::cout << "The timer has reached its max value\n";
            std::cout << "CPU Timer Max Value: " << std::to_string(this->timer) << "\n";
            //std::cout << "The timer has reached its max value\n";
            return this->timer;
        }
    }
    return 0;  
}

void CPUTimer::resetTimer()
{
    timer = 0;
}

/*
 new UDT 5:
 with 2 member functions
 */

struct Phone
{
    std::string screenStatus = "Not Broken";
    std::string dropPhone (bool breakScreen = false);

    void printScreenStatus() {std::cout << "The screen is " << this->screenStatus << "\n";}
};

std::string Phone::dropPhone (bool breakScreen)
{
    if (breakScreen)
    {
        this->screenStatus = "Broken";
        return this->screenStatus;
    }
    this->screenStatus = "Not Broken";
    return this->screenStatus;
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
    CentralProcessingUnit cpu1;
    CPUCounter counter1;
    CPUReset rst1;
    Library library1;
    Phone phone1;

    std::cout << "UDF1 Counter:\n";
    auto cnt = counter1.startCounter(0,15);
    std::cout << "cnt.counter: " << cnt << std::endl;
    counter1.returnCounterValue();
    std::cout << "\n";
    

    std::cout << "UDF2 Reset:\n";
    auto rst = rst1.reset();
    std::cout << rst << std::endl;
    rst1.printResetMessage();
    std::cout << "\n";
    
    std::cout << "UDF3 CPU communication:\n";
    cpu1.communicateWithRAM();
    std::cout << "RAM Message: " << cpu1.ramMessage;
    cpu1.communicateWithMotherboard();
    std::cout << "Motherboard Message: " << cpu1.motherboardMessage;
    std::cout << "\n";

    std::cout << "UDF4 Library Actions:\n";
    auto text = library1.checkOutBook();
    std::cout << "Library Check out message: " << text;
    library1.printCheckoutMessage();
    auto msg = library1.buyNewBooks(30);
    std::cout << "We now have " << msg << " books in our library" << std::endl;
    library1.boughtNewBooks();
    std::cout << "\n";

    std::cout << "UDF5 Phone:\n";
    auto status = phone1.dropPhone(false);
    std::cout << "The phone screen is " << status << "\n";
    phone1.printScreenStatus();

    std::cout << "good to go!" << std::endl;
    return 0;
}
