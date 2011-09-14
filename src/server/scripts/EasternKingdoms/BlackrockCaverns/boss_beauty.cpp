/*
* Copyright (C) 2010-2011 Project SkyFire <http://www.projectskyfire.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "ScriptPCH.h"
#include "blackrock_caverns.h"

class boss_beauty : public CreatureScript
{
public:
    boss_beauty() : CreatureScript("boss_beauty") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_beautyAI (creature);
    }

    struct boss_beautyAI : public ScriptedAI
    {
        boss_beautyAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void Reset() {}

        void EnterCombat(Unit* /*pWho*/) {}

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_beauty()
{
    new boss_beauty();
}