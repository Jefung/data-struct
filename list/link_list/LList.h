#include "List.h"
template <typename E>
class LList: public List<E>{
	private:
	   	List<E> *head;
		List<E> *curr;
		int cnt;
	public:
	LList(const E& item = NULL){
		curr = item;
		head = ;
		cnt = 0;
	}
	~List(){}
	
	void append(const E& item){
		if(head == NULL)
			head = item	
	}	
};

