/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

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

    void communicateWithRAM();
    void communicateWithMotherboard();
    float processData();
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
        std::cout << "It has been " << this->cpu1.resetTimer << " second(s) since reset was initiated" << std::endl;
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
    Library();
    ~Library();

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

Library::Library()
{
    librarianAge = 58;
    numEmployees = 5;
    numShelves = 50;
    numBooks = 3000;
    lateFees = 2.5f;
}

Library::~Library()
{
    //std::cout << "Library Destructor\n";
}

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

    auto cnt = counter1.startCounter(0,15);
    std::cout << "cnt.counter: " << cnt << std::endl;

    counter1.returnCounterValue();
    


    //auto rst = rst1.reset();
    //std::cout << "Reset message: " << rst << std::endl;
    
    
    //std::cout << "CPU communication \n";
    //cpu1.communicateWithRAM();
    //cpu1.communicateWithMotherboard();
    //std::cout << "\n";

    //std::cout << "Library Actions: \n";
    //library1.checkOutBook();
    //std::cout << "\n";

    //auto msg = library1.buyNewBooks(30);
    //std::cout << msg << std::endl;
    //std::cout << "\n";

    std::cout << "good to go!" << std::endl;

    return 0;
}
