
#include <iostream>
#include <thread>
int chpb = 0;
using namespace std;

#include <mutex>
#include <condition_variable>


// binary semaphore Pb = РБ(Работа с Буфером)
class binsem {
public:
	explicit binsem(int init_count = count_max)
		: count_(init_count) {}

	// P-operation / acquire \проверить, свободен ли семафор \ закрытие семафора
	void wait()
	{
		std::unique_lock<std::mutex> lk(m_);
		cv_.wait(lk, [=]{ return 0 < count_; });
		--count_;
	}												//При попытке закрыть уже закрытый семафор происходит прерывание, и ОС добавляет текущий процесс в очередь к закрытому семафору
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
		std::lock_guard<std::mutex> lk(m_);//Операция V активизирует первый стоящий в очереди к семафору процесс, который успешно завершает операцию P.
		if (count_ < count_max) {
			++count_;
			cv_.notify_one();			// Если семафор  уже открыт, операция V не имеет никакого эффекта
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

// binary semaphore 2(Zn = ЗП)(задержка потребителя)
class binsem2 {
public:
	explicit binsem2(int init_count = count_max)
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
//--------------------------------
int proizvoditel( binsem *sem, binsem2 *sem2)
{
	// функция отвечает за производство порций

	cout << "proizvoditel begin\n";
	do{
	n1:{
		cout << "proizvodstvo novoi portsii\n";

		cout << "P(Pb)\n";//вызов функций работы с буфером для занятие семафора
		sem->wait();
		sem->try_wait();
		cout << "dobavlenie novoi porcii k byfery\n";
		chpb = chpb + 1;
		cout << "chpb = ";
		cout << chpb << endl;
	}
		if (chpb == 0)
		{
			cout << "V(Pb)\n";//высвобождение семафора для работы с буфером
			sem->signal();

			cout << "V(Zn)\n";//высвобождение семафора для Задержки потребителя
			sem2->signal();
			return 0;
		}
		else{
			cout << "V(Pb)\n";//высвобождение семафора для  работы с буфером
			sem->signal();
		}
	} while (chpb != 10);
	return chpb;
	
}

int potrebitel( binsem *sem, binsem2 *sem2)
{

	// 	 функция отвечает за потребление порций

	cout << "potrebitel begin\n";
	do{
	n2:{
		cout << "P(Pb)\n";//вызов функций работы с буфером для занятие семафора
		sem->wait();
		sem->try_wait();
		chpb = chpb - 1;// потребляем порцию
		cout << "pip chpb = ";
		cout << chpb << endl;//вывод количества оставшихся порций

	}
		if (chpb == -1)
		{
			cout << "V(Pb)\n";//высвобождение семафора для работы с буфером
			sem->signal();
			cout << "P(Zn)\n";// занятие семафора Задержка потребителя
			sem2->wait();
			sem2->try_wait();
			cout << "P(Pb)\n";//вызов функций работы с буфером для занятие семафора
			sem->wait();
			sem->try_wait();
			return 0;
		}
		cout << "vzyatie porcii iz byfera\n";
		cout << "V(Pb)\n";//высвобождение семафора для работы с буфером
		sem->signal();
		cout << "obrabotka vzyatoi porcii\n";
	} while (chpb != 0);// потребление происходит пока порции есть. если их кол-во равно 0 обработка останавливается
	
}
int main(int *ptrchpb )
{
	binsem2 *sem2 = new binsem2(10);
	binsem *sem = new binsem(10);

	cout << "Hello World\n";
	cout << " Program author: Artyom Talatynnik\nProcess interaction\n";
	cout << "begin\n";
	proizvoditel( sem, sem2);
	potrebitel(sem, sem2);
	
	system("pause");
	return 0;
}
