#include <iostream>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <mutex>
#include <chrono>
#include <ctime>

using namespace std;


#include <mutex>
#include <condition_variable>
        
class Semaphore {
public:
    Semaphore (int count_ = 0)
    : count(count_) 
    {
    }
    
    inline void notify( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        //cout << "thread " << tid <<  " notify" << endl;
        //notify the waiting thread
        cv.notify_one();
    }
    inline void wait( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        while(count == 0) {
            //cout << "thread " << tid << " wait" << endl;
            //wait on the mutex until notify is called
            cv.wait(lock);
            //cout << "thread " << tid << " run" << endl;
        }
        count--;
    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};



string mailbox[10] = {" "};

Semaphore full;
Semaphore empty(50);
int read_loc = 0;
int write_loc = 0;
mutex mu;

void consumer()
{
	for (int i = 1; i < 101; i++)
	{
		full.wait(0);
		//mu.lock();
		//cout<<"N: " << n <<endl;
		//cout<<"reading index " << read_loc << ": "<<mailbox[read_loc]<<endl;
		cout << mailbox[read_loc]<< "\n";
		read_loc = (read_loc + 1) % 10;
		empty.notify(0);
		//mu.unlock();
	}
}

void producer()
{
	for (int i = 1; i < 101; i++)
	{
		empty.wait(0);
		//mu.lock();
		mailbox[write_loc] = mailbox[write_loc] + "hello,";
		mailbox[write_loc] = mailbox[write_loc] + " world! ";
		full.notify(0);
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		//for (int i = 0; i < 100000; i++)
		//	int j = 0;
		mailbox[write_loc] = mailbox[write_loc] + "hello,";
		mailbox[write_loc] = mailbox[write_loc] + " world!";
		//cout<<"writting to index " <<write_loc<<endl;
		write_loc = (write_loc + 1) % 10;
		//full.notify(0);
		//mu.unlock();
	}
}

int main()
{ 
	thread prod(producer);
	thread cons(consumer);
	
	prod.join();
	cons.join();
	return 0;
}
