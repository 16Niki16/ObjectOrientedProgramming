#ifndef relation_H_
#define relation_H_
#include<string>
template<typename T>
class RelationElement{
	T subject;
	T object;
	std::string relation;
public: 
	void print() const;
};

template<>
class RelationElement<int> {
	 int subject;
	 int object;
	 std::string relation;
public:
	std::string getRelation(RelationElement& object1, RelationElement& object2);
};
#endif // !relation_H_

template<typename T>
inline void RelationElement<T>::print() const
{
	std::cout << subject << " " << object << " " << relation << std::endl;
}

inline std::string RelationElement<int>::getRelation(RelationElement& object1, RelationElement& object2)
{
	RelationElement newObject;
	newObject.object = object2.object;
	newObject.subject = object1.subject;
	if (newObject.object == newObject.subject) {
		std::string saveSubject = std::to_string(object1.subject);
		std::string saveObject = std::to_string(object1.object);
		std::string saveObject2 = std::to_string(object2.object);
		object2.relation = object2.relation + saveObject2;
		object1.relation = saveSubject + object1.relation + saveObject;
		std::string sentence =  object1.relation + ",which is" + object2.relation;
		return sentence;
	}
	newObject.relation = object1.relation;
	return newObject.relation;

}
