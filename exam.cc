#include <iostream>
#include <queue>
using namespace std;
class Queue{
	int capacity;
	int *mem;
	int elements;
	int first;
	public:
	Queue():
		capacity(10),
		mem(new int[capacity]),
		elements(0),
		first(0){}

	~Queue(){
		delete [] mem;
	}
	Queue(const Queue &other):
		capacity(other.capacity),
		mem(new int[capacity]),
		elements(other.elements),
		first(other.first)
	{for (int i=0;i<capacity;i++)
		mem[i]=other.mem[i];
	}

	Queue &operator=(const Queue &other) {
		if (this != &other) { // guard against self assignment
			if (mem != nullptr)
				delete [] mem; // if mem is allocated, delete it
			capacity = other.capacity; 
			elements = other.elements;
			first=other.first; 
			mem = new int[capacity]; // allocate a new array
			for (int i = 0 ; i < elements ; i++) { 
				mem[i] = other.mem[i];
			}
		}
		return *this; 
	}
	/*
	//for (int i=0;i<capacity;i++)
	//mem[i]=other.mem[i];
	int start_loc = original.first;
	for (int i = 0; i < elements; i++) {
	mem[start_loc] = original.mem[start_loc];
	start_loc = (start_loc + 1) % capacity;
	}
	 */
	int &operator[](int x){
		return mem[x];
	}

	void push(int x){
		if (capacity== elements){
			int *tmp=new int[capacity*2];


			for(int i=0;i<capacity;i++){
				tmp[i]=mem[i];
			}

			delete [] mem;
			mem=tmp;
			capacity*=2;
			first=0;
		}


		int insertion_location =(first+elements)%capacity;
		mem[insertion_location]=x;
		elements++;
	}

	bool empty(){
		return elements==0;
	}

	void pop(){
		if(!empty()){
			first=(first+1)%capacity;
			elements--;}
		else 
			throw std::runtime_error("called on an empty queue");
	}
	int front(){
		if(empty())
			throw std::runtime_error("the funcrion is called on an empty queue");

		return mem[first];
	}

	void print(){
		for (int i=0;i<elements;i++)
			cout<<mem[(first+i)%capacity]<<",";
		std::cout<<std::endl;
	}

	void rotate(int n){
if (empty()) return;
		if (n>0){
			for (int i=0;i<n;i++){
				int gp=mem[first];
				pop();
				push(gp);

			}}
		else {
			std::cout<<"your number should be positive";

		}}
	void shake(){
		while (!empty()){
		int x=front();	
			pop(); 
		std::cout<<x<<",";
                rotate(x);
		}


	}
};

int main(){
	Queue q;
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.print();
	q.rotate(1);
	q.print();
	q.rotate(1);
	q.print();
	q.rotate(2);
	q.print();
	std::cout<<"shake"<<std::endl;
	q.shake();
	return 0;
}
