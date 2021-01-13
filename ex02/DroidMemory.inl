/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** DoidMemory.inl
*/

inline DroidMemory& DroidMemory::operator=(const DroidMemory& right)
{
    m_fingerPrint = right.m_fingerPrint;
    m_exp = right.m_exp;
    return (*this);
}

inline DroidMemory& DroidMemory::operator<<(const DroidMemory& right)
{
    m_exp += right.m_exp;
    m_fingerPrint ^= right.m_fingerPrint;
    return (*this);
}

inline DroidMemory& DroidMemory::operator>>(DroidMemory& right) const
{
    right.m_exp += m_exp;
    right.m_fingerPrint ^= m_fingerPrint;
    return (right);
}

inline DroidMemory& DroidMemory::operator+=(const DroidMemory& right)
{
    *this << right;
    return (*this);
}

inline DroidMemory& DroidMemory::operator+=(const std::size_t& right)
{
    m_exp += right;
    m_fingerPrint ^= right;
    return (*this);
}

inline DroidMemory& operator+(const DroidMemory& left, const DroidMemory& right)
{
    DroidMemory *newDroid = new DroidMemory();

    *newDroid += left;
    *newDroid += right;
    return (*newDroid);
}

inline DroidMemory& operator+(const DroidMemory& left, const std::size_t& right)
{
    DroidMemory *newDroid = new DroidMemory();

    *newDroid += left;
    *newDroid += right;
    return (*newDroid);
}

inline std::ostream& operator<<(std::ostream& os, const DroidMemory& droid)
{
    os << "DroidMemory '"
        << droid.getFingerprint()
        << "', "
        << droid.getExp();
    return (os);
}

inline bool DroidMemory::operator==(const DroidMemory& right) const
{
    if (m_fingerPrint == right.m_fingerPrint
    && m_exp == right.m_exp)
        return (true);
    return (false);
}

inline bool DroidMemory::operator!=(const DroidMemory& right) const
{
    return (!(*this == right));
}

inline bool DroidMemory::operator<(const DroidMemory& right) const
{
    return (m_exp < right.m_exp);
}

inline bool DroidMemory::operator<(const std::size_t& right) const
{
    return (m_exp < right);
}

inline bool DroidMemory::operator>(const DroidMemory& right) const
{
    return (m_exp > right.m_exp);
}

inline bool DroidMemory::operator>(const std::size_t& right) const
{
    return (m_exp > right);
}

inline bool DroidMemory::operator<=(const DroidMemory& right) const
{
    return (m_exp <= right.m_exp);
}

inline bool DroidMemory::operator<=(const std::size_t& right) const
{
    return (m_exp <= right);
}

inline bool DroidMemory::operator>=(const DroidMemory& right) const
{
    return (m_exp >= right.m_exp);
}

inline bool DroidMemory::operator>=(const std::size_t& right) const
{
    return (m_exp >= right);
}