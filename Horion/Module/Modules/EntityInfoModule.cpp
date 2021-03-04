#include "EntityInfoModule.h"
#include "../../DrawUtils.h"

EntityInfoModule::EntityInfoModule() : IModule(0, Category::VISUAL, "Displays info about an entity.") {
	//someone want to add some bool settings for individual items like the position display, entity name display, and hostility display  over in DrawUtils.cpp


	entIdMap[10] = "Chicken";
	entIdMap[11] = "Cow";
	entIdMap[12] = "Pig";
	entIdMap[13] = "Sheep";
	entIdMap[14] = "Wolf";
	entIdMap[15] = "Villager";
	entIdMap[16] = "Mooshroom";
	entIdMap[17] = "Squid";
	entIdMap[18] = "Rabbit";
	entIdMap[19] = "Bat";
	entIdMap[20] = "Iron Golem";
	entIdMap[21] = "Snow Golem";
	entIdMap[22] = "Ocelot";
	entIdMap[23] = "Horse";
	entIdMap[24] = "Donkey";
	entIdMap[25] = "Mule";
	entIdMap[26] = "Skeleton Horse";
	entIdMap[27] = "Zombie Horse";
	entIdMap[28] = "Polar Bear";
	entIdMap[29] = "Llama";
	entIdMap[30] = "Parrot";
	entIdMap[31] = "Dolphin";
	entIdMap[74] = "Turtle";
	entIdMap[75] = "Cat";
	entIdMap[108] = "Pufferfish";
	entIdMap[109] = "Salmon";
	entIdMap[111] = "Tropical Fish";
	entIdMap[112] = "Cod";
	entIdMap[113] = "Panda";
	entIdMap[115] = "Villager";
	entIdMap[118] = "Wandering Trader";
	entIdMap[121] = "Fox";
	entIdMap[122] = "Bee";
	entIdMap[125] = "Strider";
	//entIdMap[128] = "Goat";        activate for 1.17
	entIdMap[63] = "Player";
	entIdMap[117] = "Shield";
	entIdMap[51] = "NPC";
	entIdMap[56] = "Agent";
	entIdMap[62] = "Camera";
	entIdMap[78] = "Chalkboard";
	entIdMap[32] = "Zombie";
	entIdMap[33] = "Creeper";
	entIdMap[34] = "Skeleton";
	entIdMap[35] = "Spider";
	entIdMap[36] = "Zombified Piglin";
	entIdMap[37] = "Slime";
	entIdMap[38] = "Enderman";
	entIdMap[39] = "Silverfish";
	entIdMap[40] = "Cave Spider";
	entIdMap[41] = "Ghast";
	entIdMap[42] = "Magma Cube";
	entIdMap[43] = "Blaze";
	entIdMap[44] = "Zombie Villager";
	entIdMap[45] = "Witch";
	entIdMap[46] = "Stray";
	entIdMap[47] = "Husk";
	entIdMap[48] = "Wither Skeleton";
	entIdMap[49] = "Guardian";
	entIdMap[50] = "Elder Guardian";
	entIdMap[52] = "Wither";
	entIdMap[53] = "Ender Dragon";
	entIdMap[54] = "Shulker";
	entIdMap[55] = "Endermite";
	entIdMap[57] = "Vindicator";
	entIdMap[58] = "Phantom";
	entIdMap[59] = "Ravager";
	entIdMap[104] = "Evoker";
	entIdMap[105] = "Vex";
	entIdMap[110] = "Drowned";
	entIdMap[114] = "Pillager";
	entIdMap[116] = "Zombie Villager";
	entIdMap[123] = "Piglin";
	entIdMap[124] = "Hoglin";
	entIdMap[126] = "Zoglin";
	entIdMap[127] = "Piglin Brute";
	entIdMap[64] = "Item";
	entIdMap[69] = "XP Orb";
	entIdMap[65] = "TNT";
	entIdMap[66] = "Falling Block";
	entIdMap[67] = "Moving Block";
	entIdMap[61] = "Armor Stand";
	entIdMap[68] = "Xp Bottle";
	entIdMap[70] = "Eye of Ender Signal";
	entIdMap[71] = "Ender Crystal";
	entIdMap[72] = "Firework Rocket";
	entIdMap[73] = "Thrown Trident";
	entIdMap[76] = "Shulker Bullet";
	entIdMap[77] = "Fishing Rod Hook";
	entIdMap[79] = "Dragon Fireball";
	entIdMap[80] = "Shot Arrow";
	entIdMap[81] = "Thrown Snowball";
	entIdMap[82] = "Thrown Egg";
	entIdMap[83] = "Painting";
	entIdMap[84] = "Minecart";
	entIdMap[85] = "Ghast Fireball";
	entIdMap[86] = "Thrown Splash Potion";
	entIdMap[87] = "Thrown Ender Pearl";
	entIdMap[88] = "Leash Knot";
	entIdMap[89] = "Wither Skull";
	entIdMap[90] = "Boat";
	entIdMap[91] = "Blue Wither Skull";
	entIdMap[93] = "Lightning Bolt";
	entIdMap[94] = "Blaze Fireball";
	entIdMap[95] = "Area Affect Cloud";
	entIdMap[96] = "Minecart With Hopper";
	entIdMap[97] = "Minecart With TNT";
	entIdMap[98] = "Minecart With Chest";
	entIdMap[100] = "Minecart With Command Block";
	entIdMap[101] = "Thrown Lingering Potion";
	entIdMap[102] = "Lama Spit";
	entIdMap[103] = "Evocation Fangs";
	//entIdMap[106] = "Ice Bomb";                      idk what the heck these are
	//entIdMap[107] = "Balloon";
}

EntityInfoModule::~EntityInfoModule() {
}

const char* EntityInfoModule::getModuleName() {
	return ("EntityInfo");
}

void EntityInfoModule::onPreRender(C_MinecraftUIRenderContext* renderCtx) {
	if (this->delay == 2) {
		this->delay = 0;
		C_LocalPlayer* localPlayer = g_Data.getLocalPlayer();
		if (localPlayer != nullptr && GameData::canUseMoveKeys()) {
			g_Data.forEachEntity([&](C_Entity* ent, bool valid) {
				if (ent != g_Data.getLocalPlayer() && !Target::isValidTarget(ent)) {
					DrawUtils::drawEntityInfoTags(ent, 0.75, true);
				}
			});
		}
	} else {
		this->delay++;
	}
	
}
void EntityInfoModule::onLevelRender() {
	g_Data.forEachEntity([&](C_Entity* ent, bool valid) {
		if (ent != g_Data.getLocalPlayer() && !Target::isValidTarget(ent) && ent->getEntityTypeId() != 63 && ent->getEntityTypeId() != 64) {
			DrawUtils::setColor(255, 255, 255, 1);
			DrawUtils::drawLine3d(*ent->getPos(), ent->getPos()->add(0, 2, 0));
		}
	});
}