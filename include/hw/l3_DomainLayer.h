
#ifndef HW_L3_DOMAIN_LAYER_H
#define HW_L3_DOMAIN_LAYER_H

#include "hw/l4_InfrastructureLayer.h"

const size_t MAX_NAME_LENGTH = 50;


class SeaVessel : public ICollectable
{
    std::string _sea_vessel_name;
    uint32_t _dry_tonnage;
    uint32_t _full_tonnage;
    std::string _type;

protected:
    bool invariant() const;

public:
    SeaVessel() = delete;
    SeaVessel(const SeaVessel & p) = delete;

    SeaVessel & operator = (const SeaVessel & p) = delete;

    SeaVessel(const std::string & sea_vessel_name, uint32_t dry_tonnage, uint32_t full_tonnage, const std::string & type);

    const std::string & getSeaVesselName() const;
    uint32_t getDryTonnage() const;
    uint32_t getFullTonnage() const;
    const std::string & getType() const;

    virtual bool   write(std::ostream& os) override;

    
};


class ItemCollector: public ACollector
{
public:
    virtual std::shared_ptr<ICollectable> read(std::istream& is) override;
};

#endif // HW_L3_DOMAIN_LAYER_H
