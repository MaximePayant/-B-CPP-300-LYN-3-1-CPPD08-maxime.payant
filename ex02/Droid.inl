/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** Droid.inl
*/

inline Droid& Droid::operator=(const Droid& droid)
{
    m_id = droid.m_id;
    m_energy = droid.m_energy;
    delete(m_status);
    m_status = new std::string(*droid.m_status);
    return (*this);
}

inline bool Droid::operator==(const Droid& droid) const
{
    if (*m_status == *droid.m_status)
        return (true);
    return (false);
}

inline bool Droid::operator!=(const Droid& droid) const
{
    if (*m_status == *droid.m_status)
        return (false);
    return (true);
}

inline void Droid::operator<<(size_t& energyTank)
{
    size_t dif = 100 - m_energy;

    dif = (dif > energyTank ? energyTank : dif);
    m_energy += dif;
    energyTank -= dif;
}

inline std::ostream& operator<<(std::ostream& os, const Droid& droid)
{
    os << "Droid '"
        << droid.getId()
        << "', "
        << *droid.getStatus()
        << ", "
        << droid.getEnergy();
    return (os);
}

inline bool Droid::operator()(const std::string *task, const std::size_t& requiredExp)
{
    delete(m_status);
    if (m_energy <= 10) {
        m_status = new std::string("Battery Low");
        m_energy = 0;
        m_battleData->setExp(m_battleData->getExp() + requiredExp);
        return (false);
    }
    m_energy -= 10;
    if (m_battleData->getExp() < requiredExp) {
        m_status = new std::string(*task + " - Failed!");
        m_battleData->setExp(m_battleData->getExp() + requiredExp);
        return (false);
    }
    m_status = new std::string(*task + " - Completed!");
    m_battleData->setExp(m_battleData->getExp() + (requiredExp / 2));
    return (true);
}