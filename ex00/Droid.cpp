/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** Droid.cpp
*/

#include "Droid.hpp"

Droid::Droid(const std::string& id) :
m_id(id),
m_energy(50),
m_attack(25),
m_toughness(15)
{
    m_status = new std::string("Standing by");
    std::cout
        << "Droid '"
        << m_id
        << "' Activated"
        << std::endl;
}

Droid::Droid(const Droid& droid) :
m_id(droid.m_id),
m_energy(droid.m_energy),
m_attack(droid.m_attack),
m_toughness(droid.m_toughness)
{
    m_status = new std::string(*droid.m_status);
    std::cout
        << "Droid '"
        << m_id
        << "' Activated, Memory Dumped"
        << std::endl;
}

Droid::~Droid()
{
    std::cout
        << "Droid '"
        << m_id
        << "' Destroyed"
        << std::endl;
    delete(m_status);
}

const std::string& Droid::getId() const
{
    return (m_id);
}

const std::size_t& Droid::getEnergy() const
{
    return (m_energy);
}

const std::size_t& Droid::getAttack() const
{
    return (m_attack);
}

const std::size_t& Droid::getToughness() const
{
    return (m_toughness);
}

const std::string* Droid::getStatus() const
{
    return (m_status);
}

void Droid::setId(const std::string& newSerial)
{
    m_id = newSerial;
}

void Droid::setEnergy(const std::size_t& newEnergy)
{
    m_energy = newEnergy;
}

void Droid::setStatus(std::string* newStatut)
{
    m_status = newStatut;
}