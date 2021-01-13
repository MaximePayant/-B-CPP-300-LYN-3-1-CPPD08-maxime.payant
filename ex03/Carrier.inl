/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** Carrier.inl
*/

inline static std::size_t getSize(Droid* droids[5])
{
    std::size_t len = 0;

    for (int ctr = 0; ctr < 5; ctr += 1)
        if (droids[ctr] != nullptr)
            len += 1;
    return (len);
}

inline Carrier& Carrier::operator<<(Droid*& droid)
{
    if (droid == NULL)
        return (*this);
    for (int ctr = 0; ctr < 5; ctr += 1) {
        if (m_droids[ctr] == nullptr) {
            m_droids[ctr] = droid;
            droid = nullptr;
            break;
        }
    }
    return (~(*this));
}

inline Carrier& Carrier::operator>>(Droid*& droid)
{
    if (droid != NULL)
        return (*this);
    for (int ctr = 0; ctr < 5; ctr += 1)
        if (m_droids[ctr] != nullptr) {
            droid = m_droids[ctr];
            m_droids[ctr] = nullptr;
            break;
        }
    return (~(*this));
}

inline bool Carrier::operator()(int x, int y)
{
    if ((abs(x) + abs(y)) * (10 + (getSize(m_droids))) > m_energy)
        return (false);
    m_energy -= (abs(x) + abs(y)) * (10 + (getSize(m_droids)));
    return (true);
}

inline std::ostream& operator<<(std::ostream& os, const Carrier& carrier)
{
    os << "Carrier '"
        << carrier.getId()
        << "' Droid(s) on-board:"
        << std::endl;
    for (int ctr = 0; ctr < 5; ctr += 1) {
        std::cout << "[" << ctr << "] : ";
        if (carrier[ctr])
            std::cout << *carrier[ctr];
        else
            std::cout << "Free";
        std::cout << std::endl;
    }
    std::cout
        << "Speed : "
        << carrier.getSpeed()
        << ", Energy "
        << carrier.getEnergy();
    return (os);
}

inline Carrier& Carrier::operator~()
{
    std::size_t nbDroid = getSize(m_droids);
    if (nbDroid == 0)
        m_speed = 0;
    else
        m_speed = 100 - (10 * nbDroid);
    return (*this);
}
