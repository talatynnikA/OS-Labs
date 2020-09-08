/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

#include <mutex>
#include <condition_variable>

// binary semaphore
class binsem {
public:
	explicit binsem(int init_count = count_max)
		: count_(init_count) {}

	// P-operation / acquire \проверить, свободен ли семафор \приобретать/ занятие семафора
	void wait()
	{
		std::unique_lock<std::mutex> lk(m_);
		cv_.wait(lk, [=]{ return 0 < count_; });
		--count_;
	}
	bool try_wait()
	{
		std::lock_guard<std::mutex> lk(m_);
		if (0 < count_) {
			--count_;
			return true;
		}
		else {
			return false;
		}
	}
	// V-operation / release \высвобождение семафора
	void signal()
	{
		std::lock_guard<std::mutex> lk(m_);
		if (count_ < count_max) {
			++count_;
			cv_.notify_one();
		}
		cout << "\nsignal\n";
	}

	// Lockable requirements
	void lock() { wait(); }
	bool try_lock() { return try_wait(); }
	void unlock() { signal(); }

private:
	static const int count_max = 1;
	int count_;
	std::mutex m_;
	std::condition_variable cv_;
};

int main()
{
	cout << "Hello World";

	binsem *sem = new binsem(10);
	sem->signal();
	system("pause");
	return 0;
}
