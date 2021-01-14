/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory(const std::size_t& fingerPrint, const std::size_t& exp) :
m_fingerPrint(fingerPrint),
m_exp(exp)
{}

DroidMemory::DroidMemory(const DroidMemory& droid) :
m_fingerPrint(droid.m_fingerPrint),
m_exp(droid.m_exp)
{}

DroidMemory::~DroidMemory()
{}

const std::size_t& DroidMemory::getFingerprint() const
{
    return (m_fingerPrint);
}

const std::size_t& DroidMemory::getExp() const
{
    return (m_exp);
}

void DroidMemory::setFingerprint(const std::size_t& newFingerPrint)
{
    m_fingerPrint = newFingerPrint;
}

void DroidMemory::setExp(const std::size_t& newExp)
{
    m_exp = newExp;
}