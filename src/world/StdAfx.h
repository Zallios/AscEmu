/*
Copyright (c) 2014-2019 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

#pragma once

#include "WorldConf.h"

#ifdef USE_PCH_INCLUDES
#include <vector>
#include <fstream>
#include <array>
#include <set>
#include <map>

//////////////////////////////////////////////////////////////////////////////////////////
// Shared headers/defines

#include "CommonDefines.hpp"    // QuestLogEntry.h, Object.h
#include "Common.hpp"
#include "WorldPacket.h"
#include "Log.hpp"
#include "ByteBuffer.h"
#include "StackBuffer.h"
#include "Config/Config.h"
#include "crc32.h"
#include "LocationVector.h"
#include "Database/DatabaseEnv.h"
#include "Network/Network.h"
#include "Auth/MD5.h"
#include "Auth/BigNumber.h"
#include "Auth/Sha1.h"          // Mutex.h, Guard.h errors
#include "Auth/WowCrypt.h"
#include "FastQueue.h"
#include "CircularQueue.h"
#include "Threading/RWLock.h"
#include "TLSObject.h"
#include "AuthCodes.h"
#include "CallBack.h"
#include "CThreads.h"

#ifdef WIN32
    #include "printStackTrace.h"
#endif
//////////////////////////////////////////////////////////////////////////////////////////

//Movement
#include "Movement/UnitMovementManager.hpp"
#include "Movement/Spline/MovementSpline.hpp"
#include "Movement/Spline/MovementSplineDefines.hpp"
#include "Movement/Spline/SplineFlags.hpp"
#include "Movement/MovementCommon.hpp"

//VMAP
#include "Models/ModelInstance.h"
#include "Models/WorldModel.h"
#include "BoundingIntervalHierarchy.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "VMapDefinitions.h"

// Chat
#include "Chat/ChatCommand.hpp"
#include "Chat/ChatDefines.hpp"
#include "Chat/ChatHandler.hpp"
#include "Chat/CommandTableStorage.hpp"

// Data
#include "Data/Flags.h"
#include "Data/GuidData.h"
#include "Data/WoWContainer.h"
#include "Data/WoWCorpse.h"
#include "Data/WoWDynamicObject.h"
#include "Data/WoWGameObject.h"
#include "Data/WoWItem.h"
#include "Data/WoWObject.h"
#include "Data/WoWPlayer.h"
#include "Data/WoWUnit.h"

// Management
#if VERSION_STRING == Cata
#include "GameCata/Management/GuildFinderMgr.h"
#elif VERSION_STRING == Mop
#include "GameMop/Management/GuildFinderMgr.h"
#endif

#include "Management/AchievementMgr.h"
#include "Management/AddonMgr.h"
#include "Management/Arenas.h"
#include "Management/ArenaTeam.h"
#include "Management/AuctionHouse.h"
#include "Management/AuctionMgr.h"
#include "Management/CalendarMgr.h"
#include "Management/Channel.h"
#include "Management/ChannelMgr.h"
#include "Management/Container.h"
#include "Management/CRitual.h"
#include "Management/EquipmentSetMgr.h"
#include "Management/GameEvent.h"
#include "Management/GameEventMgr.h"
#include "Management/Group.h"
#include "Management/Guild.h"
#include "Management/GuildBankTab.h"
#include "Management/GuildBankEventLog.h"
#include "Management/GuildBankRightsAndSlots.h"
#include "Management/GuildEventLog.h"
#include "Management/GuildEmblemInfo.h"
#include "Management/GuildLog.h"
#include "Management/GuildLogHolder.h"
#include "Management/GuildMgr.h"
#include "Management/GuildNewsLog.h"
#include "Management/GuildRankInfo.h"
#include "Management/HonorHandler.h"
#include "Management/Item.h"
#include "Management/ItemInterface.h"
#include "Management/ItemPrototype.h"
#include "Management/LootMgr.h"
#include "Management/MailMgr.h"
#include "Management/Quest.h"
#include "Management/QuestDefines.hpp"
#include "Management/QuestLogEntry.hpp"
#include "Management/QuestMgr.h"
#include "Management/Skill.h"
#include "Management/SkillNameMgr.h"
#include "Management/TaxiMgr.h"
#include "Management/TransporterHandler.h"
#include "Management/WeatherMgr.h"
#include "Management/WordFilter.h"
#include "Management/WorldStates.h"
#include "Management/WorldStatesHandler.h"

#include "Management/Battleground/Battleground.h"
#include "Management/Battleground/BattlegroundMgr.h"

#include "Management/Gossip/Gossip.h"
#include "Management/Gossip/GossipDefines.hpp"

#include "Management/Guild/GuildDefinitions.h"

#include "Management/LFG/LFG.h"
#include "Management/LFG/LFGGroupData.h"
#include "Management/LFG/LFGMgr.h"
#include "Management/LFG/LFGPlayerData.h"

// Map
#include "Map/CellHandler.h"
#include "Map/CellHandlerDefines.hpp"
#include "Map/Map.h"
#include "Map/MapCell.h"
#include "Map/MapManagementGlobals.hpp"
#include "Map/MapMgr.h"
#include "Map/MapMgrDefines.hpp"
#include "Map/MapScriptInterface.h"
#include "Map/RecastIncludes.hpp"
#include "Map/TerrainMgr.h"
#include "Map/WorldCreator.h"
#include "Map/WorldCreatorDefines.hpp"

// Map/Area
#include "Map/Area/AreaManagementGlobals.hpp"
#include "Map/Area/AreaStorage.hpp"

// Objects
#include "Objects/CObjectFactory.h"
#include "Objects/DynamicObject.h"
#include "Objects/Faction.h"
#include "Objects/GameObject.h"
#include "Objects/MovementInfo.h"
#include "Objects/Object.h"
#include "Objects/ObjectMgr.h"
#include "Objects/ObjectDefines.h"

// Server
#include "Server/CharacterErrors.h"
#include "Server/BroadcastMgr.h"
#include "Server/Definitions.h"
#include "Server/EventableObject.h"
#include "Server/EventMgr.h"
#include "Server/IUpdatable.h"
#include "Server/UpdateFieldInclude.h"
#include "Server/UpdateMask.h"
#include "Server/LazyTimer.h"
#include "Server/MainServerDefines.h"
#include "Server/Master.h"
#include "Server/ServerState.h"
#include "Server/World.h"
#include "Server/World.Legacy.h"
#include "Server/WorldConfig.h"
#include "Server/WorldRunnable.h"
#include "Server/WorldSession.h"
#include "Server/WorldSocket.h"
#include "Server/WUtil.h"

// Server/Console
#include "Server/Console/BaseConsole.h"
#include "Server/Console/ConsoleAuthMgr.h"
#include "Server/Console/ConsoleCommands.h"
#include "Server/Console/ConsoleSocket.h"
#include "Server/Console/ConsoleThread.h"

// Server/LogonCommClient
#include "Server/LogonCommClient/LogonCommClient.h"
#include "Server/LogonCommClient/LogonCommHandler.h"

// Server/Packets
#include "Server/Packets/CmsgAddFriend.h"
#include "Server/Packets/CmsgAddIgnore.h"
#include "Server/Packets/CmsgAreaSpiritHealerQuery.h"
#include "Server/Packets/CmsgAreaSpiritHealerQueue.h"
#include "Server/Packets/CmsgAreatrigger.h"
#include "Server/Packets/CmsgAttackSwing.h"
#include "Server/Packets/CmsgAuctionListIBidderItemse.h"
#include "Server/Packets/CmsgAuctionListIPendingSales.h"
#include "Server/Packets/CmsgAuctionListItems.h"
#include "Server/Packets/CmsgAuctionListOwnerItems.h"
#include "Server/Packets/CmsgAuctionPlaceBid.h"
#include "Server/Packets/CmsgAuctionRemoveItem.h"
#include "Server/Packets/CmsgAuctionSellItem.h"
#include "Server/Packets/CmsgAutostoreLootItem.h"
#include "Server/Packets/CmsgBankerActivate.h"
#include "Server/Packets/CmsgBattlefieldList.h"
#include "Server/Packets/CmsgBattlefieldPort.h"
#include "Server/Packets/CmsgBattlemasterHello.h"
#include "Server/Packets/CmsgBattlemasterJoinArena.h"
#include "Server/Packets/CmsgBinderActivate.h"
#include "Server/Packets/CmsgBuyBankSlot.h"
#include "Server/Packets/CmsgBuyItem.h"
#include "Server/Packets/CmsgCastSpell.h"
#include "Server/Packets/CmsgChangeSeatsOnControlledVehicle.h"
#include "Server/Packets/CmsgChannelAnnouncements.h"
#include "Server/Packets/CmsgChannelDisplayList.h"
#include "Server/Packets/CmsgChannelBan.h"
#include "Server/Packets/CmsgChannelInvite.h"
#include "Server/Packets/CmsgChannelKick.h"
#include "Server/Packets/CmsgChannelList.h"
#include "Server/Packets/CmsgChannelModerate.h"
#include "Server/Packets/CmsgChannelModerator.h"
#include "Server/Packets/CmsgChannelMute.h"
#include "Server/Packets/CmsgChannelOwner.h"
#include "Server/Packets/CmsgChannelPassword.h"
#include "Server/Packets/CmsgChannelSetOwner.h"
#include "Server/Packets/CmsgChannelUnban.h"
#include "Server/Packets/CmsgChannelUnmoderator.h"
#include "Server/Packets/CmsgChannelUnmute.h"
#include "Server/Packets/CmsgCharCreate.h"
#include "Server/Packets/CmsgCharCustomize.h"
#include "Server/Packets/CmsgCharDelete.h"
#include "Server/Packets/CmsgCharFactionChange.h"
#include "Server/Packets/CmsgCharRename.h"
#include "Server/Packets/CmsgChatIgnored.h"
#include "Server/Packets/CmsgClearTradeItem.h"
#include "Server/Packets/CmsgComplaint.h"
#include "Server/Packets/CmsgContactList.h"
#include "Server/Packets/CmsgCreatureQuery.h"
#include "Server/Packets/CmsgDelFriend.h"
#include "Server/Packets/CmsgDelIgnore.h"
#include "Server/Packets/CmsgDismissCritter.h"
#include "Server/Packets/CmsgEjectPassenger.h"
#include "Server/Packets/CmsgEmote.h"
#include "Server/Packets/CmsgGameobjectQuery.h"
#include "Server/Packets/CmsgGameobjReportUse.h"
#include "Server/Packets/CmsgGetChannelMemberCount.h"
#include "Server/Packets/CmsgGossipHello.h"
#include "Server/Packets/CmsgGossipSelectOption.h"
#include "Server/Packets/CmsgGroupAssistantLeader.h"
#include "Server/Packets/CmsgGroupChangeSubGroup.h"
#include "Server/Packets/CmsgGroupInvite.h"
#include "Server/Packets/CmsgGroupSetLeader.h"
#include "Server/Packets/CmsgGroupUninvite.h"
#include "Server/Packets/CmsgGroupUninviteGuid.h"
#include "Server/Packets/CmsgGuildAddRank.h"
#include "Server/Packets/CmsgGuildBankBuyTab.h"
#include "Server/Packets/CmsgGuildBankDepositMoney.h"
#include "Server/Packets/CmsgGuildBankerActivate.h"
#include "Server/Packets/CmsgGuildBankQueryTab.h"
#include "Server/Packets/CmsgGuildBankQueryText.h"
#include "Server/Packets/CmsgGuildBankSwapItems.h"
#include "Server/Packets/CmsgGuildBankUpdateTab.h"
#include "Server/Packets/CmsgGuildBankWithdrawMoney.h"
#include "Server/Packets/CmsgGuildDelRank.h"
#include "Server/Packets/CmsgGuildDemote.h"
#include "Server/Packets/CmsgGuildInfoText.h"
#include "Server/Packets/CmsgGuildInvite.h"
#include "Server/Packets/CmsgGuildLeader.h"
#include "Server/Packets/CmsgGuildMotd.h"
#include "Server/Packets/CmsgGuildPromote.h"
#include "Server/Packets/CmsgGuildQuery.h"
#include "Server/Packets/CmsgGuildRemove.h"
#include "Server/Packets/CmsgGuildSetNote.h"
#include "Server/Packets/CmsgGuildSetOfficerNote.h"
#include "Server/Packets/CmsgGuildSetPublicNote.h"
#include "Server/Packets/CmsgGuildSetRank.h"
#include "Server/Packets/CmsgInitiateTrade.h"
#include "Server/Packets/CmsgInspectAchievements.h"
#include "Server/Packets/CmsgItemNameQuery.h"
#include "Server/Packets/CmsgItemQuerySingle.h"
#include "Server/Packets/CmsgJoinChannel.h"
#include "Server/Packets/CmsgLeaveChannel.h"
#include "Server/Packets/CmsgListInventory.h"
#include "Server/Packets/CmsgLootMasterGive.h"
#include "Server/Packets/CmsgLootMethod.h"
#include "Server/Packets/CmsgLootRoll.h"
#include "Server/Packets/CmsgMessageChat.h"
#include "Server/Packets/CmsgNameQuery.h"
#include "Server/Packets/CmsgNpcTextQuery.h"
#include "Server/Packets/CmsgOfferPetition.h"
#include "Server/Packets/CmsgOpenItem.h"
#include "Server/Packets/CmsgOptOutOfLoot.h"
#include "Server/Packets/CmsgPageTextQuery.h"
#include "Server/Packets/CmsgPetAction.h"
#include "Server/Packets/CmsgPetCancelAura.h"
#include "Server/Packets/CmsgPetitionBuy.h"
#include "Server/Packets/CmsgPetitionQuery.h"
#include "Server/Packets/CmsgPetitionShowlist.h"
#include "Server/Packets/CmsgPetitionShowSignatures.h"
#include "Server/Packets/CmsgPetitionSign.h"
#include "Server/Packets/CmsgPetLearnTalent.h"
#include "Server/Packets/CmsgPetNameQuery.h"
#include "Server/Packets/CmsgPetRename.h"
#include "Server/Packets/CmsgPetSetAction.h"
#include "Server/Packets/CmsgPetSpellAutocast.h"
#include "Server/Packets/CmsgPetUnlearn.h"
#include "Server/Packets/CmsgPlayedTime.h"
#include "Server/Packets/CmsgPlayerLogin.h"
#include "Server/Packets/CmsgPlayerVehicleEnter.h"
#include "Server/Packets/CmsgQueryTime.h"
#include "Server/Packets/CmsgRealmSplit.h"
#include "Server/Packets/CmsgRequestPartyMemberStats.h"
#include "Server/Packets/CmsgRequestVehicleSwitchSeat.h"
#include "Server/Packets/CmsgSellItem.h"
#include "Server/Packets/CmsgSetActionbarToggles.h"
#include "Server/Packets/CmsgSetActionButton.h"
#include "Server/Packets/CmsgSetActiveMover.h"
#include "Server/Packets/CmsgSetChannelWatch.h"
#include "Server/Packets/CmsgSetContactNotes.h"
#include "Server/Packets/CmsgSetFactionAtWar.h"
#include "Server/Packets/CmsgSetFactionInactive.h"
#include "Server/Packets/CmsgSetGuildBankText.h"
#include "Server/Packets/CmsgSetPlayerDeclinedNames.h"
#include "Server/Packets/CmsgSetSelection.h"
#include "Server/Packets/CmsgSetSheathed.h"
#include "Server/Packets/CmsgSetTaxiBenchmarkMode.h"
#include "Server/Packets/CmsgSetTitle.h"
#include "Server/Packets/CmsgSetTradeGold.h"
#include "Server/Packets/CmsgSetTradeItem.h"
#include "Server/Packets/CmsgSetWatchedFaction.h"
#include "Server/Packets/CmsgStableSwapPet.h"
#include "Server/Packets/CmsgStandStateChange.h"
#include "Server/Packets/CmsgTextEmote.h"
#include "Server/Packets/CmsgTrainerBuySpell.h"
#include "Server/Packets/CmsgTrainerList.h"
#include "Server/Packets/CmsgTurnInPetition.h"
#include "Server/Packets/CmsgTutorialFlag.h"
#include "Server/Packets/CmsgUnstablePet.h"
#include "Server/Packets/CmsgWho.h"
#include "Server/Packets/ManagedPacket.h"
#include "Server/Packets/MovementPacket.h"
#include "Server/Packets/MsgAuctionHello.h"
#include "Server/Packets/MsgBattlegroundPlayerPosition.h"
#include "Server/Packets/MsgCorpseQuery.h"
#include "Server/Packets/MsgGuildBankLogQuery.h"
#include "Server/Packets/MsgGuildBankMoneyWithdrawn.h"
#include "Server/Packets/MsgInspectArenaTeams.h"
#include "Server/Packets/MsgInspectHonorStats.h"
#include "Server/Packets/MsgListStabledPets.h"
#include "Server/Packets/MsgMinimapPing.h"
#include "Server/Packets/MsgMoveFallLand.h"
#include "Server/Packets/MsgPartyAssign.h"
#include "Server/Packets/MsgPetitionDecline.h"
#include "Server/Packets/MsgPetitionRename.h"
#include "Server/Packets/MsgQueryGuildBankText.h"
#include "Server/Packets/MsgRaidReadyCheck.h"
#include "Server/Packets/MsgRaidTargetUpdate.h"
#include "Server/Packets/MsgRandomRoll.h"
#include "Server/Packets/MsgSaveGuildEmblem.h"
#include "Server/Packets/MsgSetDungeonDifficulty.h"
#include "Server/Packets/MsgSetRaidDifficulty.h"
#include "Server/Packets/MsgTabardvendorActivate.h"
#include "Server/Packets/Opcode.h"
#include "Server/Packets/SmsgAreaSpiritHealerTime.h"
#include "Server/Packets/SmsgAreaTriggerMessage.h"
#include "Server/Packets/SmsgArenaError.h"
#include "Server/Packets/SmsgAuctionCommandResult.h"
#include "Server/Packets/SmsgBinderConfirm.h"
#include "Server/Packets/SmsgBindPointUpdate.h"
#include "Server/Packets/SmsgBuyBankSlotResult.h"
#include "Server/Packets/SmsgBuyFailed.h"
#include "Server/Packets/SmsgBuyItem.h"
#include "Server/Packets/SmsgChannelMemberCount.h"
#include "Server/Packets/SmsgCharacterLoginFailed.h"
#include "Server/Packets/SmsgCharCreate.h"
#include "Server/Packets/SmsgCharCustomize.h"
#include "Server/Packets/SmsgCharDelete.h"
#include "Server/Packets/SmsgCharFactionChange.h"
#include "Server/Packets/SmsgCharRename.h"
#include "Server/Packets/SmsgCharEnum.h"
#include "Server/Packets/SmsgChatPlayerNotFound.h"
#include "Server/Packets/SmsgClearExtraAuraInfo.h"
#include "Server/Packets/SmsgComplainResult.h"
#include "Server/Packets/SmsgCreatureQueryResponse.h"
#include "Server/Packets/SmsgDestoyObject.h"
#include "Server/Packets/SmsgDuelComplete.h"
#include "Server/Packets/SmsgDuelCountdown.h"
#include "Server/Packets/SmsgEmote.h"
#include "Server/Packets/SmsgFeatureSystemStatus.h"
#include "Server/Packets/SmsgFriendStatus.h"
#include "Server/Packets/SmsgGameobjectQueryResponse.h"
#include "Server/Packets/SmsgGroupDecline.h"
#include "Server/Packets/SmsgGroupInvite.h"
#include "Server/Packets/SmsgGuildBankMoneyWithdrawn.h"
#include "Server/Packets/SmsgGuildBankQueryTextResult.h"
#include "Server/Packets/SmsgGuildCommandResult.h"
#include "Server/Packets/SmsgGuildInfo.h"
#include "Server/Packets/SmsgGuildInvite.h"
#include "Server/Packets/SmsgInitialSpells.h"
#include "Server/Packets/SmsgInstanceDifficulty.h"
#include "Server/Packets/SmsgItemNameQueryResponse.h"
#include "Server/Packets/SmsgLearnedDanceMoves.h"
#include "Server/Packets/SmsgLogoutResponse.h"
#include "Server/Packets/SmsgLootRemoved.h"
#include "Server/Packets/SmsgMessageChat.h"
#include "Server/Packets/SmsgMoveUnsetCanFly.h"
#include "Server/Packets/SmsgNameQueryResponse.h"
#include "Server/Packets/SmsgNewWorld.h"
#include "Server/Packets/SmsgPageTextQueryResponse.h"
#include "Server/Packets/SmsgPartyCommandResult.h"
#include "Server/Packets/SmsgPartyMemberStatsFull.h"
#include "Server/Packets/SmsgPetActionSound.h"
#include "Server/Packets/SmsgPetitionQueryResponse.h"
#include "Server/Packets/SmsgPetitionShowlist.h"
#include "Server/Packets/SmsgPetitionShowSignatures.h"
#include "Server/Packets/SmsgPetitionSignResult.h"
#include "Server/Packets/SmsgPetNameQuery.h"
#include "Server/Packets/SmsgPlayedTime.h"
#include "Server/Packets/SmsgQueryTimeResponse.h"
#include "Server/Packets/SmsgQuestgiverStatusMultiple.h"
#include "Server/Packets/SmsgRealmSplit.h"
#include "Server/Packets/SmsgSellItem.h"
#include "Server/Packets/SmsgSetExtraAuraInfo.h"
#include "Server/Packets/SmsgSetPlayerDeclinedNamesResult.h"
#include "Server/Packets/SmsgSetProficiency.h"
#include "Server/Packets/SmsgShowBank.h"
#include "Server/Packets/SmsgSpiritHealerConfirm.h"
#include "Server/Packets/SmsgStableResult.h"
#include "Server/Packets/SmsgTextEmote.h"
#include "Server/Packets/SmsgTradeStatus.h"
#include "Server/Packets/SmsgTrainerBuySucceeded.h"
#include "Server/Packets/SmsgTutorialFlags.h"
#include "Server/Packets/SmsgUpdateAuraDuration.h"
#include "Server/Packets/SmsgWorldStateUiTimerUpdate.h"
#include "Server/Packets/Movement/CreatureMovement.h"

// Server/Script
#include "Server/Script/CreatureAIScript.h"
#include "Server/Script/InstanceScript.h"
#include "Server/Script/ScriptMgr.h"

// Server/Warden
#include "Server/Warden/SpeedDetector.h"

// Spell
#include "Spell/Spell.h"
#include "Spell/Spell.Legacy.h"
#include "Spell/SpellAuras.h"
#include "Spell/SpellCastTargets.h"
#include "Spell/SpellDefines.hpp"
#include "Spell/Definitions/SpellEffects.h"
#include "Spell/Definitions/SpellFailure.h"
#include "Spell/SpellHelpers.h"
#include "Spell/SpellInfo.hpp"
#include "Spell/SpellMgr.h"
#include "Spell/SpellProc.h"
#include "Spell/SpellTarget.h"
#include "Spell/SpellTargetConstraint.h"

// Spell/Customization
#include "Spell/Customization/SpellCustomizations.hpp"

// Spell/Definitions
#include "Spell/Definitions/AuraEffects.h"
#include "Spell/Definitions/AuraInterruptFlags.h"
#include "Spell/Definitions/AuraStates.h"
#include "Spell/Definitions/CastInterruptFlags.h"
#include "Spell/Definitions/ChannelInterruptFlags.h"
#include "Spell/Definitions/DiminishingGroup.h"
#include "Spell/Definitions/DispelType.h"
#include "Spell/Definitions/LockTypes.h"
#include "Spell/Definitions/PowerType.h"
#include "Spell/Definitions/PreventionType.h"
#include "Spell/Definitions/ProcFlags.h"
#include "Spell/Definitions/School.h"
#include "Spell/Definitions/Spec.h"
#include "Spell/Definitions/SpellCastTargetFlags.h"
#include "Spell/Definitions/SpellClickSpell.h"
#include "Spell/Definitions/SpellDamageType.h"
#include "Spell/Definitions/SpellDidHitResult.h"
#include "Spell/Definitions/SpellEffectTarget.h"
#include "Spell/Definitions/SpellGoFlags.h"
#include "Spell/Definitions/SpellInFrontStatus.h"
#include "Spell/Definitions/SpellIsFlags.h"
#include "Spell/Definitions/SpellLog.h"
#include "Spell/Definitions/SpellMechanics.h"
#include "Spell/Definitions/SpellModifierType.h"
#include "Spell/Definitions/SpellRanged.h"
#include "Spell/Definitions/SpellSchoolConversionTable.h"
#include "Spell/Definitions/SpellState.h"
#include "Spell/Definitions/SpellTargetMod.h"
#include "Spell/Definitions/SpellTargetType.h"
#include "Spell/Definitions/SpellTypes.h"
#include "Spell/Definitions/SummonControlTypes.h"
#include "Spell/Definitions/SummonTypes.h"
#include "Spell/Definitions/TeleportCoords.h"
#include "Spell/Definitions/TeleportEffectCustomFlags.h"


// Storage
#include "Storage/DayWatcherThread.h"
#include "Storage/MySQLDataStore.hpp"
#include "Storage/MySQLStructures.h"
#include "Storage/WorldStrings.h"

// Storage/DB2
#if VERSION_STRING >= Cata
#include "Storage/DB2/DB2Loader.h"
#include "Storage/DB2/DB2Storage.h"
#include "Storage/DB2/DB2Stores.h"
#include "Storage/DB2/DB2Structures.h"
#endif

// Storage/DBC
#include "Storage/DBC/DBCGlobals.hpp"
#include "Storage/DBC/DBCLoader.hpp"
#include "Storage/DBC/DBCRecord.hpp"
#include "Storage/DBC/DBCSQL.hpp"
#include "Storage/DBC/DBCStorage.hpp"
#include "Storage/DBC/DBCStores.h"
#include "Storage/DBC/DBCStructures.hpp"

// Units
#include "Units/Stats.h"
#include "Units/Unit.h"
#include "Units/UnitDefines.hpp"

// Units/Creatures
#include "Units/Creatures/AIEvents.h"
#include "Units/Creatures/AIInterface.h"
#include "Units/Creatures/Corpse.h"
#include "Units/Creatures/Creature.h"
#include "Units/Creatures/CreatureDefines.hpp"
#include "Units/Creatures/Pet.h"
#include "Units/Creatures/Vehicle.h"

// Units/Players
#include "Units/Players/Player.h"
#include "Units/Players/PlayerCache.h"
#include "Units/Players/PlayerClasses.hpp"
#include "Units/Players/PlayerDefines.hpp"

// Units/Summons
#include "Units/Summons/CompanionSummon.h"
#include "Units/Summons/GuardianSummon.h"
#include "Units/Summons/PossessedSummon.h"
#include "Units/Summons/Summon.h"
#include "Units/Summons/SummonDefines.hpp"
#include "Units/Summons/SummonHandler.h"
#include "Units/Summons/TotemSummon.h"
#include "Units/Summons/WildSummon.h"

#endif
