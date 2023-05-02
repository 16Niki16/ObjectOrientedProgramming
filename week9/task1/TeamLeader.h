#ifndef teamLeader_H_
#define teamLeader_H_
#include "Employee.h"
#include <vector>
class TeamLeader : public Employee{
	std::vector<Employee> team;
	std::string* projectName;

public:
	TeamLeader(std::vector<Employee>& team, std::string* projectName, std::string name, double salary);
	friend std::ostream& operator<<(std::ostream& out, const TeamLeader& student);
};
#endif

