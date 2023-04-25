#ifndef task2_H_
#define task2_H_
template <typename T>
class Set {
	T* set;
	int size;
public:
	Set(T set, int size, T1 element) : set(set), size(size) {}
	~Set() { delete[] set; }
	Set(const Set& obj) {
		set = obj.set;
		size = obj.size;
	}
	Set<T>& operator=(const Set<T>& obj) {
		if (this != &obj) {
			this->erase();
			this->copy(obj);
		}
		return *this;
	}

	void addElement(T element) {
		T newSet = new T[size + 1];
		for (int i = 0; i < size; i++) {
			newSet[i] = set[i];
		}
		newSet[size] = element;
		delete[] set;
		set = newSet;
		size = size + 1;
	}
	bool isEmpty() {
		if (set == nullptr) {
			return true;
		}
		return false;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			std::cout << set[i] << std::endl;
		}
	}
	bool constains(T element) {
		for (int i = 0; i < size; i++) {
			if (set[i] == element) {
				return true;
			}
		}
		return false;
	}

	Set<T>& operator+(const Set<T>& obj, const Set<T>& sum) {
		for (int i = 0; i < size; i++) {
			sum.set[i] = this->set[i] + obj.set[i];
		}
		return *sum;
	}
	bool operator<(const Set<T>& obj) {
		elementA = 0;
		for (int i = 0; i < size; i++) {
			if (this->set[i] == obj.set[elementA]) {
				++elementA;
				if (elementA == size) {
					return true;
				}
			}
			else if (this->set[i] != obj.set[elementA]) {
				elementA = 0;
			}
		}
		return false;
	}
};
#endif // !task2

