#ifndef manager_H_
#define manager_H_
#include "Employee.h"
#include "TeamLeader.h"
class Manager : public Employee{
	std::vector<TeamLeader> teamLeaders;
public:
	Manager(const std::vector<TeamLeader>& teamLeaders, std::string name, double salary);
	friend std::ostream& operator<<(std::ostream& out, const Manager& student);
};

#endif // !manager_H_

