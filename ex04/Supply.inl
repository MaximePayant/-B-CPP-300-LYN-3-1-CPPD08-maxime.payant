/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** Supply.inl
*/

inline std::ostream& operator<<(std::ostream& os, const Supply::Types& type)
{
    switch (type)
    {
        case Supply::Iron:
            std::cout << "Iron";
            break;
        case Supply::Silicon:
            std::cout << "Silicon";
            break;
        case Supply::Wreck:
            std::cout << "Wreck";
            break;
    }
    return (os);
}

inline std::ostream& operator<<(std::ostream& os, const Supply& supply)
{
    os << "Supply : "
        << supply.getAmount()
        << ", "
        << supply.getType();
    if (supply == Supply::Wreck && supply.getAmount()) {
        std::cout << std::endl;
        for (std::size_t ctr = 0; ctr < supply.getAmount() - 1; ctr += 1)
            std::cout << *supply[ctr] << std::endl;
        std::cout << *supply[supply.getAmount() - 1];
    }
    return (os);
}

inline Supply& Supply::operator!()
{
    if (m_type == Supply::Wreck) {
        for (std::size_t ctr = 0; ctr < m_amount; ctr += 1)
            delete(m_wrecks[ctr]);
    }
    m_amount = 0;
    return (*this);
}