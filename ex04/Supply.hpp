/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** Supply.hpp
*/

#ifndef SUPPLY_HPP
#define SUPPLY_HPP

#include <iostream>

#include "Droid.hpp"

class Supply
{

    public:

        typedef enum {Iron, Silicon, Wreck} Types;

        Supply() = delete;
        Supply(const Supply&) = delete;
        Supply(Supply&&) = delete;
        Supply(Types type, const std::size_t& size);
        Supply(Types type, const std::size_t& size, Droid **droids);
        ~Supply();

        const Types& getType() const { return (m_type); };
        const std::size_t& getAmount() const { return (m_amount); };

        operator size_t() const { return (m_amount); };
        bool operator==(const Supply& right) const { return (m_type == right.m_type); };
        bool operator!=(const Supply& right) const { return (m_type != right.m_type); };
        Supply& operator!();
        Droid*& operator*() const { return (m_wrecks[pos]); };
        Droid* operator->() const { return (m_wrecks[pos]); };
        Droid* operator[](const std::size_t& index) const { return (m_wrecks[index]); };
        Supply& operator--() { pos = (pos - 1 < 0 ? m_amount - 1 : pos - 1); return (*this); };
        Supply& operator++() { pos = (pos + 1 >= (int)m_amount ? 0 : pos + 1); return (*this); };

    private:
        Types m_type;
        std::size_t m_amount;
        Droid **m_wrecks;
        int pos;

};

#include "Supply.inl"

#endif // SUPPLY_HPP