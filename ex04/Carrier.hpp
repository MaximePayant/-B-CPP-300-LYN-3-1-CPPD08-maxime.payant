/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** Carrier.hpp
*/

#ifndef CARRIER_HPP
#define CARRIER_HPP

#include <iostream>

#include "Droid.hpp"

class Carrier
{

    private:
        std::string m_id;
        std::size_t m_energy;
        const std::size_t m_attack = 100;
        const std::size_t m_toughness = 90;
        std::size_t m_speed;
        Droid *m_droids[5];

    public:
        Carrier() = delete;
        Carrier(const Carrier&) = delete;
        Carrier(Carrier&&) = delete;
        Carrier(const std::string& id = "");
        ~Carrier();

        const std::string& getId() const;
        const std::size_t& getEnergy() const;
        const std::size_t& getAttack() const;
        const std::size_t& getToughness() const;
        const std::size_t& getSpeed() const;

        void setId(const std::string&);
        void setEnergy(const std::size_t&);
        void setSpeed(const std::size_t&);

        Carrier& operator<<(Droid*& droid);
        Carrier& operator<<(size_t& droid);
        Carrier& operator>>(Droid*& droid);
        Droid*& operator[](const std::size_t& index);
        Droid* operator[](const std::size_t& index) const;
        bool operator()(int x, int y);
        Carrier &operator~();
};

#include "Carrier.inl"

#endif // CARRIER_HPP