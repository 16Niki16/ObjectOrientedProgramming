#include "Property.h"

Property::Property(std::string& owner, bool tangible) : owner(owner), tangible(tangible)
{
}

Property::~Property()
{
}

std::string Property::getOwner()
{
    return owner;
}

bool Property::getTangible()
{
    return tangible;
}
