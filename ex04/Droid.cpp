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
    m_battleData = new DroidMemory();
    std::cout
        << "Droid '"
        << m_id
        << "' Activated"
        << std::endl;
}

Droid::Droid(const Droid& droid) :
m_id(droid.m_id),
m_energy(50),
m_attack(25),
m_toughness(15)
{
    m_status = new std::string(*droid.m_status);
    m_battleData = new DroidMemory(*droid.m_battleData);
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
    delete(m_battleData);
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
    m_energy = (newEnergy > 100 ? 100 : newEnergy);
}

void Droid::setStatus(std::string* newStatut)
{
    m_status = newStatut;
}

void Droid::setBattleData(DroidMemory *newBattleData)
{
    m_battleData = newBattleData;
}