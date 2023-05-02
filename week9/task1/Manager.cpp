#include "Manager.h"

Manager::Manager(const std::vector<TeamLeader>& teamLeaders, std::string name, double salary) : teamLeaders(teamLeaders),Employee(name,salary){}

std::ostream& operator<<(std::ostream& out, const Manager& manager)
{
	for (int i = 0; i < manager.teamLeaders.size(); i++) {
		out<<manager.teamLeaders[i]<<" ";
	}
	out << '\n';

	return out;
}
