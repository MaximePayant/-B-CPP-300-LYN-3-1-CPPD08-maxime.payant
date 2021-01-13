/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** Supply.cpp
*/

#include "Supply.hpp"

Supply::Supply(Types type, const std::size_t& size) :
m_type(type),
m_amount(size),
m_wrecks(nullptr),
pos(0)
{}

Supply::Supply(Types type, const std::size_t& size, Droid **droids) :
m_type(type),
m_amount(size),
m_wrecks(droids),
pos(0)
{}

Supply::~Supply()
{
    if (m_type == Supply::Wreck)
        for (std::size_t ctr = 0; ctr < m_amount; ctr += 1)
            delete(m_wrecks[ctr]);
}