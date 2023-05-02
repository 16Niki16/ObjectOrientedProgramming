#include "TeamLeader.h"

TeamLeader::TeamLeader(std::vector<Employee>& team, std::string* projectName, std::string name, double salary) : team(team), projectName(projectName), Employee(name, salary) {}
