
#include "hw/l3_DomainLayer.h"

using namespace std;


bool SeaVessel::invariant() const
{
    return _dry_tonnage
        && _full_tonnage
        && !_sea_vessel_name.empty() && _sea_vessel_name.size() <= MAX_NAME_LENGTH
        && !_type.empty() && _type.size() <= MAX_NAME_LENGTH;
}

SeaVessel::SeaVessel(const std::string & sea_vessel_name, uint32_t dry_tonnage, uint32_t full_tonnage, const std::string & type)
    : _sea_vessel_name(sea_vessel_name), _dry_tonnage(dry_tonnage), _full_tonnage(full_tonnage), _type(type)
{
    assert(invariant());
}

const string & SeaVessel::getSeaVesselName() const
{
    return _sea_vessel_name;
}

uint32_t SeaVessel::getDryTonnage() const
{
    return _dry_tonnage;
}

uint32_t SeaVessel::getFullTonnage() const
{
    return _full_tonnage;
}

const string & SeaVessel::getType() const
{
    return _type;
}

bool   SeaVessel::write(ostream& os)
{
    writeString(os, _sea_vessel_name);
    writeNumber(os, _dry_tonnage);
    writeNumber(os, _full_tonnage);
    writeString(os, _type);

    return os.good();
}



shared_ptr<ICollectable> ItemCollector::read(istream& is)
{
    string   sea_vessel_name = readString(is, MAX_NAME_LENGTH);
    uint32_t dry_tonnage  = readNumber<uint32_t>(is);
    uint32_t full_tonnage = readNumber<uint32_t>(is);
    string   type = readString(is, MAX_NAME_LENGTH);

    return std::make_shared<SeaVessel>(sea_vessel_name, dry_tonnage, full_tonnage, type);
}
