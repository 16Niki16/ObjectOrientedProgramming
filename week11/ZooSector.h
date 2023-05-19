#ifndef zooSector_H_
#define zooSector_H_
#include<vector>
template <typename Animaltype>
class ZooSector{
	std::vector<Animaltype> animals;
public:
	void addAnimal(Animaltype obj);
	void printAnimal();
};

#endif // !zooSector_H_

template<typename Animaltype>
inline void ZooSector<Animaltype>::addAnimal(Animaltype obj)
{
	animals.push_back(obj);
}
