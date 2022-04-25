#include <iostream>
#include <queue>
#include <exception>
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
	//Queue()
	int &operator[](int x){
		return mem[x];
	}

	void push_back(int x){
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

	void pop_front(){
		if(elements!=empty()){
			first=(first+1)%capacity;
			elements--;}
		else 
			throw std::runtime_error("called on an empty queue");
	}
	int front(){
		if(elements=empty())
			throw std::runtime_error("the funcrion is called on an empty queue");

		return mem[first];
	}

	int back(){
              if (elements=empty())
throw std::runtime_error("the function is called on an empty queue");
                int locat=(first+elements)%capacity;
		return mem[locat];
	}

	void pop_back(){
		if(elements!=empty()){
			elements--;
		}
		else 
			throw std::runtime_error("the function is called on an empty deque");
	}

	void push_front(int x){
		if(capacity==elements){
			int *tmp=new int[capacity*2];
			for(int i=0;i<capacity;i++){
				tmp[i]=mem[i];
			}

			delete [] mem;
			mem=tmp;
			capacity*=2;
			first=0;
		}
		if(first==0)
			first=capacity-1;
		else 
			first--;
		mem[first]=x;
		elements++;

	}


};

int main(){

	return 0;
}
