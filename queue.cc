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
       	{
	}

//for (int i=0;i<capacity;i++)
//mem[i]=other.mem[i];
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
		//mem[elements]=x;
		//elements++;
	


	int insertion_location =(first+elements)%capacity;

	mem[insertion_location]=x;
	elements++;
}

bool empty(){
	return elements==0;
}

void pop(){
	if(empty()){
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
};

int main(){
Queue q;
q.push(5);
q.push(6);
q.push(7);


cout<<q.front()<<endl;
cout<<q.front()<<endl;
	return 0;
}
