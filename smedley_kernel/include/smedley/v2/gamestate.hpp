#pragma once

#include <cstdint>
#include "ai.hpp"
#include "country.hpp"
#include "eu3idler.hpp"
#include "goods.hpp"
#include "history.hpp"
#include "province.hpp"
#include "rebel.hpp"
#include "settings.hpp"
#include "war.hpp"
#include "worldmarket.hpp"
#include "../clausewitz/persistent.hpp"
#include "../clausewitz/types.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

	class CPlayer
	{
	};

	class CDiplomacy : public clausewitz::CPersistent
	{
	protected:
		clausewitz::CList<void *> _relations; // 8
		CDiplomaticHistory _history; // 18
	};

	static_assert(sizeof(CDiplomacy) == 0x38);

	class CGameState : clausewitz::CPersistent
	{
	protected:
		sstd::vector<int> _canals; // 8
		clausewitz::CList<CPlayer> _players; // 18
		uint8_t _uk_0x28[0x6c];
		clausewitz::CList<int> _outliner; // 94
		sstd::vector<CCountryAI *> _country_ais; // a4
		uint8_t _uk_0xb4[0x9c8];
		CDiplomacy _diplomacy; // a7c
		uint8_t _uk_0xab4[0xc];
		void *_combat_list; // ac0
		uint32_t _uk_0xac4;
		uint32_t _uk_0xac8;
		sstd::vector<CProvince *> _provinces; // acc
		sstd::vector<CCountry *> _countries; // adc
		sstd::vector<int> _player_nations; // aec
		sstd::vector<void *> _unk_0xafc;
		CEU3Date _current_date; // b0c
		CEU3Date _start_date; // b10
		uint32_t _uk_0xb14;
		uint32_t _uk_0xb18;
		uint32_t _uk_0xb1c;
		uint32_t _uk_0xb20;
		CInGameIdler *_idler; // b24
		uint32_t _uk_0xb28;
		uint32_t _uk_0xb2c;
		uint32_t _uk_0xb30;
		uint32_t _uk_0xb34;
		uint32_t _uk_0xb38;
		clausewitz::CList<CWar *> _ongoing_wars; // b3c
		uint32_t _uk_0xb4c;
		uint32_t _uk_0xb50;
		uint32_t _uk_0xb54;
		uint32_t _uk_0xb58;
		CCountryTag _player_tag; // b5c
		uint32_t _uk_0xb64;
		uint32_t _uk_0xb68;
		uint32_t _uk_0xb6c;
		uint32_t _uk_0xb70;
		sstd::vector<void *> _uk_0xb74;
		int _uk_0xb84;
		uint32_t _uk_0xb88;
		uint32_t _uk_0xb8c;
		uint32_t _uk_0xb90;
		bool _great_wars_enabled; // b94
		bool _world_wars_enabled; // b95
		sstd::vector<clausewitz::CList<CRebelFaction *>> _rebel_factions; // b98
		uint32_t _uk_0xba8;
		CGamePlaySettings _gameplay_settings; // bac
		uint32_t _uk_0xbb8;
		uint32_t _uk_0xbbc;
		uint32_t _uk_0xbc0;
		uint32_t _uk_0xbc4;
		uint32_t _uk_0xbc8;
		CWorldMarket *_world_market; // bcc
		sstd::vector<CCountry *> _country_vec; // bd0 TODO: differentiate from _countries field. believe this one is sorted, the other may not be
		sstd::vector<CCountry *> _great_powers; // be0
		uint32_t _uk_0xbf0;
		uint32_t _uk_0xbf4;
		uint32_t _uk_0xbf8;
		uint32_t _uk_0xbfc;
		sstd::vector<int> _discovered_inventions; // c00
		uint32_t _uk_0xc10;
		CGoodsPool _overseas_penalty; // c14
		CGoodsPool _unit_cost; // c6c
		uint32_t _uk_0xcc4;
		uint32_t _uk_0xcc8;
		uint32_t _uk_0xccc;
		uint32_t _uk_0xcd0;
		clausewitz::CList<int> _pop_growth; // cd4
		uint32_t _uk_0xce4;
		CCountryTag _pop_growth_tag; // ce8
		CEU3Date _pop_growth_date; // cf0
		void *_news_collector; // cf4
		void *_crisis_manager; // cf8
		uint32_t _uk_0xcfc;
		uint32_t _uk_0xd00;
		uint32_t _uk_0xd04;
	public:
		virtual ~CGameState();
	};

	static_assert(sizeof(CGameState) == 0xd08);

}