#include <iostream>
#include<thread>
#include<chrono>



//Parallelism(P) and Concurency(C) 
//P - каждое ядро занимается своей задачей
//C - 


void work(int x, int y) {
	std::cout << "Work started " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "Work thread " << std::this_thread::get_id() << std::endl;
	std::cout << "Work ended " << std::endl;
}



//std::cout non thread safe 
int main() {
	


	std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
	std::thread t1([](int a , int b) {    // лямбда функция - указатель на функцию
		std::cout << a << " " << b << std::endl;
		std::cout << "Work started " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "Work thread: " << std::this_thread::get_id() << std::endl;
		std::cout << "Work ended " << std::endl;
		
		},5, 6);                            	


	std::thread t2(work, 3, 2);//здесь мы прокидываем указатель на функцию  - work это указатель
	std::cout << "Hello! " << std::endl;


	//race condition - гонка данных ( гонка состояний  )
	int x = 1;


	t1.join(); // присоединение к главному потоку 
	t2.join();




























}