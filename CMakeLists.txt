#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
# Copyright (c) 2015-2017 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/

#/****************************************************************************
# DO NOT EDIT THE CMakeLists.txt DIRECTLY! PLEASE EDIT THE CMakeLists.template!
# TO UPDATE THE FILE LIST, RUN GenerateCMakeFiles.py!
#/****************************************************************************

cmake_minimum_required(VERSION 3.1)

set(APP_NAME Squally)

project(${APP_NAME})

set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

set(USE_COCOS_PREBUILT OFF)

include(CocosBuildSet)
if(NOT USE_COCOS_PREBUILT)
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)
endif()

# record sources, headers, resources...
set(GAME_SOURCE)
set(GAME_HEADER)

set(GAME_RES_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/Resources"
    )
if(APPLE OR WINDOWS)
    cocos_mark_multi_resources(common_res_files RES_TO "Resources" FOLDERS ${GAME_RES_FOLDER})
endif()

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/
        ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

# add cross-platforms source files
list(APPEND GAME_SOURCE
	# This is generated by GenerateCMakeFiles.py:
    Source/Bootstrapper.cpp
	Source/GameWindow.cpp
	Source/Resources.cpp
	Source/Engine/EngineBootstrapper.cpp
	Source/Engine/GlobalDirector.cpp
	Source/Engine/SmartNode.cpp
	Source/Engine/SmartScene.cpp
	Source/Engine/Camera/GameCamera.cpp
	Source/Engine/Config/ConfigManager.cpp
	Source/Engine/Cutscenes/Cutscene.cpp
	Source/Engine/Cutscenes/CutsceneClip.cpp
	Source/Engine/Dialogue/Dialogue.cpp
	Source/Engine/Dialogue/DialogueTree.cpp
	Source/Engine/Events/MouseEvents.cpp
	Source/Engine/Hackables/HackableAttribute.cpp
	Source/Engine/Hackables/HackableCode.cpp
	Source/Engine/Hackables/HackableData.cpp
	Source/Engine/Hackables/HackableObject.cpp
	Source/Engine/Input/InputManager.cpp
	Source/Engine/Input/MouseState.cpp
	Source/Engine/Localization/Localization.cpp
	Source/Engine/Maps/DefaultLayerDeserializer.cpp
	Source/Engine/Maps/ObjectifiedTile.cpp
	Source/Engine/Maps/SerializableLayer.cpp
	Source/Engine/Maps/SerializableMap.cpp
	Source/Engine/Maps/SerializableObject.cpp
	Source/Engine/Maps/SerializableTileLayer.cpp
	Source/Engine/Physics/CollisionDeserializer.cpp
	Source/Engine/Physics/CollisionObject.cpp
	Source/Engine/Save/SaveManager.cpp
	Source/Engine/Shaders/PostProcess.cpp
	Source/Engine/Shaders/ShaderUtils.cpp
	Source/Engine/Sound/SoundManager.cpp
	Source/Engine/UI/FadeScene.cpp
	Source/Engine/UI/FloatingSprite.cpp
	Source/Engine/UI/InfiniteParallaxNode.cpp
	Source/Engine/UI/Mouse.cpp
	Source/Engine/UI/Controls/CCheckbox.cpp
	Source/Engine/UI/Controls/CProgressBar.cpp
	Source/Engine/UI/Controls/CRadioButton.cpp
	Source/Engine/UI/Controls/CSlider.cpp
	Source/Engine/UI/Controls/EditableTextWindow.cpp
	Source/Engine/UI/Controls/MenuLabel.cpp
	Source/Engine/UI/Controls/MenuSprite.cpp
	Source/Engine/UI/Controls/MouseOverPanel.cpp
	Source/Engine/UI/Controls/ScrollPane.cpp
	Source/Engine/UI/Controls/TextMenuSprite.cpp
	Source/Engine/UI/Controls/TextWindow.cpp
	Source/Engine/UI/HUD/DeveloperHud.cpp
	Source/Engine/UI/HUD/HackerModeHud.cpp
	Source/Engine/UI/HUD/Hud.cpp
	Source/Engine/Utils/GameUtils.cpp
	Source/Engine/Utils/HackUtils.cpp
	Source/Engine/Utils/MathUtils.cpp
	Source/Engine/Utils/StrUtils.cpp
	Source/Entities/Isometric/IsometricEntity.cpp
	Source/Entities/Isometric/IsometricEntityDeserializer.cpp
	Source/Entities/Isometric/Shiftman.cpp
	Source/Entities/Isometric/Squally/IsometricSqually.cpp
	Source/Entities/Platformer/PlatformerCollisionMapping.cpp
	Source/Entities/Platformer/PlatformerEnemy.cpp
	Source/Entities/Platformer/PlatformerEntity.cpp
	Source/Entities/Platformer/PlatformerEntityDeserializer.cpp
	Source/Entities/Platformer/Enemies/Castle/BossJack.cpp
	Source/Entities/Platformer/Enemies/Castle/BossWitch.cpp
	Source/Entities/Platformer/Enemies/Castle/Executioner.cpp
	Source/Entities/Platformer/Enemies/Castle/Guard.cpp
	Source/Entities/Platformer/Enemies/Castle/Harpy.cpp
	Source/Entities/Platformer/Enemies/Castle/Reaper.cpp
	Source/Entities/Platformer/Enemies/Castle/SkeletonMage.cpp
	Source/Entities/Platformer/Enemies/Castle/VampireLord.cpp
	Source/Entities/Platformer/Enemies/Castle/Vampiress.cpp
	Source/Entities/Platformer/Enemies/Castle/Zombie.cpp
	Source/Entities/Platformer/Enemies/Caverns/BlackWidow.cpp
	Source/Entities/Platformer/Enemies/Caverns/BossKrampus.cpp
	Source/Entities/Platformer/Enemies/Caverns/EarthElemental.cpp
	Source/Entities/Platformer/Enemies/Caverns/EarthGolem.cpp
	Source/Entities/Platformer/Enemies/Caverns/ForestGolem.cpp
	Source/Entities/Platformer/Enemies/Caverns/Genie.cpp
	Source/Entities/Platformer/Enemies/Caverns/RockGolem.cpp
	Source/Entities/Platformer/Enemies/Caverns/Shaman.cpp
	Source/Entities/Platformer/Enemies/Caverns/SkeletonArcher.cpp
	Source/Entities/Platformer/Enemies/Caverns/SkeletonNecromancer.cpp
	Source/Entities/Platformer/Enemies/Caverns/SkeletonWarrior.cpp
	Source/Entities/Platformer/Enemies/Forest/BossDragonOrcKing.cpp
	Source/Entities/Platformer/Enemies/Forest/Cyclops.cpp
	Source/Entities/Platformer/Enemies/Forest/Ent.cpp
	Source/Entities/Platformer/Enemies/Forest/EntMage.cpp
	Source/Entities/Platformer/Enemies/Forest/GoblinGruntBoar.cpp
	Source/Entities/Platformer/Enemies/Forest/GoblinGuard.cpp
	Source/Entities/Platformer/Enemies/Forest/GoblinShaman.cpp
	Source/Entities/Platformer/Enemies/Forest/GoblinWarriorPig.cpp
	Source/Entities/Platformer/Enemies/Forest/OrcGrunt.cpp
	Source/Entities/Platformer/Enemies/Forest/OrcWarrior.cpp
	Source/Entities/Platformer/Enemies/Forest/Troll.cpp
	Source/Entities/Platformer/Enemies/Jungle/BossRhinoman.cpp
	Source/Entities/Platformer/Enemies/Jungle/GoblinGrunt.cpp
	Source/Entities/Platformer/Enemies/Jungle/GoblinSwordsman.cpp
	Source/Entities/Platformer/Enemies/Jungle/GoblinWarrior.cpp
	Source/Entities/Platformer/Enemies/Jungle/JungleDragon.cpp
	Source/Entities/Platformer/Enemies/Jungle/Mantis.cpp
	Source/Entities/Platformer/Enemies/Jungle/Minotaur.cpp
	Source/Entities/Platformer/Enemies/Jungle/PigDemon.cpp
	Source/Entities/Platformer/Enemies/Jungle/PurpleDinosaur.cpp
	Source/Entities/Platformer/Enemies/Jungle/TikiGolem.cpp
	Source/Entities/Platformer/Enemies/Jungle/TikiWarrior.cpp
	Source/Entities/Platformer/Enemies/Mech/BossEvilEye.cpp
	Source/Entities/Platformer/Enemies/Mech/Exterminator.cpp
	Source/Entities/Platformer/Enemies/Mech/MechBoxDrone.cpp
	Source/Entities/Platformer/Enemies/Mech/MechDog.cpp
	Source/Entities/Platformer/Enemies/Mech/MechGolem.cpp
	Source/Entities/Platformer/Enemies/Mech/MechGolemDark.cpp
	Source/Entities/Platformer/Enemies/Mech/MechGuard.cpp
	Source/Entities/Platformer/Enemies/Mech/MiteBot.cpp
	Source/Entities/Platformer/Enemies/Mech/Robot.cpp
	Source/Entities/Platformer/Enemies/Mech/VikingBot.cpp
	Source/Entities/Platformer/Enemies/Mech/VikingBotSmall.cpp
	Source/Entities/Platformer/Enemies/Obelisk/Abomination.cpp
	Source/Entities/Platformer/Enemies/Obelisk/BatDemon.cpp
	Source/Entities/Platformer/Enemies/Obelisk/BossSkeletonKing.cpp
	Source/Entities/Platformer/Enemies/Obelisk/DarkDragon.cpp
	Source/Entities/Platformer/Enemies/Obelisk/DemonArcher.cpp
	Source/Entities/Platformer/Enemies/Obelisk/SkeletonBaron.cpp
	Source/Entities/Platformer/Enemies/Obelisk/SkeletonCleaver.cpp
	Source/Entities/Platformer/Enemies/Obelisk/SkeletonKnight.cpp
	Source/Entities/Platformer/Enemies/Obelisk/SkeletonPriestess.cpp
	Source/Entities/Platformer/Enemies/Obelisk/Undead.cpp
	Source/Entities/Platformer/Enemies/Obelisk/VoidDemon.cpp
	Source/Entities/Platformer/Enemies/Ruins/AnubisTiny.cpp
	Source/Entities/Platformer/Enemies/Ruins/AnubisWarrior.cpp
	Source/Entities/Platformer/Enemies/Ruins/BossEgyptianGoddess.cpp
	Source/Entities/Platformer/Enemies/Ruins/Lioness.cpp
	Source/Entities/Platformer/Enemies/Ruins/LionMan.cpp
	Source/Entities/Platformer/Enemies/Ruins/Medusa.cpp
	Source/Entities/Platformer/Enemies/Ruins/MedusaSmall.cpp
	Source/Entities/Platformer/Enemies/Ruins/Mermaid.cpp
	Source/Entities/Platformer/Enemies/Ruins/MummyPharaoh.cpp
	Source/Entities/Platformer/Enemies/Ruins/TigerMan.cpp
	Source/Entities/Platformer/Enemies/Ruins/Tigress.cpp
	Source/Entities/Platformer/Enemies/Snow/BossIceGolem.cpp
	Source/Entities/Platformer/Enemies/Snow/BossSanta.cpp
	Source/Entities/Platformer/Enemies/Snow/EvilSnowman.cpp
	Source/Entities/Platformer/Enemies/Snow/FrostDragon.cpp
	Source/Entities/Platformer/Enemies/Snow/FrostShooter.cpp
	Source/Entities/Platformer/Enemies/Snow/GoblinElf.cpp
	Source/Entities/Platformer/Enemies/Snow/IceGolem.cpp
	Source/Entities/Platformer/Enemies/Snow/TinyIceGolem.cpp
	Source/Entities/Platformer/Enemies/Snow/ToySoldierGoblin.cpp
	Source/Entities/Platformer/Enemies/Snow/WaterElemental.cpp
	Source/Entities/Platformer/Enemies/Snow/Yeti.cpp
	Source/Entities/Platformer/Enemies/Snow/YetiWarrior.cpp
	Source/Entities/Platformer/Enemies/Volcano/BossDemonKing.cpp
	Source/Entities/Platformer/Enemies/Volcano/CritterDemon.cpp
	Source/Entities/Platformer/Enemies/Volcano/DemonDragon.cpp
	Source/Entities/Platformer/Enemies/Volcano/DemonGhost.cpp
	Source/Entities/Platformer/Enemies/Volcano/DemonGrunt.cpp
	Source/Entities/Platformer/Enemies/Volcano/DemonRogue.cpp
	Source/Entities/Platformer/Enemies/Volcano/DemonShaman.cpp
	Source/Entities/Platformer/Enemies/Volcano/DemonSwordsman.cpp
	Source/Entities/Platformer/Enemies/Volcano/DemonWarrior.cpp
	Source/Entities/Platformer/Enemies/Volcano/FireElemental.cpp
	Source/Entities/Platformer/Enemies/Volcano/LavaGolem.cpp
	Source/Entities/Platformer/Npcs/Knight.cpp
	Source/Entities/Platformer/Npcs/NpcBase.cpp
	Source/Entities/Platformer/Squally/Hover.cpp
	Source/Entities/Platformer/Squally/Squally.cpp
	Source/Events/DialogEvents.cpp
	Source/Events/HackableEvents.cpp
	Source/Events/HexusEvents.cpp
	Source/Events/NavigationEvents.cpp
	Source/Objects/Isometric/HexusArcade.cpp
	Source/Objects/Isometric/IsometricDecorDeserializer.cpp
	Source/Objects/Isometric/IsometricDecorObject.cpp
	Source/Objects/Isometric/IsometricObjectDeserializer.cpp
	Source/Objects/Platformer/Chest.cpp
	Source/Objects/Platformer/Monitor.cpp
	Source/Objects/Platformer/ParallaxObject.cpp
	Source/Objects/Platformer/PlatformerDecorDeserializer.cpp
	Source/Objects/Platformer/PlatformerDecorObject.cpp
	Source/Objects/Platformer/PlatformerObjectDeserializer.cpp
	Source/Objects/Platformer/WarpGate.cpp
	Source/Objects/Platformer/WarpGateExactScanTutorial.cpp
	Source/Objects/Platformer/Wind.cpp
	Source/Objects/Platformer/Plushies/Plushie.cpp
	Source/Objects/Platformer/Plushies/PlushieMonkey.cpp
	Source/Scenes/SceneDirector.cpp
	Source/Scenes/Cutscenes/IntroCutscene/BoardMembers.cpp
	Source/Scenes/Cutscenes/IntroCutscene/HomeAssistantRobot.cpp
	Source/Scenes/Cutscenes/IntroCutscene/IntroCutscene.cpp
	Source/Scenes/Cutscenes/IntroCutscene/IntroSpace.cpp
	Source/Scenes/Cutscenes/IntroCutscene/NeonCity.cpp
	Source/Scenes/Cutscenes/IntroCutscene/RobotDoctor.cpp
	Source/Scenes/Cutscenes/IntroCutscene/SquallyUploadMars.cpp
	Source/Scenes/Cutscenes/IntroCutscene/SquallyUploadSpace.cpp
	Source/Scenes/Cutscenes/IntroCutscene/VaporLabs.cpp
	Source/Scenes/Cutscenes/IntroCutscene/VaporWeb.cpp
	Source/Scenes/Cutscenes/Objects/Explosion.cpp
	Source/Scenes/Cutscenes/Objects/FlyingCar.cpp
	Source/Scenes/Cutscenes/Objects/Grid.cpp
	Source/Scenes/Cutscenes/Objects/GridObject.cpp
	Source/Scenes/Cutscenes/Objects/Smoke.cpp
	Source/Scenes/Cutscenes/Objects/StarLayer.cpp
	Source/Scenes/Fights/Fight.cpp
	Source/Scenes/Hexus/Card.cpp
	Source/Scenes/Hexus/CardRow.cpp
	Source/Scenes/Hexus/CardStorage.cpp
	Source/Scenes/Hexus/Config.cpp
	Source/Scenes/Hexus/Deck.cpp
	Source/Scenes/Hexus/GameState.cpp
	Source/Scenes/Hexus/Hexus.cpp
	Source/Scenes/Hexus/CardData/CardData.cpp
	Source/Scenes/Hexus/CardData/CardList.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary0.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary1.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary10.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary11.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary12.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary13.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary14.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary15.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary2.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary3.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary4.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary5.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary6.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary7.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary8.cpp
	Source/Scenes/Hexus/CardData/Binary/CardBinary9.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal0.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal1.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal10.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal11.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal12.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal13.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal14.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal15.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal2.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal3.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal4.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal5.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal6.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal7.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal8.cpp
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal9.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex0.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex1.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex10.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex11.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex12.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex13.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex14.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex15.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex2.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex3.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex4.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex5.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex6.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex7.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex8.cpp
	Source/Scenes/Hexus/CardData/Hex/CardHex9.cpp
	Source/Scenes/Hexus/CardData/Special/CardAddition.cpp
	Source/Scenes/Hexus/CardData/Special/CardEnvironmentBinStorm.cpp
	Source/Scenes/Hexus/CardData/Special/CardEnvironmentClear.cpp
	Source/Scenes/Hexus/CardData/Special/CardEnvironmentDecStorm.cpp
	Source/Scenes/Hexus/CardData/Special/CardEnvironmentHexStorm.cpp
	Source/Scenes/Hexus/CardData/Special/CardFlip1.cpp
	Source/Scenes/Hexus/CardData/Special/CardFlip2.cpp
	Source/Scenes/Hexus/CardData/Special/CardFlip3.cpp
	Source/Scenes/Hexus/CardData/Special/CardFlip4.cpp
	Source/Scenes/Hexus/CardData/Special/CardInverse.cpp
	Source/Scenes/Hexus/CardData/Special/CardLogicalAnd.cpp
	Source/Scenes/Hexus/CardData/Special/CardLogicalOr.cpp
	Source/Scenes/Hexus/CardData/Special/CardLogicalXor.cpp
	Source/Scenes/Hexus/CardData/Special/CardShiftLeft.cpp
	Source/Scenes/Hexus/CardData/Special/CardShiftRight.cpp
	Source/Scenes/Hexus/CardData/Special/CardSubtraction.cpp
	Source/Scenes/Hexus/Components/Avatars.cpp
	Source/Scenes/Hexus/Components/Banners.cpp
	Source/Scenes/Hexus/Components/CardPreview.cpp
	Source/Scenes/Hexus/Components/CoinFlip.cpp
	Source/Scenes/Hexus/Components/ComponentBase.cpp
	Source/Scenes/Hexus/Components/ControlCombineStaged.cpp
	Source/Scenes/Hexus/Components/ControlDraw.cpp
	Source/Scenes/Hexus/Components/ControlEndTurn.cpp
	Source/Scenes/Hexus/Components/ControlNeutral.cpp
	Source/Scenes/Hexus/Components/ControlReplaceCards.cpp
	Source/Scenes/Hexus/Components/ControlSacrificeStaged.cpp
	Source/Scenes/Hexus/Components/ControlSelectionStaged.cpp
	Source/Scenes/Hexus/Components/DeckCardCountDisplay.cpp
	Source/Scenes/Hexus/Components/HandCardCountDisplay.cpp
	Source/Scenes/Hexus/Components/LossesDisplay.cpp
	Source/Scenes/Hexus/Components/PassButton.cpp
	Source/Scenes/Hexus/Components/RowTotals.cpp
	Source/Scenes/Hexus/Components/ScoreTotal.cpp
	Source/Scenes/Hexus/HelpMenus/BinaryHelpMenu.cpp
	Source/Scenes/Hexus/HelpMenus/HelpMenuBase.cpp
	Source/Scenes/Hexus/Opponents/HexusOpponentData.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataDemonKing.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataEgyptianGoddess.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataEvilEye.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataIceGolem.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataJack.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataKrampus.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataOrcKing.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataRhinoman.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataSanta.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataSkeletonKing.cpp
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataWitch.cpp
	Source/Scenes/Hexus/Opponents/Kickstarter/HexusOpponentDataKnight.cpp
	Source/Scenes/Hexus/Opponents/Npcs/HexusOpponentDataEgyptianMummy.cpp
	Source/Scenes/Maps/Isometric/IsometricMap.cpp
	Source/Scenes/Maps/Platformer/PlatformerMap.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/BackgroundBase.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/BackgroundDeserializer.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/JungleBackground.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/MountainBackground.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/ObeliskBackground.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/OceanBackground.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/SnowBackground.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/MatrixRain/MatrixLetter.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/MatrixRain/MatrixRain.cpp
	Source/Scenes/Maps/Platformer/Backgrounds/MatrixRain/MatrixStrand.cpp
	Source/Scenes/Maps/Platformer/Weather/Fireflies.cpp
	Source/Scenes/Maps/Platformer/Weather/Rain.cpp
	Source/Scenes/Maps/Platformer/Weather/Snow.cpp
	Source/Scenes/Maps/Platformer/Weather/WeatherDeserializer.cpp
	Source/Scenes/Menus/MenuBackground.cpp
	Source/Scenes/Menus/Confirmation/ConfirmationMenu.cpp
	Source/Scenes/Menus/Dialog/DialogMenu.cpp
	Source/Scenes/Menus/HackerMode/CodeEditor.cpp
	Source/Scenes/Menus/HackerMode/RadialMenu.cpp
	Source/Scenes/Menus/LoadingScreen/LoadingScreen.cpp
	Source/Scenes/Menus/Minigames/MinigamesMenu.cpp
	Source/Scenes/Menus/Minigames/Hexus/HexusMenu.cpp
	Source/Scenes/Menus/Minigames/Hexus/HexusOpponentFrame.cpp
	Source/Scenes/Menus/Minigames/Hexus/HexusPuzzleItem.cpp
	Source/Scenes/Menus/Minigames/Hexus/HexusPuzzleMenu.cpp
	Source/Scenes/Menus/Options/OptionsMenu.cpp
	Source/Scenes/Menus/Pause/PauseMenu.cpp
	Source/Scenes/Menus/SaveSelect/SaveSelectMenu.cpp
	Source/Scenes/Menus/Title/HackerMode.cpp
	Source/Scenes/Menus/Title/TitleScreen.cpp
	Source/Scenes/Menus/Title/TitleScreenBackground.cpp
	Source/Scenes/Menus/Tutorial/TutorialItem.cpp
	Source/Scenes/Menus/Tutorial/TutorialScreen.cpp
	Source/Scenes/Menus/WorldMap/MapNode.cpp
	Source/Scenes/Menus/WorldMap/WorldMap.cpp
	Source/Sound/MusicDeserializer.cpp
)

# add cross-platforms header files
list(APPEND GAME_HEADER
	# This is generated by GenerateCMakeFiles.py:
    Source/Bootstrapper.h
	Source/GameWindow.h
	Source/Resources.h
	Source/Engine/EngineBootstrapper.h
	Source/Engine/GlobalDirector.h
	Source/Engine/GlobalNode.h
	Source/Engine/SmartNode.h
	Source/Engine/SmartScene.h
	Source/Engine/Camera/GameCamera.h
	Source/Engine/Config/ConfigManager.h
	Source/Engine/Cutscenes/Cutscene.h
	Source/Engine/Cutscenes/CutsceneClip.h
	Source/Engine/Dialogue/Dialogue.h
	Source/Engine/Dialogue/DialogueTree.h
	Source/Engine/Events/MouseEvents.h
	Source/Engine/Hackables/HackableAttribute.h
	Source/Engine/Hackables/HackableCode.h
	Source/Engine/Hackables/HackableData.h
	Source/Engine/Hackables/HackableObject.h
	Source/Engine/Input/InputManager.h
	Source/Engine/Input/MouseState.h
	Source/Engine/Localization/Localization.h
	Source/Engine/Maps/DefaultLayerDeserializer.h
	Source/Engine/Maps/ILayerDeserializer.h
	Source/Engine/Maps/IObjectDeserializer.h
	Source/Engine/Maps/ObjectifiedTile.h
	Source/Engine/Maps/SerializableLayer.h
	Source/Engine/Maps/SerializableMap.h
	Source/Engine/Maps/SerializableObject.h
	Source/Engine/Maps/SerializableTileLayer.h
	Source/Engine/Physics/CategoryGroup.h
	Source/Engine/Physics/CollisionDeserializer.h
	Source/Engine/Physics/CollisionObject.h
	Source/Engine/Save/SaveManager.h
	Source/Engine/Shaders/PostProcess.h
	Source/Engine/Shaders/ShaderUtils.h
	Source/Engine/Sound/SoundManager.h
	Source/Engine/UI/FadeScene.h
	Source/Engine/UI/FloatingSprite.h
	Source/Engine/UI/InfiniteParallaxNode.h
	Source/Engine/UI/Mouse.h
	Source/Engine/UI/Controls/CCheckbox.h
	Source/Engine/UI/Controls/CProgressBar.h
	Source/Engine/UI/Controls/CRadioButton.h
	Source/Engine/UI/Controls/CSlider.h
	Source/Engine/UI/Controls/EditableTextWindow.h
	Source/Engine/UI/Controls/MenuLabel.h
	Source/Engine/UI/Controls/MenuSprite.h
	Source/Engine/UI/Controls/MouseOverPanel.h
	Source/Engine/UI/Controls/ScrollPane.h
	Source/Engine/UI/Controls/TextMenuSprite.h
	Source/Engine/UI/Controls/TextWindow.h
	Source/Engine/UI/HUD/DeveloperHud.h
	Source/Engine/UI/HUD/HackerModeHud.h
	Source/Engine/UI/HUD/Hud.h
	Source/Engine/Utils/GameUtils.h
	Source/Engine/Utils/HackUtils.h
	Source/Engine/Utils/MathUtils.h
	Source/Engine/Utils/StrUtils.h
	Source/Entities/Isometric/IsometricEntities.h
	Source/Entities/Isometric/IsometricEntity.h
	Source/Entities/Isometric/IsometricEntityDeserializer.h
	Source/Entities/Isometric/Shiftman.h
	Source/Entities/Isometric/Squally/IsometricSqually.h
	Source/Entities/Platformer/PlatformerCollisionMapping.h
	Source/Entities/Platformer/PlatformerEnemy.h
	Source/Entities/Platformer/PlatformerEntities.h
	Source/Entities/Platformer/PlatformerEntity.h
	Source/Entities/Platformer/PlatformerEntityDeserializer.h
	Source/Entities/Platformer/Enemies/Castle/BossJack.h
	Source/Entities/Platformer/Enemies/Castle/BossWitch.h
	Source/Entities/Platformer/Enemies/Castle/Executioner.h
	Source/Entities/Platformer/Enemies/Castle/Guard.h
	Source/Entities/Platformer/Enemies/Castle/Harpy.h
	Source/Entities/Platformer/Enemies/Castle/Reaper.h
	Source/Entities/Platformer/Enemies/Castle/SkeletonMage.h
	Source/Entities/Platformer/Enemies/Castle/VampireLord.h
	Source/Entities/Platformer/Enemies/Castle/Vampiress.h
	Source/Entities/Platformer/Enemies/Castle/Zombie.h
	Source/Entities/Platformer/Enemies/Caverns/BlackWidow.h
	Source/Entities/Platformer/Enemies/Caverns/BossKrampus.h
	Source/Entities/Platformer/Enemies/Caverns/EarthElemental.h
	Source/Entities/Platformer/Enemies/Caverns/EarthGolem.h
	Source/Entities/Platformer/Enemies/Caverns/ForestGolem.h
	Source/Entities/Platformer/Enemies/Caverns/Genie.h
	Source/Entities/Platformer/Enemies/Caverns/RockGolem.h
	Source/Entities/Platformer/Enemies/Caverns/Shaman.h
	Source/Entities/Platformer/Enemies/Caverns/SkeletonArcher.h
	Source/Entities/Platformer/Enemies/Caverns/SkeletonNecromancer.h
	Source/Entities/Platformer/Enemies/Caverns/SkeletonWarrior.h
	Source/Entities/Platformer/Enemies/Forest/BossDragonOrcKing.h
	Source/Entities/Platformer/Enemies/Forest/Cyclops.h
	Source/Entities/Platformer/Enemies/Forest/Ent.h
	Source/Entities/Platformer/Enemies/Forest/EntMage.h
	Source/Entities/Platformer/Enemies/Forest/GoblinGruntBoar.h
	Source/Entities/Platformer/Enemies/Forest/GoblinGuard.h
	Source/Entities/Platformer/Enemies/Forest/GoblinShaman.h
	Source/Entities/Platformer/Enemies/Forest/GoblinWarriorPig.h
	Source/Entities/Platformer/Enemies/Forest/OrcGrunt.h
	Source/Entities/Platformer/Enemies/Forest/OrcWarrior.h
	Source/Entities/Platformer/Enemies/Forest/Troll.h
	Source/Entities/Platformer/Enemies/Jungle/BossRhinoman.h
	Source/Entities/Platformer/Enemies/Jungle/GoblinGrunt.h
	Source/Entities/Platformer/Enemies/Jungle/GoblinSwordsman.h
	Source/Entities/Platformer/Enemies/Jungle/GoblinWarrior.h
	Source/Entities/Platformer/Enemies/Jungle/JungleDragon.h
	Source/Entities/Platformer/Enemies/Jungle/Mantis.h
	Source/Entities/Platformer/Enemies/Jungle/Minotaur.h
	Source/Entities/Platformer/Enemies/Jungle/PigDemon.h
	Source/Entities/Platformer/Enemies/Jungle/PurpleDinosaur.h
	Source/Entities/Platformer/Enemies/Jungle/TikiGolem.h
	Source/Entities/Platformer/Enemies/Jungle/TikiWarrior.h
	Source/Entities/Platformer/Enemies/Mech/BossEvilEye.h
	Source/Entities/Platformer/Enemies/Mech/Exterminator.h
	Source/Entities/Platformer/Enemies/Mech/MechBoxDrone.h
	Source/Entities/Platformer/Enemies/Mech/MechDog.h
	Source/Entities/Platformer/Enemies/Mech/MechGolem.h
	Source/Entities/Platformer/Enemies/Mech/MechGolemDark.h
	Source/Entities/Platformer/Enemies/Mech/MechGuard.h
	Source/Entities/Platformer/Enemies/Mech/MiteBot.h
	Source/Entities/Platformer/Enemies/Mech/Robot.h
	Source/Entities/Platformer/Enemies/Mech/VikingBot.h
	Source/Entities/Platformer/Enemies/Mech/VikingBotSmall.h
	Source/Entities/Platformer/Enemies/Obelisk/Abomination.h
	Source/Entities/Platformer/Enemies/Obelisk/BatDemon.h
	Source/Entities/Platformer/Enemies/Obelisk/BossSkeletonKing.h
	Source/Entities/Platformer/Enemies/Obelisk/DarkDragon.h
	Source/Entities/Platformer/Enemies/Obelisk/DemonArcher.h
	Source/Entities/Platformer/Enemies/Obelisk/SkeletonBaron.h
	Source/Entities/Platformer/Enemies/Obelisk/SkeletonCleaver.h
	Source/Entities/Platformer/Enemies/Obelisk/SkeletonKnight.h
	Source/Entities/Platformer/Enemies/Obelisk/SkeletonPriestess.h
	Source/Entities/Platformer/Enemies/Obelisk/Undead.h
	Source/Entities/Platformer/Enemies/Obelisk/VoidDemon.h
	Source/Entities/Platformer/Enemies/Ruins/AnubisTiny.h
	Source/Entities/Platformer/Enemies/Ruins/AnubisWarrior.h
	Source/Entities/Platformer/Enemies/Ruins/BossEgyptianGoddess.h
	Source/Entities/Platformer/Enemies/Ruins/Lioness.h
	Source/Entities/Platformer/Enemies/Ruins/LionMan.h
	Source/Entities/Platformer/Enemies/Ruins/Medusa.h
	Source/Entities/Platformer/Enemies/Ruins/MedusaSmall.h
	Source/Entities/Platformer/Enemies/Ruins/Mermaid.h
	Source/Entities/Platformer/Enemies/Ruins/MummyPharaoh.h
	Source/Entities/Platformer/Enemies/Ruins/TigerMan.h
	Source/Entities/Platformer/Enemies/Ruins/Tigress.h
	Source/Entities/Platformer/Enemies/Snow/BossIceGolem.h
	Source/Entities/Platformer/Enemies/Snow/BossSanta.h
	Source/Entities/Platformer/Enemies/Snow/EvilSnowman.h
	Source/Entities/Platformer/Enemies/Snow/FrostDragon.h
	Source/Entities/Platformer/Enemies/Snow/FrostShooter.h
	Source/Entities/Platformer/Enemies/Snow/GoblinElf.h
	Source/Entities/Platformer/Enemies/Snow/IceGolem.h
	Source/Entities/Platformer/Enemies/Snow/TinyIceGolem.h
	Source/Entities/Platformer/Enemies/Snow/ToySoldierGoblin.h
	Source/Entities/Platformer/Enemies/Snow/WaterElemental.h
	Source/Entities/Platformer/Enemies/Snow/Yeti.h
	Source/Entities/Platformer/Enemies/Snow/YetiWarrior.h
	Source/Entities/Platformer/Enemies/Volcano/BossDemonKing.h
	Source/Entities/Platformer/Enemies/Volcano/CritterDemon.h
	Source/Entities/Platformer/Enemies/Volcano/DemonDragon.h
	Source/Entities/Platformer/Enemies/Volcano/DemonGhost.h
	Source/Entities/Platformer/Enemies/Volcano/DemonGrunt.h
	Source/Entities/Platformer/Enemies/Volcano/DemonRogue.h
	Source/Entities/Platformer/Enemies/Volcano/DemonShaman.h
	Source/Entities/Platformer/Enemies/Volcano/DemonSwordsman.h
	Source/Entities/Platformer/Enemies/Volcano/DemonWarrior.h
	Source/Entities/Platformer/Enemies/Volcano/FireElemental.h
	Source/Entities/Platformer/Enemies/Volcano/LavaGolem.h
	Source/Entities/Platformer/Npcs/Knight.h
	Source/Entities/Platformer/Npcs/NpcBase.h
	Source/Entities/Platformer/Squally/Hover.h
	Source/Entities/Platformer/Squally/Squally.h
	Source/Events/DialogEvents.h
	Source/Events/HackableEvents.h
	Source/Events/HexusEvents.h
	Source/Events/NavigationEvents.h
	Source/Objects/Isometric/HexusArcade.h
	Source/Objects/Isometric/IsometricDecorDeserializer.h
	Source/Objects/Isometric/IsometricDecorObject.h
	Source/Objects/Isometric/IsometricObjectDeserializer.h
	Source/Objects/Isometric/IsometricObjects.h
	Source/Objects/Platformer/Chest.h
	Source/Objects/Platformer/Monitor.h
	Source/Objects/Platformer/ParallaxObject.h
	Source/Objects/Platformer/PlatformerDecorDeserializer.h
	Source/Objects/Platformer/PlatformerDecorObject.h
	Source/Objects/Platformer/PlatformerObjectDeserializer.h
	Source/Objects/Platformer/PlatformerObjects.h
	Source/Objects/Platformer/WarpGate.h
	Source/Objects/Platformer/WarpGateExactScanTutorial.h
	Source/Objects/Platformer/Wind.h
	Source/Objects/Platformer/Plushies/Plushie.h
	Source/Objects/Platformer/Plushies/PlushieMonkey.h
	Source/Objects/Platformer/Plushies/Plushies.h
	Source/Scenes/SceneDirector.h
	Source/Scenes/Cutscenes/IntroCutscene/BoardMembers.h
	Source/Scenes/Cutscenes/IntroCutscene/HomeAssistantRobot.h
	Source/Scenes/Cutscenes/IntroCutscene/IntroCutscene.h
	Source/Scenes/Cutscenes/IntroCutscene/IntroSpace.h
	Source/Scenes/Cutscenes/IntroCutscene/NeonCity.h
	Source/Scenes/Cutscenes/IntroCutscene/RobotDoctor.h
	Source/Scenes/Cutscenes/IntroCutscene/SquallyUploadMars.h
	Source/Scenes/Cutscenes/IntroCutscene/SquallyUploadSpace.h
	Source/Scenes/Cutscenes/IntroCutscene/VaporLabs.h
	Source/Scenes/Cutscenes/IntroCutscene/VaporWeb.h
	Source/Scenes/Cutscenes/Objects/Explosion.h
	Source/Scenes/Cutscenes/Objects/FlyingCar.h
	Source/Scenes/Cutscenes/Objects/Grid.h
	Source/Scenes/Cutscenes/Objects/GridObject.h
	Source/Scenes/Cutscenes/Objects/Smoke.h
	Source/Scenes/Cutscenes/Objects/StarLayer.h
	Source/Scenes/Fights/Fight.h
	Source/Scenes/Hexus/Card.h
	Source/Scenes/Hexus/CardRow.h
	Source/Scenes/Hexus/CardStorage.h
	Source/Scenes/Hexus/Config.h
	Source/Scenes/Hexus/Deck.h
	Source/Scenes/Hexus/GameState.h
	Source/Scenes/Hexus/Hexus.h
	Source/Scenes/Hexus/CardData/CardData.h
	Source/Scenes/Hexus/CardData/CardList.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary0.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary1.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary10.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary11.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary12.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary13.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary14.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary15.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary2.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary3.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary4.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary5.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary6.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary7.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary8.h
	Source/Scenes/Hexus/CardData/Binary/CardBinary9.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal0.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal1.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal10.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal11.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal12.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal13.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal14.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal15.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal2.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal3.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal4.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal5.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal6.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal7.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal8.h
	Source/Scenes/Hexus/CardData/Decimal/CardDecimal9.h
	Source/Scenes/Hexus/CardData/Hex/CardHex0.h
	Source/Scenes/Hexus/CardData/Hex/CardHex1.h
	Source/Scenes/Hexus/CardData/Hex/CardHex10.h
	Source/Scenes/Hexus/CardData/Hex/CardHex11.h
	Source/Scenes/Hexus/CardData/Hex/CardHex12.h
	Source/Scenes/Hexus/CardData/Hex/CardHex13.h
	Source/Scenes/Hexus/CardData/Hex/CardHex14.h
	Source/Scenes/Hexus/CardData/Hex/CardHex15.h
	Source/Scenes/Hexus/CardData/Hex/CardHex2.h
	Source/Scenes/Hexus/CardData/Hex/CardHex3.h
	Source/Scenes/Hexus/CardData/Hex/CardHex4.h
	Source/Scenes/Hexus/CardData/Hex/CardHex5.h
	Source/Scenes/Hexus/CardData/Hex/CardHex6.h
	Source/Scenes/Hexus/CardData/Hex/CardHex7.h
	Source/Scenes/Hexus/CardData/Hex/CardHex8.h
	Source/Scenes/Hexus/CardData/Hex/CardHex9.h
	Source/Scenes/Hexus/CardData/Special/CardAddition.h
	Source/Scenes/Hexus/CardData/Special/CardEnvironmentBinStorm.h
	Source/Scenes/Hexus/CardData/Special/CardEnvironmentClear.h
	Source/Scenes/Hexus/CardData/Special/CardEnvironmentDecStorm.h
	Source/Scenes/Hexus/CardData/Special/CardEnvironmentHexStorm.h
	Source/Scenes/Hexus/CardData/Special/CardFlip1.h
	Source/Scenes/Hexus/CardData/Special/CardFlip2.h
	Source/Scenes/Hexus/CardData/Special/CardFlip3.h
	Source/Scenes/Hexus/CardData/Special/CardFlip4.h
	Source/Scenes/Hexus/CardData/Special/CardInverse.h
	Source/Scenes/Hexus/CardData/Special/CardLogicalAnd.h
	Source/Scenes/Hexus/CardData/Special/CardLogicalOr.h
	Source/Scenes/Hexus/CardData/Special/CardLogicalXor.h
	Source/Scenes/Hexus/CardData/Special/CardShiftLeft.h
	Source/Scenes/Hexus/CardData/Special/CardShiftRight.h
	Source/Scenes/Hexus/CardData/Special/CardSubtraction.h
	Source/Scenes/Hexus/Components/Avatars.h
	Source/Scenes/Hexus/Components/Banners.h
	Source/Scenes/Hexus/Components/CardPreview.h
	Source/Scenes/Hexus/Components/CoinFlip.h
	Source/Scenes/Hexus/Components/ComponentBase.h
	Source/Scenes/Hexus/Components/Components.h
	Source/Scenes/Hexus/Components/ControlCombineStaged.h
	Source/Scenes/Hexus/Components/ControlDraw.h
	Source/Scenes/Hexus/Components/ControlEndTurn.h
	Source/Scenes/Hexus/Components/ControlNeutral.h
	Source/Scenes/Hexus/Components/ControlReplaceCards.h
	Source/Scenes/Hexus/Components/ControlSacrificeStaged.h
	Source/Scenes/Hexus/Components/ControlSelectionStaged.h
	Source/Scenes/Hexus/Components/DeckCardCountDisplay.h
	Source/Scenes/Hexus/Components/HandCardCountDisplay.h
	Source/Scenes/Hexus/Components/LossesDisplay.h
	Source/Scenes/Hexus/Components/PassButton.h
	Source/Scenes/Hexus/Components/RowTotals.h
	Source/Scenes/Hexus/Components/ScoreTotal.h
	Source/Scenes/Hexus/HelpMenus/BinaryHelpMenu.h
	Source/Scenes/Hexus/HelpMenus/HelpMenuBase.h
	Source/Scenes/Hexus/HelpMenus/HelpMenus.h
	Source/Scenes/Hexus/Opponents/HexusOpponentData.h
	Source/Scenes/Hexus/Opponents/HexusOpponents.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataDemonKing.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataEgyptianGoddess.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataEvilEye.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataIceGolem.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataJack.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataKrampus.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataOrcKing.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataRhinoman.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataSanta.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataSkeletonKing.h
	Source/Scenes/Hexus/Opponents/Bosses/HexusOpponentDataWitch.h
	Source/Scenes/Hexus/Opponents/Kickstarter/HexusOpponentDataKnight.h
	Source/Scenes/Hexus/Opponents/Npcs/HexusOpponentDataEgyptianMummy.h
	Source/Scenes/Maps/IMap.h
	Source/Scenes/Maps/Isometric/IsometricMap.h
	Source/Scenes/Maps/Platformer/PlatformerMap.h
	Source/Scenes/Maps/Platformer/Backgrounds/BackgroundBase.h
	Source/Scenes/Maps/Platformer/Backgrounds/BackgroundDeserializer.h
	Source/Scenes/Maps/Platformer/Backgrounds/Backgrounds.h
	Source/Scenes/Maps/Platformer/Backgrounds/JungleBackground.h
	Source/Scenes/Maps/Platformer/Backgrounds/MountainBackground.h
	Source/Scenes/Maps/Platformer/Backgrounds/ObeliskBackground.h
	Source/Scenes/Maps/Platformer/Backgrounds/OceanBackground.h
	Source/Scenes/Maps/Platformer/Backgrounds/SnowBackground.h
	Source/Scenes/Maps/Platformer/Backgrounds/MatrixRain/MatrixLetter.h
	Source/Scenes/Maps/Platformer/Backgrounds/MatrixRain/MatrixRain.h
	Source/Scenes/Maps/Platformer/Backgrounds/MatrixRain/MatrixStrand.h
	Source/Scenes/Maps/Platformer/Weather/Fireflies.h
	Source/Scenes/Maps/Platformer/Weather/Rain.h
	Source/Scenes/Maps/Platformer/Weather/Snow.h
	Source/Scenes/Maps/Platformer/Weather/WeatherDeserializer.h
	Source/Scenes/Menus/MenuBackground.h
	Source/Scenes/Menus/Confirmation/ConfirmationMenu.h
	Source/Scenes/Menus/Dialog/DialogMenu.h
	Source/Scenes/Menus/HackerMode/CodeEditor.h
	Source/Scenes/Menus/HackerMode/RadialMenu.h
	Source/Scenes/Menus/LoadingScreen/LoadingScreen.h
	Source/Scenes/Menus/Minigames/MinigamesMenu.h
	Source/Scenes/Menus/Minigames/Hexus/HexusMenu.h
	Source/Scenes/Menus/Minigames/Hexus/HexusOpponentFrame.h
	Source/Scenes/Menus/Minigames/Hexus/HexusPuzzleItem.h
	Source/Scenes/Menus/Minigames/Hexus/HexusPuzzlesMenu.h
	Source/Scenes/Menus/Options/OptionsMenu.h
	Source/Scenes/Menus/Pause/PauseMenu.h
	Source/Scenes/Menus/SaveSelect/SaveSelectMenu.h
	Source/Scenes/Menus/Title/HackerMode.h
	Source/Scenes/Menus/Title/TitleScreen.h
	Source/Scenes/Menus/Title/TitleScreenBackground.h
	Source/Scenes/Menus/Tutorial/TutorialItem.h
	Source/Scenes/Menus/Tutorial/TutorialScreen.h
	Source/Scenes/Menus/WorldMap/MapNode.h
	Source/Scenes/Menus/WorldMap/WorldMap.h
	Source/Sound/MusicDeserializer.h
)

if(LINUX)
    list(APPEND GAME_SOURCE
         proj.linux/main.cpp
         )
elseif(WINDOWS)
    list(APPEND GAME_HEADER
         proj.win32/main.h
         proj.win32/resource.h
         )
    list(APPEND GAME_SOURCE
         proj.win32/main.cpp
         proj.win32/game.rc
         ${common_res_files}
         )
elseif(APPLE)
    if(MACOSX)
        set(APP_UI_RES
            proj.ios_mac/mac/Icon.icns
            proj.ios_mac/mac/Info.plist
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/mac/main.cpp
             proj.ios_mac/mac/Prefix.pch
             ${APP_UI_RES}
             )
    endif()
    list(APPEND GAME_SOURCE ${common_res_files})
endif()

# mark app complie info and libs info
set(APP_SRC
    ${GAME_SOURCE}
    ${GAME_HEADER}
    )
cocos_build_app(${APP_NAME}
                APP_SRC "${APP_SRC}"
                DEPEND_COMMON_LIBS "cocos2d"
                )

if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")
    if(MACOSX)
        set_target_properties(${APP_NAME} PROPERTIES
                              MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/mac/Info.plist"
                              )
    endif()
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME} COPY_TO ${APP_BIN_DIR})
endif()

if(LINUX OR WINDOWS)
    cocos_copy_target_res(${APP_NAME} COPY_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()