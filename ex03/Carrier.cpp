/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** Carrier.cpp
*/

#include "Carrier.hpp"

Carrier::Carrier(const std::string& id) :
m_id(id),
m_energy(300),
m_speed(0)
{
    m_droids[0] = nullptr;
    m_droids[1] = nullptr;
    m_droids[2] = nullptr;
    m_droids[3] = nullptr;
    m_droids[4] = nullptr;
}

Carrier::~Carrier()
{
    for (int ctr = 0; ctr < 5; ctr += 1)
        delete(m_droids[ctr]);
}

const std::string& Carrier::getId() const
{
    return (m_id);
}

const std::size_t& Carrier::getEnergy() const
{
    return (m_energy);
}

const std::size_t& Carrier::getAttack() const
{
    return (m_attack);
}

const std::size_t& Carrier::getToughness() const
{
    return (m_toughness);
}

const std::size_t& Carrier::getSpeed() const
{
    return (m_speed);
}

void Carrier::setId(const std::string& id)
{
    m_id = id;
}

void Carrier::setEnergy(const std::size_t& newEnergy)
{
    m_energy = (newEnergy > 600 ? 600 : newEnergy);
}

void Carrier::setSpeed(const std::size_t& newSpeed)
{
    m_speed = (newSpeed > 100 ? 100 : newSpeed);
}

Droid*& Carrier::operator[](const std::size_t& index)
{
    return (m_droids[index]);
}

Droid* Carrier::operator[](const std::size_t& index) const
{
    return (m_droids[index]);
}