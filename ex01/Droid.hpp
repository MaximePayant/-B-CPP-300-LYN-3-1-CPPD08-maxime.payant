/*
** EPITECH PROJECT, 2021
** CPP_D07M
** File description:
** Droid.hpp
*/


#ifndef DROID_HPP
#define DROID_HPP

#include <iostream>

#include "DroidMemory.hpp"

class Droid
{
    private:
        std::string m_id;
        std::size_t m_energy;
        const std::size_t m_attack;
        const std::size_t m_toughness;
        std::string *m_status;
        DroidMemory *m_battleData;

    public:
        Droid() = delete;
        Droid(const std::string& serial);
        Droid(const Droid& droid);
        ~Droid();

        const std::string& getId() const;
        const std::size_t& getEnergy() const;
        const std::size_t& getAttack() const;
        const std::size_t& getToughness() const;
        const std::string* getStatus() const;
        const DroidMemory* getBattleData() const;

        void setId(const std::string& newSerial);
        void setEnergy(const std::size_t& newEnergy);
        void setStatus(std::string* newStatut);
        void setBattleData(DroidMemory *newBattleData);

        void operator=(const Droid& droid);
        bool operator==(const Droid& right) const;
        bool operator!=(const Droid& right) const;
        void operator<<(size_t& energyTank);

};

#include "Droid.inl"

#endif // DROID_HPP