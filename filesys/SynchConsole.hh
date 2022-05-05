#ifndef NACHOS_MACHINE_SYNCHCONSOLE__HH
#define NACHOS_MACHINE_SYNCHCONSOLE__HH
#include "console.hh"
#include "threads/lock.hh"
#include "threads/semaphore.hh"

class Lock;

class SynchConsole {
    public:
        SynchConsole(const char * = nullptr, const char * = nullptr);
        ~SynchConsole();

        void ReadAvail();
        void WriteDone();
        char GetChar();
        void PutChar(char c);
    private:
        Console *console;
        Semaphore *readAvail;
        Semaphore *writeDone;
        Lock *readLock;
        Lock *writeLock;
};

#endif